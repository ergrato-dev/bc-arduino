# 🔨 Proyecto Semana 3: Lámpara RGB Inteligente

> ⏱️ Tiempo estimado: 90 minutos · ⭐⭐⭐ Nivel: Avanzado

---

## 📋 Índice

1. [Descripción](#-descripción)
2. [Objetivos](#-objetivos-de-aprendizaje)
3. [Materiales](#-materiales)
4. [Especificaciones](#-especificaciones-técnicas)
5. [Diagrama](#-diagrama-de-conexión)
6. [Implementación](#-guía-de-implementación)
7. [Código Completo](#-código-completo)
8. [Pruebas](#-pruebas-y-validación)
9. [Extensiones](#-extensiones-opcionales)
10. [Entrega](#-entrega)

---

## 📝 Descripción

Diseña y construye una **lámpara RGB inteligente** con múltiples modos de operación controlados por botones. La lámpara incluirá efectos visuales, control de brillo con potenciómetro y retroalimentación sonora.

### Características Principales

- 🎨 **8 colores predefinidos** con transiciones suaves
- 🌈 **Modo arcoíris** con barrido automático de colores
- 💡 **Control de brillo** mediante potenciómetro
- 🔊 **Feedback sonoro** al cambiar de modo
- ⚡ **Código no bloqueante** usando `millis()`

---

## 🎯 Objetivos de Aprendizaje

Al completar este proyecto, habrás practicado:

- [ ] Control PWM de LED RGB (ánodo/cátodo común)
- [ ] Lectura analógica y mapeo de valores
- [ ] Generación de tonos con buzzer
- [ ] Debounce de botones
- [ ] Máquina de estados para modos
- [ ] Programación no bloqueante con `millis()`
- [ ] Organización de código en funciones

---

## 📦 Materiales

| Componente             | Cantidad | Notas                |
| ---------------------- | -------- | -------------------- |
| Arduino Uno            | 1        | R3 o R4              |
| LED RGB (cátodo común) | 1        | 4 pines              |
| Resistencia 220Ω       | 3        | Una por color        |
| Potenciómetro 10kΩ     | 1        | Control de brillo    |
| Pulsador táctil        | 2        | Cambio de modo/color |
| Buzzer pasivo          | 1        | Feedback sonoro      |
| Protoboard             | 1        | 400 puntos           |
| Cables jumper          | 15+      | Varios colores       |

---

## ⚙️ Especificaciones Técnicas

### Modos de Operación

| Modo        | ID  | Descripción                    | Botón             |
| ----------- | --- | ------------------------------ | ----------------- |
| Estático    | 0   | Color fijo seleccionable       | BTN2 cambia color |
| Respiración | 1   | Fade in/out del color actual   | Automático        |
| Arcoíris    | 2   | Transición continua de colores | Automático        |
| Fiesta      | 3   | Cambios rápidos aleatorios     | Automático        |

### Colores Disponibles (Modo Estático)

| #   | Color    | R   | G   | B   |
| --- | -------- | --- | --- | --- |
| 0   | Rojo     | 255 | 0   | 0   |
| 1   | Verde    | 0   | 255 | 0   |
| 2   | Azul     | 0   | 0   | 255 |
| 3   | Amarillo | 255 | 255 | 0   |
| 4   | Cian     | 0   | 255 | 255 |
| 5   | Magenta  | 255 | 0   | 255 |
| 6   | Naranja  | 255 | 128 | 0   |
| 7   | Blanco   | 255 | 255 | 255 |

### Controles

| Control       | Función                            |
| ------------- | ---------------------------------- |
| Botón 1       | Cambiar modo (0→1→2→3→0...)        |
| Botón 2       | Cambiar color (solo modo estático) |
| Potenciómetro | Ajustar brillo global (0-100%)     |

---

## 🔌 Diagrama de Conexión

```
                    Potenciómetro 10kΩ
                       ┌─────┐
           5V ─────────┤ 1   │
           A0 ─────────┤ 2   │ (Wiper)
          GND ─────────┤ 3   │
                       └─────┘

    Arduino Uno
    ┌─────────────────────────────────────┐
    │                                     │
    │   ~9  ──[220Ω]──┐                   │
    │                 │     LED RGB       │
    │  ~10  ──[220Ω]──┼──── (cátodo)      │
    │                 │                   │
    │  ~11  ──[220Ω]──┘     R  G  B  GND  │
    │                       │  │  │   │   │
    │   GND ────────────────┴──┴──┴───┘   │
    │                                     │
    │    2  ──┬── BTN1 ──── GND           │
    │         │  (Modo)                   │
    │                                     │
    │    3  ──┬── BTN2 ──── GND           │
    │         │  (Color)                  │
    │                                     │
    │    8  ──────── BUZZER+ ─┐           │
    │   GND ──────── BUZZER- ─┘           │
    │                                     │
    └─────────────────────────────────────┘
```

### Tabla de Conexiones

| Arduino   | Componente            | Notas             |
| --------- | --------------------- | ----------------- |
| ~9 (PWM)  | LED Rojo (via 220Ω)   | Pin R del RGB     |
| ~10 (PWM) | LED Verde (via 220Ω)  | Pin G del RGB     |
| ~11 (PWM) | LED Azul (via 220Ω)   | Pin B del RGB     |
| GND       | LED RGB (cátodo)      | Pin más largo     |
| 2         | Botón 1 (Modo)        | INPUT_PULLUP      |
| 3         | Botón 2 (Color)       | INPUT_PULLUP      |
| A0        | Potenciómetro (wiper) | Terminal central  |
| 5V        | Potenciómetro         | Terminal 1        |
| GND       | Potenciómetro         | Terminal 3        |
| 8         | Buzzer (+)            | Terminal positivo |
| GND       | Buzzer (-)            | Terminal negativo |

---

## 📐 Guía de Implementación

### Paso 1: Estructura Base

Crea la estructura del sketch con todas las secciones:

```cpp
// 1. Definiciones de pines
// 2. Constantes (colores, notas)
// 3. Variables de estado
// 4. setup()
// 5. loop()
// 6. Funciones de control RGB
// 7. Funciones de modos
// 8. Funciones de input
// 9. Funciones de sonido
```

### Paso 2: Control RGB Básico

Implementa la función para establecer un color:

```cpp
void setColor(int r, int g, int b) {
    // Aplicar brillo global
    float brightnessFactor = brightness / 255.0;

    analogWrite(RED_PIN, r * brightnessFactor);
    analogWrite(GREEN_PIN, g * brightnessFactor);
    analogWrite(BLUE_PIN, b * brightnessFactor);
}
```

### Paso 3: Lectura de Potenciómetro

Lee y mapea el valor del brillo:

```cpp
void updateBrightness() {
    int potValue = analogRead(POT_PIN);
    brightness = map(potValue, 0, 1023, 0, 255);
}
```

### Paso 4: Debounce de Botones

Implementa debounce para lecturas limpias:

```cpp
bool readButtonWithDebounce(int pin, bool &lastState,
                            unsigned long &lastDebounce) {
    bool reading = digitalRead(pin);
    bool pressed = false;

    if (reading != lastState) {
        lastDebounce = millis();
    }

    if ((millis() - lastDebounce) > DEBOUNCE_DELAY) {
        if (reading == LOW && lastState == HIGH) {
            pressed = true;
        }
        lastState = reading;
    }

    return pressed;
}
```

### Paso 5: Máquina de Estados

Implementa el cambio entre modos:

```cpp
void handleModeButton() {
    if (readButtonWithDebounce(BTN_MODE_PIN, ...)) {
        currentMode = (currentMode + 1) % NUM_MODES;
        playModeSound(currentMode);
    }
}
```

### Paso 6: Efectos de Cada Modo

Implementa la lógica de cada modo usando `millis()`:

```cpp
void updateMode() {
    switch (currentMode) {
        case MODE_STATIC:
            modeStatic();
            break;
        case MODE_BREATHING:
            modeBreathing();
            break;
        case MODE_RAINBOW:
            modeRainbow();
            break;
        case MODE_PARTY:
            modeParty();
            break;
    }
}
```

---

## 💻 Código Completo

```cpp
/*
 * ==========================================================
 * PROYECTO: Lámpara RGB Inteligente
 * Semana 3 - Bootcamp Arduino
 * ==========================================================
 *
 * ¿Qué hace?
 * Lámpara LED RGB con múltiples modos de operación:
 * estático, respiración, arcoíris y fiesta. Control de
 * brillo con potenciómetro y feedback sonoro.
 *
 * ¿Para qué?
 * - Iluminación ambiental decorativa
 * - Práctica de PWM, entradas analógicas y digitales
 * - Implementación de máquina de estados
 *
 * ¿Cómo funciona?
 * 1. Loop principal actualiza brillo, lee botones
 * 2. Máquina de estados ejecuta el modo actual
 * 3. Cada modo usa millis() para animaciones
 * 4. Buzzer da feedback al cambiar modo/color
 *
 * Hardware:
 * - LED RGB (cátodo común) en pines 9, 10, 11
 * - Potenciómetro en A0
 * - Botones en pines 2 y 3
 * - Buzzer en pin 8
 *
 * Compatibilidad Tinkercad: ✅
 * ==========================================================
 */

// ==========================================================
// DEFINICIÓN DE PINES
// ==========================================================
const int RED_PIN = 9;       // PWM - LED Rojo
const int GREEN_PIN = 10;    // PWM - LED Verde
const int BLUE_PIN = 11;     // PWM - LED Azul
const int BTN_MODE_PIN = 2;  // Botón cambio de modo
const int BTN_COLOR_PIN = 3; // Botón cambio de color
const int POT_PIN = A0;      // Potenciómetro brillo
const int BUZZER_PIN = 8;    // Buzzer feedback

// ==========================================================
// CONSTANTES DE CONFIGURACIÓN
// ==========================================================
const unsigned long DEBOUNCE_DELAY = 50;
const int NUM_MODES = 4;
const int NUM_COLORS = 8;

// Modos de operación
const int MODE_STATIC = 0;
const int MODE_BREATHING = 1;
const int MODE_RAINBOW = 2;
const int MODE_PARTY = 3;

// Tiempos de animación (ms)
const int BREATHING_SPEED = 15;
const int RAINBOW_SPEED = 20;
const int PARTY_SPEED = 150;

// Notas para feedback
const int NOTE_MODE[] = {262, 330, 392, 523}; // Do, Mi, Sol, Do5
const int NOTE_COLOR = 440;  // La

// ==========================================================
// COLORES PREDEFINIDOS (R, G, B)
// ==========================================================
const int COLORS[NUM_COLORS][3] = {
    {255, 0, 0},     // Rojo
    {0, 255, 0},     // Verde
    {0, 0, 255},     // Azul
    {255, 255, 0},   // Amarillo
    {0, 255, 255},   // Cian
    {255, 0, 255},   // Magenta
    {255, 128, 0},   // Naranja
    {255, 255, 255}  // Blanco
};

const char* COLOR_NAMES[] = {
    "Rojo", "Verde", "Azul", "Amarillo",
    "Cian", "Magenta", "Naranja", "Blanco"
};

const char* MODE_NAMES[] = {
    "Estatico", "Respiracion", "Arcoiris", "Fiesta"
};

// ==========================================================
// VARIABLES DE ESTADO
// ==========================================================
int currentMode = MODE_STATIC;
int currentColor = 0;
int brightness = 255;

// Variables para debounce
bool lastModeState = HIGH;
bool lastColorState = HIGH;
unsigned long lastModeDebounce = 0;
unsigned long lastColorDebounce = 0;

// Variables para animaciones
unsigned long lastAnimUpdate = 0;
int breathingValue = 0;
int breathingDirection = 1;
int rainbowHue = 0;

// ==========================================================
// SETUP
// ==========================================================
void setup() {
    // Configurar pines de salida
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    // Configurar pines de entrada con pull-up interno
    pinMode(BTN_MODE_PIN, INPUT_PULLUP);
    pinMode(BTN_COLOR_PIN, INPUT_PULLUP);

    // Iniciar Serial para debug
    Serial.begin(9600);
    Serial.println("=================================");
    Serial.println("  Lampara RGB Inteligente v1.0");
    Serial.println("=================================");
    Serial.println("BTN1: Cambiar modo");
    Serial.println("BTN2: Cambiar color (modo estatico)");
    Serial.println("POT:  Ajustar brillo");
    Serial.println("---------------------------------");

    // Melodía de inicio
    playStartupMelody();

    // Mostrar estado inicial
    printStatus();
}

// ==========================================================
// LOOP PRINCIPAL
// ==========================================================
void loop() {
    // 1. Actualizar brillo desde potenciómetro
    updateBrightness();

    // 2. Leer botones
    handleButtons();

    // 3. Ejecutar modo actual
    updateMode();
}

// ==========================================================
// FUNCIONES DE CONTROL RGB
// ==========================================================

/**
 * Establece el color del LED RGB con brillo aplicado
 */
void setColor(int r, int g, int b) {
    float factor = brightness / 255.0;

    analogWrite(RED_PIN, (int)(r * factor));
    analogWrite(GREEN_PIN, (int)(g * factor));
    analogWrite(BLUE_PIN, (int)(b * factor));
}

/**
 * Establece color desde el array de colores predefinidos
 */
void setColorFromPalette(int colorIndex) {
    setColor(
        COLORS[colorIndex][0],
        COLORS[colorIndex][1],
        COLORS[colorIndex][2]
    );
}

/**
 * Convierte HSV a RGB (para efecto arcoíris)
 * hue: 0-360, sat: 0-255, val: 0-255
 */
void setColorHSV(int hue, int sat, int val) {
    int r, g, b;
    int base;

    if (sat == 0) {
        r = g = b = val;
    } else {
        base = ((255 - sat) * val) >> 8;

        switch (hue / 60) {
            case 0:
                r = val;
                g = (((val - base) * hue) / 60) + base;
                b = base;
                break;
            case 1:
                r = (((val - base) * (60 - (hue % 60))) / 60) + base;
                g = val;
                b = base;
                break;
            case 2:
                r = base;
                g = val;
                b = (((val - base) * (hue % 60)) / 60) + base;
                break;
            case 3:
                r = base;
                g = (((val - base) * (60 - (hue % 60))) / 60) + base;
                b = val;
                break;
            case 4:
                r = (((val - base) * (hue % 60)) / 60) + base;
                g = base;
                b = val;
                break;
            case 5:
                r = val;
                g = base;
                b = (((val - base) * (60 - (hue % 60))) / 60) + base;
                break;
        }
    }

    setColor(r, g, b);
}

// ==========================================================
// FUNCIONES DE ENTRADA
// ==========================================================

/**
 * Actualiza el brillo global desde el potenciómetro
 */
void updateBrightness() {
    static int lastBrightness = 0;
    int potValue = analogRead(POT_PIN);
    brightness = map(potValue, 0, 1023, 0, 255);

    // Solo imprimir si cambió significativamente
    if (abs(brightness - lastBrightness) > 10) {
        Serial.print("Brillo: ");
        Serial.print((brightness * 100) / 255);
        Serial.println("%");
        lastBrightness = brightness;
    }
}

/**
 * Lee botón con debounce - retorna true si se presionó
 */
bool readButtonDebounced(int pin, bool &lastState,
                          unsigned long &lastDebounce) {
    bool reading = digitalRead(pin);
    bool pressed = false;

    if (reading != lastState) {
        lastDebounce = millis();
    }

    if ((millis() - lastDebounce) > DEBOUNCE_DELAY) {
        if (reading == LOW && lastState == HIGH) {
            pressed = true;
        }
    }

    lastState = reading;
    return pressed;
}

/**
 * Maneja la lectura de ambos botones
 */
void handleButtons() {
    // Botón de modo
    if (readButtonDebounced(BTN_MODE_PIN, lastModeState, lastModeDebounce)) {
        currentMode = (currentMode + 1) % NUM_MODES;
        playModeSound(currentMode);
        printStatus();

        // Reset de animaciones al cambiar modo
        breathingValue = 0;
        breathingDirection = 1;
        rainbowHue = 0;
    }

    // Botón de color (solo funciona en modo estático)
    if (readButtonDebounced(BTN_COLOR_PIN, lastColorState, lastColorDebounce)) {
        if (currentMode == MODE_STATIC) {
            currentColor = (currentColor + 1) % NUM_COLORS;
            playColorSound();
            printStatus();
        }
    }
}

// ==========================================================
// FUNCIONES DE MODOS
// ==========================================================

/**
 * Ejecuta el modo actual
 */
void updateMode() {
    switch (currentMode) {
        case MODE_STATIC:
            modeStatic();
            break;
        case MODE_BREATHING:
            modeBreathing();
            break;
        case MODE_RAINBOW:
            modeRainbow();
            break;
        case MODE_PARTY:
            modeParty();
            break;
    }
}

/**
 * Modo estático: muestra color fijo seleccionado
 */
void modeStatic() {
    setColorFromPalette(currentColor);
}

/**
 * Modo respiración: fade in/out del color actual
 */
void modeBreathing() {
    if (millis() - lastAnimUpdate >= BREATHING_SPEED) {
        lastAnimUpdate = millis();

        // Actualizar valor de respiración
        breathingValue += breathingDirection * 2;

        // Invertir dirección en los límites
        if (breathingValue >= 255) {
            breathingValue = 255;
            breathingDirection = -1;
        } else if (breathingValue <= 0) {
            breathingValue = 0;
            breathingDirection = 1;
        }

        // Aplicar con factor de respiración
        float factor = breathingValue / 255.0;
        int r = COLORS[currentColor][0] * factor;
        int g = COLORS[currentColor][1] * factor;
        int b = COLORS[currentColor][2] * factor;

        setColor(r, g, b);
    }
}

/**
 * Modo arcoíris: transición continua por el espectro
 */
void modeRainbow() {
    if (millis() - lastAnimUpdate >= RAINBOW_SPEED) {
        lastAnimUpdate = millis();

        rainbowHue = (rainbowHue + 1) % 360;
        setColorHSV(rainbowHue, 255, 255);
    }
}

/**
 * Modo fiesta: cambios rápidos aleatorios
 */
void modeParty() {
    if (millis() - lastAnimUpdate >= PARTY_SPEED) {
        lastAnimUpdate = millis();

        int randomColor = random(NUM_COLORS);
        setColorFromPalette(randomColor);
    }
}

// ==========================================================
// FUNCIONES DE SONIDO
// ==========================================================

/**
 * Melodía de inicio
 */
void playStartupMelody() {
    int melody[] = {262, 330, 392, 523};
    for (int i = 0; i < 4; i++) {
        tone(BUZZER_PIN, melody[i], 100);
        delay(120);
    }
    noTone(BUZZER_PIN);
}

/**
 * Sonido al cambiar de modo
 */
void playModeSound(int mode) {
    tone(BUZZER_PIN, NOTE_MODE[mode], 150);
    delay(160);
    noTone(BUZZER_PIN);
}

/**
 * Sonido al cambiar de color
 */
void playColorSound() {
    tone(BUZZER_PIN, NOTE_COLOR, 50);
    delay(60);
    noTone(BUZZER_PIN);
}

// ==========================================================
// FUNCIONES DE DEBUG
// ==========================================================

/**
 * Imprime el estado actual en Serial Monitor
 */
void printStatus() {
    Serial.println("---------------------------------");
    Serial.print("Modo: ");
    Serial.print(MODE_NAMES[currentMode]);
    Serial.print(" | Color: ");
    Serial.print(COLOR_NAMES[currentColor]);
    Serial.print(" | Brillo: ");
    Serial.print((brightness * 100) / 255);
    Serial.println("%");
}
```

---

## 🧪 Pruebas y Validación

### Lista de Verificación Funcional

| Prueba                | Esperado               | ✓   |
| --------------------- | ---------------------- | --- |
| Encendido             | Melodía + LED enciende | ☐   |
| BTN1 presionado       | Cambia modo + sonido   | ☐   |
| BTN2 en modo estático | Cambia color + sonido  | ☐   |
| BTN2 en otros modos   | Sin efecto             | ☐   |
| Girar potenciómetro   | Brillo cambia          | ☐   |
| Modo respiración      | Fade suave             | ☐   |
| Modo arcoíris         | Transición continua    | ☐   |
| Modo fiesta           | Cambios rápidos        | ☐   |

### Pruebas de Calidad

- [ ] Sin parpadeos visibles
- [ ] Transiciones suaves
- [ ] Botones responden correctamente
- [ ] Serial Monitor muestra info
- [ ] Sin delays bloqueantes en loop

---

## 🚀 Extensiones Opcionales

### Nivel 1: Memoria EEPROM

Guarda el último modo y color al apagar:

```cpp
#include <EEPROM.h>

void saveSettings() {
    EEPROM.write(0, currentMode);
    EEPROM.write(1, currentColor);
}

void loadSettings() {
    currentMode = EEPROM.read(0);
    currentColor = EEPROM.read(1);
}
```

### Nivel 2: Modo Música

Agrega modo que responde a palmadas (con sensor de sonido):

```cpp
const int MODE_MUSIC = 4;
// Detectar picos de sonido para cambiar color
```

### Nivel 3: Control Serial

Agrega comandos por Serial:

```cpp
// m0-m3: cambiar modo
// c0-c7: cambiar color
// b0-100: ajustar brillo
```

---

## 📤 Entrega

### Archivos a Entregar

1. **Código fuente** (`lampara_rgb.ino`)
2. **Foto/screenshot** del circuito funcionando
3. **Video corto** (30s) mostrando todos los modos

### Criterios de Evaluación

| Criterio                      | Puntos  |
| ----------------------------- | ------- |
| Circuito correcto             | 20      |
| Código compila sin errores    | 10      |
| Todos los modos funcionan     | 25      |
| Control de brillo funciona    | 15      |
| Feedback sonoro funciona      | 10      |
| Código documentado            | 10      |
| Uso de millis() (no blocking) | 10      |
| **Total**                     | **100** |

---

## 💡 Consejos Finales

1. **Prueba por partes**: Primero RGB, luego pot, luego botones
2. **Debug con Serial**: Imprime valores para encontrar errores
3. **Verifica polaridad**: LED RGB cátodo vs ánodo común
4. **Resistencias obligatorias**: Siempre usar 220Ω por color
5. **millis() es clave**: Evita delay() en el loop principal

---

## 🔗 Recursos Adicionales

- [Documentación analogWrite()](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)
- [Tutorial RGB LED](https://docs.arduino.cc/learn/electronics/rgb-leds/)
- [Referencia millis()](https://www.arduino.cc/reference/en/language/functions/time/millis/)

---

## ➡️ Siguiente Sección

[Recursos Adicionales →](../4-recursos/README.md)
