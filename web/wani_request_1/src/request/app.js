const createError = require("http-errors");
const express = require("express");
const path = require("path");
const cookieParser = require("cookie-parser");
const logger = require("morgan");
const puppeteer = require("puppeteer");

const app = express();

// view engine setup
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

app.use(logger("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, "public")));

app.get("/", function (req, res, next) {
  res.render("index", { title: "Wani Request" });
});

app.post('/', function (req, res, next) {
  console.log(req.body.url);
  if (req.body.url) {
    try {
      const target_url = new URL(req.body.url);

      res.send("URL received.\n");
      console.log("URL received.\n");

      const secret_url = process.env.SECRET_URL;
      console.log(secret_url);
      const url_param = "?url=" + target_url;
      const crawl_url = secret_url + url_param;

      (async () => {
        const browser = await puppeteer.launch({args: ['--no-sandbox', '--disable-setuid-sandbox']});
        const page = await browser.newPage();

        await page.goto(crawl_url, { waitUntil: "networkidle0" });
        console.log(await page.title());

        await Promise.all([
          page.waitForNavigation({ waitUntil: ['load', 'networkidle2'] }),
          page.click('a')
        ]);

        await browser.close();
      })();
    } catch (error) {
      res.send("Please send URL.");
    }
  } else {
    res.send("Please send URL.");
  }
})

// catch 404 and forward to error handler
app.use(function (req, res, next) {
  next(createError(404));
});

// error handler
app.use(function (err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get("env") === "development" ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render("error");
});

module.exports = app;
