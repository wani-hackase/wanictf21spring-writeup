const createError = require("http-errors");
const express = require("express");
const path = require("path");
const cookieParser = require("cookie-parser");
const logger = require("morgan");
const puppeteer = require("puppeteer");
const axios = require("axios");

const target_url = process.env.TARGET;
const domain = process.env.DOMAIN;

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
  res.send("get method.");
});

app.post("/page1", function (req, res, next) {
  if (req.body.wani && req.body.token) {
    try {
      console.log("Received :", req.body.wani);

      const url_param = "/page1?wani=" + req.body.wani;
      const crawl_url = target_url + url_param;

      const cookies1 = [
        {
          domain: domain,
          path: "/page1",
          name: "flag1",
          value: "FLAG{y0u_4r3_x55",
        },
      ];

      (async () => {
        const response = await axios.get(
          "https://www.google.com/recaptcha/api/siteverify?secret=xxxxxxxxxxxxxxxxxxxxxxxx&response=" +
            req.body.token
        );
        if (!response.data.success) {
          console.log("recaptcha check failed :", response.data);
          res.send("recaptcha check failed");
          return;
        }
        const browser = await puppeteer.launch({
          args: ["--no-sandbox", "--disable-setuid-sandbox"],
        });
        const page = await browser.newPage();

        await page.setCookie(...cookies1);
        console.log(crawl_url);
        await page.goto(crawl_url, { waitUntil: "networkidle0" });

        await browser.close();
        console.log("browser close.");
        res.send("受け取ったよ.\n");
      })();
    } catch (error) {
      res.send("エラーが起きたみたいだよ。");
    }
  } else {
    res.send("何も届いてないよ");
  }
});

app.post("/page2", function (req, res, next) {
  if (req.body.text && req.body.token) {
    try {
      console.log("Received :", req.body.text);

      const crawl_url = target_url + "/page2";

      const cookies2 = [
        {
          domain: domain,
          path: "/page2",
          name: "flag2",
          value: "-60d_c75a4c80cf07}",
        },
      ];

      const req_text = req.body.text;

      (async () => {
        const response = await axios.get(
          "https://www.google.com/recaptcha/api/siteverify?secret=6LdbEbwaAAAAADASOSAYPmbIgq-ZGq7GgmzDZmxR&response=" +
            req.body.token
        );
        if (!response.data.success) {
          console.log("recaptcha check failed :", response.data);
          res.send("recaptcha check failed");
          return;
        }
        const browser = await puppeteer.launch({
          args: ["--no-sandbox", "--disable-setuid-sandbox"],
        });
        const page = await browser.newPage();

        await page.setCookie(...cookies2);

        await page.goto(crawl_url, { waitUntil: "networkidle0" });

        await page.$eval("#textarea", (element) => (element.value = ""));
        await page.type("#textarea", req_text);
        //await page.screenshot({ path: 'screenshot.png' });

        await page.click("#link");
        await page.waitForTimeout(1000);

        await browser.close();
        console.log("browser close.");
        res.send("受け取ったよ.\n");
      })();
    } catch (error) {
      res.send("エラーが起きたみたいだよ。");
    }
  } else {
    res.send("何も届いてないよ");
  }
});

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
