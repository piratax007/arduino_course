# Lección 4 - sensores

**2 Sesiones: 1 hora / sesión**

Los sensores (digitales y análogos) en la electrónica digital son un recurso muy utilizado debido a su versatilidad y funcionalidad para desarrollar aplicaciones interactivas (IoT) con el contexto.

## Montaje 1 - Sensor Infrarrojo Pasivo (PIR)

### Objetivo

El sensor HC_SR501 Sensor Infrarojo Pasivo (por sus siglas en inglés) es utilizado ampliamente en sistemas de seguridad o para el encendido automático de luces. Algunas ideas en las que puedes emplear un sensor PIR son:
- Para encender las luces de las escaleras del edificio donde vives.
- Para enviar un mensaje a tu celular alertándote de que alguien a abierto tu closet en tu ausencia.
- Para abrir la puerta del dispensario de comida cuando tu mascota se acerque a su plato.

En este montaje utilizarás un sensor PIR para encender un LED cuando algo se mueva cerca del montaje.

### ¿Cómo funciona el sensor PIR?

<img src="./images/HC_SR501_PIR.png">

Todos los cuerpos con una temperatura superior al cero absoluto emiten energía calórica en forma de radiación infraroja. A mayor temperatura del cuerpo más será la cantidad de radiación que emita. El sensor PIR esta especialmente diseñado para detectar tales radiaciones.

El sensor HC_SR501 PIR básicamente esta conformado por un sensor piroeléctrico y una lente de Fresnel que se encarga de concentrar los rayos infrarojos en el sensor piroeléctrico.

El sensor piroeléctrico esta conformafo por dos *slots* que producen radiación infraroja positiva y negativa respectivamente de tal forma que se anulan mutuamente, esto es así debido a que se busca detectar las emisiones de radiación infraroja no la radiación presente en el ambiente. Cuando uno de los *slots* detecta un incremento o decremento en la radiación infraroja respecto del otro *slot* el sensor habrá detectado movimiento.

<img src="./images/PIR-Sensor-Working-Animation-Differential-Output.gif">

### Sensor HC_SR501 PIR

El sensor HC_SR501 PIR tiene tres pines de conección GND, Salida Digital y VCC. El voltage de operación de este sensor esta entre 4.5 y 12 volts con lo que a 5 volts funciona adecuadamente.

<img src="./images/HC_SR501_PIR_Pinout.png">

El sensor HC_SR501 PIR cuenta con dos potenciometros que ajustan el grado de **Sensivilidad** o la distania a la que el movimiento puede ser detectado en un rango de 3 a 7 metros aproximadamente. La forma de la habitación en la que se encuentre el sensor puede afectar su desempeño; el segundo potenciometro ajusta el **Tiempo** que permanecerá el estado HIGH en la salida digital, este tiempo se ajusta en un rango de 3 a 500 segundos.

### Controla un LED con el sensor HC_SR501 PIR

#### Materiales

- 1 Sensor HC_SR501 PIR
- 1 Resistencia de 220 Ohm
- 1 LED
- Jumpers

En este montaje usarás un LED para indicar visualmente cuándo el sensor HC SR501 PIR ha detectado movimiento. Conecta los componentes como se muestra en la figura.

<img src="./images/HC_SR501_PIR_montaje.png">

El OUT del sensor esta conectado a un pin digital de Arduino y en este montaje el ánodo del diodo no esta conectado directamente a los 5 volt sino que recibirá el voltaje a través de un pin digital de Arduino que se configurará como salida digital.

#### El código

```
const int sensorPin = 12;
const int ledPin = 13;

void setup(){
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  if (digitalRead(sensorPin) == HIGH){
    digitalWrite(ledPin, HIGH);
  }else {
    digitalWrite(ledPin, LOW);
  }
}
```

El sensor HC_SR501 PIR requiere de un tiempo de *"aclimatación"* para leer correctamente la energí infraroja de la habitación. Después de encendido el sensor tomará entre 30 y 60 segundos en adaptarse correctamente al ambiente.

Adicionalmente este sensor tiene un tiempo de **reset** después de hacer una lectura, entre 5 y 6 segundos después de detectar movimiento el sensor no hará ningúna nueva detección.

Estos tiempos deben tomarse en cuenta al momento de utilizar este sensor en nuestros montajes.

## Montaje 2 - Sensor de parqueo



## Referencias

1. [How HC-SR501 PIR Sensor Works & Interface It With Arduino][1]

[1]:https://lastminuteengineers.com/pir-sensor-arduino-tutorial/
