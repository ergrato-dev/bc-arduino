# 🔬 Práctica 03: Contador de Pulsaciones

> **Nivel**: ⭐⭐ Intermedio  
> **Tiempo estimado**: 25 minutos  
> **Tinkercad**: ✅ Compatible

---

## 🎯 Objetivos

- [ ] Implementar un contador de pulsaciones con debounce
- [ ] Mostrar el conteo en Serial Monitor
- [ ] Agregar un segundo botón para decrementar
- [ ] Limitar el rango del contador (0-9)

---

## 📚 Teoría Relacionada

- [Módulo 03: Debouncing](../1-teoria/03-debouncing.md)
- [Módulo 02: Resistencias Pull-up/down](../1-teoria/02-resistencias-pull-up-down.md)

---

## 🔌 Circuito

```
Arduino Uno R3
┌──────────────────────────────────────────────────┐
│                                                  │
│   Pin 13 ────[220Ω]────►LED────┐                │
│                                │                │
│   Pin 2  ──────────────BTN+────┤  (Incrementar) │
│                                │                │
│   Pin 3  ──────────────BTN-────┤  (Decrementar) │
│                                │                │
│   GND    ──────────────────────┘                │
│                                                  │
└──────────────────────────────────────────────────┘
```

### Lista de Componentes

| Cantidad | Componente | Valor/Tipo |
|----------|------------|------------|
| 1 | Arduino Uno R3 | - |
| 1 | LED | Cualquier color |
| 1 | Resistencia | 220Ω |
| 2 | Pulsadores | Normalmente abiertos |
| 1 | Protoboard | - |
| 5 | Cables | Jumper |

---

## 💻 Código

### Versión Básica: Un Botón

```cpp
/*
 * =================================================
 * PRÁCTICA 03: Contador de Pulsaciones (Básico)
 * =================================================
 *
 * ¿Qué hace?
 * Cuenta las pulsaciones del botón y muestra en Serial
 *
 * ¿Para qué?
 * Verificar que el debounce funciona correctamente
 * Una pulsación física = exactamente +1 en el contador
 *
 * Hardware:
 * - Arduino Uno R3
 * - Botón en pin 2 (INPUT_PULLUP)
 * - LED en pin 13 (parpadea al contar)
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
// CONSTANTES
// =================================================
const unsigned long DEBOUNCE_DELAY = 50;
const int MAX_COUNT = 99;  // Máximo valor del contador

// =================================================
// VARIABLES
// =================================================
int counter = 0;                    // Contador de pulsaciones

// Variables de debounce
int buttonState = HIGH;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;

// =================================================
// SETUP
// =================================================
void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

    Serial.begin(9600);
    Serial.println("============================");
    Serial.println("Contador de Pulsaciones");
    Serial.println("============================");
    Serial.println("Presiona el botón para contar");
    Serial.print("Contador: ");
    Serial.println(counter);
    Serial.println("----------------------------");
}

// =================================================
// LOOP
// =================================================
void loop() {
    // Verificar si hubo pulsación válida
    if (checkButtonPress()) {
        // Incrementar contador
        counter++;

        // Limitar al máximo
        if (counter > MAX_COUNT) {
            counter = 0;  // Reiniciar al llegar al máximo
            Serial.println("¡Contador reiniciado!");
        }

        // Mostrar en Serial
        Serial.print("Contador: ");
        Serial.println(counter);

        // Parpadeo visual de confirmación
        blinkLED();
    }
}

// =================================================
// FUNCIONES AUXILIARES
// =================================================

/**
 * Verifica si el botón fue presionado (con debounce)
 * Retorna true solo en el momento exacto de la pulsación
 */
bool checkButtonPress() {
    bool pressed = false;
    int reading = digitalRead(BUTTON_PIN);

    // Detectar cambio
    if (reading != lastButtonState) {
        lastDebounceTime = millis();
    }

    // Verificar estabilidad
    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
        if (reading != buttonState) {
            buttonState = reading;

            // Detectar flanco de bajada (presión)
            if (buttonState == LOW) {
                pressed = true;
            }
        }
    }

    lastButtonState = reading;
    return pressed;
}

/**
 * Parpadeo rápido del LED como confirmación visual
 */
void blinkLED() {
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
}
```

### Versión Completa: Dos Botones (Incrementar/Decrementar)

