<?php

/**
 * Animal Waitch App
 * index.php
 * @since 2021/04/11
 */
require 'tools.php';
require 'db.php';

$email = isset($_POST['email']) ? $_POST['email'] : '';
$password = isset($_POST['password']) ? $_POST['password'] : '';
$login = false;
$err = '';

if ($email !== '' && $password !== '') {
  if (strlen($email) > 32) {
    $err = 'Login Failed... Email address must be 32 characters or less.';
  } else {
    if (strlen($password) > 128) {
      $err = 'Login Failed... Password must be 128 characters or less.';
    } else {
      $dsn = 'mysql:host=mysql;dbname=animaldb;chartset=utf8mb4';
      $db_user = 'animal';
      $db_pass = 'RTpBfdBT4e3rc5yD';
      $login = login($dsn, $db_user, $db_pass, $email, $password);
      if (!$login) {
        $err = 'Login Failed... Either the email or password is invalid.';
      }
    }
  }
}
?>
<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <link rel="icon" href="image/ico/logo.ico">
  <title>Animal Watch Service</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css">
  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/js/bootstrap.bundle.min.js"></script>
</head>

<body class="text-center">
  <nav class="navbar navbar-dark bg-dark">
    <a class="navbar-brand" href="">
      <img src="image/svg/logo.svg" width="32" height="32" class="d-inlne-block align-top" alt="squirrel">
      <b class="ml-2 align-middle">Animal Watch Service</b>
    </a>
  </nav>
  <div class="mx-auto">
    <div>
      <img class="mt-5 mb-4" src="image/svg/logo.svg" alt="" width="96" height="96">
    </div>
    <?php if (!$login) { ?>
      <div class="mx-auto" style="width: 420px;">
        <form class="form-signin" method="POST">
          <h1 class="h3 mb-3 font-weight-normal text-muted">Please sign in</h1>
          <label for="inputEmail" class="sr-only">Email address</label>
          <input type="email" id="inputEmail" class="form-control" placeholder="Email address" required autofocus name="email" value="<?php echo toHtmlEn($email); ?>">
          <label for="inputPassword" class="sr-only">Password</label>
          <input type="password" id="inputPassword" class="form-control" placeholder="Password" required name="password" value="<?php echo toHtmlEn($password); ?>">
          <button class="btn btn-lg btn-success mt-3" type="submit">Sign in</button>
        </form>
      </div>
    <?php } else { ?>
    <div class="mx-auto">
      <div class="album py-5 bg-light">
        <div class="container">
          <div class="row">
            <div class="col-md-12" id="collection-heading">
              <h3 class="text-muted">Animal Collection</h3>
            </div>
          </div>
          <div class="row">
            <div class="col-md-4">
              <div class="card mb-4 box-shadow">
                <img class="card-img-top" src="image/jpg/serval.jpg" alt="Card image cap">
                <div class="card-body">
                  <p class="card-text text-muted">The serval is a wild cat native to Africa. It is rare in North Africa and the Sahel, but widespread in sub-Saharan countries except rainforest regions.</p>
                </div>
              </div>
            </div>
            <div class="col-md-4">
              <div class="card mb-4 box-shadow">
                <img class="card-img-top" src="image/jpg/elephant.jpg" alt="Card image cap">
                <div class="card-body">
                  <p class="card-text text-muted">Elephants are mammals of the family Elephantidae and the largest existing land animals. Three species are currently recognised: the African bush elephant, the African forest elephant, and the Asian elephant. </p>
                </div>
              </div>
            </div>
            <div class="col-md-4">
              <div class="card mb-4 box-shadow">
                <img class="card-img-top" src="image/jpg/rabbit.jpg" alt="Card image cap">
                <div class="card-body">
                  <p class="card-text text-muted">Rabbits are small mammals in the family Leporidae of the order Lagomorpha. Oryctolagus cuniculus includes the European rabbit species and its descendants, the world's 305 breeds of domestic rabbit.</p>
                </div>
              </div>
            </div>
            <div class="col-md-4">
              <div class="card mb-4 box-shadow">
                <img class="card-img-top" src="image/jpg/alpaca.jpg" alt="Card image cap">
                <div class="card-body">
                  <p class="card-text text-muted">The alpaca is a species of South American camelid mammal. It is similar to, and often confused with, the llama. However, alpacas are often noticeably smaller than llamas.</p>
                </div>
              </div>
            </div>
            <div class="col-md-4">
              <div class="card mb-4 box-shadow">
                <img class="card-img-top" src="image/jpg/platypus.jpg" alt="Card image cap">
                <div class="card-body">
                  <p class="card-text text-muted">The platypus, sometimes referred to as the duck-billed platypus, is a semiaquatic, egg-laying mammal endemic to eastern Australia, including Tasmania. The platypus is the sole living representative of its family and genus, though a number of related species appear in the fossil record.</p>
                </div>
              </div>
            </div>
            <div class="col-md-4">
              <div class="card mb-4 box-shadow">
                <img class="card-img-top" src="image/jpg/crocodile.jpg" alt="Card image cap">
                <div class="card-body">
                  <p class="card-text text-muted">Crocodiles or true crocodiles are large semiaquatic reptiles that live throughout the tropics in Africa, Asia, the Americas and Australia.</p>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
      <?php } ?>
      <div style="font-weight:bold; color:red">
        <?php echo toHtmlEn($err); ?>
      </div>
      <p class="mt-5 mb-3 text-muted">&copy; 2021 WaniCTF'21-spring</p>
  </div>
</body>
</html>
