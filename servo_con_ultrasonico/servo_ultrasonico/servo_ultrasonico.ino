/*
                               B
                               /\
                              /  \
                             /    \
                          c /      \ a = distancia_objeto()
                           /        \
                          /          \
  encontrandoAlfa() =  A /____________\ C
                             b = DISTANCIA_SERVOS
*/
/*
   Librerias
*/
#include <Servo.h>
Servo servo_laser;
Servo servo_ultrasonico;
/*
  DECLARACION DE LOS PINES QUE SE USARAN EN EL ARDUINO
*/
int Echo = 6;
int Trig = 9;
int pinServo_Ultrasonico = 3;
int pinServo_Lazer = 5;
int pinLaser = 13;
/*
   Variables Globales del sistema
*/
const float Pi = 3.141593;
const long DISTANCIA_MAX_ULTRASONICO = 30;
const long DISTANCIA_SERVOS = 30;
char dato_teclado;
bool buscando = false;

void setup() {
  Serial.begin(9600);

  servo_laser.attach(pinServo_Lazer);
  servo_ultrasonico.attach(pinServo_Ultrasonico);

  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(pinLaser, OUTPUT);

}

void loop() {
  Serial.println("Laboratorio 4");
  Serial.println("ROBOTICA");
  Serial.println("Ingrese la letra a para comenzar el rastreo");

  do {
    dato_teclado = Serial.read();

  } while (dato_teclado != 'a');

  comenzarBusqueda();
}

void encenderLaser() {
  digitalWrite(pinLaser, HIGH);
}
void apagarLaser() {
  digitalWrite(pinLaser, LOW);
}


void comenzarBusqueda() {
  buscando = true;
  apagarLaser(); //Apagamos nuestro laser en caso de que este encendido
  moverServo(0, servo_laser ); //Colocamos el laser en la posicion inicial
  while (buscando) {

    for (int angulo_beta = 0; angulo_beta <= 180; angulo_beta++) {
      if (!objetoEncontrado(angulo_beta)) {
        moverServo(angulo_beta, servo_ultrasonico );
      } else {
        buscando = false;
        break;
      }

    }
    if (buscando) {
      for (int angulo_beta = 179; angulo_beta >= 1; angulo_beta--) {
        if (!objetoEncontrado(angulo_beta)) {
          moverServo(angulo_beta, servo_ultrasonico );
        } else {
          buscando = false;
          break;
        }
      }
    }
  }
}
bool objetoEncontrado(int angulo_beta) {
  long distancia = distancia_objeto() ;
  
  if (distancia >= 0 && distancia <= DISTANCIA_MAX_ULTRASONICO) {
    moverServo(encontrandoAlfa(distancia, DISTANCIA_SERVOS , angulo_beta), servo_laser );
    encenderLaser(); //Encendemos el laser
    Serial.println((String)"Angulo Beta " + angulo_beta + "°");
    Serial.println((String)"Objeto encontrado a los " + distancia + " cm.");
    return true;
  }
  return false;
}

float encontrandoAlfa(int a, int b, int C) {
  float c = sqrt((a * a) + (b * b) - (2 * a * b * cos(GradosARadianes(C))) );
  float alfa = asin((a * sin(GradosARadianes(C))) / c) * (180 / Pi); //Volvemos a transformarlo a grados
  Serial.println((String)"Angulo Alfa " + alfa + "°");
  return 180 - alfa;
}

long distancia_objeto() {
  long tiempo; //timepo que demora en llegar el eco
  long distancia; //distancia en centimetros

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);        //Enviamos un pulso de 10us
  digitalWrite(Trig, LOW);

  tiempo = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  distancia = tiempo / 59;      //escalamos el tiempo a una distancia en cm
  delay(50);
  return distancia;
}

void moverServo(int angulo, Servo servo)
{
  servo.write(angulo);
  delay(30);
}
float GradosARadianes(float grados ) {
  return grados * (Pi / 180);
}
