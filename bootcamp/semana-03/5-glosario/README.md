# 📖 Glosario - Semana 3

> Términos clave relacionados con PWM, control analógico y actuadores

---

## A

### ADC (Analog-to-Digital Converter)

**Conversor Analógico-Digital**. Circuito que convierte señales analógicas continuas en valores digitales discretos. En Arduino Uno, el ADC tiene resolución de 10 bits (0-1023).

```cpp
int value = analogRead(A0);  // Usa el ADC interno
// Resultado: 0 a 1023
```

### analogRead()

Función que lee el voltaje en un pin analógico (A0-A5) y lo convierte a un valor entre 0-1023 usando el ADC interno.

```cpp
int sensorValue = analogRead(A0);
// 0V → 0, 5V → 1023
```

### analogWrite()

Función que genera una señal PWM en pines compatibles (~). El valor va de 0 (0% duty cycle) a 255 (100% duty cycle).

```cpp
analogWrite(9, 127);  // 50% duty cycle en pin 9
```

---

## B

### Buzzer Activo

Buzzer que contiene oscilador interno. Solo necesita voltaje DC para sonar a una frecuencia fija. **No compatible con tone()**.

### Buzzer Pasivo

Buzzer sin oscilador interno. Requiere señal de frecuencia variable para producir diferentes tonos. **Compatible con tone()**.

### Breathing Effect

**Efecto de respiración**. Técnica donde un LED aumenta y disminuye su brillo gradualmente, simulando el ritmo de respiración. Se logra con PWM variable.

```cpp
// Incrementar brillo
for (int i = 0; i <= 255; i++) {
    analogWrite(LED_PIN, i);
    delay(10);
}
```

---

## C

### Cátodo Común (LED RGB)

Configuración de LED RGB donde los tres LEDs comparten el terminal negativo (cátodo). El pin común se conecta a GND.

```
      R    G    B    GND
      │    │    │     │
    [LED][LED][LED]───┴── (común)
```

### Ciclo de Trabajo

Ver **Duty Cycle**.

### constrain()

Función que limita un valor a un rango específico.

```cpp
int safe = constrain(value, 0, 255);
// Si value < 0, retorna 0
// Si value > 255, retorna 255
// Si 0 <= value <= 255, retorna value
```

---

## D

### DAC (Digital-to-Analog Converter)

**Conversor Digital-Analógico**. Convierte valores digitales en voltaje analógico verdadero. Arduino Uno NO tiene DAC, usa PWM como alternativa.

### Dimmer

Dispositivo o técnica para controlar la intensidad de una luz. En Arduino se implementa con PWM.

### Duty Cycle

**Ciclo de trabajo**. Porcentaje del tiempo que una señal PWM está en estado HIGH dentro de un período. 0% = siempre LOW, 100% = siempre HIGH.

```
100% ████████████████
 75% ████████████░░░░
 50% ████████░░░░░░░░
 25% ████░░░░░░░░░░░░
  0% ░░░░░░░░░░░░░░░░
```

---

## F

### Fade

**Desvanecimiento**. Transición gradual del brillo de un LED, ya sea encendiendo (fade in) o apagando (fade out).

### Frecuencia PWM

Número de ciclos PWM por segundo, medido en Hertz (Hz). En Arduino Uno es ~490 Hz para la mayoría de pines PWM.

---

## H

### H-Bridge (Puente H)

Circuito que permite controlar la dirección de un motor DC. Puede invertir la polaridad del voltaje aplicado al motor.

```
     +V
      │
   [Q1]   [Q2]
      │   │
      └─M─┘
      │   │
   [Q3]   [Q4]
      │
     GND
```

### HSV (Hue, Saturation, Value)

Modelo de color alternativo a RGB. Hue (0-360°) define el color, Saturation (0-100%) la pureza, Value (0-100%) el brillo.

```cpp
// Hue: 0=rojo, 120=verde, 240=azul
setColorHSV(180, 255, 255);  // Cian brillante
```

---

## L

### L293D

Circuito integrado de puente H dual. Permite controlar dos motores DC o un motor paso a paso. Soporta hasta 600mA por canal.

### LED RGB

LED que contiene tres LEDs (Rojo, Verde, Azul) en un solo encapsulado. Mezclando intensidades se pueden crear millones de colores.

---

## M

### map()

Función que re-mapea un valor de un rango a otro.

```cpp
int pwm = map(analogValue, 0, 1023, 0, 255);
// Convierte rango 0-1023 a 0-255
```

### millis()

Función que retorna el tiempo en milisegundos desde que Arduino se encendió. Útil para temporización no bloqueante.

