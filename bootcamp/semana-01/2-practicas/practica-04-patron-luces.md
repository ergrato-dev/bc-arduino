# 💻 Práctica 04: Patrón de Luces Personalizado

> ⏱️ **Tiempo estimado:** 30 minutos  
> ⭐⭐⭐ **Dificultad:** Intermedio  
> 🎯 **Compatibilidad Tinkercad:** ✅

---

## 📋 Información General

| Campo               | Valor                                                     |
| ------------------- | --------------------------------------------------------- |
| **Dificultad**      | ⭐⭐⭐ Intermedio                                         |
| **Tiempo estimado** | 30 minutos                                                |
| **Componentes**     | Arduino Uno, 5 LEDs, 5 Resistencias 220Ω, Protoboard      |
| **Conceptos**       | Arrays, bucles for, patrones, creatividad, código modular |

---

## 🎯 Objetivos

Al completar esta práctica, serás capaz de:

- [ ] Usar arrays para almacenar pines
- [ ] Implementar bucles for para iterar sobre LEDs
- [ ] Diseñar patrones de iluminación creativos
- [ ] Organizar código de forma modular
- [ ] Crear efectos visuales interesantes

---

## 📝 Descripción

En esta práctica diseñarás tu propio **patrón de luces** usando 5 LEDs. Aprenderás a usar **arrays** para manejar múltiples pines de forma eficiente y crearás efectos visuales como secuencias, ondas, parpadeos aleatorios y más.

---

## 🔧 Requisitos Técnicos

### Componentes

| Componente             | Cantidad | Notas                                   |
| ---------------------- | -------- | --------------------------------------- |
| Arduino Uno R3         | 1        |                                         |
| LEDs (cualquier color) | 5        | Pueden ser del mismo color o diferentes |
| Resistencia 220Ω       | 5        | Una por LED                             |
| Protoboard             | 1        |                                         |
| Cables jumper          | 8+       |                                         |

---

## 📐 Diagrama del Circuito

### Esquemático

```
                              ARDUINO UNO
    ┌──────────────────────────────────────────────────────┐
    │                                                      │
    │   Pin 8  ─────┐                                      │
    │   Pin 9  ─────│───┐                                  │
    │   Pin 10 ─────│───│───┐                              │
    │   Pin 11 ─────│───│───│───┐                          │
    │   Pin 12 ─────│───│───│───│───┐                      │
    │               │   │   │   │   │                      │
    │   GND ────────│───│───│───│───│──┐                   │
    │               │   │   │   │   │  │                   │
    └───────────────│───│───│───│───│──│───────────────────┘
                    │   │   │   │   │  │
    ┌───────────────│───│───│───│───│──│───────────────────┐
    │  PROTOBOARD   │   │   │   │   │  │                   │
    │               │   │   │   │   │  │                   │
    │   [R]─[LED]───┴───│───│───│───│──┤                   │
    │       LED 0       │   │   │   │  │                   │
    │   [R]─[LED]───────┴───│───│───│──┤                   │
    │       LED 1           │   │   │  │                   │
    │   [R]─[LED]───────────┴───│───│──┤                   │
    │       LED 2               │   │  │                   │
    │   [R]─[LED]───────────────┴───│──┤                   │
    │       LED 3                   │  │                   │
    │   [R]─[LED]───────────────────┴──┤                   │
    │       LED 4                      │                   │
    │                                  │                   │
    │   Todos los cátodos ─────────────┴─── GND            │
    │                                                      │
    └──────────────────────────────────────────────────────┘
```

### Disposición Física

