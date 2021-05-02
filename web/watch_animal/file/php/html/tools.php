<?php
/**
 * Animal Waitch App
 * tools.php
 * @since 2021/04/11
 */
function toHtmlEn($string) {
    return htmlspecialchars($string,ENT_QUOTES,'UTF-8');
}

function console_log( $data ){
    echo '<script>';
    echo 'console.log('. json_encode( $data ) .')';
    echo '</script>';
}
?>