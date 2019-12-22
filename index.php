<?php
use twitch\Token;
use utilidades\Log;
//include_once "utilidades\autoload.inc";
include_once "utilidades/log.inc";
include_once "twitch/twitch.php";
try{
   $datosUsuario=Token::usuarioID();
   
   if($datosUsuario===null){
      return;
   }
   Log::debug($datosUsuario["id"]);
}catch (\Exception $ex){
   echo $ex->getMessage();
}

//echo "#FF0000";



