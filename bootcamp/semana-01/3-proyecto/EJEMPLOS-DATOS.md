# 📊 Ejemplos y Datos - Knight Rider

> Patrones adicionales, código de ejemplo y datos para pruebas

---

## 🎨 Patrones de Ejemplo

### Patrón 1: Knight Rider Clásico

El patrón básico que replica el efecto del auto fantástico.

```cpp
/*
 * Patrón: Knight Rider Clásico
 * Efecto: LED se mueve de izquierda a derecha y viceversa
 * Velocidad: 80ms por LED
 */

void patternKnightRider() {
    // IDA: 0 → 1 → 2 → 3 → 4 → 5
    for (int i = 0; i < NUM_LEDS; i++) {
        lightOnly(i);
        delay(DELAY_MS);
    }
    
    // VUELTA: 4 → 3 → 2 → 1
    for (int i = NUM_LEDS - 2; i > 0; i--) {
        lightOnly(i);
        delay(DELAY_MS);
    }
}
```

**Visualización:**
```
T0:  ●○○○○○  →  T1:  ○●○○○○  →  T2:  ○○●○○○
T3:  ○○○●○○  →  T4:  ○○○○●○  →  T5:  ○○○○○●
T6:  ○○○○●○  →  T7:  ○○○●○○  →  T8:  ○○●○○○
T9:  ○●○○○○  →  (repite desde T0)
```

---

### Patrón 2: Knight Rider con Estela

Dos LEDs encendidos simultáneamente para efecto de "estela".

```cpp
/*
 * Patrón: Knight Rider con Estela
 * Efecto: LED principal + LED anterior encendido
 * Crea efecto de movimiento más fluido
 */

void patternWithTrail() {
    // IDA con estela
    for (int i = 0; i < NUM_LEDS; i++) {
        allOff();
        digitalWrite(LED_PINS[i], HIGH);  // LED principal
        if (i > 0) {
            digitalWrite(LED_PINS[i-1], HIGH);  // Estela
        }
        delay(DELAY_MS);
    }
    
    // VUELTA con estela
    for (int i = NUM_LEDS - 2; i > 0; i--) {
        allOff();
        digitalWrite(LED_PINS[i], HIGH);  // LED principal
        if (i < NUM_LEDS - 1) {
            digitalWrite(LED_PINS[i+1], HIGH);  // Estela
        }
        delay(DELAY_MS);
    }
}
```

**Visualización:**
```
T0:  ●○○○○○  →  T1:  ●●○○○○  →  T2:  ○●●○○○
T3:  ○○●●○○  →  T4:  ○○○●●○  →  T5:  ○○○○●●
T6:  ○○○○●●  →  T7:  ○○○●●○  →  T8:  ○○●●○○
```

---

### Patrón 3: Ping Pong

Un LED "rebota" en los extremos.

```cpp
/*
 * Patrón: Ping Pong
 * Efecto: Similar a Knight Rider pero el LED
 *         "rebota" mostrando brevemente el extremo
 */

void patternPingPong() {
    // IDA completa
    for (int i = 0; i < NUM_LEDS; i++) {
        lightOnly(i);
        delay(DELAY_MS);
    }
    
    // VUELTA completa (incluyendo extremos)
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
        lightOnly(i);
        delay(DELAY_MS);
    }
}
```

---

### Patrón 4: Llenado y Vaciado

Los LEDs se llenan progresivamente y luego se vacían.

```cpp
/*
 * Patrón: Llenado y Vaciado
 * Efecto: LEDs se encienden uno a uno hasta llenar,
 *         luego se apagan uno a uno
 */

void patternFillDrain() {
    // Llenado: agregar LEDs uno a uno
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], HIGH);
        delay(DELAY_MS);
    }
    
    delay(200);  // Pausa con todos encendidos
    
    // Vaciado: quitar LEDs uno a uno
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
        digitalWrite(LED_PINS[i], LOW);
        delay(DELAY_MS);
    }
    
    delay(200);  // Pausa con todos apagados
}
```

**Visualización:**
```
LLENADO:
T0:  ●○○○○○  →  T1:  ●●○○○○  →  T2:  ●●●○○○
T3:  ●●●●○○  →  T4:  ●●●●●○  →  T5:  ●●●●●●

VACIADO:
T6:  ●●●●●○  →  T7:  ●●●●○○  →  T8:  ●●●○○○
T9:  ●●○○○○  →  T10: ●○○○○○  →  T11: ○○○○○○
```

---

### Patrón 5: Centro hacia Afuera

Iluminación que expande desde el centro.