```
┌─────────────────────────────────────────────────────────────┐
│                    DISPOSICIÓN EN LÍNEA                     │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│      LED 0    LED 1    LED 2    LED 3    LED 4             │
│        ◯        ◯        ◯        ◯        ◯               │
│        │        │        │        │        │               │
│       [R]      [R]      [R]      [R]      [R]              │
│        │        │        │        │        │               │
│       Pin8    Pin9    Pin10   Pin11   Pin12                │
│                                                             │
│   Los LEDs deben estar en línea recta para apreciar       │
│   los patrones de secuencia                                │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 📋 Instrucciones

### Paso 1: Armar el Circuito

1. Coloca los 5 LEDs en línea en la protoboard
2. Conecta una resistencia de 220Ω a cada LED
3. Conecta los pines 8, 9, 10, 11, 12 a cada resistencia
4. Conecta todos los cátodos a GND

### Paso 2: Código Base con Arrays

```cpp
/*
 * =================================================
 * PRÁCTICA 04: Patrón de Luces Personalizado
 * =================================================
 *
 * ¿Qué hace?
 * Crea diversos patrones de iluminación con 5 LEDs:
 * - Secuencia ida y vuelta (Knight Rider)
 * - Llenado progresivo
 * - Parpadeo alternado
 * - Y más patrones personalizados
 *
 * ¿Para qué?
 * - Aprender a usar arrays para múltiples pines
 * - Practicar bucles for
 * - Desarrollar creatividad con patrones
 * - Crear código modular y reutilizable
 *
 * ¿Cómo funciona?
 * 1. Los pines se almacenan en un array
 * 2. Bucles for iteran sobre el array
 * 3. Cada función implementa un patrón diferente
 * 4. loop() ejecuta todos los patrones en secuencia
 *
 * Hardware requerido:
 * - Arduino Uno R3
 * - 5 LEDs
 * - 5 Resistencias 220Ω
 * - Protoboard y cables
 *
 * Conexiones:
 * - Pin 8  → Resistencia → LED 0
 * - Pin 9  → Resistencia → LED 1
 * - Pin 10 → Resistencia → LED 2
 * - Pin 11 → Resistencia → LED 3
 * - Pin 12 → Resistencia → LED 4
 * - Todos los cátodos → GND
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// CONSTANTES
// ==================================================

// Número de LEDs
const int NUM_LEDS = 5;

// Array con los pines de cada LED
// El índice 0 es LED izquierdo, índice 4 es derecho
const int LED_PINS[NUM_LEDS] = {8, 9, 10, 11, 12};

// Velocidades de los patrones (ms)
const int SPEED_FAST = 50;
const int SPEED_NORMAL = 100;
const int SPEED_SLOW = 200;

// ==================================================
// SETUP
// ==================================================
void setup() {
    // Configurar todos los pines como salida usando un bucle
    for(int i = 0; i < NUM_LEDS; i++) {
        pinMode(LED_PINS[i], OUTPUT);
    }

    // Iniciar Serial
    Serial.begin(9600);
    Serial.println("================================");
    Serial.println("  PATRÓN DE LUCES - Práctica 04");
    Serial.println("================================");

    // Apagar todos los LEDs al inicio
    allOff();
}

// ==================================================
// LOOP - Ejecuta todos los patrones
// ==================================================
void loop() {
    // Patrón 1: Secuencia simple (izquierda a derecha)
    Serial.println("\n>> Patrón 1: Secuencia simple");
    patternSequence(3);

    // Patrón 2: Knight Rider (ida y vuelta)
    Serial.println("\n>> Patrón 2: Knight Rider");
    patternKnightRider(3);

    // Patrón 3: Llenado progresivo
    Serial.println("\n>> Patrón 3: Llenado");
    patternFill(2);

    // Patrón 4: Parpadeo alternado
    Serial.println("\n>> Patrón 4: Alternado");
    patternAlternate(5);

    // Patrón 5: Todos parpadean
    Serial.println("\n>> Patrón 5: Parpadeo total");
    patternBlinkAll(5);

    // Pausa entre ciclos completos
    delay(1000);
}

// ==================================================
// FUNCIONES DE UTILIDAD
// ==================================================

/**
 * Apaga todos los LEDs
 */
void allOff() {
    for(int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], LOW);
    }
}

/**
 * Enciende todos los LEDs
 */
void allOn() {
    for(int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], HIGH);
    }
}

/**
 * Enciende solo el LED en la posición indicada
 * @param position Índice del LED (0 a NUM_LEDS-1)
 */
void lightOnly(int position) {
    for(int i = 0; i < NUM_LEDS; i++) {
        if(i == position) {
            digitalWrite(LED_PINS[i], HIGH);
        } else {
            digitalWrite(LED_PINS[i], LOW);
        }
    }
}

// ==================================================
// PATRONES
// ==================================================

/**
 * Patrón 1: Secuencia simple de izquierda a derecha
 * @param repetitions Número de veces que se repite
 */
void patternSequence(int repetitions) {
    for(int r = 0; r < repetitions; r++) {
        // Recorrer de izquierda a derecha
        for(int i = 0; i < NUM_LEDS; i++) {
            lightOnly(i);
            delay(SPEED_NORMAL);
        }
    }
    allOff();
}

/**
 * Patrón 2: Knight Rider (ida y vuelta)
 * Efecto del auto fantástico
 * @param repetitions Número de ciclos completos
 */
