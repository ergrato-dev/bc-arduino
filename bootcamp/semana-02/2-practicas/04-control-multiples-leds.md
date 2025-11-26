# 🔬 Práctica 04: Control de Múltiples LEDs

> **Nivel**: ⭐⭐⭐ Avanzado  
> **Tiempo estimado**: 20 minutos  
> **Tinkercad**: ✅ Compatible

---

## 🎯 Objetivos

- [ ] Manejar múltiples LEDs con arrays
- [ ] Implementar patrones de iluminación
- [ ] Usar un botón para cambiar entre modos
- [ ] Aplicar máquinas de estados en la práctica

---

## 📚 Teoría Relacionada

- [Módulo 04: Máquinas de Estados](../1-teoria/04-maquinas-de-estados.md)
- [Módulo 03: Debouncing](../1-teoria/03-debouncing.md)

---

## 🔌 Circuito

```
Arduino Uno R3
┌────────────────────────────────────────────────────────┐
│                                                        │
│   Pin 13 ────[220Ω]────►LED1 (Rojo)────┐              │
│   Pin 12 ────[220Ω]────►LED2 (Amarillo)─┤              │
│   Pin 11 ────[220Ω]────►LED3 (Verde)────┤              │
│   Pin 10 ────[220Ω]────►LED4 (Azul)─────┤              │
│                                         │              │
│   Pin 2  ──────────────BTN──────────────┤  (Modo)     │
│                                         │              │
│   GND    ───────────────────────────────┘              │
│                                                        │
└────────────────────────────────────────────────────────┘
```

### Lista de Componentes

| Cantidad | Componente     | Valor/Tipo                  |
| -------- | -------------- | --------------------------- |
| 1        | Arduino Uno R3 | -                           |
| 4        | LEDs           | Rojo, Amarillo, Verde, Azul |
| 4        | Resistencias   | 220Ω                        |
| 1        | Pulsador       | Normalmente abierto         |
| 1        | Protoboard     | -                           |
| 7        | Cables         | Jumper                      |

---

## 💻 Código

### Sistema de Modos con FSM

