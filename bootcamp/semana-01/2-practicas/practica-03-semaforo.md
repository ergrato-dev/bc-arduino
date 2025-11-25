# 💻 Práctica 03: Semáforo Básico

> ⏱️ **Tiempo estimado:** 25 minutos  
> ⭐⭐ **Dificultad:** Básico  
> 🎯 **Compatibilidad Tinkercad:** ✅

---

## 📋 Información General

| Campo               | Valor                                                        |
| ------------------- | ------------------------------------------------------------ |
| **Dificultad**      | ⭐⭐ Básico                                                  |
| **Tiempo estimado** | 25 minutos                                                   |
| **Componentes**     | Arduino Uno, 3 LEDs (R/Y/G), 3 Resistencias 220Ω, Protoboard |
| **Conceptos**       | Secuencias, múltiples salidas, tiempos, funciones            |

---

## 🎯 Objetivos

Al completar esta práctica, serás capaz de:

- [ ] Controlar múltiples LEDs simultáneamente
- [ ] Crear secuencias temporizadas
- [ ] Organizar código usando funciones
- [ ] Aplicar tiempos realistas de semáforo

---

## 📝 Descripción

Construirás un **semáforo funcional** con tres LEDs (rojo, amarillo, verde) que sigue la secuencia estándar de tráfico. Esta práctica refuerza el manejo de múltiples salidas y la organización del código.

---

## 🔧 Requisitos Técnicos

### Componentes

| Componente       | Cantidad | Notas       |
| ---------------- | -------- | ----------- |
| Arduino Uno R3   | 1        |             |
| LED Rojo         | 1        |             |
| LED Amarillo     | 1        |             |
| LED Verde        | 1        |             |
| Resistencia 220Ω | 3        | Una por LED |
| Protoboard       | 1        |             |
| Cables jumper    | 6        |             |

---

## 📐 Diagrama del Circuito

### Esquemático

```
                           ARDUINO UNO
    ┌─────────────────────────────────────────────────┐
    │                                                 │
    │  Pin 10 (ROJO)    ────────────┐                │
    │  Pin 9  (AMARILLO)────────────│───┐            │
    │  Pin 8  (VERDE)   ────────────│───│───┐        │
    │                               │   │   │        │
    │  GND ─────────────────────────│───│───│──┐     │
    │                               │   │   │  │     │
    └───────────────────────────────│───│───│──│─────┘
                                    │   │   │  │
    ┌───────────────────────────────│───│───│──│─────┐
    │            PROTOBOARD         │   │   │  │     │
    │                               │   │   │  │     │
    │   Pin 10 ──[220Ω]──[LED🔴]────│───│───│──┘     │
    │                               │   │   │        │
    │   Pin 9  ──[220Ω]──[LED🟡]────│───│───┘        │
    │                               │   │            │
    │   Pin 8  ──[220Ω]──[LED🟢]────│───┘            │
    │                               │                │
    │   Todos los cátodos ──────────┴──── GND        │
    │                                                 │
    └─────────────────────────────────────────────────┘
```

### Vista de Protoboard