```cpp
/*
 * =================================================
 * PRÁCTICA 03: Contador Bidireccional
 * =================================================
 *
 * ¿Qué hace?
 * Botón 1: Incrementa el contador
 * Botón 2: Decrementa el contador
 * Rango limitado de 0 a 9
 *
 * Hardware:
 * - Arduino Uno R3
 * - Botón incremento en pin 2
 * - Botón decremento en pin 3
 * - LED en pin 13
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// =================================================
// DEFINICIÓN DE PINES
// =================================================
const int BTN_INCREMENT = 2;  // Botón para sumar
const int BTN_DECREMENT = 3;  // Botón para restar
const int LED_PIN = 13;

// =================================================
// CONSTANTES
// =================================================
const unsigned long DEBOUNCE_DELAY = 50;
const int MIN_COUNT = 0;
const int MAX_COUNT = 9;

// =================================================
// VARIABLES
// =================================================
int counter = 0;

// Variables de debounce para botón incremento
int btnIncState = HIGH;
int lastBtnIncState = HIGH;
unsigned long lastBtnIncDebounce = 0;

// Variables de debounce para botón decremento
int btnDecState = HIGH;
int lastBtnDecState = HIGH;
unsigned long lastBtnDecDebounce = 0;

// =================================================
// SETUP
// =================================================
void setup() {
    pinMode(BTN_INCREMENT, INPUT_PULLUP);
    pinMode(BTN_DECREMENT, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

    Serial.begin(9600);
    Serial.println("================================");
    Serial.println("Contador Bidireccional (0-9)");
    Serial.println("================================");
    Serial.println("BTN Pin 2: Incrementar (+)");
    Serial.println("BTN Pin 3: Decrementar (-)");
    Serial.println("--------------------------------");
    printCounter();
}

// =================================================
// LOOP
// =================================================
void loop() {
    // Verificar botón de incremento
    if (checkButton(BTN_INCREMENT, btnIncState, lastBtnIncState, lastBtnIncDebounce)) {
        if (counter < MAX_COUNT) {
            counter++;
            Serial.print("[+] ");
            printCounter();
            blinkLED(1);  // 1 parpadeo
        } else {
            Serial.println("[!] Máximo alcanzado (9)");
            blinkLED(3);  // 3 parpadeos de advertencia
        }
    }

    // Verificar botón de decremento
    if (checkButton(BTN_DECREMENT, btnDecState, lastBtnDecState, lastBtnDecDebounce)) {
        if (counter > MIN_COUNT) {
            counter--;
            Serial.print("[-] ");
            printCounter();
            blinkLED(1);
        } else {
            Serial.println("[!] Mínimo alcanzado (0)");
            blinkLED(3);
        }
    }
}

// =================================================
// FUNCIONES AUXILIARES
// =================================================

/**
 * Verifica si un botón fue presionado (genérico)
 * Usa referencias para manejar múltiples botones
 */
bool checkButton(int pin, int &state, int &lastState, unsigned long &lastDebounce) {
    bool pressed = false;
    int reading = digitalRead(pin);

    if (reading != lastState) {
        lastDebounce = millis();
    }

    if ((millis() - lastDebounce) > DEBOUNCE_DELAY) {
        if (reading != state) {
            state = reading;
            if (state == LOW) {
                pressed = true;
            }
        }
    }

    lastState = reading;
    return pressed;
}

/**
 * Imprime el contador en formato visual
 */
void printCounter() {
    Serial.print("Contador: [");
    Serial.print(counter);
    Serial.println("]");
}

/**
 * Parpadea el LED n veces
 */
void blinkLED(int times) {
    for (int i = 0; i < times; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(50);
        digitalWrite(LED_PIN, LOW);
        if (i < times - 1) delay(50);
    }
}
```

---

## 🔍 Explicación: Función Genérica de Debounce

Para manejar múltiples botones, usamos **referencias** en C++:

```cpp
bool checkButton(int pin, int &state, int &lastState, unsigned long &lastDebounce)
```

| Parámetro | Tipo | Descripción |
|-----------|------|-------------|
| `pin` | `int` | Número del pin (valor) |
| `&state` | `int&` | Referencia al estado confirmado |
| `&lastState` | `int&` | Referencia a la última lectura |
| `&lastDebounce` | `unsigned long&` | Referencia al timestamp |

> 💡 El símbolo `&` crea una **referencia**: la función modifica directamente las variables originales, no copias.

---

## 🧪 Pruebas

### Prueba 1: Contador Básico (Un Botón)
1. ✅ Presionar 5 veces → Contador = 5
2. ✅ Presionar muy rápido → Cada pulsación cuenta 1
3. ✅ LED parpadea con cada conteo

### Prueba 2: Contador Bidireccional
1. ✅ Incrementar de 0 a 5 → Contador = 5
2. ✅ Decrementar a 3 → Contador = 3
3. ✅ Decrementar hasta 0 → Se detiene en 0
4. ✅ Incrementar hasta 9 → Se detiene en 9

### Serial Monitor Esperado

```
================================
Contador Bidireccional (0-9)
================================
BTN Pin 2: Incrementar (+)
BTN Pin 3: Decrementar (-)
--------------------------------
Contador: [0]
[+] Contador: [1]
[+] Contador: [2]
[-] Contador: [1]
[+] Contador: [2]
[+] Contador: [3]
```

---

## 🎮 Desafíos Extra

### Desafío 1: Reinicio con Ambos Botones
Presionar ambos botones simultáneamente reinicia el contador a 0.

<details>
<summary>💡 Pista</summary>

Verifica el estado de ambos botones directamente (sin debounce para esto).

</details>

<details>
<summary>✅ Solución</summary>

