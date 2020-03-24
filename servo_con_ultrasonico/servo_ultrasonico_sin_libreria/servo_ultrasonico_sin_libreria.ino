/*
          B
          /\
         /  \
        /    \
     b /      \ a
      /        \
     /          \
  A /____________\ C
          c
*/
/*
  DECLARACION DE LOS PINES QUE SE USARAN EN EL ARDUINO
*/
int Echo = 4;
int Trig = 2;
int pinServoConUltrasonico = 7;
int pinServoConLazer = 8;

int a, b, c, A, B, C;
const float Pi = 3.141593;
char dato;

//Declaracion de los pines


void setup() {
  pinMode(pinServoConUltrasonico, OUTPUT);
  pinMode(pinServoConLazer, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
}

bool buscando = false;
void loop() {
  Serial.println("Laboratorio 4");
  Serial.println("ROBOTICA");
  Serial.println("Ingrese la letra a para comenzar el rastreo");
  /*
    moverServo(0, pinServoConLazer );
    moverServo(0, pinServoConUltrasonico);*/
  do {
    dato = Serial.read();

  } while (dato != 'a');

  comenzarBusqueda();






  /*
    moverServo(0, pinServoConLazer );
    moverServo(0, pinServoConUltrasonico);*/
  //Prueba: encontrar grado faltante
  //Serial.println((String)encontrandoA(5, 30, 10));

  //Prueba: encontrar distancia
  /*Serial.println("hola");
    Serial.println((String)encontrar_a());
    delay(30);*/

}

void comenzarBusqueda() {
  //
  buscando = true;
  while (buscando) {

    for (int grado = 1; grado <= 180; grado++) {
      long distancia = encontrar_a() ;
      if (distancia < 30) {
        moverServo(encontrandoA(distancia, 30, grado), pinServoConLazer );
        delay(30);
        buscando = false;
        break;
      }
      moverServo(grado, pinServoConUltrasonico );
      delay(30);
    }
    if (buscando) {

      for (int grado = 179; grado >= 1; grado--) {
        long distancia = encontrar_a() ;
        if (encontrar_a() < 30) {
          moverServo(encontrandoA(distancia, 30, grado), pinServoConLazer );
          delay(30);
          buscando = false;
          break;
        }
        moverServo(grado, pinServoConUltrasonico );
        delay(30);
      }
    }
  }
}

float encontrandoA(int a, int b, int C) {
  float c = sqrt((a * a) + (b * b) - (2 * a * b * cos(transformarGradosEnRadianes(C))) );
  return 180 - asin((a * sin(transformarGradosEnRadianes(C))) / c) * (180 / Pi); //Volvemos a transformarlo a grados
}

int contador = 0;
int contador2 = 0;
long encontrar_a() {
  //a es nuestra distancia

  /*

  */
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
  Serial.println((String)"Distancia: " + distancia + " cm.");
  //}
  delay(50);
  return distancia;






}

void moverServo (int angulo, int pinServo)
{
  float pausa;
  pausa = angulo * 2000.0 / 180.0 + 500 ;
  digitalWrite(pinServo, HIGH);
  delayMicroseconds(pausa);
  digitalWrite(pinServo, LOW);
  delayMicroseconds(2500 - pausa);
}
float transformarGradosEnRadianes(float grados ) {
  return grados * (Pi / 180);
}
