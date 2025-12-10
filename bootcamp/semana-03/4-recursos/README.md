# 📖 Recursos Adicionales - Semana 3

> Material complementario para profundizar en PWM y control analógico

---

## 📚 Documentación Oficial Arduino

### Funciones PWM

| Función         | Descripción                         | Enlace                                                                                             |
| --------------- | ----------------------------------- | -------------------------------------------------------------------------------------------------- |
| `analogWrite()` | Escritura PWM en pines compatibles  | [Arduino Reference](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/) |
| `analogRead()`  | Lectura de valores analógicos (ADC) | [Arduino Reference](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/)  |
| `map()`         | Mapeo de rangos numéricos           | [Arduino Reference](https://www.arduino.cc/reference/en/language/functions/math/map/)              |
| `constrain()`   | Limitar valores a un rango          | [Arduino Reference](https://www.arduino.cc/reference/en/language/functions/math/constrain/)        |

### Funciones de Sonido

| Función    | Descripción                    | Enlace                                                                                          |
| ---------- | ------------------------------ | ----------------------------------------------------------------------------------------------- |
| `tone()`   | Generar onda cuadrada (sonido) | [Arduino Reference](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/)   |
| `noTone()` | Detener generación de tono     | [Arduino Reference](https://www.arduino.cc/reference/en/language/functions/advanced-io/notone/) |

### Temporización

| Función    | Descripción              | Enlace                                                                                   |
| ---------- | ------------------------ | ---------------------------------------------------------------------------------------- |
| `millis()` | Tiempo desde inicio (ms) | [Arduino Reference](https://www.arduino.cc/reference/en/language/functions/time/millis/) |
| `micros()` | Tiempo desde inicio (μs) | [Arduino Reference](https://www.arduino.cc/reference/en/language/functions/time/micros/) |

---

## 🎥 Videos Recomendados

### PWM y Control de LEDs

| Video                                                           | Canal             | Duración | Tema                 |
| --------------------------------------------------------------- | ----------------- | -------- | -------------------- |
| [PWM Explicado](https://www.youtube.com/watch?v=GQLED3gmONg)    | GreatScott!       | 6 min    | Fundamentos PWM      |
| [Arduino LED Fade](https://www.youtube.com/watch?v=Y-QbUYzIUvI) | Paul McWhorter    | 15 min   | analogWrite tutorial |
| [RGB LED Tutorial](https://www.youtube.com/watch?v=WbJyinQFHmM) | DroneBot Workshop | 20 min   | Control RGB completo |

### Motores y Actuadores

| Video                                                           | Canal             | Duración | Tema           |
| --------------------------------------------------------------- | ----------------- | -------- | -------------- |
| [DC Motor Control](https://www.youtube.com/watch?v=8xvUNyJDGqk) | DroneBot Workshop | 25 min   | PWM + puente H |
| [Servo Control](https://www.youtube.com/watch?v=kUHmYKWwuWs)    | Paul McWhorter    | 18 min   | Servomotores   |

### Buzzer y Sonido

| Video                                                         | Canal           | Duración | Tema             |
| ------------------------------------------------------------- | --------------- | -------- | ---------------- |
| [Arduino Buzzer](https://www.youtube.com/watch?v=JiLADN6E-5U) | Electronoobs    | 10 min   | tone() básico    |
| [Making Music](https://www.youtube.com/watch?v=RWv8zW7Fttw)   | Kristian Blåsol | 12 min   | Melodías Arduino |

---

## 📄 Datasheets Importantes

### Componentes Utilizados

| Componente             | Fabricante | Enlace                                                                                                                        |
| ---------------------- | ---------- | ----------------------------------------------------------------------------------------------------------------------------- |
| ATmega328P             | Microchip  | [Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf) |
| LED RGB (cátodo común) | Genérico   | [Datasheet](https://www.sparkfun.com/datasheets/Components/LED/RGB_LED-5mm.pdf)                                               |
| Transistor 2N2222      | ON Semi    | [Datasheet](https://www.onsemi.com/pdf/datasheet/p2n2222a-d.pdf)                                                              |
| TIP120 (Darlington)    | ST         | [Datasheet](https://www.st.com/resource/en/datasheet/tip120.pdf)                                                              |
| L293D (Puente H)       | TI         | [Datasheet](https://www.ti.com/lit/ds/symlink/l293d.pdf)                                                                      |

---

## 🔧 Herramientas Online

### Simuladores

| Herramienta         | Descripción              | Enlace                                              |
| ------------------- | ------------------------ | --------------------------------------------------- |
| Tinkercad Circuits  | Simulador Arduino online | [tinkercad.com](https://www.tinkercad.com/circuits) |
| Wokwi               | Simulador avanzado       | [wokwi.com](https://wokwi.com/)                     |
| Falstad Circuit Sim | Simulador de circuitos   | [falstad.com](https://www.falstad.com/circuit/)     |

### Calculadoras

| Herramienta              | Uso                           | Enlace                                                                         |
| ------------------------ | ----------------------------- | ------------------------------------------------------------------------------ |
| LED Resistor Calculator  | Calcular resistencia para LED | [ohmslawcalculator.com](https://ohmslawcalculator.com/led-resistor-calculator) |
| PWM Frequency Calculator | Calcular frecuencia PWM       | [omnicalculator.com](https://www.omnicalculator.com/other/pwm)                 |
| Resistor Color Code      | Identificar resistencias      | [resistorcolorcodecalc.com](https://www.resistorcolorcodecalc.com/)            |

### Generadores de Código

| Herramienta          | Uso                 | Enlace                                                                 |
| -------------------- | ------------------- | ---------------------------------------------------------------------- |
| Arduino Melody Maker | Crear melodías      | [github.com/robsoncouto](https://github.com/robsoncouto/arduino-songs) |
| Color Picker RGB     | Obtener valores RGB | [colorpicker.me](https://colorpicker.me/)                              |

---

## 📘 Artículos y Tutoriales

### PWM en Profundidad

1. **[Secrets of Arduino PWM](https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM)**

   - Funcionamiento interno del PWM en ATmega
   - Configuración de timers
   - Cambio de frecuencia PWM

2. **[PWM Tutorial for Robotics](https://www.societyofrobots.com/microcontroller_tutorial.shtml)**
   - Aplicaciones en robótica
   - Control de velocidad de motores
   - Servomotores

### LED RGB

1. **[RGB LED Tutorial - SparkFun](https://learn.sparkfun.com/tutorials/light-emitting-diodes-leds)**

   - Fundamentos de LEDs
   - Cátodo vs ánodo común
   - Mezclado de colores

2. **[HSV Color Model](https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use)**
   - Modelo de color HSV
   - Conversión HSV a RGB
   - Efectos de arcoíris

### Motores DC

1. **[DC Motor Control - LastMinuteEngineers](https://lastminuteengineers.com/l293d-dc-motor-arduino-tutorial/)**
   - Control con L293D
   - Dirección y velocidad
   - Protección del Arduino

---

## 📦 Librerías Útiles

### Control de LEDs

```cpp
// TimerOne - PWM de alta frecuencia
#include <TimerOne.h>

// FastLED - LEDs direccionables (WS2812)
#include <FastLED.h>

// Adafruit NeoPixel
#include <Adafruit_NeoPixel.h>
```

### Sonido y Música

```cpp
// Tone - Múltiples tonos simultáneos
#include <Tone.h>

// Mozzi - Síntesis de audio avanzada
#include <MozziGuts.h>
```

### Motores

```cpp
// Servo - Control de servomotores
#include <Servo.h>

// AccelStepper - Motores paso a paso
#include <AccelStepper.h>

// Adafruit Motor Shield
#include <Adafruit_MotorShield.h>
```

---

## 🎵 Tabla de Frecuencias Musicales

### Notas Completas (Hz)

| Nota    | Octava 3 | Octava 4 | Octava 5 | Octava 6 |
| ------- | -------- | -------- | -------- | -------- |
| C (Do)  | 131      | 262      | 523      | 1047     |
| C#      | 139      | 277      | 554      | 1109     |
| D (Re)  | 147      | 294      | 587      | 1175     |
| D#      | 156      | 311      | 622      | 1245     |
| E (Mi)  | 165      | 330      | 659      | 1319     |
| F (Fa)  | 175      | 349      | 698      | 1397     |
| F#      | 185      | 370      | 740      | 1480     |
| G (Sol) | 196      | 392      | 784      | 1568     |
| G#      | 208      | 415      | 831      | 1661     |
| A (La)  | 220      | 440      | 880      | 1760     |
| A#      | 233      | 466      | 932      | 1865     |
| B (Si)  | 247      | 494      | 988      | 1976     |

### Archivo pitches.h

```cpp
// Descarga el archivo completo de:
// https://github.com/arduino/arduino-examples/blob/main/examples/02.Digital/toneMelody/pitches.h
```

---

## 🎨 Tabla de Colores RGB

### Colores Básicos

| Color    | R   | G   | B   | Hex     |
| -------- | --- | --- | --- | ------- |
| Rojo     | 255 | 0   | 0   | #FF0000 |
| Verde    | 0   | 255 | 0   | #00FF00 |
| Azul     | 0   | 0   | 255 | #0000FF |
| Amarillo | 255 | 255 | 0   | #FFFF00 |
| Cian     | 0   | 255 | 255 | #00FFFF |
| Magenta  | 255 | 0   | 255 | #FF00FF |
| Blanco   | 255 | 255 | 255 | #FFFFFF |
| Naranja  | 255 | 165 | 0   | #FFA500 |
| Rosa     | 255 | 192 | 203 | #FFC0CB |
| Púrpura  | 128 | 0   | 128 | #800080 |

### Colores Cálidos

| Color      | R   | G   | B   |
| ---------- | --- | --- | --- |
| Warm White | 255 | 244 | 229 |
| Candle     | 255 | 147 | 41  |
| Sunset     | 255 | 100 | 50  |
| Fire       | 255 | 80  | 0   |

---

## 📐 Fórmulas Importantes

### Frecuencia PWM Arduino Uno

```
f_PWM = f_clock / (prescaler × 256)

Pins 5, 6: ~980 Hz (Timer0)
Pins 9, 10: ~490 Hz (Timer1)
Pins 3, 11: ~490 Hz (Timer2)
```

### Duty Cycle

```
Duty Cycle (%) = (valor_analogWrite / 255) × 100

Voltaje promedio = Vcc × (Duty Cycle / 100)
```

### Resistencia para LED

```
R = (Vcc - Vf) / If

Donde:
- Vcc = Voltaje de alimentación (5V)
- Vf = Voltaje forward del LED (~2V rojo, ~3.2V azul)
- If = Corriente deseada (típico 10-20mA)
```

---

## ➡️ Siguiente Sección

[Glosario →](../5-glosario/README.md)