```cpp
/*
 * Patrón: Centro hacia Afuera
 * Efecto: Comienza en el centro y se expande
 *         hacia ambos extremos
 */

void patternCenterOut() {
    int center = NUM_LEDS / 2;  // Índice 3 para 6 LEDs
    
    // Expandir desde centro
    for (int offset = 0; offset <= center; offset++) {
        allOff();
        
        // LED izquierdo desde centro
        if (center - offset >= 0) {
            digitalWrite(LED_PINS[center - offset], HIGH);
        }
        // LED derecho desde centro
        if (center + offset < NUM_LEDS) {
            digitalWrite(LED_PINS[center + offset], HIGH);
        }
        // Para 6 LEDs (índices 0-5), centro es 2 y 3
        if (offset == 0 && center - 1 >= 0) {
            digitalWrite(LED_PINS[center - 1], HIGH);
        }
        
        delay(DELAY_MS);
    }
    
    // Contraer hacia centro
    for (int offset = center; offset >= 0; offset--) {
        allOff();
        
        if (center - offset >= 0) {
            digitalWrite(LED_PINS[center - offset], HIGH);
        }
        if (center + offset < NUM_LEDS) {
            digitalWrite(LED_PINS[center + offset], HIGH);
        }
        if (offset == 0 && center - 1 >= 0) {
            digitalWrite(LED_PINS[center - 1], HIGH);
        }
        
        delay(DELAY_MS);
    }
}
```

**Visualización:**
```
EXPANDIR:
T0:  ○○●●○○  →  T1:  ○●●●●○  →  T2:  ●●●●●●

CONTRAER:
T3:  ●●●●●●  →  T4:  ○●●●●○  →  T5:  ○○●●○○
```

---

### Patrón 6: Alternado (Par/Impar)

LEDs pares e impares alternan.

```cpp
/*
 * Patrón: Alternado
 * Efecto: LEDs pares e impares parpadean alternadamente
 */

void patternAlternate(int repetitions) {
    for (int r = 0; r < repetitions; r++) {
        // Encender pares (0, 2, 4)
        for (int i = 0; i < NUM_LEDS; i++) {
            digitalWrite(LED_PINS[i], (i % 2 == 0) ? HIGH : LOW);
        }
        delay(DELAY_MS * 2);
        
        // Encender impares (1, 3, 5)
        for (int i = 0; i < NUM_LEDS; i++) {
            digitalWrite(LED_PINS[i], (i % 2 == 1) ? HIGH : LOW);
        }
        delay(DELAY_MS * 2);
    }
    allOff();
}
```

**Visualización:**
```
T0:  ●○●○●○  →  T1:  ○●○●○●  →  T2:  ●○●○●○  →  ...
```

---

### Patrón 7: Onda Doble

Dos LEDs moviéndose en direcciones opuestas.

```cpp
/*
 * Patrón: Onda Doble
 * Efecto: Un LED va de izq→der mientras otro va de der→izq
 */

void patternDoubleWave() {
    for (int i = 0; i < NUM_LEDS; i++) {
        allOff();
        
        // LED moviéndose hacia la derecha
        digitalWrite(LED_PINS[i], HIGH);
        
        // LED moviéndose hacia la izquierda
        int oppositeIndex = NUM_LEDS - 1 - i;
        if (oppositeIndex != i) {  // Evitar encender el mismo
            digitalWrite(LED_PINS[oppositeIndex], HIGH);
        }
        
        delay(DELAY_MS);
    }
}
```

**Visualización:**
```
T0:  ●○○○○●  →  T1:  ○●○○●○  →  T2:  ○○●●○○
T3:  ○○●●○○  →  T4:  ○●○○●○  →  T5:  ●○○○○●
```

---

## 📊 Tabla de Velocidades

| Nombre | DELAY_MS | Ciclos/seg | Efecto |
|--------|----------|------------|--------|
| Ultra rápido | 30 | 3.3 | Casi continuo |
| Rápido | 50 | 2.0 | Ágil, dinámico |
| Normal | 80 | 1.25 | **Recomendado** |
| Lento | 120 | 0.83 | Relajado |
| Muy lento | 200 | 0.5 | Dramático |

---

## 🧮 Datos de Prueba

### Secuencia de Estados para Debugging

```cpp
// Usar este código para verificar cada LED individualmente
void testSequence() {
    Serial.println("=== TEST DE LEDs ===");
    
    for (int i = 0; i < NUM_LEDS; i++) {
        Serial.print("LED ");
        Serial.print(i);
        Serial.print(" (Pin ");
        Serial.print(LED_PINS[i]);
        Serial.println(")");
        
        lightOnly(i);
        delay(1000);  // 1 segundo por LED para verificar
    }
    
    Serial.println("=== TEST COMPLETO ===");
    allOff();
}
```

