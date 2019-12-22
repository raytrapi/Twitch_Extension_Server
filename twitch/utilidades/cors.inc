<?php
namespace twitch\utilidades;
class Cors{
   /**
    * Genera las cabeceras para corregir el problema de Cors
    * @return bool verdadero si se ha de continuar y false si se ha de detern
    */
   public static function cabeceras(){
      header('Access-Control-Allow-Origin:*');
      header('Access-Control-Allow-Methods:GET,POST,OPTIONS');//,PUT,DELETE,UPDATE
      header('Access-Control-Allow-Headers:Authorization,Content-Type,X-REQUESTED-WITH');
      return $_SERVER["REQUEST_METHOD"]!="OPTIONS";
   }
}