void patternKnightRider(int repetitions) {
    for(int r = 0; r < repetitions; r++) {
        // Ida (izquierda a derecha)
        for(int i = 0; i < NUM_LEDS; i++) {
            lightOnly(i);
            delay(SPEED_FAST);
        }

        // Vuelta (derecha a izquierda, sin repetir extremos)
        for(int i = NUM_LEDS - 2; i > 0; i--) {
            lightOnly(i);
            delay(SPEED_FAST);
        }
    }
    allOff();
}

/**
 * Patrón 3: Llenado progresivo
 * Los LEDs se encienden uno a uno y luego se apagan
 * @param repetitions Número de ciclos
 */
void patternFill(int repetitions) {
    for(int r = 0; r < repetitions; r++) {
        // Llenar (encender uno a uno)
        for(int i = 0; i < NUM_LEDS; i++) {
            digitalWrite(LED_PINS[i], HIGH);
            delay(SPEED_SLOW);
        }

        delay(300);  // Pausa con todos encendidos

        // Vaciar (apagar uno a uno)
        for(int i = NUM_LEDS - 1; i >= 0; i--) {
            digitalWrite(LED_PINS[i], LOW);
            delay(SPEED_SLOW);
        }

        delay(200);
    }
}

/**
 * Patrón 4: Parpadeo alternado
 * LEDs pares vs impares
 * @param repetitions Número de alternancias
 */
void patternAlternate(int repetitions) {
    for(int r = 0; r < repetitions; r++) {
        // Encender pares (0, 2, 4), apagar impares (1, 3)
        for(int i = 0; i < NUM_LEDS; i++) {
            digitalWrite(LED_PINS[i], (i % 2 == 0) ? HIGH : LOW);
        }
        delay(SPEED_SLOW);

        // Encender impares, apagar pares
        for(int i = 0; i < NUM_LEDS; i++) {
            digitalWrite(LED_PINS[i], (i % 2 == 1) ? HIGH : LOW);
        }
        delay(SPEED_SLOW);
    }
    allOff();
}

/**
 * Patrón 5: Todos parpadean juntos
 * @param repetitions Número de parpadeos
 */
void patternBlinkAll(int repetitions) {
    for(int r = 0; r < repetitions; r++) {
        allOn();
        delay(SPEED_NORMAL);
        allOff();
        delay(SPEED_NORMAL);
    }
}
```

### Paso 3: Probar los Patrones

1. Carga el código y observa los 5 patrones
2. Identifica cada patrón mientras se ejecuta
3. Observa los mensajes en Serial Monitor

---

## 🎨 Patrones de Ejemplo

### Patrón 1: Secuencia Simple

```
Tiempo:   T0    T1    T2    T3    T4
LED 0:    ●     ○     ○     ○     ○
LED 1:    ○     ●     ○     ○     ○
LED 2:    ○     ○     ●     ○     ○
LED 3:    ○     ○     ○     ●     ○
LED 4:    ○     ○     ○     ○     ●
```

### Patrón 2: Knight Rider

```
Tiempo:   T0    T1    T2    T3    T4    T5    T6    T7
LED 0:    ●     ○     ○     ○     ○     ○     ○     ●
LED 1:    ○     ●     ○     ○     ○     ○     ●     ○
LED 2:    ○     ○     ●     ○     ○     ●     ○     ○
LED 3:    ○     ○     ○     ●     ●     ○     ○     ○
LED 4:    ○     ○     ○     ○     ●     ○     ○     ○
          ─────────IDA──────────────VUELTA─────────