```cpp
/*
 * =================================================
 * PRÁCTICA 04: Control de Múltiples LEDs
 * =================================================
 *
 * ¿Qué hace?
 * Controla 4 LEDs con diferentes patrones
 * Un botón cambia entre modos de iluminación
 *
 * Modos:
 * 0. APAGADO: Todos los LEDs apagados
 * 1. TODOS: Todos los LEDs encendidos
 * 2. SECUENCIA: LEDs se encienden en secuencia
 * 3. PING_PONG: LEDs van y vienen
 * 4. ALEATORIO: Parpadeo aleatorio
 *
 * Hardware:
 * - Arduino Uno R3
 * - 4 LEDs en pines 13, 12, 11, 10
 * - Botón en pin 2
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// =================================================
// DEFINICIÓN DE PINES
// =================================================
const int BUTTON_PIN = 2;

// Array de pines de LEDs
const int LED_PINS[] = {13, 12, 11, 10};
const int NUM_LEDS = 4;

// =================================================
// CONSTANTES
// =================================================
const unsigned long DEBOUNCE_DELAY = 50;
const unsigned long PATTERN_DELAY = 200;  // Velocidad de patrones

// =================================================
// DEFINICIÓN DE MODOS (Estados)
// =================================================
enum LightMode {
    MODE_OFF,       // 0: Todos apagados
    MODE_ALL_ON,    // 1: Todos encendidos
    MODE_SEQUENCE,  // 2: Secuencia
    MODE_PINGPONG,  // 3: Ping-pong
    MODE_RANDOM,    // 4: Aleatorio
    NUM_MODES       // Total de modos (5)
};

// =================================================
// VARIABLES
// =================================================
LightMode currentMode = MODE_OFF;
int currentLed = 0;              // LED actual en secuencia
int pingPongDirection = 1;       // Dirección del ping-pong
unsigned long lastPatternUpdate = 0;

// Variables de debounce
int buttonState = HIGH;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;

// =================================================
// SETUP
// =================================================
void setup() {
    // Configurar todos los LEDs como salida
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(LED_PINS[i], OUTPUT);
        digitalWrite(LED_PINS[i], LOW);
    }

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // Semilla para números aleatorios
    randomSeed(analogRead(A0));

    Serial.begin(9600);
    Serial.println("====================================");
    Serial.println("Control de Múltiples LEDs");
    Serial.println("====================================");
    Serial.println("Presiona el botón para cambiar modo");
    printCurrentMode();
}

// =================================================
// LOOP
// =================================================
void loop() {
    // 1. Verificar cambio de modo
    if (checkButtonPress()) {
        nextMode();
    }

    // 2. Ejecutar el patrón del modo actual
    executeCurrentMode();
}

// =================================================
// FUNCIONES DE MODOS
// =================================================

/**
 * Cambia al siguiente modo
 */
void nextMode() {
    // Avanzar al siguiente modo (con wrap-around)
    currentMode = (LightMode)((currentMode + 1) % NUM_MODES);

    // Reiniciar variables de patrón
    currentLed = 0;
    pingPongDirection = 1;

    // Apagar todos los LEDs al cambiar
    allLedsOff();

    printCurrentMode();
}

/**
 * Ejecuta el patrón según el modo actual
 */
void executeCurrentMode() {
    switch (currentMode) {
        case MODE_OFF:
            modeOff();
            break;

        case MODE_ALL_ON:
            modeAllOn();
            break;

        case MODE_SEQUENCE:
            modeSequence();
            break;

        case MODE_PINGPONG:
            modePingPong();
            break;

        case MODE_RANDOM:
            modeRandom();
            break;

        default:
            break;
    }
}

/**
 * Modo 0: Todos apagados
 */
void modeOff() {
    allLedsOff();
}

/**
 * Modo 1: Todos encendidos
 */
void modeAllOn() {
    allLedsOn();
}

/**
 * Modo 2: Secuencia (uno tras otro)
 */
void modeSequence() {
    if (millis() - lastPatternUpdate >= PATTERN_DELAY) {
        // Apagar todos
        allLedsOff();

        // Encender el LED actual
        digitalWrite(LED_PINS[currentLed], HIGH);

        // Avanzar al siguiente
        currentLed = (currentLed + 1) % NUM_LEDS;

        lastPatternUpdate = millis();
    }
}

/**
 * Modo 3: Ping-Pong (va y viene)
 */
void modePingPong() {
    if (millis() - lastPatternUpdate >= PATTERN_DELAY) {
        // Apagar todos
        allLedsOff();

        // Encender el LED actual
        digitalWrite(LED_PINS[currentLed], HIGH);

        // Mover en la dirección actual
        currentLed += pingPongDirection;

        // Cambiar dirección en los extremos
        if (currentLed >= NUM_LEDS - 1) {
            pingPongDirection = -1;
            currentLed = NUM_LEDS - 1;
        } else if (currentLed <= 0) {
            pingPongDirection = 1;
            currentLed = 0;
        }

        lastPatternUpdate = millis();
    }
}

/**
 * Modo 4: Aleatorio
 */
void modeRandom() {
    if (millis() - lastPatternUpdate >= PATTERN_DELAY) {
        // Cada LED tiene 50% de probabilidad de encenderse
        for (int i = 0; i < NUM_LEDS; i++) {
            digitalWrite(LED_PINS[i], random(2));  // 0 o 1
        }

        lastPatternUpdate = millis();
    }
}

// =================================================
// FUNCIONES AUXILIARES
// =================================================

/**
 * Apaga todos los LEDs
 */
void allLedsOff() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], LOW);
    }
}

/**
 * Enciende todos los LEDs
 */
void allLedsOn() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], HIGH);
    }
}

/**
 * Imprime el modo actual en Serial Monitor
 */
void printCurrentMode() {
    Serial.print("Modo actual: ");
    switch (currentMode) {
        case MODE_OFF:      Serial.println("0 - APAGADO"); break;
        case MODE_ALL_ON:   Serial.println("1 - TODOS ENCENDIDOS"); break;
        case MODE_SEQUENCE: Serial.println("2 - SECUENCIA"); break;
        case MODE_PINGPONG: Serial.println("3 - PING-PONG"); break;
        case MODE_RANDOM:   Serial.println("4 - ALEATORIO"); break;
        default:            Serial.println("Desconocido"); break;
    }
}

/**
 * Verifica si el botón fue presionado (con debounce)
 */
bool checkButtonPress() {
    bool pressed = false;
    int reading = digitalRead(BUTTON_PIN);

    if (reading != lastButtonState) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
        if (reading != buttonState) {
            buttonState = reading;
            if (buttonState == LOW) {
                pressed = true;
            }
        }
    }

    lastButtonState = reading;
    return pressed;
}
```