```
┌─────────────────────────────────────────────────────────────┐
│                       PROTOBOARD                            │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   (+) ●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●  (no usado)           │
│   (-) ●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●  ◄── GND Arduino      │
│                                                             │
│       a b c d e     f g h i j                               │
│    1  ●─●─●─●─●     ●─●─●─●─●   ◄── Pin 10                 │
│    2  ● ●[===]●     ● ● ● ● ●       Resistencia 220Ω       │
│    3  ● ●[LED]●     ● ● ● ● ●       LED Rojo 🔴            │
│    4  ●─●─●─●─●─────●─●─●─●─●   ◄── Conectar a (-)        │
│    5  ● ● ● ● ●     ● ● ● ● ●                              │
│    6  ●─●─●─●─●     ●─●─●─●─●   ◄── Pin 9                  │
│    7  ● ●[===]●     ● ● ● ● ●       Resistencia 220Ω       │
│    8  ● ●[LED]●     ● ● ● ● ●       LED Amarillo 🟡        │
│    9  ●─●─●─●─●─────●─●─●─●─●   ◄── Conectar a (-)        │
│   10  ● ● ● ● ●     ● ● ● ● ●                              │
│   11  ●─●─●─●─●     ●─●─●─●─●   ◄── Pin 8                  │
│   12  ● ●[===]●     ● ● ● ● ●       Resistencia 220Ω       │
│   13  ● ●[LED]●     ● ● ● ● ●       LED Verde 🟢           │
│   14  ●─●─●─●─●─────●─●─●─●─●   ◄── Conectar a (-)        │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Tabla de Conexiones

| Componente     | Terminal   | Conectar a                |
| -------------- | ---------- | ------------------------- |
| Arduino Pin 10 | -          | Resistencia 1, terminal A |
| Resistencia 1  | Terminal B | LED Rojo, Ánodo (+)       |
| LED Rojo       | Cátodo (-) | Línea GND                 |
| Arduino Pin 9  | -          | Resistencia 2, terminal A |
| Resistencia 2  | Terminal B | LED Amarillo, Ánodo (+)   |
| LED Amarillo   | Cátodo (-) | Línea GND                 |
| Arduino Pin 8  | -          | Resistencia 3, terminal A |
| Resistencia 3  | Terminal B | LED Verde, Ánodo (+)      |
| LED Verde      | Cátodo (-) | Línea GND                 |
| Arduino GND    | -          | Línea (-) de protoboard   |

---

## 📋 Instrucciones

### Paso 1: Armar el Circuito

1. Coloca los 3 LEDs en la protoboard (separados para que se vea como semáforo)
2. Conecta una resistencia de 220Ω a cada LED
3. Conecta los cables desde Arduino a cada resistencia
4. Conecta todos los cátodos (patas cortas) a GND

### Paso 2: Escribir el Código

```cpp
/*
 * =================================================
 * PRÁCTICA 03: Semáforo Básico
 * =================================================
 *
 * ¿Qué hace?
 * Simula un semáforo de tráfico con la secuencia:
 * Verde → Amarillo → Rojo → (repite)
 *
 * ¿Para qué?
 * - Controlar múltiples salidas
 * - Crear secuencias temporizadas
 * - Organizar código con funciones
 * - Simular un sistema del mundo real
 *
 * ¿Cómo funciona?
 * 1. Verde encendido por 5 segundos (paso de vehículos)
 * 2. Amarillo encendido por 2 segundos (precaución)
 * 3. Rojo encendido por 5 segundos (alto)
 * 4. Repite el ciclo
 *
 * Hardware requerido:
 * - Arduino Uno R3
 * - 3 LEDs (Rojo, Amarillo, Verde)
 * - 3 Resistencias 220Ω
 * - Protoboard y cables
 *
 * Conexiones:
 * - Pin 10 → Resistencia → LED Rojo
 * - Pin 9  → Resistencia → LED Amarillo
 * - Pin 8  → Resistencia → LED Verde
 * - Todos los cátodos → GND
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// CONSTANTES - Pines
// ==================================================
const int PIN_RED = 10;     // LED Rojo
const int PIN_YELLOW = 9;   // LED Amarillo
const int PIN_GREEN = 8;    // LED Verde

// ==================================================
// CONSTANTES - Tiempos (en milisegundos)
// ==================================================
const int TIME_GREEN = 5000;   // 5 segundos
const int TIME_YELLOW = 2000;  // 2 segundos
const int TIME_RED = 5000;     // 5 segundos

// ==================================================
// SETUP
// ==================================================
void setup() {
    // Configurar todos los pines como salida
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_YELLOW, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);

    // Iniciar con todos los LEDs apagados
    turnAllOff();

    // Iniciar Serial para debugging
    Serial.begin(9600);
    Serial.println("=========================");
    Serial.println("   SEMÁFORO INICIADO");
    Serial.println("=========================");
}

// ==================================================
// LOOP
// ==================================================
void loop() {
    // Fase 1: Verde (Paso permitido)
    greenPhase();

    // Fase 2: Amarillo (Precaución)
    yellowPhase();

    // Fase 3: Rojo (Alto)
    redPhase();
}

// ==================================================
// FUNCIONES AUXILIARES
// ==================================================

/**
 * Apaga todos los LEDs
 * Se usa para asegurar un estado limpio antes de cada fase
 */
void turnAllOff() {
    digitalWrite(PIN_RED, LOW);
    digitalWrite(PIN_YELLOW, LOW);
    digitalWrite(PIN_GREEN, LOW);
}

/**
 * Fase Verde: Paso permitido
 * - Enciende LED verde
 * - Mantiene por TIME_GREEN milisegundos
 */
void greenPhase() {
    turnAllOff();
    digitalWrite(PIN_GREEN, HIGH);
    Serial.println("🟢 VERDE - Paso permitido");
    delay(TIME_GREEN);
}

/**
 * Fase Amarillo: Precaución
 * - Enciende LED amarillo
 * - Mantiene por TIME_YELLOW milisegundos
 */
void yellowPhase() {
    turnAllOff();
    digitalWrite(PIN_YELLOW, HIGH);
    Serial.println("🟡 AMARILLO - Precaución");
    delay(TIME_YELLOW);
}

/**
 * Fase Rojo: Alto
 * - Enciende LED rojo
 * - Mantiene por TIME_RED milisegundos
 */
