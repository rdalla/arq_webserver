#ifndef HTML_H
#define HTML_H

#define HTML_PAGE \
"<!DOCTYPE html>\
<html>\
<body>\
<center><h1>Projeto 2 - Webserver</h1></center>\
<center><h1>Arquitetura de redes de comunicacao</h1></center>\
<table>\
<tr>\
<td>\
<form>\
<button name=\"LED1\" button style=\"color:green\" value=\"ON\" type=\"submit\"> LED1 ON</button>\
<button name=\"LED1\" button style=\"color:red\" value=\"OFF\" type=\"submit\"> LED1 OFF</button>\
</form>\
</td>\
<td>\
<form>\
<button type=\"submit\">BLINK</button>\
<label>Delay:</label>\
<input type=\"text\" name=\"BLINK1\" value=\"500\">\
</form>\
</td>\
</tr>\
<tr>\
<td>\
<form>\
<button name=\"LED2\" button style=\"color:green\" value=\"ON\" type=\"submit\"> LED2 ON</button>\
<button name=\"LED2\" button style=\"color:red\" value=\"OFF\" type=\"submit\"> LED2 OFF</button>\
</form>\
</td>\
<td>\
<form>\
<button type=\"submit\">BLINK</button>\
<label>Delay:</label>\
<input type=\"text\" name=\"BLINK2\" value=\"500\">\
</form>\
</td>\
</tr>\
<tr>\
<td>\
<form>\
<button name=\"LED3\" button style=\"color:green\" value=\"ON\" type=\"submit\"> LED3 ON</button>\
<button name=\"LED3\" button style=\"color:red\" value=\"OFF\" type=\"submit\"> LED3 OFF</button>\
</form>\
</td>\
<td>\
<form>\
<button type=\"submit\">BLINK</button>\
<label>Delay:</label>\
<input type=\"text\" name=\"BLINK3\" value=\"500\">\
</form>\
</td>\
</tr>\
</table>\
</body>\
</html>"

#endif