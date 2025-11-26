# 🔬 Práctica 02: Toggle LED con Debounce

> **Nivel**: ⭐⭐ Intermedio  
> **Tiempo estimado**: 25 minutos  
> **Tinkercad**: ✅ Compatible

---

## 🎯 Objetivos

- [ ] Implementar debounce con millis()
- [ ] Crear un sistema de toggle (encender/apagar con cada pulsación)
- [ ] Detectar flancos de bajada (momento de presión)
- [ ] Evitar el uso de delay() para código no bloqueante

---

## 📚 Teoría Relacionada

- [Módulo 03: Debouncing](../1-teoria/03-debouncing.md)
- [Módulo 04: Máquinas de Estados](../1-teoria/04-maquinas-de-estados.md)

---

## 🔌 Circuito

El circuito es idéntico a la Práctica 01:

```
Arduino Uno R3
┌─────────────────────────────────────────┐
│                                         │
│   Pin 13 ────[220Ω]────►LED────┐       │
│                                │       │
│   Pin 2  ──────────────BTN─────┤       │
│                                │       │
│   GND    ──────────────────────┘       │
│                                         │
└─────────────────────────────────────────┘
```

### Lista de Componentes

| Cantidad | Componente | Valor/Tipo |
|----------|------------|------------|
| 1 | Arduino Uno R3 | - |
| 1 | LED | Cualquier color |
| 1 | Resistencia | 220Ω |
| 1 | Pulsador | Normalmente abierto |
| 1 | Protoboard | - |
| 4 | Cables | Jumper |

---

## 💻 Código

### Código Principal con Debounce

```cpp
/*
 * =================================================
 * PRÁCTICA 02: Toggle LED con Debounce
 * =================================================
 *
 * ¿Qué hace?
 * Alterna el estado del LED con cada pulsación del botón
 * Una pulsación = encender, otra pulsación = apagar
 *
 * ¿Para qué?
 * Aprender a implementar debounce y detectar flancos
 *
 * ¿Cómo funciona?
 * 1. Lee el botón constantemente
 * 2. Si detecta cambio, inicia temporizador
 * 3. Espera 50ms de estabilidad
 * 4. Confirma el cambio y actúa solo en flanco de bajada
 * 5. Toggle del LED (invierte su estado actual)
 *
 * Hardware:
 * - Arduino Uno R3
 * - LED en pin 13 con resistencia 220Ω
 * - Botón entre pin 2 y GND
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// =================================================
// DEFINICIÓN DE PINES
// =================================================
const int BUTTON_PIN = 2;
const int LED_PIN = 13;

// =================================================
// CONSTANTES DE CONFIGURACIÓN
// =================================================
const unsigned long DEBOUNCE_DELAY = 50;  // 50ms de estabilización

// =================================================
// VARIABLES DE ESTADO
// =================================================
bool ledState = false;              // Estado actual del LED

// Variables para debounce
int buttonState = HIGH;             // Estado confirmado del botón
int lastButtonState = HIGH;         // Última lectura (puede tener rebotes)
unsigned long lastDebounceTime = 0; // Momento del último cambio

// =================================================
// SETUP
// =================================================
void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

    // Estado inicial del LED
    digitalWrite(LED_PIN, ledState);

    Serial.begin(9600);
    Serial.println("=================================");
    Serial.println("Práctica 02: Toggle LED");
    Serial.println("=================================");
    Serial.println("Presiona el botón para alternar");
    Serial.println("Estado inicial: LED APAGADO");
    Serial.println("---------------------------------");
}

// =================================================
// LOOP
// =================================================
void loop() {
    // 1. Leer el estado actual del pin
    int reading = digitalRead(BUTTON_PIN);

    // 2. Detectar si hubo algún cambio (potencial rebote)
    if (reading != lastButtonState) {
        // Reiniciar el temporizador de debounce
        lastDebounceTime = millis();
    }

    // 3. Verificar si pasó suficiente tiempo desde el último cambio
    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
        // El estado ha sido estable por más de DEBOUNCE_DELAY ms

        // 4. Verificar si realmente cambió el estado confirmado
        if (reading != buttonState) {
            // Actualizar el estado confirmado
            buttonState = reading;

            // 5. Actuar solo en el flanco de BAJADA (botón presionado)
            // Con INPUT_PULLUP: LOW = presionado
            if (buttonState == LOW) {
                // Toggle: invertir el estado del LED
                ledState = !ledState;

                // Actualizar el LED físico
                digitalWrite(LED_PIN, ledState);

                // Reportar al Serial Monitor
                Serial.print("Toggle! LED ahora: ");
                Serial.println(ledState ? "ENCENDIDO" : "APAGADO");
            }
        }
    }

    // 6. Guardar la lectura actual para la próxima iteración
    lastButtonState = reading;
}
```

