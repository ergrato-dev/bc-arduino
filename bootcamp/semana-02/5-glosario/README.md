# 📖 Glosario - Semana 02

> **Entradas y Salidas Digitales**  
> Términos y conceptos clave

---

## A

### ADC (Analog-to-Digital Converter)

Convertidor analógico-digital. Circuito que convierte señales analógicas (0-5V) en valores digitales (0-1023). Arduino Uno tiene un ADC de 10 bits.

### Ánodo

Terminal positivo de un LED. Es la pata más larga. Se conecta al voltaje positivo (a través de una resistencia).

### Array

Estructura de datos que almacena múltiples valores del mismo tipo. En Arduino se usa para manejar múltiples pines.

```cpp
int ledPins[] = {13, 12, 11, 10};
```

---

## B

### Bouncing (Rebote)

Fenómeno mecánico donde los contactos de un botón producen múltiples conexiones/desconexiones al ser presionado. Dura típicamente 10-50ms.

### Breadboard (Protoboard)

Placa de pruebas para montar circuitos sin soldadura. Las filas están conectadas internamente.

---

## C

### Cátodo

Terminal negativo de un LED. Es la pata más corta. Se conecta a GND.

### Constante

Valor que no cambia durante la ejecución del programa.

```cpp
const int LED_PIN = 13;
```

---

## D

### Debounce

Técnica para eliminar lecturas falsas causadas por el rebote mecánico de botones. Se implementa por software esperando estabilidad.

### Delay

Función que pausa la ejecución del programa. `delay(1000)` pausa 1 segundo.

```cpp
delay(milliseconds);
```

### Digital

Señal que solo tiene dos estados posibles: HIGH (1) o LOW (0).

### digitalRead()

Función que lee el estado de un pin digital. Retorna HIGH o LOW.

```cpp
int estado = digitalRead(pin);
```

### digitalWrite()

Función que escribe un estado (HIGH o LOW) en un pin digital.

```cpp
digitalWrite(pin, HIGH);
```

---

## E

### Enum (Enumeración)

Tipo de dato definido por el usuario que consiste en constantes nombradas.

```cpp
enum Estado { APAGADO, ENCENDIDO };
```

---

## F

### Flanco (Edge)

Transición de una señal digital de un estado a otro.

- **Flanco de subida**: LOW → HIGH
- **Flanco de bajada**: HIGH → LOW

### Floating Pin (Pin Flotante)

Pin de entrada sin conexión definida. Lee valores aleatorios debido al ruido eléctrico.

### FSM (Finite State Machine)

Máquina de Estados Finitos. Modelo de programación donde el sistema tiene estados definidos y transiciones entre ellos.

---

## G

### GND (Ground)

Referencia de voltaje 0V. Punto común para todas las mediciones de voltaje.

### GPIO (General Purpose Input/Output)

Pines de propósito general que pueden configurarse como entrada o salida.

---

## H

### HIGH

Estado lógico alto. Equivale a 5V en Arduino Uno (o 3.3V en algunas placas).

---

## I

### INPUT

Modo de pin que permite leer voltajes externos.

```cpp
pinMode(pin, INPUT);
```

### INPUT_PULLUP

Modo de pin que activa una resistencia interna de pull-up (~20-50kΩ a 5V).

```cpp
pinMode(pin, INPUT_PULLUP);
```

---

## L

### LED (Light Emitting Diode)

Diodo emisor de luz. Componente que emite luz cuando circula corriente en la dirección correcta.

### Loop

Función principal de Arduino que se ejecuta repetidamente después de `setup()`.

### LOW

Estado lógico bajo. Equivale a 0V.

---

## M

### millis()

Función que retorna los milisegundos transcurridos desde que Arduino inició.

```cpp
unsigned long tiempo = millis();
```

---

## N

### Normalmente Abierto (NO)

Tipo de interruptor/botón que no conduce corriente en reposo. Al presionarlo, se cierra el circuito.

### Normalmente Cerrado (NC)

Tipo de interruptor/botón que conduce corriente en reposo. Al presionarlo, se abre el circuito.

---

## O

### OUTPUT

Modo de pin que permite enviar voltaje (HIGH o LOW).

```cpp
pinMode(pin, OUTPUT);
```

---

## P

### Pin

Conexión física del microcontrolador. Puede ser digital (0-13), analógico (A0-A5), de alimentación (5V, 3.3V, GND), etc.

### pinMode()

Función que configura un pin como entrada o salida.

```cpp
pinMode(pin, modo); // OUTPUT, INPUT, INPUT_PULLUP
```

### Pull-down

Resistencia conectada entre un pin y GND. Mantiene el pin en LOW cuando no hay otra señal.

### Pull-up

Resistencia conectada entre un pin y VCC. Mantiene el pin en HIGH cuando no hay otra señal.

### PWM (Pulse Width Modulation)

Modulación por ancho de pulso. Técnica para simular salidas analógicas variando el ciclo de trabajo de una señal digital.

---

## R

### Resistencia

Componente que limita el flujo de corriente. Se mide en ohmios (Ω).

---

## S

### Serial

Protocolo de comunicación para enviar datos entre Arduino y la computadora.

```cpp
Serial.begin(9600);
Serial.println("Hola");
```

### Setup

Función de Arduino que se ejecuta una vez al inicio. Se usa para configuración.

### Switch-case

Estructura de control que ejecuta código según el valor de una variable.

```cpp
switch(modo) {
    case 0: /* código */ break;
    case 1: /* código */ break;
}
```

---

## T

### Toggle

Acción de alternar entre dos estados. Si está ON, pasa a OFF; si está OFF, pasa a ON.

```cpp
estado = !estado;  // Toggle
```

---

## U

### unsigned long

Tipo de dato para números enteros positivos grandes. Necesario para `millis()`.

```cpp
unsigned long tiempo = millis();
```

---

## V

### Variable

Espacio en memoria con un nombre que almacena un valor que puede cambiar.

```cpp
int contador = 0;
```

### VCC

Voltaje de alimentación positivo. En Arduino Uno es 5V.

### Voltaje

Diferencia de potencial eléctrico. Se mide en voltios (V).

---

## Símbolos Comunes

| Símbolo | Significado           |
| ------- | --------------------- |
| `==`    | Igual a (comparación) |
| `!=`    | Diferente de          |
| `!`     | Negación lógica       |
| `&&`    | AND lógico            |
| `\|\|`  | OR lógico             |
| `++`    | Incremento            |
| `--`    | Decremento            |
| `+=`    | Suma y asigna         |
| `-=`    | Resta y asigna        |

---

## Unidades Comunes

| Unidad       | Símbolo | Uso                  |
| ------------ | ------- | -------------------- |
| Voltios      | V       | Voltaje              |
| Amperios     | A       | Corriente            |
| Miliamperios | mA      | Corriente (1/1000 A) |
| Ohmios       | Ω       | Resistencia          |
| Kiloohmios   | kΩ      | Resistencia (1000 Ω) |
| Hertz        | Hz      | Frecuencia           |
| Milisegundos | ms      | Tiempo (1/1000 s)    |

---

## ➡️ Volver al Inicio

[README Principal →](../README.md)
