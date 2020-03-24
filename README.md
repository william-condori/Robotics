# Robotics

## Manejo de sensor Ultrasónico
Utilizaremos un sensor ultrasónico del tipo HC-SR04 conectado a un microcontrolador (MCU) para medir la distancia de objetos posicionados aleatoriamente a distancias de 20 cm a 1 m.

<img src="https://github.com/WilliamAbelCondori/Robotics/blob/master/img/ultrasonico.png" alt="Build Status">

### Materiales
|DETALLE|UNIDAD|CANTIDAD|
|---- | -----|:------:|
|Sensor ultrasónico HC-SR04 |unidad |1|
|Módulo Arduino UNO |unidad |1|
|Cables de conexión |unidad |4|
|Protoboard (Opcional)  |unidad |1|

### Procedimiento
1. Realizar la conexión del sensor ultrasónico con el módulo Arduino utilizando el protoboard. 
2. Conectar el sensor a la fuente de poder. 
3. Conectar el módulo Arduino a la computadora. 
4. Conectar las señales Trig y Echo a entradas del Analizador Lógico. 
5. Ejecutar el programa de Arduino 
6. Verificar las señales de Trig y Echo en el Analizador Lógico. 
7. Verificar los resultados entregados por el MCU (Arduino).

### [Ver Código](https://github.com/WilliamAbelCondori/Robotics/blob/master/ultrasonico/ultrasonico.ino)

-----------

## Manejo de Servomotores con Potenciometro
Controlaremos un servomotor analógico y  su posición mediante el uso de un potenciometro.

<img src="https://github.com/WilliamAbelCondori/Robotics/blob/master/img/potenciometro_servo.jpg" alt="Build Status">

### Materiales
|DETALLE|UNIDAD|CANTIDAD|
|---- | -----|:------:|
|Servomotor SG90 |unidad |1|
|Módulo Arduino UNO |unidad |1|
|Potenciometro  |unidad |1|
|Cables de conexión |unidad |4|
|Protoboard (Opcional)  |unidad |1|

### Procedimiento
1. Realizar la conexión del servomotor y el potenciómetro con el módulo Arduino utilizando el protoboard. 
2. Conectar el servomotor a la fuente de poder (NO a la salida +5v del MCU). 
3. Conectar las señales de control del servomotor a entradas del Analizador Lógico. 
4. Ejecutar el programa de Arduino, que debe realizar las siguientes tareas: 
	a. Configurar GIPO conectado al Servomotor como salida. 
	b. Configurar GPIO conectado al Potenciómetro como entrada. 
	c. Mostrar en pantalla la lectura ADC del potenciómetro. 
	d. Calcular el ancho de pulso requerido en función al valor del potenciómetro y mostrar valores en el monitor serie 
	e. Generar señal PWM mediante temporizadores (sin librería) para mover el Servomotor en función al valor leído en el Potenciómetro.  Luego generar la señal PWM utilizando librerías.  
5.  Verificar la señal PWM generada por el MCU. 
6. Verificar la posición del servomotor en función al ancho de pulso entregado por el MCU.

### [Ver Código](https://github.com/WilliamAbelCondori/Robotics/tree/master/servomotor)

----


## Manejo de motores paso a paso
Controlaremos un motor paso a paso mediante el uso de la placa arduino.

<img src="https://github.com/WilliamAbelCondori/Robotics/blob/master/img/motor_unipolar.jpg" alt="Build Status">

### Materiales
|DETALLE|UNIDAD|CANTIDAD|
|---- | -----|:------:|
|Motor Paso a Paso Unipolar |unidad |1|
|Módulo Arduino UNO |unidad |1|
|Módulo ULN2003A |unidad |1|
|Cables de conexión |unidad |4|
|Protoboard   |unidad |1|

### Procedimiento
1. Realizar la conexión del motor paso a paso con el módulo Arduino y el módulo de control ULN2003 o L298 utilizando el protoboard. 
2. Conectar el módulo de control ULN2003 o L298 a la fuente de poder. 
3. Conectar el módulo Arduino a la computadora. 
4. Ejecutar el programa de Arduino.
5. Verificar la posición del motor en función a la cantidad de pulsos enviados por el MCU.

### [Ver Código](https://github.com/WilliamAbelCondori/Robotics/blob/master/motor_unipolar/motor_unipolar.ino)

----



## Cañón Laser
Aplicaremos funciones matemáticas de trigonometría para calcular ángulos de posicionamiento.  Se requiere determinar la posición de un objeto mediante el uso de un sensor ultrasónico.  Una vez determinada la posición, se deberá girar un puntero laser para apuntar al objeto encontrado.

<img src="https://github.com/WilliamAbelCondori/Robotics/blob/master/img/buscador.png" alt="Build Status">

### Materiales
|DETALLE|UNIDAD|CANTIDAD|
|---- | -----|:------:|
|Servomotor  |unidad |2|
|Módulo Arduino UNO |unidad |1|
|Sensor ultrasónico|unidad |1|
|Cables de conexión |unidad |varios|
|Protoboard   |unidad |1|

### Procedimiento
1. Realizar la conexión de los servomotores con el módulo arduino.
2. Realizar la conexión del sensor ultrasónico con el módulo arduino.
3. Realizar las conexiones del puntero laser con el módulo arduino.
4. Realizar las conexiones de botón con el módulo arduino.
5. Esperar a que se presione el botón para iniciar la secuencia de búsquda. 
6. Programar el módulo arduino para mover el servomotor del sensor ultrasónico hasta encontrar un objeto.
7. Programar las funciones trigonométricas para calcular el ángulo del servomotor del puntero laser.
8. Mover el puntero laser y disparar.
### [Ver Código](https://github.com/WilliamAbelCondori/Robotics/tree/master/servo_con_ultrasonico)
