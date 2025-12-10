# Práctica 3: Control con Potenciómetro

> ⭐⭐ Nivel: Intermedio · ⏱️ 20 minutos

---

## 🎯 Objetivo

Controlar el brillo de un LED usando un potenciómetro, mapeando la entrada analógica (0-1023) a salida PWM (0-255).

---

## 📦 Materiales

| Componente | Cantidad |
|------------|----------|
| Arduino Uno | 1 |
| LED Rojo 5mm | 1 |
| Resistencia 220Ω | 1 |
| Potenciómetro 10kΩ | 1 |
| Protoboard | 1 |
| Cables jumper | 6 |

---

## 🔌 Diagrama de Conexión

```
                  Potenciómetro 10kΩ
                     ┌─────┐
                     │     │
    5V ──────────────┤ 1   │
                     │     │
    A0 ──────────────┤ 2   │ (Wiper/Central)
                     │     │
    GND ─────────────┤ 3   │
                     └─────┘

    Arduino Uno
    ┌─────────────┐
    │         ~9  ├────[220Ω]────┬──── LED (+)
    │             │              │
    │         GND ├──────────────┴──── LED (-)
    │             │
    │          A0 ├──── Potenciómetro (wiper)
    │             │
    │          5V ├──── Potenciómetro (extremo 1)
    │             │
    │         GND ├──── Potenciómetro (extremo 2)
    └─────────────┘
```

### Tabla de Conexiones

| Arduino | Componente |
|---------|------------|
| Pin ~9 (PWM) | Resistencia → LED (+) |
| GND | LED (-) |
| A0 | Potenciómetro (terminal central) |
| 5V | Potenciómetro (terminal 1) |
| GND | Potenciómetro (terminal 3) |

---

## 💻 Código

### Versión Básica

```cpp
/*
 * =================================================
 * PROYECTO: Control de Brillo con Potenciómetro
 * =================================================
 * 
 * ¿Qué hace?
 * El potenciómetro controla el brillo del LED.
 * Girar el pot cambia la intensidad de 0 a 100%.
 * 
 * ¿Para qué?
 * - Dimmer de luces
 * - Control de volumen visual
 * - Interfaz de usuario analógica
 * 
 * ¿Cómo funciona?
 * 1. Lee valor analógico del pot (0-1023)
 * 2. Mapea a rango PWM (0-255) con map()
 * 3. Aplica el valor al LED con analogWrite()
 * 
 * Hardware: LED + 220Ω en pin 9, Pot en A0
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// DEFINICIÓN DE PINES
// ==================================================
const int LED_PIN = 9;      // Pin PWM para LED
const int POT_PIN = A0;     // Pin analógico para pot

// ==================================================
// VARIABLES
// ==================================================
int potValue = 0;           // Valor del potenciómetro (0-1023)
int brightness = 0;         // Brillo del LED (0-255)

// ==================================================
// SETUP
// ==================================================
void setup() {
    pinMode(LED_PIN, OUTPUT);
    // A0 no necesita pinMode para analogRead
    
    Serial.begin(9600);
    Serial.println("Control de brillo iniciado");
}

// ==================================================
// LOOP
// ==================================================
void loop() {
    // 1. Leer valor del potenciómetro
    potValue = analogRead(POT_PIN);
    
    // 2. Mapear de 0-1023 a 0-255
    brightness = map(potValue, 0, 1023, 0, 255);
    
    // 3. Aplicar brillo al LED
    analogWrite(LED_PIN, brightness);
    
    // 4. Mostrar valores en Serial Monitor
    Serial.print("Pot: ");
    Serial.print(potValue);
    Serial.print(" -> Brillo: ");
    Serial.print(brightness);
    Serial.print(" (");
    Serial.print((brightness * 100) / 255);
    Serial.println("%)");
    
    // Pequeña pausa para estabilidad
    delay(50);
}
```

### Versión con Suavizado

