<!DOCTYPE html>
<html>
<body>
<h1>MY first PHP page.</h1>
<?php
echo "Hello World<br>";
require_once "PHPTelnet.php";
$telnet = new PHPTelnet();
$telent->show_connect_error = 0;
$result = $telnet->Connect('192.168.1.1', 'admin', 'admin');

switch ($result) {
case 0:
	echo "login success<br>";
	$telnet->Docommand("wl -i wl0.1 assoclist", $result);
	echo $result;
	break;
case 1:
	echo '[PHP Telnet] Connect failed: Unable to open network connection';
	break;
case 2:
	echo '[PHP Telnet] Connect failed: Unknown host';
	break;
case 3:
	echo '[PHP Telnet] Connect failed: Login failed';
	break;
case 4:	
	echo '[PHP Telnet] Connect failed: Your PHP version does not support PHP Telnet';
	break;
}
$telnet->Disconnect();
?>
</body>
</html>