### Salida Esperada en Serial Monitor

```
================================
   KNIGHT RIDER v1.0
   Secuenciador de LEDs
================================
Iniciando...
¡Listo!
=== Ciclo 1 ===
LED 0 → LED 1 → LED 2 → LED 3 → LED 4 → LED 5
LED 4 → LED 3 → LED 2 → LED 1
=== Ciclo 2 ===
...
```

---

## 🔢 Configuraciones Alternativas de Pines

### Configuración A: Pines 3-8 (Recomendada)

```cpp
const int LED_PINS[NUM_LEDS] = {3, 4, 5, 6, 7, 8};
```
- ✅ Pines contiguos, fácil de cablear
- ✅ Evita pines 0, 1 (Serial)
- ✅ Evita pin 13 (LED integrado)

### Configuración B: Pines 2-7

```cpp
const int LED_PINS[NUM_LEDS] = {2, 3, 4, 5, 6, 7};
```
- ✅ Empieza desde el primer pin digital disponible
- ⚠️ Pin 2 a veces se usa para interrupciones

### Configuración C: Pines PWM (Para futura expansión)

```cpp
const int LED_PINS[NUM_LEDS] = {3, 5, 6, 9, 10, 11};
```
- ✅ Todos son pines PWM (~)
- ✅ Permite añadir efectos de fade después
- ⚠️ No son contiguos físicamente

---

## 📋 Plantilla de Código Completa

```cpp
/*
 * =================================================
 * PROYECTO: Knight Rider - Secuenciador de LEDs
 * =================================================
 * 
 * Versión: 1.0
 * Autor: [TU NOMBRE]
 * Fecha: [FECHA]
 * 
 * Descripción:
 * [Describe tu implementación]
 * 
 * Funcionalidades:
 * [x] Secuencia ida (izq → der)
 * [x] Secuencia vuelta (der → izq)
 * [ ] Velocidad variable
 * [ ] Efecto estela
 * [ ] Otros...
 * 
 * Conexiones:
 * Pin 3 → LED 0
 * Pin 4 → LED 1
 * Pin 5 → LED 2
 * Pin 6 → LED 3
 * Pin 7 → LED 4
 * Pin 8 → LED 5
 * Todos cátodos → GND
 * 
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// CONSTANTES
// ==================================================
const int NUM_LEDS = 6;
const int LED_PINS[NUM_LEDS] = {3, 4, 5, 6, 7, 8};
const int DELAY_MS = 80;

// ==================================================
// VARIABLES
// ==================================================
// Agregar aquí si necesitas variables globales

// ==================================================
// SETUP
// ==================================================
void setup() {
    // Configurar pines
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(LED_PINS[i], OUTPUT);
    }
    
    // Serial
    Serial.begin(9600);
    Serial.println("Knight Rider iniciado");
    
    // Animación de inicio
    startupAnimation();
}

// ==================================================
// LOOP
// ==================================================
void loop() {
    sequenceForward();
    sequenceBackward();
}

// ==================================================
// FUNCIONES AUXILIARES
// ==================================================

void allOff() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], LOW);
    }
}

void allOn() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], HIGH);
    }
}

void lightOnly(int position) {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], (i == position) ? HIGH : LOW);
    }
}

void sequenceForward() {
    for (int i = 0; i < NUM_LEDS; i++) {
        lightOnly(i);
        delay(DELAY_MS);
    }
}

void sequenceBackward() {
    for (int i = NUM_LEDS - 2; i > 0; i--) {
        lightOnly(i);
        delay(DELAY_MS);
    }
}

void startupAnimation() {
    for (int i = 0; i < 3; i++) {
        allOn();
        delay(200);
        allOff();
        delay(200);
    }
    delay(500);
}

// ==================================================
// FUNCIONES EXTRA (OPCIONALES)
// ==================================================

// Agrega aquí tus funciones adicionales para bonus
```

---

## 🔗 Enlaces de Referencia

| Recurso | URL |
|---------|-----|
| Video: Auto Fantástico Original | [YouTube](https://www.youtube.com/results?search_query=knight+rider+car+lights) |
| Proyecto Tinkercad Ejemplo | [tinkercad.com](https://www.tinkercad.com/things/example-knight-rider) |
| Arduino Arrays | [arduino.cc](https://www.arduino.cc/reference/en/language/variables/data-types/array/) |
| Loops en Arduino | [arduino.cc](https://www.arduino.cc/reference/en/language/structure/control-structure/for/) |

---

<div align="center">

[⬅️ Guía de Diseño](./GUIA-DISENO.md) | [README Proyecto](./README.md) | [Recursos ➡️](../4-recursos/README.md)

</div>
