<?php
use twitch\Token;
use utilidades\Log;
//include_once "utilidades\autoload.inc";
include_once "utilidades/log.inc";
include_once "twitch/twitch.php";
try{
   if(twitch\Peticion::procesar()===null){
      return null;
   }
}catch(Exception $ex){
   echo "{\"error\":\"".$ex->getMessage()."\"}";
   header("HTTP/1.1 400 KO");
}





//echo "#FF0000";



