
#include <WiFi.h>
#include <IRremote.h>


IRsend irsend;

IPAddress local_IP(192,168,1,183); // Built on Class C private networks 
IPAddress gateway(192,168,1,1);    // Change according to your own settings
IPAddress subnet(255,255,255,0);

WiFiServer server(80); //Initialize the server on Port 80
int LED_PIN = BUILTIN_LED;

const char *ssid = "PUT_SSID_HERE";
const char *pass = "PUT_PASSWORD_HERE";



void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Configuring IP");
  if (!WiFi.config(local_IP,gateway,subnet)){
    Serial.println("failed"); 
  }
  Serial.println("OK");
  Serial.println("Connecting to: " );
  Serial.println(ssid);
  WiFi.begin(ssid,pass);
  while (WiFi.status() != WL_CONNECTED) {
    irsend.sendSAMSUNG(0xE0E0E01F,32);
    Serial.print(" . ");
    digitalWrite(LED_BUILTIN,digitalRead(LED_BUILTIN));
    delay(500);
    irsend.sendSAMSUNG(0xE0E0D02F,32);
    delay(500);
    
   }
   Serial.println("Connected");
   Serial.println(WiFi.localIP());


server.begin(); // Start the HTTP Server
}

void loop() {


WiFiClient client = server.available();


if (!client) {


return;

}
//Looking under the hood


Serial.println("Somebody has connected:)");


//Read what the browser has sent into a Stringclass and print the request to the monitor


String request = client.readStringUntil('\r');

Serial.println(request);

// Handle the Request


if (request.indexOf("/Power") != -1){


irsend.sendSAMSUNG(0xE0E040BF,32);
Serial.println("Power");
}

else if (request.indexOf("/VolumeUp") != -1){
irsend.sendSAMSUNG(0xE0E0E01F,32);

}
else if (request.indexOf("/VolumeDown") != -1){
irsend.sendSAMSUNG(0xE0E0D02F,32);

}
else if (request.indexOf("/ChUp") != -1){
irsend.sendSAMSUNG(0xE0E048B7,32);

}
else if (request.indexOf("/ChDown") != -1){
irsend.sendSAMSUNG(0xE0E008F7,32);

}
else if (request.indexOf("/Mute") != -1){
irsend.sendSAMSUNG(0xE0E0F00F,32);

}
else if (request.indexOf("/Source") != -1){
irsend.sendSAMSUNG(0xE0E0807F,32);

}
else if (request == "GET /0 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E08877,32);
Serial.println("0");
}
else if (request == "GET /1 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E020DF,32);
Serial.println("1");
}
else if (request == "GET /2 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E0A05F,32);
Serial.println("2");
}
else if (request == "GET /3 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E0609F,32);
Serial.println("3");
}
else if (request == "GET /4 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E010EF,32);
Serial.println("4");
}
else if (request == "GET /5 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E0906F,32);
Serial.println("5");
}
else if (request == "GET /6 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E050AF,32);
Serial.println("6");
}
else if (request == "GET /7 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E030CF,32);
Serial.println("7");
}
else if (request == "GET /8 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E0B04F,32);
Serial.println("8");
}
else if (request == "GET /9 HTTP/1.1"){
irsend.sendSAMSUNG(0xE0E0708F,32);
Serial.println("9");
}
else if (request.indexOf("/Up") != -1){
irsend.sendSAMSUNG(0xE0E006F9,32);
}
else if (request.indexOf("/Down") != -1){
irsend.sendSAMSUNG(0xE0E08679,32);
}
else if (request.indexOf("/Left") != -1){
irsend.sendSAMSUNG(0xE0E0A659,32);
}
else if (request.indexOf("/Right") != -1){
irsend.sendSAMSUNG(0xE0E046B9,32);
}
else if (request.indexOf("/Ok") != -1){
irsend.sendSAMSUNG(0xE0E016E9,32);
}
else if (request.indexOf("/Menu") != -1){
irsend.sendSAMSUNG(0xE0E058A7,32);
}
else if (request.indexOf("/Aspect") != -1){
irsend.sendSAMSUNG(0xE0E06897,32);
}


}
