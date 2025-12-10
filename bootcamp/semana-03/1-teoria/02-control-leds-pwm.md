# Módulo 2: Control de LEDs con PWM

> ⏱️ Tiempo estimado: 15 minutos

---

## 🎯 Objetivos

- Crear efectos de fade in/out en LEDs
- Controlar LED RGB con mezcla de colores
- Implementar efectos visuales avanzados

---

## 💡 Efecto Fade (Respiración)

### Concepto

El efecto "fade" o "respiración" consiste en variar gradualmente el brillo de un LED, creando una transición suave entre apagado y encendido.

### Implementación Básica

```cpp
/*
 * LED Fade - Efecto Respiración
 *
 * ¿Qué hace? El LED aumenta y disminuye su brillo suavemente
 * ¿Para qué? Indicador de estado elegante, luz ambiental
 * ¿Cómo? Incrementos/decrementos graduales de PWM
 *
 * Compatible con Tinkercad ✅
 */

const int LED_PIN = 9;
int brightness = 0;
int fadeAmount = 5;

void setup() {
    // pinMode no es estrictamente necesario para analogWrite
}

void loop() {
    // Establecer brillo actual
    analogWrite(LED_PIN, brightness);

    // Cambiar brillo para siguiente iteración
    brightness = brightness + fadeAmount;

    // Invertir dirección en los extremos
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
    }

    // Velocidad del efecto
    delay(30);
}
```

### Versión No Bloqueante con millis()

```cpp
/*
 * LED Fade No Bloqueante
 *
 * ¿Qué hace? Fade sin usar delay()
 * ¿Para qué? Permitir otras tareas simultáneas
 * ¿Cómo? Control de tiempo con millis()
 */

const int LED_PIN = 9;
const unsigned long FADE_INTERVAL = 30;  // ms entre cambios

int brightness = 0;
int fadeAmount = 5;
unsigned long previousMillis = 0;

void setup() {
    // Configuración inicial
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= FADE_INTERVAL) {
        previousMillis = currentMillis;

        analogWrite(LED_PIN, brightness);
        brightness += fadeAmount;

        if (brightness <= 0 || brightness >= 255) {
            fadeAmount = -fadeAmount;
        }
    }

    // Aquí puedes hacer otras tareas
    // mientras el LED sigue con su efecto
}
```

---

## 🌈 LED RGB

### Tipos de LED RGB

| Tipo           | Cátodo Común            | Ánodo Común                 |
| -------------- | ----------------------- | --------------------------- |
| Conexión común | GND                     | VCC (5V)                    |
| Encender color | analogWrite(pin, valor) | analogWrite(pin, 255-valor) |
| Apagar color   | analogWrite(pin, 0)     | analogWrite(pin, 255)       |

### Conexión Cátodo Común

```
            ┌─────────┐
    Pin 9 ──┤ R       │
    (PWM)   │         │
            │   RGB   │
    Pin 10 ─┤ G   LED │
    (PWM)   │         │
            │         │
    Pin 11 ─┤ B       │
    (PWM)   │         │
            │   GND ──┼── GND (común)
            └─────────┘

Resistencias: 220Ω en cada pin de color
```

### Código Base LED RGB

```cpp
/*
 * Control LED RGB - Colores Básicos
 *
 * ¿Qué hace? Permite establecer cualquier color RGB
 * ¿Para qué? Iluminación decorativa, indicadores de estado
 * ¿Cómo? Combinación de 3 canales PWM
 *
 * Compatible con Tinkercad ✅
 */

// Pines PWM para cada color
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void setup() {
    // Los pines se configuran automáticamente con analogWrite
}

void loop() {
    // Rojo puro
    setColor(255, 0, 0);
    delay(1000);

    // Verde puro
    setColor(0, 255, 0);
    delay(1000);

    // Azul puro
    setColor(0, 0, 255);
    delay(1000);

    // Amarillo (R + G)
    setColor(255, 255, 0);
    delay(1000);

    // Magenta (R + B)
    setColor(255, 0, 255);
    delay(1000);

    // Cian (G + B)
    setColor(0, 255, 255);
    delay(1000);

    // Blanco (R + G + B)
    setColor(255, 255, 255);
    delay(1000);

    // Apagado
    setColor(0, 0, 0);
    delay(1000);
}

/**
 * Establece el color del LED RGB
 *
 * @param red   Intensidad rojo (0-255)
 * @param green Intensidad verde (0-255)
 * @param blue  Intensidad azul (0-255)
 */
void setColor(int red, int green, int blue) {
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}
```

---

## 🎨 Tabla de Colores

### Colores Básicos