void redPhase() {
    turnAllOff();
    digitalWrite(PIN_RED, HIGH);
    Serial.println("🔴 ROJO - Alto");
    delay(TIME_RED);
}
```

### Paso 3: Probar el Circuito

1. Verifica las conexiones (especialmente polaridad de LEDs)
2. Inicia la simulación
3. Observa la secuencia: Verde → Amarillo → Rojo
4. Abre Serial Monitor para ver los mensajes

---

## 🎨 Resultado Esperado

### Secuencia Visual

```
┌─────────────────────────────────────────────────────────────┐
│                    SECUENCIA DEL SEMÁFORO                   │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   Tiempo:    0s      5s      7s      12s     17s     19s   │
│              │       │       │       │       │       │     │
│   ROJO:      ○       ○       ○       ●●●●●●●●○       ○     │
│   AMARILLO:  ○       ○       ●●●●●●●●○       ○       ●●●   │
│   VERDE:     ●●●●●●●●○       ○       ○       ●●●●●●●●○     │
│              │       │       │       │       │       │     │
│              └─VERDE─┴─AMAR──┴──ROJO─┴─VERDE─┴─AMAR──┘     │
│                 5s     2s       5s      5s     2s          │
│                                                             │
│   Ciclo completo: 12 segundos                              │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Serial Monitor

```
=========================
   SEMÁFORO INICIADO
=========================
🟢 VERDE - Paso permitido
🟡 AMARILLO - Precaución
🔴 ROJO - Alto
🟢 VERDE - Paso permitido
🟡 AMARILLO - Precaución
...
```

---

## 💡 Pistas

<details>
<summary>Pista 1: Solo un LED enciende</summary>

Verifica:

- Cada LED tiene su propia resistencia
- Cada LED está conectado a un pin diferente
- Todos los cátodos van a GND (tierra común)

</details>

<details>
<summary>Pista 2: El orden de los colores está mal</summary>

Revisa las conexiones físicas vs el código:

- ¿Pin 10 está conectado al LED rojo?
- ¿Pin 9 está conectado al LED amarillo?
- ¿Pin 8 está conectado al LED verde?

Puedes cambiar los valores de las constantes si conectaste diferente.

</details>

<details>
<summary>Pista 3: ¿Cómo hacer parpadear el amarillo?</summary>

Modifica la función `yellowPhase()`:

```cpp
void yellowPhase() {
    turnAllOff();
    Serial.println("🟡 AMARILLO - Precaución");

    // Parpadear 4 veces (2 segundos total)
    for(int i = 0; i < 4; i++) {
        digitalWrite(PIN_YELLOW, HIGH);
        delay(250);
        digitalWrite(PIN_YELLOW, LOW);
        delay(250);
    }
}
```

</details>

---

## ✅ Criterios de Evaluación

| Criterio                | Puntos | Descripción                               |
| ----------------------- | ------ | ----------------------------------------- |
| **Secuencia correcta**  | 4      | Verde→Amarillo→Rojo con tiempos realistas |
| **Conexiones**          | 3      | 3 LEDs con resistencias individuales      |
| **Organización código** | 3      | Funciones separadas, constantes claras    |
| **Total**               | **10** |                                           |

---

## 🚀 Desafíos Extra (Opcional)

### Desafío A: Semáforo Peatonal

Agrega un segundo semáforo para peatones (con 2 LEDs):

```cpp
const int PIN_WALK = 6;     // LED Verde peatón
const int PIN_STOP = 5;     // LED Rojo peatón

// Cuando el semáforo vehicular está en ROJO,
// el peatonal debe estar en VERDE (caminar)
```

### Desafío B: Modo Nocturno

Después de las 10pm (simulado), el semáforo solo parpadea en amarillo:

```cpp
int cycleCount = 0;
const int NIGHT_MODE_AFTER = 10;  // Después de 10 ciclos

void loop() {
    cycleCount++;

    if(cycleCount > NIGHT_MODE_AFTER) {
        nightMode();
    } else {
        // Secuencia normal
        greenPhase();
        yellowPhase();
        redPhase();
    }
}

void nightMode() {
    turnAllOff();
    digitalWrite(PIN_YELLOW, HIGH);
    delay(500);
    digitalWrite(PIN_YELLOW, LOW);
    delay(500);
}
```

### Desafío C: Semáforo de Cruce

Implementa dos semáforos sincronizados (Norte-Sur y Este-Oeste) donde cuando uno está en verde, el otro está en rojo.

---

## 📚 Recursos Relacionados

| Recurso                    | Enlace                                                                                                        |
| -------------------------- | ------------------------------------------------------------------------------------------------------------- |
| Teoría: Electrónica Básica | [Módulo 02](../1-teoria/02-electronica-basica.md)                                                             |
| Funciones en Arduino       | [arduino.cc](https://www.arduino.cc/reference/en/language/structure/functions/)                               |
| Proyecto similar           | [Arduino Traffic Light](https://create.arduino.cc/projecthub/techno_z/arduino-traffic-light-simulator-2ec9f7) |

---

## 📝 Reflexión

1. ¿Por qué es útil usar funciones separadas para cada fase?
2. ¿Qué modificarías para hacer los tiempos configurables sin recompilar?
3. ¿Cómo podrías añadir un botón para peatones que cambie la secuencia?

---

<div align="center">

[⬅️ Práctica 02](./practica-02-led-externo.md) | [Índice](./README.md) | [Práctica 04 ➡️](./practica-04-patron-luces.md)

</div>
