int Echo = 11;
int Trig = 12;
char dato;

int contador = 0;
int contador2 = 0;
int valor_acumulado = 0;
int valor_real = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}

void loop() {
  Serial.println("Laboratorio 1");
  Serial.println("ROBOTICA");
  Serial.println("-------------------------------");
  Serial.println("Enviando Trigger....");
  Serial.println("Presione la tecla 'a' para comenzar ");

  do {
    dato = Serial.read();

  } while (dato != 'a');

  
    long duracion;
    long distancia;

    digitalWrite(Trig, LOW);
    delayMicroseconds(4);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);

    //reemplazando pulseIn
    while (!digitalRead(Echo)) {}
    contador = micros();
    while (digitalRead(Echo)) {}
    contador2 = micros();
    duracion = contador2 - contador;

    duracion = duracion / 2;
    distancia = duracion / 29; //con esto tenemos nuestra distancia en cm

    Serial.println((String)"Pulso Echo recibido. ");
    Serial.println((String)"Tiempo = " + duracion + " us.");
    Serial.println((String)"Distancia: " + distancia + " cm.");
    delay(50);


}