| Color    | R   | G   | B   | Código                    |
| -------- | --- | --- | --- | ------------------------- |
| Rojo     | 255 | 0   | 0   | `setColor(255, 0, 0)`     |
| Verde    | 0   | 255 | 0   | `setColor(0, 255, 0)`     |
| Azul     | 0   | 0   | 255 | `setColor(0, 0, 255)`     |
| Amarillo | 255 | 255 | 0   | `setColor(255, 255, 0)`   |
| Magenta  | 255 | 0   | 255 | `setColor(255, 0, 255)`   |
| Cian     | 0   | 255 | 255 | `setColor(0, 255, 255)`   |
| Blanco   | 255 | 255 | 255 | `setColor(255, 255, 255)` |
| Naranja  | 255 | 128 | 0   | `setColor(255, 128, 0)`   |
| Rosa     | 255 | 105 | 180 | `setColor(255, 105, 180)` |
| Púrpura  | 128 | 0   | 128 | `setColor(128, 0, 128)`   |

---

## 🌈 Efecto Arcoíris

### Transición Suave de Colores

```cpp
/*
 * Efecto Arcoíris - Transición de colores
 *
 * ¿Qué hace? Cicla suavemente por todos los colores
 * ¿Para qué? Efecto visual llamativo
 * ¿Cómo? Transición gradual entre R→G→B→R
 */

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void setup() {
    Serial.begin(9600);
}

void loop() {
    rainbowCycle();
}

/**
 * Genera un ciclo completo de arcoíris
 * Usa modelo HSV simplificado
 */
void rainbowCycle() {
    // Fase 1: Rojo a Amarillo (incrementar G)
    for (int g = 0; g <= 255; g += 5) {
        setColor(255, g, 0);
        delay(20);
    }

    // Fase 2: Amarillo a Verde (decrementar R)
    for (int r = 255; r >= 0; r -= 5) {
        setColor(r, 255, 0);
        delay(20);
    }

    // Fase 3: Verde a Cian (incrementar B)
    for (int b = 0; b <= 255; b += 5) {
        setColor(0, 255, b);
        delay(20);
    }

    // Fase 4: Cian a Azul (decrementar G)
    for (int g = 255; g >= 0; g -= 5) {
        setColor(0, g, 255);
        delay(20);
    }

    // Fase 5: Azul a Magenta (incrementar R)
    for (int r = 0; r <= 255; r += 5) {
        setColor(r, 0, 255);
        delay(20);
    }

    // Fase 6: Magenta a Rojo (decrementar B)
    for (int b = 255; b >= 0; b -= 5) {
        setColor(255, 0, b);
        delay(20);
    }
}

void setColor(int r, int g, int b) {
    analogWrite(RED_PIN, r);
    analogWrite(GREEN_PIN, g);
    analogWrite(BLUE_PIN, b);
}
```

---

## ✨ Efectos Adicionales

### Parpadeo Suave

```cpp
/**
 * Parpadeo suave con PWM
 * Más elegante que digitalWrite con delay
 */
void softBlink(int pin, int onTime, int offTime) {
    // Fade in
    for (int i = 0; i <= 255; i += 10) {
        analogWrite(pin, i);
        delay(onTime / 25);
    }

    // Fade out
    for (int i = 255; i >= 0; i -= 10) {
        analogWrite(pin, i);
        delay(offTime / 25);
    }
}
```

### Efecto Latido (Heartbeat)

```cpp
/**
 * Efecto latido de corazón
 * Dos pulsos rápidos seguidos de pausa
 */
void heartbeat(int pin) {
    // Primer pulso
    pulse(pin, 200);
    delay(100);

    // Segundo pulso
    pulse(pin, 200);
    delay(500);  // Pausa larga
}

void pulse(int pin, int duration) {
    // Subida rápida
    for (int i = 0; i <= 255; i += 15) {
        analogWrite(pin, i);
        delay(duration / 34);
    }

    // Bajada rápida
    for (int i = 255; i >= 0; i -= 15) {
        analogWrite(pin, i);
        delay(duration / 34);
    }
}
```

---

## 📝 Resumen

| Efecto    | Descripción                  | Uso Típico             |
| --------- | ---------------------------- | ---------------------- |
| Fade      | Transición gradual de brillo | Indicadores de estado  |
| RGB       | Control de 3 canales PWM     | Iluminación decorativa |
| Arcoíris  | Ciclo de colores             | Efectos visuales       |
| Heartbeat | Pulso doble                  | Indicador "vivo"       |

---

## ➡️ Siguiente

[Motores y Actuadores →](./03-motores-actuadores.md)
