<?php
spl_autoload_register(function (string $clase){
   $partes = explode("\\", $clase);
   $partes[count($partes) - 1] = strtolower($partes[count($partes) - 1]) . ".inc";
   $clase = implode("\\", $partes);
   require_once $clase;
}
);