```cpp
void loop() {
    // Verificar reinicio (ambos botones presionados)
    if (digitalRead(BTN_INCREMENT) == LOW && digitalRead(BTN_DECREMENT) == LOW) {
        delay(50);  // Pequeño debounce
        if (digitalRead(BTN_INCREMENT) == LOW && digitalRead(BTN_DECREMENT) == LOW) {
            counter = 0;
            Serial.println("[R] Contador reiniciado a 0");
            blinkLED(5);

            // Esperar a que se suelten los botones
            while (digitalRead(BTN_INCREMENT) == LOW || digitalRead(BTN_DECREMENT) == LOW) {
                delay(10);
            }
        }
        return;  // Salir del loop para evitar contar
    }

    // ... resto del código de incremento/decremento ...
}
```

</details>

### Desafío 2: Auto-Incremento
Si mantienes presionado el botón de incremento más de 1 segundo, el contador sube automáticamente cada 200ms.

<details>
<summary>💡 Pista</summary>

Registra el tiempo de inicio de presión y verifica si ha pasado el umbral.

</details>

<details>
<summary>✅ Solución</summary>

```cpp
unsigned long pressStartTime = 0;
unsigned long lastAutoIncrement = 0;
const unsigned long HOLD_THRESHOLD = 1000;   // 1 segundo
const unsigned long AUTO_INCREMENT_DELAY = 200;  // 200ms

void loop() {
    int incReading = digitalRead(BTN_INCREMENT);

    if (incReading == LOW) {
        // Botón presionado
        if (pressStartTime == 0) {
            pressStartTime = millis();
        }

        // Verificar si es presión larga
        if ((millis() - pressStartTime) > HOLD_THRESHOLD) {
            // Auto-incremento
            if ((millis() - lastAutoIncrement) > AUTO_INCREMENT_DELAY) {
                if (counter < MAX_COUNT) {
                    counter++;
                    Serial.print("[AUTO+] ");
                    printCounter();
                    blinkLED(1);
                }
                lastAutoIncrement = millis();
            }
        }
    } else {
        // Botón suelto - verificar si fue pulsación corta
        if (pressStartTime != 0 && (millis() - pressStartTime) < HOLD_THRESHOLD) {
            // Fue pulsación corta, el checkButton normal se encarga
        }
        pressStartTime = 0;
    }

    // ... resto del código normal con checkButton ...
}
```

</details>

### Desafío 3: Modo Cíclico
Agregar un tercer botón que cambie entre modo "limitado" (0-9) y modo "cíclico" (después de 9 viene 0, antes de 0 viene 9).

<details>
<summary>💡 Pista</summary>

Usa una variable booleana para el modo y el operador módulo `%`.

</details>

<details>
<summary>✅ Solución</summary>

```cpp
const int BTN_MODE = 4;
bool cyclicMode = false;

// En setup:
pinMode(BTN_MODE, INPUT_PULLUP);

// Variables de debounce para BTN_MODE
int btnModeState = HIGH;
int lastBtnModeState = HIGH;
unsigned long lastBtnModeDebounce = 0;

void loop() {
    // Verificar cambio de modo
    if (checkButton(BTN_MODE, btnModeState, lastBtnModeState, lastBtnModeDebounce)) {
        cyclicMode = !cyclicMode;
        Serial.print("[M] Modo: ");
        Serial.println(cyclicMode ? "CÍCLICO" : "LIMITADO");
        blinkLED(2);
    }

    // Incremento
    if (checkButton(BTN_INCREMENT, btnIncState, lastBtnIncState, lastBtnIncDebounce)) {
        if (cyclicMode) {
            counter = (counter + 1) % 10;  // 0-9, después de 9 viene 0
        } else {
            if (counter < MAX_COUNT) counter++;
        }
        printCounter();
    }

    // Decremento
    if (checkButton(BTN_DECREMENT, btnDecState, lastBtnDecState, lastBtnDecDebounce)) {
        if (cyclicMode) {
            counter = (counter - 1 + 10) % 10;  // Antes de 0 viene 9
        } else {
            if (counter > MIN_COUNT) counter--;
        }
        printCounter();
    }
}
```

</details>

---

## ❌ Errores Comunes

### 1. Contador salta valores
**Causa**: Debounce insuficiente o mal implementado
```cpp
// Verificar con mensajes de debug
Serial.print("Reading: ");
Serial.print(reading);
Serial.print(" | State: ");
Serial.println(state);
```

### 2. Botones interfieren entre sí
**Causa**: Variables de debounce compartidas
```cpp
// ❌ Incorrecto - Mismas variables para ambos botones
int buttonState = HIGH;  // Compartida

// ✅ Correcto - Variables separadas por botón
int btnIncState = HIGH;
int btnDecState = HIGH;
```

---

## ✅ Checklist de Completitud

- [ ] Contador básico funcionando
- [ ] Contador bidireccional funcionando
- [ ] Límites 0-9 respetados
- [ ] LED parpadea como confirmación
- [ ] Serial Monitor muestra valores correctos
- [ ] Desafío 1: Reinicio (opcional)
- [ ] Desafío 2: Auto-incremento (opcional)
- [ ] Desafío 3: Modo cíclico (opcional)

---

## ➡️ Siguiente Práctica

[Práctica 04: Control Múltiples LEDs →](./04-control-multiples-leds.md)
