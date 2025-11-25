# 📖 Glosario - Semana 01

> **Términos técnicos y conceptos clave de la Semana 01: Introducción a Arduino y Electrónica Básica**

---

## 📋 Índice Alfabético

| A-D                               | E-L                                    | M-R                                   | S-Z                               |
| --------------------------------- | -------------------------------------- | ------------------------------------- | --------------------------------- |
| [ADC](#adc)                       | [Electrón](#electrón)                  | [Microcontrolador](#microcontrolador) | [Serial Monitor](#serial-monitor) |
| [Amperio](#amperio-a)             | [Forward Voltage](#forward-voltage-vf) | [Ohmio](#ohmio-ω)                     | [Setup](#setup)                   |
| [Ánodo](#ánodo)                   | [GND](#gnd-ground)                     | [OUTPUT](#output)                     | [Sketch](#sketch)                 |
| [Arduino IDE](#arduino-ide)       | [GPIO](#gpio)                          | [Pin](#pin)                           | [Tinkercad](#tinkercad)           |
| [ATmega328P](#atmega328p)         | [HIGH](#high)                          | [pinMode()](#pinmode)                 | [USB](#usb)                       |
| [Breadboard](#breadboard)         | [INPUT](#input)                        | [Polaridad](#polaridad)               | [Voltio](#voltio-v)               |
| [Bootloader](#bootloader)         | [LED](#led)                            | [Protoboard](#protoboard)             | [VCC](#vcc)                       |
| [Circuito](#circuito)             | [Ley de Ohm](#ley-de-ohm)              | [PWM](#pwm)                           | [Watt](#watt-w)                   |
| [Compilar](#compilar)             | [Loop](#loop)                          | [Resistencia](#resistencia)           |                                   |
| [Corriente](#corriente-eléctrica) | [LOW](#low)                            | [Resistor](#resistor)                 |                                   |
| [Cátodo](#cátodo)                 |                                        |                                       |                                   |
| [delay()](#delay)                 |                                        |                                       |                                   |
| [Digital](#digital)               |                                        |                                       |                                   |
| [digitalWrite()](#digitalwrite)   |                                        |                                       |                                   |

---

## 📚 Definiciones

### A

#### ADC

**Analog-to-Digital Converter** (Conversor Analógico-Digital)

Circuito que convierte señales analógicas continuas en valores digitales discretos. El Arduino Uno tiene un ADC de 10 bits, lo que significa que puede representar valores de 0 a 1023.

```
Señal Analógica (0-5V) → ADC → Valor Digital (0-1023)
```

**Uso en Arduino:** `analogRead(A0)` devuelve un valor entre 0-1023.

---

#### Amperio (A)

**Unidad de corriente eléctrica**

Mide la cantidad de electrones que fluyen por un conductor por unidad de tiempo. Un amperio equivale a un coulomb de carga eléctrica por segundo.

| Prefijo      | Símbolo | Valor      |
| ------------ | ------- | ---------- |
| Miliamperio  | mA      | 0.001 A    |
| Microamperio | µA      | 0.000001 A |

**En Arduino:** Los pines digitales pueden suministrar hasta 20mA (máximo 40mA).

---

#### Ánodo

**Terminal positivo de un LED o diodo**

Es la pata más larga del LED y debe conectarse al lado positivo (HIGH) del circuito. La corriente fluye del ánodo al cátodo.

```
     Ánodo (+)
        │
        ▼
       ╱█╲    ← LED
      ╱███╲
        │
     Cátodo (-)
```

**Identificación:** Pata más larga, lado sin borde plano.

---

#### Arduino IDE

**Integrated Development Environment** (Entorno de Desarrollo Integrado)

Software oficial para programar placas Arduino. Incluye editor de código, compilador, y herramientas para cargar programas a la placa.

**Versión actual:** Arduino IDE 2.x

**Componentes principales:**

- Editor de código con resaltado de sintaxis
- Compilador avr-gcc
- Cargador de sketches
- Serial Monitor
- Gestor de bibliotecas

---

#### ATmega328P

**Microcontrolador principal del Arduino Uno**

Chip fabricado por Microchip (antes Atmel) que es el "cerebro" del Arduino Uno R3.

| Especificación | Valor     |
| -------------- | --------- |
| Arquitectura   | AVR 8-bit |
| Velocidad      | 16 MHz    |
| Flash          | 32 KB     |
| SRAM           | 2 KB      |
| EEPROM         | 1 KB      |
| Pines I/O      | 23        |

---

### B

#### Bootloader

**Programa precargado en el microcontrolador**

Software pequeño que permite cargar nuevos programas a través del puerto USB sin necesidad de un programador externo. Ocupa aproximadamente 0.5KB de memoria Flash.

**Función:** Espera unos segundos al encender para recibir un nuevo programa antes de ejecutar el sketch almacenado.

---

#### Breadboard

**Ver [Protoboard](#protoboard)**

---

### C

#### Cátodo

**Terminal negativo de un LED o diodo**

Es la pata más corta del LED y debe conectarse al lado negativo (GND) del circuito.

**Identificación:**

- Pata más corta
- Lado con borde plano en la cápsula
- Marca de identificación en el componente

---

#### Circuito

**Camino cerrado por donde fluye la corriente eléctrica**

Un circuito completo requiere:

1. **Fuente de energía** (alimentación)
2. **Conductor** (cables)
3. **Carga** (LED, motor, etc.)
4. **Retorno a la fuente** (GND)

```
    +5V ──────┬──────────┐
              │          │
              R          │
              │          │
              ├────LED───┘
              │
    GND ──────┘
```

---

#### Compilar

**Proceso de traducir código a lenguaje máquina**

El compilador convierte el código escrito en C/C++ (lenguaje Arduino) a instrucciones binarias que el microcontrolador puede ejecutar.

**Proceso:**

```
Código (.ino) → Preprocesador → Compilador → Enlazador → Binario (.hex)
```

**En Arduino IDE:** Botón ✓ (Verificar) o Ctrl+R

---

#### Corriente Eléctrica

**Flujo de electrones a través de un conductor**

Se mide en [Amperios](#amperio-a). La corriente fluye del positivo al negativo (convención) o del negativo al positivo (flujo real de electrones).

**Tipos:**

- **DC (Corriente Continua):** Flujo constante en una dirección. Usado en Arduino.
- **AC (Corriente Alterna):** Cambia de dirección periódicamente. Usado en la red eléctrica.

---

### D

#### delay()

**Función que pausa la ejecución del programa**

```cpp
delay(1000);  // Pausa de 1000 milisegundos (1 segundo)
```

| Valor | Tiempo       |
| ----- | ------------ |
| 100   | 0.1 segundos |
| 500   | 0.5 segundos |
| 1000  | 1 segundo    |
| 60000 | 1 minuto     |

**⚠️ Advertencia:** Durante el delay, el Arduino no puede hacer nada más. Para multitarea, usar `millis()`.

---

#### Digital

**Señal que solo tiene dos estados posibles**

En Arduino, digital significa HIGH (5V) o LOW (0V). No hay valores intermedios.

```
HIGH (1) ─────┐     ┌─────┐     ┌─────
              │     │     │     │
              │     │     │     │
LOW  (0) ─────┴─────┘     └─────┘
```

**Contraste con Analógico:** Las señales analógicas pueden tener cualquier valor entre 0V y 5V.

---

#### digitalWrite()

**Función para establecer el estado de un pin digital**

```cpp
digitalWrite(pin, valor);
```

| Parámetro | Descripción         | Valores    |
| --------- | ------------------- | ---------- |
| `pin`     | Número del pin      | 0-13       |
| `valor`   | Estado a establecer | HIGH o LOW |

**Ejemplo:**

```cpp
digitalWrite(13, HIGH);  // Enciende LED en pin 13
digitalWrite(13, LOW);   // Apaga LED en pin 13
```

---

### E

#### Electrón

**Partícula subatómica con carga negativa**

Los electrones son los portadores de la corriente eléctrica. Cuando se mueven a través de un conductor, generan corriente.

**Dato:** Un amperio equivale a aproximadamente 6.24 × 10¹⁸ electrones por segundo.

---

### F

#### Forward Voltage (Vf)

**Voltaje de operación de un LED**

Es el voltaje que "cae" a través del LED cuando está encendido. Varía según el color del LED.

| Color    | Vf típico |
| -------- | --------- |
| Rojo     | 1.8-2.2V  |
| Amarillo | 2.0-2.2V  |
| Verde    | 2.0-3.2V  |
| Azul     | 3.0-3.5V  |
| Blanco   | 3.0-3.5V  |

**Uso:** Necesario para calcular la resistencia limitadora.

---

### G

#### GND (Ground)

**Tierra o referencia de 0 voltios**

Punto de referencia común para todas las mediciones de voltaje en el circuito. Todo circuito debe tener conexión a GND.

**En Arduino Uno:**

- 3 pines GND disponibles
- Conecta el negativo de todos los componentes

---

#### GPIO

**General Purpose Input/Output** (Entrada/Salida de Propósito General)

Pines del microcontrolador que pueden configurarse como entrada o salida digital.

**Arduino Uno:** 14 pines GPIO digitales (0-13) + 6 pines analógicos que también pueden usarse como GPIO.

---

### H

#### HIGH

**Estado lógico alto (1)**

En Arduino Uno, HIGH equivale a 5V. Representa el estado "encendido" o "verdadero".

```cpp
digitalWrite(13, HIGH);  // Pin 13 a 5V
```

---

### I

#### INPUT

**Modo de configuración de pin como entrada**

Configura el pin para leer señales externas (botones, sensores).

```cpp
pinMode(2, INPUT);       // Pin 2 como entrada
pinMode(3, INPUT_PULLUP); // Pin 3 con resistencia interna
```

---

### L

#### LED

**Light Emitting Diode** (Diodo Emisor de Luz)

Componente semiconductor que emite luz cuando la corriente fluye a través de él en la dirección correcta.

**Características:**

- Requiere polaridad correcta (ánodo a +, cátodo a -)
- Necesita resistencia limitadora
- Corriente típica: 10-20mA
- Eficiente energéticamente

---

#### Ley de Ohm

**Relación fundamental entre voltaje, corriente y resistencia**

```
V = I × R
```

| Variable | Unidad   | Descripción             |
| -------- | -------- | ----------------------- |
| V        | Voltios  | Diferencia de potencial |
| I        | Amperios | Corriente eléctrica     |
| R        | Ohmios   | Resistencia             |

**Triángulo de Ohm:**

```
      ┌───┐
      │ V │
      ├───┤
      │I×R│
      └───┘

V = I × R
I = V / R
R = V / I
```

**Ejemplo práctico:**
Para un LED rojo (Vf=2V) con 20mA en Arduino (5V):

```
R = (5V - 2V) / 0.020A = 150Ω
```

---

#### Loop

**Función principal que se ejecuta infinitamente**

```cpp
void loop() {
    // Código que se repite continuamente
}
```

**Características:**

- Se ejecuta después de `setup()`
- Se repite mientras Arduino tenga energía
- Contiene la lógica principal del programa

---

#### LOW

**Estado lógico bajo (0)**

En Arduino Uno, LOW equivale a 0V. Representa el estado "apagado" o "falso".

```cpp
digitalWrite(13, LOW);  // Pin 13 a 0V
```

---

### M

#### Microcontrolador

**Computadora pequeña en un solo chip**

Integra procesador, memoria y periféricos de entrada/salida. Es el "cerebro" de Arduino.

**Componentes internos:**

- CPU (Unidad Central de Procesamiento)
- RAM (memoria volátil)
- Flash (memoria de programa)
- Periféricos (timers, ADC, UART, etc.)

---

### O

#### Ohmio (Ω)

**Unidad de resistencia eléctrica**

Mide la oposición al flujo de corriente. Un ohmio es la resistencia que permite pasar 1 amperio cuando se aplica 1 voltio.

| Prefijo   | Símbolo | Valor       |
| --------- | ------- | ----------- |
| Kiloohmio | kΩ      | 1,000 Ω     |
| Megaohmio | MΩ      | 1,000,000 Ω |

---

#### OUTPUT

**Modo de configuración de pin como salida**

Configura el pin para enviar señales (encender LEDs, activar motores).

```cpp
pinMode(13, OUTPUT);  // Pin 13 como salida
```

---

### P

#### Pin

**Terminal de conexión en la placa Arduino**

Puntos de conexión para componentes externos. Cada pin tiene un número y función específica.

**Tipos en Arduino Uno:**

- **Digitales (0-13):** Entrada/salida digital
- **Analógicos (A0-A5):** Entrada analógica
- **PWM (~):** Pines 3, 5, 6, 9, 10, 11
- **Alimentación:** 5V, 3.3V, GND, Vin

---

#### pinMode()

**Función para configurar el modo de un pin**

```cpp
pinMode(pin, modo);
```

| Modo           | Descripción                          |
| -------------- | ------------------------------------ |
| `INPUT`        | Entrada sin resistencia              |
| `OUTPUT`       | Salida                               |
| `INPUT_PULLUP` | Entrada con resistencia interna a 5V |

**Ejemplo:**

```cpp
pinMode(13, OUTPUT);     // LED
pinMode(2, INPUT_PULLUP); // Botón
```

---

#### Polaridad

**Dirección correcta de conexión de un componente**

Algunos componentes (LEDs, diodos, condensadores electrolíticos) deben conectarse con la orientación correcta.

**Componentes con polaridad:**

- ✅ LEDs (ánodo/cátodo)
- ✅ Diodos
- ✅ Condensadores electrolíticos
- ❌ Resistencias (sin polaridad)
- ❌ Condensadores cerámicos (sin polaridad)

---

#### Protoboard

**Placa de pruebas sin soldadura** (también: Breadboard)

Placa con orificios conectados internamente que permite crear circuitos temporales sin soldar.

```
Conexiones internas típicas:
    a b c d e   f g h i j
    ┌─────────┬─────────┐
  1 │● ● ● ● ●│● ● ● ● ●│ 1
  2 │● ● ● ● ●│● ● ● ● ●│ 2
  3 │● ● ● ● ●│● ● ● ● ●│ 3
    └─────────┴─────────┘
    ─────────   ─────────
     Filas conectadas horizontalmente

    ═══════════════════════
    Buses de alimentación (verticales)
```

---

#### PWM

**Pulse Width Modulation** (Modulación por Ancho de Pulso)

Técnica para simular salida analógica usando pulsos digitales de ancho variable.

```
Duty Cycle 25%:  ─┐   ┌─┐   ┌─┐   ┌─
                  └───┘ └───┘ └───┘

Duty Cycle 50%:  ──┐  ┌──┐  ┌──┐  ┌──
                   └──┘  └──┘  └──┘

Duty Cycle 75%:  ───┐ ┌───┐ ┌───┐ ┌───
                    └─┘   └─┘   └─┘
```

**En Arduino:** `analogWrite(pin, valor)` donde valor es 0-255.

**Pines PWM en Uno:** 3, 5, 6, 9, 10, 11 (marcados con ~)

---

### R

#### Resistencia

**Oposición al flujo de corriente eléctrica**

Propiedad de los materiales de oponerse al paso de electrones. Se mide en [Ohmios](#ohmio-ω).

**Factores que afectan:**

- Material del conductor
- Longitud
- Sección transversal
- Temperatura

---

#### Resistor

**Componente que proporciona resistencia**

Componente pasivo que limita el flujo de corriente. Usado para proteger LEDs y otros componentes.

**Código de colores (4 bandas):**

```
┌─────────────────────────┐
│  ██  ██  ██  █          │
│ (1) (2) (×) (%)         │
└─────────────────────────┘
  1: Primera cifra
  2: Segunda cifra
  ×: Multiplicador
  %: Tolerancia
```

**Ejemplo 220Ω:** Rojo(2) - Rojo(2) - Marrón(×10) = 22 × 10 = 220Ω

---

### S

#### Serial Monitor

**Herramienta de comunicación y debugging**

Ventana en Arduino IDE que permite enviar y recibir datos con la placa a través del puerto USB.

**Funciones comunes:**

```cpp
Serial.begin(9600);      // Iniciar a 9600 baudios
Serial.println("Hola");  // Enviar texto con salto de línea
Serial.print(valor);     // Enviar sin salto de línea
```

**Atajos:** Ctrl+Shift+M para abrir Serial Monitor

---

#### Setup

**Función de inicialización que se ejecuta una vez**

```cpp
void setup() {
    // Código que se ejecuta solo al inicio
    pinMode(13, OUTPUT);
    Serial.begin(9600);
}
```

**Usos típicos:**

- Configurar pines (pinMode)
- Inicializar comunicación serial
- Configurar bibliotecas
- Establecer valores iniciales

---

#### Sketch

**Programa de Arduino**

Nombre que recibe un programa escrito para Arduino. Se guarda con extensión `.ino`.

**Estructura básica:**

```cpp
// Declaraciones globales

void setup() {
    // Inicialización
}

void loop() {
    // Código principal
}
```

---

### T

#### Tinkercad

**Simulador online de circuitos Arduino**

Plataforma gratuita de Autodesk para diseñar y simular circuitos electrónicos con Arduino virtual.

**Características:**

- Arduino Uno R3 virtual
- Componentes básicos incluidos
- Programación en bloques o código
- Simulación en tiempo real
- Compartir proyectos

**URL:** [tinkercad.com/circuits](https://www.tinkercad.com/circuits)

---

### U

#### USB

**Universal Serial Bus**

Puerto de conexión estándar usado para:

1. Alimentar Arduino (5V)
2. Cargar programas
3. Comunicación serial

**En Arduino Uno:** USB tipo B

---

### V

#### VCC

**Voltage at Common Collector** (Voltaje de alimentación)

Nombre común para el voltaje positivo de alimentación. En Arduino Uno, VCC = 5V.

**Sinónimos:** +5V, V+, alimentación positiva

---

#### Voltio (V)

**Unidad de potencial eléctrico (voltaje)**

Mide la "presión" que empuja a los electrones a través del circuito. Es la diferencia de potencial entre dos puntos.

| Voltajes comunes | Fuente           |
| ---------------- | ---------------- |
| 1.5V             | Pila AA          |
| 5V               | Arduino Uno      |
| 9V               | Batería cuadrada |
| 12V              | Fuente PC        |
| 120/220V         | Red eléctrica    |

---

### W

#### Watt (W)

**Unidad de potencia eléctrica**

Mide la energía consumida o transferida por unidad de tiempo.

```
P = V × I
```

| Variable      | Unidad   |
| ------------- | -------- |
| P (Potencia)  | Watts    |
| V (Voltaje)   | Voltios  |
| I (Corriente) | Amperios |

**Ejemplo:** Un LED típico consume:

```
P = 2V × 0.020A = 0.04W = 40mW
```

---

## 📊 Tabla de Referencia Rápida

### Funciones Arduino Semana 01

| Función            | Uso              | Ejemplo                  |
| ------------------ | ---------------- | ------------------------ |
| `pinMode()`        | Configurar pin   | `pinMode(13, OUTPUT)`    |
| `digitalWrite()`   | Escribir digital | `digitalWrite(13, HIGH)` |
| `delay()`          | Pausar           | `delay(1000)`            |
| `Serial.begin()`   | Iniciar serial   | `Serial.begin(9600)`     |
| `Serial.println()` | Imprimir         | `Serial.println("Hola")` |

### Valores Eléctricos Comunes

| Componente  | Voltaje | Corriente |
| ----------- | ------- | --------- |
| LED Rojo    | 2.0V    | 20mA      |
| LED Verde   | 2.2V    | 20mA      |
| LED Azul    | 3.2V    | 20mA      |
| Arduino Pin | 5V      | 20mA máx  |

### Resistencias para LEDs (5V)

| Color LED | Vf   | Resistencia |
| --------- | ---- | ----------- |
| Rojo      | 2.0V | 150Ω        |
| Amarillo  | 2.0V | 150Ω        |
| Verde     | 2.2V | 140Ω        |
| Azul      | 3.2V | 90Ω         |

**Valor seguro universal:** 220Ω

---

## 🔗 Referencias Cruzadas

Los términos están interconectados. Aquí algunas relaciones clave:

```
Ley de Ohm
    ├── Voltio
    ├── Amperio
    └── Ohmio → Resistor

LED
    ├── Ánodo
    ├── Cátodo
    ├── Forward Voltage
    └── Polaridad

Arduino
    ├── Microcontrolador → ATmega328P
    ├── Pin → GPIO
    ├── Sketch
    │   ├── setup()
    │   └── loop()
    └── Funciones
        ├── pinMode()
        ├── digitalWrite()
        └── delay()
```

---

## 📚 Términos por Categoría

### Electricidad

- Amperio, Corriente, Electrón, Ley de Ohm, Ohmio, Voltio, Watt

### Componentes

- Ánodo, Cátodo, LED, Polaridad, Resistor, Protoboard

### Arduino Hardware

- ATmega328P, Bootloader, GPIO, Microcontrolador, Pin, USB, VCC, GND

### Arduino Software

- Arduino IDE, Compilar, Sketch, Setup, Loop, Serial Monitor, Tinkercad

### Funciones

- delay(), digitalWrite(), pinMode()

### Señales

- ADC, Digital, HIGH, LOW, INPUT, OUTPUT, PWM

---

<div align="center">

**[⬅️ Volver a Recursos](../4-recursos/)** · **[🏠 Inicio Semana](../)** · **[📚 Ir a Semana 02](../../semana-02/)**

</div>
