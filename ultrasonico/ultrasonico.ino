int Echo=4;
int Trig=2;
char dato;

int contador=0;
int contador2=0;
int valor_acumulado=0;
int valor_real =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);
  pinMode(Echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Laboratorio 1");
  Serial.println("ROBOTICA");
  Serial.println("-------------------------------");
  Serial.println("Enviando Trigger....");
  Serial.println("Presione la tecla 'a' ");
  

  do{
      dato = Serial.read();
      
  }while(dato != 'a');
  //valor_acumulado=micros();
  
  if(dato == 'a'){
   
  long duracion;
  long distancia;

  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  //reemplazando pulseIn
  while(!digitalRead(Echo)){}
  contador = micros();
  while(digitalRead(Echo)){}
  contador2=micros();
  duracion=contador2-contador;

  
  

  //duracion = pulseIn(Echo, HIGH);
  duracion = duracion/2;
  distancia= duracion/29;  //con esto tenemos nuestra distancia en cm

  
  
  Serial.println((String)"Pulso Echo recibido. ");
  Serial.println((String)"Tiempo = " + duracion + " us.");
  Serial.println((String)"Distancia: "+ distancia + " cm.");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  
 
  }
  delay(50);
  

}