---

## 🔍 Conceptos Clave

### Arrays para Pines

```cpp
// Definir un array de pines
const int LED_PINS[] = {13, 12, 11, 10};
const int NUM_LEDS = 4;

// Iterar sobre todos los LEDs
for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
}
```

### Enum para Modos

```cpp
enum LightMode {
    MODE_OFF,       // = 0
    MODE_ALL_ON,    // = 1
    MODE_SEQUENCE,  // = 2
    MODE_PINGPONG,  // = 3
    MODE_RANDOM,    // = 4
    NUM_MODES       // = 5 (útil para ciclar)
};

// Cambiar al siguiente modo
currentMode = (LightMode)((currentMode + 1) % NUM_MODES);
```

### Temporización sin delay()

```cpp
if (millis() - lastPatternUpdate >= PATTERN_DELAY) {
    // Ejecutar acción
    lastPatternUpdate = millis();
}
```

---

## 🧪 Pruebas

### Por Modo

| Modo    | Comportamiento Esperado         |
| ------- | ------------------------------- |
| 0 - OFF | Todos los LEDs apagados         |
| 1 - ALL | Todos los LEDs encendidos       |
| 2 - SEQ | LEDs se encienden 1→2→3→4→1→... |
| 3 - PP  | LEDs van 1→2→3→4→3→2→1→...      |
| 4 - RND | Parpadeo aleatorio              |

### Serial Monitor

```
====================================
Control de Múltiples LEDs
====================================
Presiona el botón para cambiar modo
Modo actual: 0 - APAGADO
Modo actual: 1 - TODOS ENCENDIDOS
Modo actual: 2 - SECUENCIA
Modo actual: 3 - PING-PONG
Modo actual: 4 - ALEATORIO
Modo actual: 0 - APAGADO
```

---

## 🎮 Desafíos Extra

### Desafío 1: Control de Velocidad

Agrega un segundo botón para cambiar la velocidad del patrón (lento, medio, rápido).

<details>
<summary>💡 Pista</summary>

Crea un array de delays y cicla entre ellos.

</details>

<details>
<summary>✅ Solución</summary>

```cpp
const int BTN_SPEED = 3;
const unsigned long SPEEDS[] = {400, 200, 100};  // Lento, Medio, Rápido
const int NUM_SPEEDS = 3;
int currentSpeed = 1;  // Empieza en medio

// Variables de debounce para BTN_SPEED
int btnSpeedState = HIGH;
int lastBtnSpeedState = HIGH;
unsigned long lastBtnSpeedDebounce = 0;

void setup() {
    pinMode(BTN_SPEED, INPUT_PULLUP);
    // ... resto del setup ...
}

void loop() {
    // Cambio de velocidad
    if (checkButton(BTN_SPEED, btnSpeedState, lastBtnSpeedState, lastBtnSpeedDebounce)) {
        currentSpeed = (currentSpeed + 1) % NUM_SPEEDS;
        Serial.print("Velocidad: ");
        Serial.println(currentSpeed == 0 ? "LENTO" : (currentSpeed == 1 ? "MEDIO" : "RÁPIDO"));
    }

    // Usar SPEEDS[currentSpeed] en lugar de PATTERN_DELAY
}
```

</details>

### Desafío 2: Modo "Acumulativo"

Nuevo modo donde cada pulsación enciende un LED más, hasta llegar a 4, luego se apagan todos y reinicia.

<details>
<summary>💡 Pista</summary>

Necesitas un contador separado del modo para saber cuántos LEDs están encendidos.

</details>

<details>
<summary>✅ Solución</summary>

