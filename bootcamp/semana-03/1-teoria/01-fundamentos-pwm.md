# Módulo 1: Fundamentos de PWM

> ⏱️ Tiempo estimado: 20 minutos

---

## 🎯 Objetivos

- Comprender qué es PWM y por qué se usa
- Entender el concepto de duty cycle
- Usar la función `analogWrite()`
- Identificar los pines PWM de Arduino

---

## 📖 ¿Qué es PWM?

### El Problema

Arduino es un dispositivo **digital**: sus pines solo pueden estar en dos estados:

- **HIGH** (5V)
- **LOW** (0V)

Pero muchas aplicaciones necesitan **valores intermedios**:

- LED al 50% de brillo
- Motor a media velocidad
- Señales de control para servos

### La Solución: PWM

**PWM (Pulse Width Modulation)** o Modulación por Ancho de Pulso es una técnica que simula voltajes analógicos encendiendo y apagando un pin digital muy rápidamente.

```
PWM NO genera voltajes reales intermedios
PWM genera un PROMEDIO de voltaje mediante pulsos
```

---

## 📊 Duty Cycle (Ciclo de Trabajo)

El **duty cycle** es el porcentaje de tiempo que la señal está en HIGH durante un período.

### Visualización

```
0% Duty Cycle (analogWrite = 0)
Siempre OFF
___________________________  0V
                             Promedio = 0V

25% Duty Cycle (analogWrite = 64)
 █     █     █     █
 █     █     █     █
_█_____█_____█_____█_____
                             Promedio ≈ 1.25V

50% Duty Cycle (analogWrite = 127)
 ███   ███   ███   ███
 ███   ███   ███   ███
_███___███___███___███___
                             Promedio ≈ 2.5V

75% Duty Cycle (analogWrite = 191)
 █████ █████ █████ █████
 █████ █████ █████ █████
_█████_█████_█████_█████_
                             Promedio ≈ 3.75V

100% Duty Cycle (analogWrite = 255)
█████████████████████████  5V
                             Promedio = 5V
```

---

## 🔢 La Función analogWrite()

### Sintaxis

```cpp
analogWrite(pin, valor);
```

| Parámetro | Descripción    | Rango              |
| --------- | -------------- | ------------------ |
| `pin`     | Pin PWM a usar | 3, 5, 6, 9, 10, 11 |
| `valor`   | Duty cycle     | 0-255 (8 bits)     |

### Fórmulas de Conversión

```cpp
// De porcentaje a valor analogWrite
int valor = (porcentaje / 100.0) * 255;

// De valor analogWrite a porcentaje
float porcentaje = (valor / 255.0) * 100;

// De valor analogWrite a voltaje promedio
float voltaje = (valor / 255.0) * 5.0;
```

### Ejemplo Básico

```cpp
/*
 * LED al 50% de brillo usando PWM
 *
 * ¿Qué hace? Enciende un LED a la mitad de su brillo
 * ¿Para qué? Demostrar control de intensidad con PWM
 * ¿Cómo? Usando analogWrite con valor 127 (50% de 255)
 */

const int LED_PIN = 9;  // Pin PWM

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // 50% de brillo = 127
    analogWrite(LED_PIN, 127);
}
```

---

## 📍 Pines PWM en Arduino Uno

### Identificación Visual

Los pines PWM están marcados con el símbolo **~** (tilde) en la placa:

```
Pines PWM: ~3, ~5, ~6, ~9, ~10, ~11
```

### Frecuencias por Timer

Arduino Uno usa 3 timers para generar PWM:

| Timer  | Pines | Frecuencia | Notas                      |
| ------ | ----- | ---------- | -------------------------- |
| Timer0 | 5, 6  | ~980 Hz    | ⚠️ Afecta millis()/delay() |
| Timer1 | 9, 10 | ~490 Hz    | 16 bits interno            |
| Timer2 | 3, 11 | ~490 Hz    | 8 bits                     |

### Tabla de Pines

```
┌─────────────────────────────────────────────────────┐
│                   ARDUINO UNO                        │
├─────────────────────────────────────────────────────┤
│ Pin │ PWM │ Timer │ Frecuencia │ Uso Recomendado    │
├─────┼─────┼───────┼────────────┼────────────────────┤
│  3  │ ✅  │   2   │   490 Hz   │ LEDs, General      │
│  5  │ ✅  │   0   │   980 Hz   │ LEDs (alta freq)   │
│  6  │ ✅  │   0   │   980 Hz   │ LEDs (alta freq)   │
│  9  │ ✅  │   1   │   490 Hz   │ Servos, Motores    │
│ 10  │ ✅  │   1   │   490 Hz   │ Servos, Motores    │
│ 11  │ ✅  │   2   │   490 Hz   │ LEDs, General      │
└─────┴─────┴───────┴────────────┴────────────────────┘
```

---

## ⚠️ Consideraciones Importantes

### 1. No Requiere pinMode() para OUTPUT

```cpp
// Esto NO es necesario para analogWrite()
// pinMode(9, OUTPUT);  // Opcional

// analogWrite() configura el pin automáticamente
analogWrite(9, 127);
```

### 2. Diferencia con analogRead()

```cpp
// analogWrite() → SALIDA PWM (pines 3,5,6,9,10,11)
analogWrite(9, 127);     // Escribe en pin digital PWM

// analogRead() → ENTRADA ANALÓGICA (pines A0-A5)
int valor = analogRead(A0);  // Lee de pin analógico
```

### 3. Valores Fuera de Rango

```cpp
// Los valores se limitan automáticamente
analogWrite(9, 300);  // Se trata como 255
analogWrite(9, -50);  // Se trata como 0
```

### 4. PWM vs Voltaje Real

```cpp
// PWM NO es un voltaje analógico real
// Es un promedio que SIMULA un voltaje

// Algunos componentes necesitan suavizado:
// - Capacitor para filtrar PWM a voltaje DC
// - Pero LEDs y motores funcionan bien con PWM directo
```

---

## 💻 Código de Práctica

### Barrido de Duty Cycle

```cpp
/*
 * Barrido PWM de 0% a 100%
 *
 * ¿Qué hace? Incrementa gradualmente el brillo de un LED
 * ¿Para qué? Visualizar todos los niveles de PWM
 * ¿Cómo? Loop de 0 a 255 con incrementos de 5
 *
 * Conexión: LED + resistencia 220Ω en pin 9
 * Compatible con Tinkercad ✅
 */

const int LED_PIN = 9;

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Incrementar brillo
    for (int brightness = 0; brightness <= 255; brightness += 5) {
        analogWrite(LED_PIN, brightness);

        // Mostrar valores en Serial Monitor
        Serial.print("PWM: ");
        Serial.print(brightness);
        Serial.print(" | Duty: ");
        Serial.print((brightness / 255.0) * 100);
        Serial.print("% | Voltaje: ");
        Serial.print((brightness / 255.0) * 5.0);
        Serial.println("V");

        delay(50);
    }

    // Decrementar brillo
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
        analogWrite(LED_PIN, brightness);
        delay(50);
    }
}
```

---

## 📝 Resumen

| Concepto      | Descripción                                     |
| ------------- | ----------------------------------------------- |
| PWM           | Simulación de voltaje analógico mediante pulsos |
| Duty Cycle    | % de tiempo en HIGH durante un período          |
| analogWrite() | Función para generar PWM (0-255)                |
| Pines PWM     | 3, 5, 6, 9, 10, 11 (marcados con ~)             |
| Frecuencia    | 490 Hz o 980 Hz según el timer                  |

---

## ➡️ Siguiente

[Control de LEDs con PWM →](./02-control-leds-pwm.md)
