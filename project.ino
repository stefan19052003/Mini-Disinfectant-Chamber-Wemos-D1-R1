
int relay = D5;
int led = D13;
int us_echo = D2;
int us_trig = D3;

int waktu;
int distance;

int waktu;
int distance;

void setup () {
pinMode(LED_BUILTIN, OUTPUT);
pinMode(us_echo, INPUT);
pinMode(us_trig, OUTPUT);
pinMode(relay, OUTPUT);
pinMode(led, OUTPUT);
Serial.begin(115200);
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
    digitalWrite(relay, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(5);
    digitalWrite(relay, LOW);
    digitalWrite(LED_BUILTIN, LOW);
}else{
    digitalWrite(relay, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(5);
} 
}



