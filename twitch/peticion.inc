<?php

namespace twitch;

use utilidades\Log;

class Peticion {
   public static function procesar(){
      //Log::debug($_SERVER);
      $datosUsuario=Token::usuarioID();
      if($datosUsuario===null){
         return null;
      }
      $direccionLlamada=explode("/",$_SERVER["REQUEST_URI"]);
      Log::debug("Procesamos: ".$direccionLlamada[count($direccionLlamada)-1]);
      Log::debug($datosUsuario["id"]);
      echo "{\"datos\":\"HOLA\"}";
      
   }
}