---

## 🔍 Explicación Detallada

### Variables del Debounce

```cpp
int buttonState = HIGH;             // Estado CONFIRMADO (después de debounce)
int lastButtonState = HIGH;         // Última LECTURA (puede tener rebotes)
unsigned long lastDebounceTime = 0; // Timestamp del último cambio
```

### Flujo del Algoritmo

```
┌──────────────────────────────────────────────────────────────┐
│                                                              │
│   reading = digitalRead(BUTTON_PIN)                          │
│                    │                                         │
│                    ▼                                         │
│   ┌────────────────────────────────┐                        │
│   │ ¿reading != lastButtonState?   │                        │
│   └────────────────┬───────────────┘                        │
│              Sí    │    No                                   │
│              ▼     │    │                                    │
│   lastDebounceTime │    │                                    │
│   = millis()       │    │                                    │
│              │     │    │                                    │
│              └─────┼────┘                                    │
│                    │                                         │
│                    ▼                                         │
│   ┌────────────────────────────────────────┐                │
│   │ ¿(millis() - lastDebounceTime)         │                │
│   │  > DEBOUNCE_DELAY?                     │                │
│   └────────────────┬───────────────────────┘                │
│              Sí    │    No                                   │
│              ▼     │    │                                    │
│   ┌─────────────────────────┐              │                │
│   │ ¿reading != buttonState?│              │                │
│   └────────────┬────────────┘              │                │
│          Sí    │    No                     │                │
│          ▼     │    │                      │                │
│   buttonState  │    │                      │                │
│   = reading    │    │                      │                │
│          │     │    │                      │                │
│          ▼     │    │                      │                │
│   ┌──────────────────────┐                 │                │
│   │ ¿buttonState == LOW? │                 │                │
│   └──────────┬───────────┘                 │                │
│        Sí    │    No                       │                │
│        ▼     │    │                        │                │
│   ledState   │    │                        │                │
│   = !ledState│    │                        │                │
│   (TOGGLE)   │    │                        │                │
│        │     │    │                        │                │
│        └─────┴────┴────────────────────────┘                │
│                    │                                         │
│                    ▼                                         │
│   lastButtonState = reading                                  │
│                                                              │
└──────────────────────────────────────────────────────────────┘
```

### ¿Por qué detectar solo el flanco de bajada?

```
Pulsación del botón con INPUT_PULLUP:

HIGH ─────┐          ┌─────────── No presionado
          │          │
          │          │
LOW       └──────────┘            Presionado
          ↑          ↑
          │          │
     Flanco de   Flanco de
      BAJADA      SUBIDA
    (presión)   (soltar)

Si actuamos en ambos flancos:
- 1 pulsación = 2 toggles = LED vuelve al estado original ❌

Si actuamos solo en flanco de bajada:
- 1 pulsación = 1 toggle = LED cambia de estado ✅
```

---

## 🧪 Pruebas

### Verificación Básica

1. ✅ LED inicia **apagado**
2. ✅ Primera pulsación → LED **encendido**
3. ✅ Segunda pulsación → LED **apagado**
4. ✅ Pulsaciones rápidas responden correctamente
5. ✅ No hay toggles múltiples por rebote

### Prueba con Serial Monitor

```
Salida esperada:
---
=================================
Práctica 02: Toggle LED
=================================
Presiona el botón para alternar
Estado inicial: LED APAGADO
---------------------------------
Toggle! LED ahora: ENCENDIDO
Toggle! LED ahora: APAGADO
Toggle! LED ahora: ENCENDIDO
```

---

## 🎮 Desafíos Extra

### Desafío 1: Doble Clic
Implementa detección de doble clic: si presionas dos veces rápido (menos de 500ms), el LED parpadea 3 veces.

<details>
<summary>💡 Pista</summary>

Guarda el tiempo de la última pulsación y compara con la pulsación actual.

