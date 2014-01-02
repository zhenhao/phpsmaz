<?php

$strs = array(
    "http://www.baidu.com",
    "This is a small string",
    "THIS IS A SMALL STRING",
    "Nothing is more difficult, and therefore more precious, than to be able to decide",
    "http://github.com/antirez/smaz/tree/master",
    "1000 numbers 2000 will 10 20 30 compress very little", 
    "好好学习，天天向上",
    "good", 
    "luck",
);

foreach($strs as $str)
{

    $x = smaz_encode($str);
    $t = smaz_decode($x);

    $rate = 100 - round(strlen($x)/strlen($str) * 100, 2);

    echo $rate > 0 ? "-" : "+", abs($rate), "%\t", $t, "\n";
}

