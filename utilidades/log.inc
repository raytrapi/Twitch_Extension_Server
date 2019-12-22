<?php 
namespace utilidades;
class Log{
   public static function debug($texto){
      if(is_array($texto)){
         $texto=print_r($texto,true);
      }
      $fecha = date("d-m-Y H:i:s");
      
      $path = "peticion.txt";
      $fo = fopen($path, "a");
      if ($fo) {
         fwrite($fo, $fecha . "\t" . $texto . "\r\n");
         fclose($fo);
      }
   }
   
}