</details>

<details>
<summary>✅ Solución</summary>

```cpp
unsigned long lastPressTime = 0;
const unsigned long DOUBLE_CLICK_TIME = 500;

// Dentro del if (buttonState == LOW):
unsigned long currentTime = millis();

if ((currentTime - lastPressTime) < DOUBLE_CLICK_TIME) {
    // Doble clic detectado!
    for (int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
    }
} else {
    // Clic simple - toggle normal
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
}

lastPressTime = currentTime;
```

</details>

### Desafío 2: Presión Larga
Si mantienes presionado más de 2 segundos, el LED parpadea rápidamente mientras está presionado.

<details>
<summary>💡 Pista</summary>

Guarda el tiempo cuando se presiona y verifica cuánto tiempo ha pasado mientras sigue presionado.

</details>

<details>
<summary>✅ Solución</summary>

```cpp
unsigned long pressStartTime = 0;
bool isLongPress = false;

void loop() {
    // ... código de debounce existente ...

    // Después de confirmar que el botón está presionado
    if (buttonState == LOW) {
        if (pressStartTime == 0) {
            pressStartTime = millis();
        }

        if ((millis() - pressStartTime) > 2000) {
            // Presión larga - parpadeo rápido
            digitalWrite(LED_PIN, !digitalRead(LED_PIN));
            delay(50);
            isLongPress = true;
        }
    } else {
        if (!isLongPress && pressStartTime != 0) {
            // Fue presión corta - toggle
            ledState = !ledState;
            digitalWrite(LED_PIN, ledState);
        }
        pressStartTime = 0;
        isLongPress = false;
    }
}
```

</details>

### Desafío 3: Contador de Estado
Después de 5 toggles, el LED parpadea 5 veces y reinicia el contador.

<details>
<summary>💡 Pista</summary>

Usa una variable contador que incremente con cada toggle.

</details>

<details>
<summary>✅ Solución</summary>

```cpp
int toggleCount = 0;

// Dentro del if (buttonState == LOW):
ledState = !ledState;
digitalWrite(LED_PIN, ledState);
toggleCount++;

Serial.print("Toggle #");
Serial.println(toggleCount);

if (toggleCount >= 5) {
    Serial.println("¡5 toggles! Celebrando...");
    for (int i = 0; i < 5; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
    }
    toggleCount = 0;
    ledState = false;
    digitalWrite(LED_PIN, LOW);
}
```

</details>

---

## ❌ Errores Comunes

### 1. Toggle múltiple con una pulsación
**Causa**: No detectar el flanco, actuar en el estado
```cpp
// ❌ Incorrecto - Actúa mientras está presionado
if (buttonState == LOW) {
    ledState = !ledState;  // Se ejecuta miles de veces por segundo
}

// ✅ Correcto - Solo cuando CAMBIA a LOW
if (reading != buttonState) {
    buttonState = reading;
    if (buttonState == LOW) {
        ledState = !ledState;  // Solo una vez por pulsación
    }
}
```

### 2. Olvidar actualizar lastButtonState
**Causa**: El algoritmo no puede detectar cambios
```cpp
// ❌ Incorrecto - Falta la última línea
void loop() {
    int reading = digitalRead(BUTTON_PIN);
    if (reading != lastButtonState) {
        lastDebounceTime = millis();
    }
    // ... resto del código ...
    // ¡Falta! lastButtonState = reading;
}
```

### 3. Usar delay() para debounce
**Causa**: Bloquea todo el programa
```cpp
// ❌ Incorrecto - delay() bloqueante
if (digitalRead(BUTTON_PIN) == LOW) {
    delay(50);  // El programa "se congela"
    ledState = !ledState;
}

// ✅ Correcto - millis() no bloqueante
if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    // El programa sigue ejecutándose
}
```

---

## ✅ Checklist de Completitud

- [ ] Circuito funcionando
- [ ] Toggle funciona correctamente
- [ ] Sin toggles múltiples por rebote
- [ ] Serial Monitor muestra estados
- [ ] Desafío 1: Doble clic (opcional)
- [ ] Desafío 2: Presión larga (opcional)
- [ ] Desafío 3: Contador (opcional)

---

## ➡️ Siguiente Práctica

[Práctica 03: Contador de Pulsaciones →](./03-contador-pulsaciones.md)
