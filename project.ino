
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "base64.h"


int relay = D5;

int us_echo = D2;
int us_trig = D3;
int waktu;
int distance;

char ssid[] = "Jonathan Lt. 2";
char pass[] = "11223344A";

// Replace with your unique IFTTT URL resource
const char* resource = "/trigger/order_arrived/with/key/d7TxO2d7eF45kcMOU_5Ce4MrOoJlEHQ3-1zMAKTts9H";


// Maker Webhooks IFTTT
const char* server = "maker.ifttt.com";


void setup () {
Serial.begin(115200);
pinMode(LED_BUILTIN, OUTPUT);
pinMode(us_echo, INPUT);
pinMode(us_trig, OUTPUT);
pinMode(relay, OUTPUT);

digitalWrite(relay, LOW);
delay(10);

//Connect to Wifi
Serial.println();
Serial.println();
Serial.println("Connecting to...");

WiFi.begin(ssid, pass);

while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
}
Serial.println("");
Serial.println("Connected to Wifi");
Serial.println(WiFi.localIP());
}

void loop () {
digitalWrite(us_trig, LOW);
delayMicroseconds(2);
digitalWrite(us_trig, HIGH);
delayMicroseconds(10);
digitalWrite(us_trig, LOW);

waktu = pulseIn(us_echo, HIGH);  //dalam microsecond
distance = (waktu * 0.034) / 2;    //dalam cm


if (distance <= 5) {
    webIFTTTRequest();
    digitalWrite(relay, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(3000);
    digitalWrite(relay, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    int k = readNow();
    while(k <= 5){
        Serial.print("ini K");
        Serial.println(k);
        Serial.println(readNow());
        delay(1000);
        k = readNow();
        Serial.println(k);
    }

}else{
    digitalWrite(relay, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
} 
}
void webIFTTTRequest() {
  Serial.print("Connecting to "); 
  Serial.print(server);
  
  WiFiClient client;
  if (!client.connect(server, 80)) {
    Serial.println("connection failed");
  }
  
  Serial.print("Request resource: "); 
  Serial.println(resource);
  client.print(String("GET ") + resource + " HTTP/1.1\r\n" +
                  "Host: " + server + "\r\n" + 
                  "Connection: close\r\n\r\n");
                  

  unsigned long timeout = millis();
  // Read all the lines of the reply from server and print them to Serial
  while (client.available() == 0) {
    if (millis() - timeout > 5000){
      Serial.println(">>> Client Timeout !");
      client.stop(); return;
    }
  } 

  while(client.available()){
    Serial.write(client.read());
  }
  Serial.println("\nclosing connection");
  client.stop();
}

int readNow() {
    int dT;
    int dX;
    digitalWrite(us_trig, LOW);
    delayMicroseconds(2);
    digitalWrite(us_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(us_trig, LOW);

    dT = pulseIn(us_echo, HIGH);  //dalam microsecond
    dX = (dT * 0.034) / 2;    //dalam cm
  return dX;
}

