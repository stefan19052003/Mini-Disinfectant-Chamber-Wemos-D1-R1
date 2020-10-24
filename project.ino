#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "base64.h"

int relay = D5;

int us_echo = D2;
int us_trig = D3;
int waktu;
int distance;

int stepper1 = D10;
int stepper2 = D11;
int stepper3 = D12;
int stepper4 = D13; 
int step_num = 0;

char ssid[] = "Jonathan Lt. 2";
char pass[] = "11223344A";

//const char* account_sid = "AC1f4819ce3eb0dafd94c084126093d869";
//const char* auth_token = "f027b4fc27747d38fec643f742771db0";

//Data twilio
String account_sid = "AC1f4819ce3eb0dafd94c084126093d869";
String auth_token = "f027b4fc27747d38fec643f742771db0";
String from = "14155238886";
String to = "6287820777640";
String body = "Paketmu sudah sampai.";

void setup () {
Serial.begin(115200);
pinMode(LED_BUILTIN, OUTPUT);
pinMode(us_echo, INPUT);
pinMode(us_trig, OUTPUT);
pinMode(relay, OUTPUT);
pinMode(stepper1, OUTPUT);
pinMode(stepper2, OUTPUT);
pinMode(stepper3, OUTPUT);
pinMode(stepper4, OUTPUT);
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

HTTPClient http;
int nilai = random(29,37);
String data = (String) nilai;
//String link = "http://jagorobot.pythonanywhere.com/kirimwa?nilai=" + state;
String link = "http://jagorobot.pythonanywhere.com/kirimwa?account_sid=" + account_sid + "&auth_token="+ auth_token +"&to_wa=" + to + "&from_wa="+ from +"&body_message=" + body;

http.begin(link);
int httpCode = http.GET();
Serial.println(httpCode);

if (httpCode > 0) { //Check for the returning code
    
    String payload = http.getString();
    Serial.println(link);
    Serial.println(httpCode);
    Serial.println(payload);
}
else {
    Serial.println("Error on HTTP request");
}
http.end();
}

void loop () {
Serial.println(step_num);
Serial.println("...");
digitalWrite(us_trig, LOW);
delayMicroseconds(2);
digitalWrite(us_trig, HIGH);
delayMicroseconds(10);
digitalWrite(us_trig, LOW);

waktu = pulseIn(us_echo, HIGH);  //dalam microsecond
distance = (waktu * 0.034) / 2;    //dalam cm


if (distance <= 5) {
    digitalWrite(relay, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);

    for(int x = 0; x < 4; x++){
      Serial.println(x);
      switch(x){
        case 0:
        digitalWrite(stepper1, HIGH);
        digitalWrite(stepper2, LOW);
        digitalWrite(stepper3, LOW);
        digitalWrite(stepper4, LOW);
        break;
        case 1:
        digitalWrite(stepper1, LOW);
        digitalWrite(stepper2, HIGH);
        digitalWrite(stepper3, LOW);
        digitalWrite(stepper4, LOW);
        break;
        case 2:
        digitalWrite(stepper1, LOW);
        digitalWrite(stepper2, LOW);
        digitalWrite(stepper3, HIGH);
        digitalWrite(stepper4, LOW);
        break;
        case 3:
        digitalWrite(stepper1, LOW);
        digitalWrite(stepper2, LOW);
        digitalWrite(stepper3, LOW);
        digitalWrite(stepper4, HIGH);
        break;
      }
      delay(2);
      }
    
    digitalWrite(relay, LOW);
    digitalWrite(LED_BUILTIN, LOW);
}else{
    digitalWrite(relay, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(5000);
} 
}

void OneStep(){
for(int x = 0; x < 4; x++){
Serial.println(x);
switch(x){
  case 0:
  digitalWrite(stepper1, HIGH);
  digitalWrite(stepper2, LOW);
  digitalWrite(stepper3, LOW);
  digitalWrite(stepper4, LOW);
  break;
  case 1:
  digitalWrite(stepper1, LOW);
  digitalWrite(stepper2, HIGH);
  digitalWrite(stepper3, LOW);
  digitalWrite(stepper4, LOW);
  break;
  case 2:
  digitalWrite(stepper1, LOW);
  digitalWrite(stepper2, LOW);
  digitalWrite(stepper3, HIGH);
  digitalWrite(stepper4, LOW);
  break;
  case 3:
  digitalWrite(stepper1, LOW);
  digitalWrite(stepper2, LOW);
  digitalWrite(stepper3, LOW);
  digitalWrite(stepper4, HIGH);
  break;
}
delay(3);
}}