```cpp
// Agregar al enum
enum LightMode {
    // ... modos anteriores ...
    MODE_ACCUMULATE,  // Nuevo modo
    NUM_MODES
};

int accumulatedLeds = 0;

void modeAccumulate() {
    // Este modo responde a pulsaciones, no a tiempo
    // Se maneja en loop()
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], i < accumulatedLeds ? HIGH : LOW);
    }
}

// En loop(), después de checkButtonPress():
if (currentMode == MODE_ACCUMULATE) {
    if (checkButtonPress()) {
        accumulatedLeds++;
        if (accumulatedLeds > NUM_LEDS) {
            accumulatedLeds = 0;
        }
    }
}
```

</details>

### Desafío 3: Guardado de Modo

Al mantener presionado el botón 3 segundos, guarda el modo actual en EEPROM y lo restaura al reiniciar.

<details>
<summary>💡 Pista</summary>

Usa la biblioteca `EEPROM.h` y detecta presión larga.

</details>

<details>
<summary>✅ Solución</summary>

```cpp
#include <EEPROM.h>

const int EEPROM_ADDRESS = 0;
unsigned long pressStartTime = 0;
const unsigned long SAVE_HOLD_TIME = 3000;

void setup() {
    // ... setup existente ...

    // Restaurar modo guardado
    int savedMode = EEPROM.read(EEPROM_ADDRESS);
    if (savedMode < NUM_MODES) {
        currentMode = (LightMode)savedMode;
        Serial.println("Modo restaurado de EEPROM");
        printCurrentMode();
    }
}

void loop() {
    int reading = digitalRead(BUTTON_PIN);

    if (reading == LOW) {
        if (pressStartTime == 0) {
            pressStartTime = millis();
        } else if ((millis() - pressStartTime) > SAVE_HOLD_TIME) {
            // Guardar en EEPROM
            EEPROM.write(EEPROM_ADDRESS, currentMode);
            Serial.println("¡Modo guardado en EEPROM!");

            // Parpadear todos los LEDs como confirmación
            for (int i = 0; i < 3; i++) {
                allLedsOn();
                delay(100);
                allLedsOff();
                delay(100);
            }

            pressStartTime = 0;
            while (digitalRead(BUTTON_PIN) == LOW);  // Esperar que suelte
        }
    } else {
        if (pressStartTime != 0 && (millis() - pressStartTime) < SAVE_HOLD_TIME) {
            // Pulsación corta - cambiar modo
            if (checkButtonPress()) {
                nextMode();
            }
        }
        pressStartTime = 0;
    }

    executeCurrentMode();
}
```

</details>

---

## ❌ Errores Comunes

### 1. Índice fuera de rango

```cpp
// ❌ Incorrecto - puede acceder LED_PINS[4]
currentLed++;
digitalWrite(LED_PINS[currentLed], HIGH);

// ✅ Correcto - limitar al rango válido
currentLed = (currentLed + 1) % NUM_LEDS;
digitalWrite(LED_PINS[currentLed], HIGH);
```

### 2. Patrones no fluidos

```cpp
// ❌ Incorrecto - delay() bloquea
void modeSequence() {
    digitalWrite(LED_PINS[currentLed], HIGH);
    delay(200);  // Bloquea, no responde al botón
}

// ✅ Correcto - millis() no bloquea
void modeSequence() {
    if (millis() - lastPatternUpdate >= PATTERN_DELAY) {
        // ... código ...
        lastPatternUpdate = millis();
    }
}
```

---

## ✅ Checklist de Completitud

- [ ] 4 LEDs conectados y funcionando
- [ ] Botón cambia entre modos
- [ ] Modo OFF funciona
- [ ] Modo ALL funciona
- [ ] Modo SEQUENCE funciona
- [ ] Modo PING-PONG funciona
- [ ] Modo RANDOM funciona
- [ ] Desafío 1: Control de velocidad (opcional)
- [ ] Desafío 2: Modo acumulativo (opcional)
- [ ] Desafío 3: Guardado EEPROM (opcional)

---

## ➡️ Siguiente Sección

[Proyecto Semanal: Panel de Control →](../3-proyecto/README.md)