```

### Patrón 3: Llenado

```
Fase LLENAR:              Fase VACIAR:
T0    T1    T2    T3    T4    T5    T6    T7    T8
●     ●     ●     ●     ●     ●     ●     ●     ●
○     ●     ●     ●     ●     ●     ●     ●     ○
○     ○     ●     ●     ●     ●     ●     ○     ○
○     ○     ○     ●     ●     ●     ○     ○     ○
○     ○     ○     ○     ●     ○     ○     ○     ○
```

---

## 💡 Pistas

<details>
<summary>Pista 1: Crear un patrón desde el centro</summary>

```cpp
void patternFromCenter(int reps) {
    int center = NUM_LEDS / 2;  // LED del centro (índice 2)

    for(int r = 0; r < reps; r++) {
        // Expandir desde el centro
        for(int offset = 0; offset <= center; offset++) {
            allOff();
            if(center - offset >= 0) {
                digitalWrite(LED_PINS[center - offset], HIGH);
            }
            if(center + offset < NUM_LEDS) {
                digitalWrite(LED_PINS[center + offset], HIGH);
            }
            delay(SPEED_NORMAL);
        }

        // Contraer hacia el centro
        for(int offset = center; offset >= 0; offset--) {
            allOff();
            if(center - offset >= 0) {
                digitalWrite(LED_PINS[center - offset], HIGH);
            }
            if(center + offset < NUM_LEDS) {
                digitalWrite(LED_PINS[center + offset], HIGH);
            }
            delay(SPEED_NORMAL);
        }
    }
}
```

</details>

<details>
<summary>Pista 2: Patrón aleatorio</summary>

```cpp
void patternRandom(int duration) {
    unsigned long startTime = millis();

    while(millis() - startTime < duration) {
        int randomLed = random(0, NUM_LEDS);  // LED aleatorio

        // Encender LED aleatorio
        digitalWrite(LED_PINS[randomLed], HIGH);
        delay(50);
        digitalWrite(LED_PINS[randomLed], LOW);
        delay(50);
    }
    allOff();
}
```

**Nota:** `random()` necesita inicializarse en setup():

```cpp
void setup() {
    randomSeed(analogRead(0));  // Semilla desde pin analógico flotante
    // ... resto del setup
}
```

</details>

<details>
<summary>Pista 3: Patrón de "onda"</summary>

```cpp
void patternWave(int reps) {
    for(int r = 0; r < reps; r++) {
        // Cada LED se enciende con un desfase
        for(int step = 0; step < NUM_LEDS * 2; step++) {
            for(int i = 0; i < NUM_LEDS; i++) {
                // Calcular brillo basado en posición en la onda
                int distance = abs(step - i);
                if(distance <= 1) {
                    digitalWrite(LED_PINS[i], HIGH);
                } else {
                    digitalWrite(LED_PINS[i], LOW);
                }
            }
            delay(SPEED_FAST);
        }
    }
    allOff();
}
```

</details>

---

## ✅ Criterios de Evaluación

| Criterio           | Puntos | Descripción                       |
| ------------------ | ------ | --------------------------------- |
| **Creatividad**    | 4      | Patrón original y elaborado       |
| **Implementación** | 4      | Código eficiente con arrays/loops |
| **Documentación**  | 4      | Explicación completa del patrón   |
| **Total**          | **12** |                                   |

### Niveles de Logro

| Nivel        | Puntos | Descripción                                               |
| ------------ | ------ | --------------------------------------------------------- |
| Excelente    | 10-12  | Patrón creativo, código eficiente, documentación completa |
| Muy Bueno    | 7-9    | Buen patrón, código funcional, documentación básica       |
| Bueno        | 4-6    | Patrón simple, código funciona                            |
| Insuficiente | 0-3    | No implementa patrón propio                               |

---

## 🚀 Desafíos Extra

### Desafío A: Tu Patrón Original

Diseña y documenta un patrón completamente original. Incluye:

- Nombre del patrón
- Descripción del efecto visual
- Pseudocódigo o diagrama
- Implementación

### Desafío B: Selector de Patrones

Usa Serial para que el usuario seleccione qué patrón ejecutar:

```cpp
void loop() {
    if(Serial.available() > 0) {
        char input = Serial.read();

        switch(input) {
            case '1': patternSequence(3); break;
            case '2': patternKnightRider(3); break;
            case '3': patternFill(2); break;
            case '4': patternAlternate(5); break;
            case '5': patternBlinkAll(5); break;
            default:
                Serial.println("Opción no válida (1-5)");
        }
    }
}
```

### Desafío C: Combinación de Patrones

Crea un "mega patrón" que combine elementos de varios patrones en una secuencia única y fluida.

---

## 📚 Recursos Relacionados

| Recurso           | Enlace                                                                                      |
| ----------------- | ------------------------------------------------------------------------------------------- |
| Arrays en Arduino | [arduino.cc](https://www.arduino.cc/reference/en/language/variables/data-types/array/)      |
| Bucle for         | [arduino.cc](https://www.arduino.cc/reference/en/language/structure/control-structure/for/) |
| LED Patterns      | [instructables.com](https://www.instructables.com/LED-Patterns/)                            |

---

## 📝 Reflexión

1. ¿Por qué es más eficiente usar arrays en lugar de variables individuales?
2. ¿Cómo modificarías el código para soportar 8 LEDs sin cambiar las funciones de patrones?
3. ¿Qué ventajas tiene organizar el código en funciones separadas?

---

<div align="center">

[⬅️ Práctica 03](./practica-03-semaforo.md) | [Índice](./README.md) | [Proyecto ➡️](../3-proyecto/README.md)

</div>