```cpp
/*
 * Control con suavizado de lecturas
 * Evita fluctuaciones del potenciómetro
 */

const int LED_PIN = 9;
const int POT_PIN = A0;
const int NUM_READINGS = 10;  // Número de lecturas a promediar

int readings[NUM_READINGS];   // Array de lecturas
int readIndex = 0;            // Índice actual
int total = 0;                // Suma de lecturas
int average = 0;              // Promedio

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    
    // Inicializar array
    for (int i = 0; i < NUM_READINGS; i++) {
        readings[i] = 0;
    }
}

void loop() {
    // Restar lectura anterior del total
    total = total - readings[readIndex];
    
    // Leer nuevo valor
    readings[readIndex] = analogRead(POT_PIN);
    
    // Sumar al total
    total = total + readings[readIndex];
    
    // Avanzar índice
    readIndex = (readIndex + 1) % NUM_READINGS;
    
    // Calcular promedio
    average = total / NUM_READINGS;
    
    // Mapear y aplicar
    int brightness = map(average, 0, 1023, 0, 255);
    analogWrite(LED_PIN, brightness);
    
    delay(10);
}
```

---

## 📐 La Función map()

### Sintaxis

```cpp
map(value, fromLow, fromHigh, toLow, toHigh);
```

### Parámetros

| Parámetro | Descripción | Ejemplo |
|-----------|-------------|---------|
| value | Valor a mapear | potValue |
| fromLow | Mínimo del rango origen | 0 |
| fromHigh | Máximo del rango origen | 1023 |
| toLow | Mínimo del rango destino | 0 |
| toHigh | Máximo del rango destino | 255 |

### Ejemplos

```cpp
// Mapeo básico
map(512, 0, 1023, 0, 255);  // Retorna ~127

// Mapeo invertido (giro opuesto)
map(potValue, 0, 1023, 255, 0);

// Mapeo con rango limitado
map(potValue, 0, 1023, 50, 200);  // Nunca totalmente apagado

// Mapeo a porcentaje
map(potValue, 0, 1023, 0, 100);
```

---

## 🧪 Pruebas

### Verificación

- [ ] LED apagado con pot en mínimo
- [ ] LED al máximo con pot en máximo
- [ ] Transición suave al girar
- [ ] Valores mostrados en Serial Monitor

### Experimentos

1. **Inversión**: Usa `map(potValue, 0, 1023, 255, 0)` para invertir
2. **Rango limitado**: Usa `map(potValue, 0, 1023, 20, 255)` para mínimo 20
3. **Zona muerta**: Agrega umbral para ignorar valores muy bajos

---

## 🎯 Desafíos

<details>
<summary><strong>Desafío 1: Control RGB con 3 potenciómetros</strong></summary>

Controla cada color con un potenciómetro diferente.

```cpp
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int POT_R = A0;
const int POT_G = A1;
const int POT_B = A2;

void loop() {
    int r = map(analogRead(POT_R), 0, 1023, 0, 255);
    int g = map(analogRead(POT_G), 0, 1023, 0, 255);
    int b = map(analogRead(POT_B), 0, 1023, 0, 255);
    
    analogWrite(RED_PIN, r);
    analogWrite(GREEN_PIN, g);
    analogWrite(BLUE_PIN, b);
    
    delay(50);
}
```
</details>

<details>
<summary><strong>Desafío 2: Umbral con indicador</strong></summary>

LED parpadea si el brillo supera cierto umbral.

```cpp
const int THRESHOLD = 200;

void loop() {
    int potValue = analogRead(POT_PIN);
    int brightness = map(potValue, 0, 1023, 0, 255);
    
    if (brightness > THRESHOLD) {
        // Parpadeo de advertencia
        analogWrite(LED_PIN, brightness);
        delay(100);
        analogWrite(LED_PIN, 0);
        delay(100);
    } else {
        analogWrite(LED_PIN, brightness);
        delay(50);
    }
}
```
</details>

---

## ❓ Solución de Problemas

| Problema | Causa | Solución |
|----------|-------|----------|
| Valores erráticos | Pot mal conectado | Verificar 3 terminales |
| Siempre 0 o 1023 | Terminal central incorrecto | Probar otro terminal |
| Rango incompleto | Pot dañado | Verificar con otro pot |
| Fluctuaciones | Ruido eléctrico | Usar suavizado |

---

## 📝 Conceptos Aprendidos

- ✅ Lectura analógica con `analogRead()`
- ✅ Mapeo de rangos con `map()`
- ✅ Combinación entrada analógica + salida PWM
- ✅ Suavizado de lecturas

---

## ➡️ Siguiente

[Melodía con Buzzer →](./04-melodia-buzzer.md)