```cpp
unsigned long startTime = millis();
if (millis() - startTime >= 1000) {
    // Ha pasado 1 segundo
}
```

### Modulación

Proceso de variar una característica de una señal (amplitud, frecuencia, o ancho de pulso) para transmitir información o controlar dispositivos.

---

## N

### noTone()

Función que detiene la generación de tono en un pin.

```cpp
tone(8, 440);    // Inicia tono de 440 Hz
delay(1000);
noTone(8);       // Detiene el tono
```

---

## O

### Octava

Intervalo musical donde la frecuencia se duplica. La nota La4 (A4) = 440 Hz, La5 (A5) = 880 Hz.

---

## P

### Piezo

Elemento que convierte energía eléctrica en vibración mecánica (o viceversa). Usado en buzzers y sensores de golpe.

### Potenciómetro

Resistencia variable con tres terminales. El terminal central (wiper) proporciona voltaje variable entre los extremos.

```
    ┌─────┐
5V ─┤     ├─ GND
    │  │  │
    └──┼──┘
       │
      A0 (wiper)
```

### Prescaler

Divisor de frecuencia del reloj usado para ajustar la velocidad de los timers. Afecta la frecuencia PWM.

### PWM (Pulse Width Modulation)

**Modulación por Ancho de Pulso**. Técnica que simula voltaje analógico variando el tiempo que una señal digital está en HIGH vs LOW.

```
PWM 75%: ████████████░░░░ (HIGH 75% del tiempo)
         ↑          ↑
      período    duty cycle
```

### PWM Pin

Pines de Arduino capaces de generar señal PWM. En Uno son: 3, 5, 6, 9, 10, 11 (marcados con ~).

---

## R

### Resolución ADC

Número de bits del conversor analógico-digital. Arduino Uno tiene 10 bits = 2^10 = 1024 niveles (0-1023).

### Resolución PWM

Número de niveles de duty cycle disponibles. Arduino tiene 8 bits = 256 niveles (0-255).

### RGB

Modelo de color aditivo. Rojo + Verde + Azul mezclados en diferentes intensidades crean todos los colores visibles.

```cpp
// Blanco = máximo de todos
setColor(255, 255, 255);

// Amarillo = Rojo + Verde
setColor(255, 255, 0);
```

---

## S

### Señal Analógica

Señal que puede tomar cualquier valor dentro de un rango continuo. Ejemplo: voltaje de 0V a 5V.

### Señal Digital

Señal con solo dos estados posibles: HIGH (5V) o LOW (0V).

---

## T

### Timer

Contador de hardware en el microcontrolador usado para generar PWM, medir tiempo y crear interrupciones.

| Timer  | Pines PWM | Frecuencia |
| ------ | --------- | ---------- |
| Timer0 | 5, 6      | ~980 Hz    |
| Timer1 | 9, 10     | ~490 Hz    |
| Timer2 | 3, 11     | ~490 Hz    |

### tone()

Función que genera una onda cuadrada de frecuencia específica en un pin.

```cpp
tone(pin, frequency);           // Tono continuo
tone(pin, frequency, duration); // Tono con duración
```

### Transistor

Componente semiconductor usado como interruptor electrónico. Permite que Arduino controle cargas de mayor corriente (motores, LEDs de alta potencia).

---

## V

### Voltaje Promedio

En PWM, el voltaje efectivo percibido por la carga. Se calcula como: `Vprom = Vcc × (DutyCycle / 100)`.

```
Duty 50% con 5V → Vprom = 2.5V
Duty 25% con 5V → Vprom = 1.25V
```

---

## W

### Wiper

Terminal central móvil de un potenciómetro que "barre" sobre la resistencia, proporcionando voltaje variable.

---

## Símbolos Eléctricos

| Símbolo | Componente   |
| ------- | ------------ |
| ─/\/\/─ | Resistencia  |
| ─\|├─   | Capacitor    |
| ─►\|─   | Diodo        |
| ─►\|◄─  | LED          |
| ─[M]─   | Motor        |
| ─🔊─    | Buzzer       |
| ─⏚─     | Tierra (GND) |

---

## Fórmulas Rápidas

| Concepto        | Fórmula                                          |
| --------------- | ------------------------------------------------ |
| Duty Cycle      | `(analogWrite_value / 255) × 100%`               |
| Voltaje PWM     | `5V × (duty_cycle / 100)`                        |
| Frecuencia nota | `f(n) = 440 × 2^((n-69)/12)` donde n = nota MIDI |
| Resistencia LED | `R = (Vcc - Vf) / If`                            |

---

## ➡️ Volver al Índice

[← Volver a Semana 3](../README.md)
