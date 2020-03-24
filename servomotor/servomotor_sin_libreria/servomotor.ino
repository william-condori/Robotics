int pinServo=8;
int pinPotenciometro = A0; // Pin usado para conectar el potenciómeto

int angulo;    // Esta variable definirá la posición del 


void setup() {
  Serial.begin(9600);
  pinMode(pinServo, OUTPUT);
}


void loop() {
 angulo = analogRead(pinPotenciometro);   // leemos el valor del potenciometro (valor entre 0 y 1023)
 angulo = map(angulo, 0, 1023, 0, 180);   // valor proporcional a la escala del servomotor (valor entre 0 y 180)
 Serial.println(angulo);
 moverServo(angulo);  
 delay(10);




}
void moverServo (int angulo)
{
   float pausa;
   pausa = angulo*2000.0/180.0 +500 ;
   digitalWrite(pinServo, HIGH);
   delayMicroseconds(pausa);
   digitalWrite(pinServo, LOW);
   delayMicroseconds(2500-pausa);
}


