#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
void setup() {
Serial.begin(9600);
 WiFi.begin("REALME 5G","03032003");
while(WiFi.status() != WL_CONNECTED){
  Serial.print('.');
  delay(200);
  }
  Serial.println();
  Serial.println("Witty Board Connected!");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
 

}
