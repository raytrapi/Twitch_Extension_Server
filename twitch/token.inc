<?php
namespace twitch;

use twitch\utilidades\Cors;

class Token{
   public static function usuarioID(){
      if(!file_exists(__DIR__."/config/datos.inc")){
         throw new \Exception("No existe el fichero de configuración de datos. Revise la carpeta ".__DIR__."/config/datos.inc");   
      }
      include_once __DIR__."/config/datos.inc";
      if(!Cors::cabeceras()){
         return null;
      }
      $token=self::getBearerToken();
      $token64=[];
      $clave=base64_decode(CLAVE_FIMA);
      
      if(strlen($token)>0){
         $token64=explode('.',$token);
         $token=[];
         $longitudFirma=strlen($token64[2]);
         if($longitudFirma%4 >0){
            $longitudFirma=ceil($longitudFirma/4)*4;
         }
         $token64[2]=strtr(str_pad($token64[2],$longitudFirma,"="),"-_","+/");
         for($i=0;$i<count($token64);$i++){
            $token[$i]=base64_decode($token64[$i]);
         }
         $hash=hash_hmac( "sha256",$token64[0].".".$token64[1],$clave,true);
         if($token[2]!=$hash){
            throw new \Exception("Firma incorrecta");
         }
      }else{
         throw new \Exception("No hay token");
      }
      $payload=json_decode($token[1], true);
      return ["id"=>$payload["opaque_user_id"]];
   }



   /*
   Copiado de internet
   */
   private static function getBearerToken() {
      $headers = self::getAuthorizationHeader();
      // HEADER: Get the access token from the header
      if (!empty($headers)) {
         if (preg_match('/Bearer\s(\S+)/', $headers, $matches)) {
            return $matches[1];
         }
      }
      return null;
   }
   private static function getAuthorizationHeader(){
      $headers = null;
      if (isset($_SERVER['Authorization'])) {
         $headers = trim($_SERVER["Authorization"]);
      }
      else if (isset($_SERVER['HTTP_AUTHORIZATION'])) { //Nginx or fast CGI
         
         $headers = trim($_SERVER["HTTP_AUTHORIZATION"]);
      } elseif (function_exists('apache_request_headers')) {
         $requestHeaders = apache_request_headers();
         // Server-side fix for bug in old Android versions (a nice side-effect of this fix means we don't care about capitalization for Authorization)
         $requestHeaders = array_combine(array_map('ucwords', array_keys($requestHeaders)), array_values($requestHeaders));
         if (isset($requestHeaders['Authorization'])) {
            $headers = trim($requestHeaders['Authorization']);
         }
      }
      return $headers;
   }
}

