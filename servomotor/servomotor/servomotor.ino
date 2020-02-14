int pin=8;
int pinPotenciometro = 0;
int angulo;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}


void loop() {
 angulo = analogRead(pinPotenciometro);   
 angulo = map(angulo, 0, 255, 0, 180);   
  
 moverServo(angulo);
 delay(5);
}
void moverServo( int angulo) {
  //float pausa;
  //pausa = angulo * 2500.0/180.0;
  analogWrite(pin,angulo);
  delay(5);
  //delayMicroseconds(pausa);
  analogWrite(pin,angulo);
  //delayMicroseconds(2500-pausa);
  delay(5);

}
