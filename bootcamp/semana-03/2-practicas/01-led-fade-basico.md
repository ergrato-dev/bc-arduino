# Práctica 1: LED Fade Básico

> ⭐ Nivel: Básico · ⏱️ 20 minutos

---

## 🎯 Objetivo

Crear un efecto de "respiración" en un LED, donde el brillo aumenta y disminuye gradualmente usando PWM.

---

## 📦 Materiales

| Componente | Cantidad |
|------------|----------|
| Arduino Uno | 1 |
| LED Rojo 5mm | 1 |
| Resistencia 220Ω | 1 |
| Protoboard | 1 |
| Cables jumper | 3 |

---

## 🔌 Diagrama de Conexión

```
    Arduino Uno
    ┌─────────────┐
    │         ~9  ├────[220Ω]────┬──── LED (+)
    │             │              │
    │         GND ├──────────────┴──── LED (-)
    └─────────────┘

Nota: Pin 9 es PWM (marcado con ~)
```

### Tabla de Conexiones

| Arduino | Componente |
|---------|------------|
| Pin ~9 (PWM) | Resistencia 220Ω → LED Ánodo (+) |
| GND | LED Cátodo (-) |

---

## 💻 Código

### Versión 1: Con delay() (Simple)

```cpp
/*
 * =================================================
 * PROYECTO: LED Fade Básico
 * =================================================
 * 
 * ¿Qué hace?
 * El LED aumenta y disminuye su brillo de forma continua,
 * creando un efecto de "respiración" suave.
 * 
 * ¿Para qué?
 * - Indicador de estado elegante
 * - Luz ambiental
 * - Aprender PWM básico
 * 
 * ¿Cómo funciona?
 * 1. Incrementa el brillo de 0 a 255
 * 2. Al llegar a 255, invierte la dirección
 * 3. Decrementa hasta llegar a 0
 * 4. Repite el ciclo
 * 
 * Hardware: LED + 220Ω en pin 9
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// DEFINICIÓN DE PINES
// ==================================================
const int LED_PIN = 9;  // Pin PWM

// ==================================================
// VARIABLES
// ==================================================
int brightness = 0;     // Brillo actual (0-255)
int fadeAmount = 5;     // Incremento por paso

// ==================================================
// SETUP
// ==================================================
void setup() {
    // analogWrite configura el pin automáticamente
    // pero es buena práctica declararlo
    pinMode(LED_PIN, OUTPUT);
    
    Serial.begin(9600);
    Serial.println("LED Fade iniciado");
}

// ==================================================
// LOOP
// ==================================================
void loop() {
    // Establecer brillo actual
    analogWrite(LED_PIN, brightness);
    
    // Mostrar valor en Serial Monitor
    Serial.print("Brillo: ");
    Serial.print(brightness);
    Serial.print(" (");
    Serial.print((brightness * 100) / 255);
    Serial.println("%)");
    
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

### Versión 2: Con millis() (No bloqueante)

```cpp
/*
 * LED Fade No Bloqueante
 * Permite ejecutar otras tareas mientras el LED hace fade
 */

const int LED_PIN = 9;
const unsigned long FADE_INTERVAL = 30;

int brightness = 0;
int fadeAmount = 5;
unsigned long previousMillis = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    unsigned long currentMillis = millis();
    
    // Solo actualizar si pasó el intervalo
    if (currentMillis - previousMillis >= FADE_INTERVAL) {
        previousMillis = currentMillis;
        
        analogWrite(LED_PIN, brightness);
        brightness += fadeAmount;
        
        if (brightness <= 0 || brightness >= 255) {
            fadeAmount = -fadeAmount;
        }
    }
    
    // Aquí puedes agregar otras tareas
}
```

---

## 🧪 Pruebas

### Verificación Básica

- [ ] El LED enciende gradualmente
- [ ] El LED apaga gradualmente  
- [ ] El ciclo se repite continuamente
- [ ] No hay parpadeo visible (transición suave)

### Experimentos

1. **Cambiar velocidad**: Modifica `fadeAmount` a 1 (más lento) o 10 (más rápido)
2. **Cambiar intervalo**: Modifica `delay(30)` a otros valores
3. **Rango limitado**: Cambia el rango a 50-200 para evitar apagado total

---

## 🎯 Desafíos

<details>
<summary><strong>Desafío 1: Velocidad variable</strong></summary>

Modifica el código para que la velocidad del fade cambie cada ciclo completo.

```cpp
int fadeSpeed = 5;

void loop() {
    analogWrite(LED_PIN, brightness);
    brightness += fadeAmount;
    
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
        
        // Cambiar velocidad al completar ciclo
        if (brightness <= 0) {
            fadeSpeed = random(1, 15);
            fadeAmount = fadeSpeed;
        }
    }
    
    delay(30);
}
```
</details>

<details>
<summary><strong>Desafío 2: Fade asimétrico</strong></summary>

Haz que el encendido sea lento y el apagado sea rápido.

```cpp
void loop() {
    analogWrite(LED_PIN, brightness);
    
    if (fadeAmount > 0) {
        // Encendido lento
        brightness += 2;
        delay(40);
    } else {
        // Apagado rápido
        brightness -= 10;
        delay(20);
    }
    
    if (brightness <= 0) {
        fadeAmount = 1;
        brightness = 0;
    }
    if (brightness >= 255) {
        fadeAmount = -1;
        brightness = 255;
    }
}
```
</details>

---

## ❓ Solución de Problemas

| Problema | Causa | Solución |
|----------|-------|----------|
| LED no enciende | Conexión incorrecta | Verificar polaridad LED |
| LED siempre al máximo | Pin no es PWM | Usar pin 3,5,6,9,10,11 |
| Parpadeo visible | Incremento muy grande | Reducir fadeAmount |
| Transición brusca | delay muy largo | Reducir delay |

---

## 📝 Conceptos Aprendidos

- ✅ Uso de `analogWrite()` para PWM
- ✅ Control de brillo con valores 0-255
- ✅ Inversión de dirección con variable
- ✅ Diferencia entre versión bloqueante y no bloqueante

---

## ➡️ Siguiente

[Control RGB →](./02-control-rgb.md)
