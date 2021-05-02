<?php
/**
 * Animal Waitch App
 * dp.php
 * @since 2021/04/11
 */

function login($dsn, $db_user, $db_pass, $email, $password) {
    $db = new PDO($dsn, $db_user, $db_pass);
    $r = $db->query("SELECT * FROM users WHERE email = '" . $email . "' AND password = '" . $password . "'");
    $result = $r && $r->fetch();
    return $result;
}
?>