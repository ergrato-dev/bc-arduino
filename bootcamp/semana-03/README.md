# Semana 3: Salidas Analógicas (PWM)

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Comprender el concepto de PWM (Pulse Width Modulation)
- Controlar la intensidad de LEDs con analogWrite()
- Generar efectos de fade in/fade out
- Controlar la velocidad de motores DC
- Generar tonos con buzzer usando tone()

---

## 📚 Contenido Teórico

### 1. ¿Qué es PWM? (45 min)

#### Concepto Fundamental

Arduino no puede generar voltajes analógicos reales (como 2.5V). En cambio, usa **PWM (Modulación por Ancho de Pulso)** para simular valores intermedios.

```
PWM = Encender y apagar muy rápido un pin digital
      El porcentaje de tiempo encendido determina el "voltaje promedio"
```

#### Visualización del PWM

```
Duty Cycle 0% (analogWrite = 0) - Siempre apagado
   _____________________
  |                     |  0V promedio
  |_____________________|

Duty Cycle 25% (analogWrite = 64)
   ▓░░░▓░░░▓░░░▓░░░
   ┌─┐   ┌─┐   ┌─┐     ~1.25V promedio
   │ │   │ │   │ │
  ─┘ └───┘ └───┘ └───

Duty Cycle 50% (analogWrite = 127)
   ▓▓░░▓▓░░▓▓░░▓▓░░
   ┌──┐  ┌──┐  ┌──┐    ~2.5V promedio
   │  │  │  │  │  │
  ─┘  └──┘  └──┘  └──

Duty Cycle 75% (analogWrite = 191)
   ▓▓▓░▓▓▓░▓▓▓░▓▓▓░
   ┌───┐ ┌───┐ ┌───┐   ~3.75V promedio
   │   │ │   │ │   │
  ─┘   └─┘   └─┘   └─

Duty Cycle 100% (analogWrite = 255) - Siempre encendido
   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
   ─────────────────    5V promedio
```

#### Pines PWM en Arduino Uno

```
Pines con PWM: 3, 5, 6, 9, 10, 11 (marcados con ~)

    ┌─────────────────────────────────────────┐
    │     ARDUINO UNO                         │
    │                                         │
    │  0  1  2  3  4  5  6  7  8  9 10 11 12 13│
    │  RX TX     ~     ~  ~     ~  ~  ~       │
    │            ↑     ↑  ↑     ↑  ↑  ↑       │
    │          PWM   PWM PWM   PWM PWM PWM    │
    └─────────────────────────────────────────┘
```

#### Función analogWrite()

```cpp
// Sintaxis
analogWrite(pin, valor);

// pin: Solo pines PWM (3, 5, 6, 9, 10, 11)
// valor: 0 a 255 (8 bits)

// Ejemplos:
analogWrite(9, 0);    // 0% - Apagado
analogWrite(9, 64);   // 25%
analogWrite(9, 127);  // 50%
analogWrite(9, 191);  // 75%
analogWrite(9, 255);  // 100% - Máximo brillo
```

---

### 2. Frecuencia de PWM (30 min)

#### Frecuencias en Arduino Uno

```
Pines 3, 9, 10, 11 → ~490 Hz
Pines 5, 6         → ~980 Hz

Estas frecuencias son suficientes para:
- Control de LEDs (imperceptible al ojo humano)
- Control de motores DC
- NO para generar audio musical (usar tone())
```

#### Cálculo de Voltaje Promedio

```
V_promedio = (Duty Cycle / 100) × V_max

Ejemplo con valor PWM = 127:
Duty Cycle = (127 / 255) × 100 = 49.8%
V_promedio = 0.498 × 5V = 2.49V
```

---

### 3. Función map() (30 min)

#### Re-mapeo de Rangos

```cpp
// Sintaxis
map(valor, min_entrada, max_entrada, min_salida, max_salida);

// Ejemplo: Convertir lectura de potenciómetro (0-1023) a PWM (0-255)
int lectura = analogRead(A0);           // 0 a 1023
int pwm = map(lectura, 0, 1023, 0, 255); // 0 a 255

// Ejemplo: Convertir PWM a porcentaje
int porcentaje = map(pwm, 0, 255, 0, 100);
```

#### Visualización de map()

```
Entrada: 0 ────────────────────── 1023
         │                          │
         ↓     map() transforma     ↓
         │                          │
Salida:  0 ────────────────────── 255
```

---

### 4. Función tone() para Buzzer (30 min)

#### Generación de Tonos

```cpp
// Iniciar tono
tone(pin, frecuencia);           // Tono continuo
tone(pin, frecuencia, duracion); // Tono por tiempo específico

// Detener tono
noTone(pin);

// Ejemplo: Nota LA (440 Hz) por 500ms
tone(8, 440, 500);
```

#### Notas Musicales (Frecuencias)

```cpp
// Definiciones de notas musicales
#define NOTE_C4  262  // Do
#define NOTE_D4  294  // Re
#define NOTE_E4  330  // Mi
#define NOTE_F4  349  // Fa
#define NOTE_G4  392  // Sol
#define NOTE_A4  440  // La
#define NOTE_B4  494  // Si
#define NOTE_C5  523  // Do (octava superior)

// Silencio
#define REST     0
```

---

## 💻 Ejercicios Prácticos

### Ejercicio 1: Fade In/Fade Out de LED (30 min)

**Objetivo:** Crear efecto de respiración con un LED.

**Componentes:**

- Arduino Uno R3
- 1 LED
- 1 Resistencia 220Ω

**Diagrama:**

```
Pin 9 (PWM) ──[220Ω]──[LED]── GND
```

**Código:**

```cpp
/*
 * Ejercicio 1: Fade LED
 * Efecto de respiración usando PWM
 */

const int LED_PIN = 9;  // Pin PWM
int brillo = 0;
int incremento = 5;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // Establecer brillo
    analogWrite(LED_PIN, brillo);

    // Cambiar brillo
    brillo = brillo + incremento;

    // Invertir dirección en los extremos
    if (brillo <= 0 || brillo >= 255) {
        incremento = -incremento;
    }

    delay(30);  // Velocidad del fade
}
```

**Versión con función:**

```cpp
const int LED_PIN = 9;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    fadeIn(LED_PIN, 2000);   // 2 segundos para encender
    fadeOut(LED_PIN, 2000);  // 2 segundos para apagar
}

void fadeIn(int pin, int duracion) {
    int pausa = duracion / 256;
    for (int i = 0; i <= 255; i++) {
        analogWrite(pin, i);
        delay(pausa);
    }
}

void fadeOut(int pin, int duracion) {
    int pausa = duracion / 256;
    for (int i = 255; i >= 0; i--) {
        analogWrite(pin, i);
        delay(pausa);
    }
}
```

---

### Ejercicio 2: Control de Brillo con Potenciómetro (45 min)

**Objetivo:** Controlar brillo del LED con un potenciómetro.

**Componentes:**

- Arduino Uno R3
- 1 LED
- 1 Resistencia 220Ω
- 1 Potenciómetro 10kΩ

**Diagrama:**

```
Potenciómetro:
  5V ──┤├── A0
  GND ─┤│

LED:
  Pin 9 (PWM) ──[220Ω]──[LED]── GND
```

**Código:**

```cpp
/*
 * Ejercicio 2: Control de Brillo
 * Potenciómetro controla intensidad del LED
 */

const int POT_PIN = A0;
const int LED_PIN = 9;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Leer potenciómetro (0-1023)
    int valorPot = analogRead(POT_PIN);

    // Convertir a PWM (0-255)
    int brillo = map(valorPot, 0, 1023, 0, 255);

    // Aplicar brillo
    analogWrite(LED_PIN, brillo);

    // Mostrar en serial
    Serial.print("Pot: ");
    Serial.print(valorPot);
    Serial.print(" -> Brillo: ");
    Serial.print(brillo);
    Serial.print(" (");
    Serial.print(map(brillo, 0, 255, 0, 100));
    Serial.println("%)");

    delay(100);
}
```

---

### Ejercicio 3: Semáforo con Transiciones Suaves (45 min)

**Objetivo:** Mejorar el semáforo de la semana 1 con transiciones PWM.

**Componentes:**

- Arduino Uno R3
- 3 LEDs (Rojo, Amarillo, Verde)
- 3 Resistencias 220Ω

**Diagrama:**

```
Pin 11 (PWM) ──[220Ω]──[LED Rojo]──── GND
Pin 10 (PWM) ──[220Ω]──[LED Amarillo]── GND
Pin 9  (PWM) ──[220Ω]──[LED Verde]─── GND
```

**Código:**

```cpp
/*
 * Ejercicio 3: Semáforo con Transiciones
 * Los LEDs encienden y apagan gradualmente
 */

const int LED_ROJO = 11;
const int LED_AMARILLO = 10;
const int LED_VERDE = 9;

const int TIEMPO_VERDE = 4000;
const int TIEMPO_AMARILLO = 2000;
const int TIEMPO_ROJO = 4000;
const int TIEMPO_TRANSICION = 500;

void setup() {
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
}

void loop() {
    // Verde
    encenderSuave(LED_VERDE, TIEMPO_TRANSICION);
    delay(TIEMPO_VERDE);
    apagarSuave(LED_VERDE, TIEMPO_TRANSICION);

    // Amarillo
    encenderSuave(LED_AMARILLO, TIEMPO_TRANSICION);
    delay(TIEMPO_AMARILLO);
    apagarSuave(LED_AMARILLO, TIEMPO_TRANSICION);

    // Rojo
    encenderSuave(LED_ROJO, TIEMPO_TRANSICION);
    delay(TIEMPO_ROJO);
    apagarSuave(LED_ROJO, TIEMPO_TRANSICION);
}

void encenderSuave(int pin, int duracion) {
    int pausa = duracion / 256;
    for (int i = 0; i <= 255; i++) {
        analogWrite(pin, i);
        delay(pausa);
    }
}

void apagarSuave(int pin, int duracion) {
    int pausa = duracion / 256;
    for (int i = 255; i >= 0; i--) {
        analogWrite(pin, i);
        delay(pausa);
    }
}
```

---

### Ejercicio 4: Piano Básico con Buzzer (45 min)

**Objetivo:** Crear un piano de 4 notas con botones y buzzer.

**Componentes:**

- Arduino Uno R3
- 1 Buzzer pasivo
- 4 Botones pulsadores

**Diagrama:**

```
Buzzer:
Pin 8 ──[Buzzer]── GND

Botones (INPUT_PULLUP):
Pin 2 ── Botón DO ── GND
Pin 3 ── Botón RE ── GND
Pin 4 ── Botón MI ── GND
Pin 5 ── Botón FA ── GND
```

**Código:**

```cpp
/*
 * Ejercicio 4: Piano Básico
 * 4 botones reproducen 4 notas
 */

const int BUZZER_PIN = 8;

// Pines de botones
const int BOTON_DO = 2;
const int BOTON_RE = 3;
const int BOTON_MI = 4;
const int BOTON_FA = 5;

// Frecuencias de notas
const int NOTE_C4 = 262;  // Do
const int NOTE_D4 = 294;  // Re
const int NOTE_E4 = 330;  // Mi
const int NOTE_F4 = 349;  // Fa

void setup() {
    pinMode(BOTON_DO, INPUT_PULLUP);
    pinMode(BOTON_RE, INPUT_PULLUP);
    pinMode(BOTON_MI, INPUT_PULLUP);
    pinMode(BOTON_FA, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    if (digitalRead(BOTON_DO) == LOW) {
        tone(BUZZER_PIN, NOTE_C4);
    } else if (digitalRead(BOTON_RE) == LOW) {
        tone(BUZZER_PIN, NOTE_D4);
    } else if (digitalRead(BOTON_MI) == LOW) {
        tone(BUZZER_PIN, NOTE_E4);
    } else if (digitalRead(BOTON_FA) == LOW) {
        tone(BUZZER_PIN, NOTE_F4);
    } else {
        noTone(BUZZER_PIN);
    }
}
```

---

## 🔨 Proyecto de la Semana: Lámpara RGB Interactiva

**Descripción:** Crear una lámpara que cambia de color usando LEDs RGB y potenciómetros.

**Componentes:**

- Arduino Uno R3
- 1 LED RGB (cátodo común)
- 3 Resistencias 220Ω
- 3 Potenciómetros 10kΩ (opcional: 1 para modo)
- 1 Botón

**Diagrama de Conexión:**

```
LED RGB (Cátodo Común):
  Pin 11 (PWM) ──[220Ω]── Rojo
  Pin 10 (PWM) ──[220Ω]── Verde
  Pin 9  (PWM) ──[220Ω]── Azul
  GND ──────────────────── Cátodo (pata más larga)

Potenciómetros:
  A0 ── Pot Rojo
  A1 ── Pot Verde
  A2 ── Pot Azul

Botón:
  Pin 2 ── Botón ── GND
```

**Código Solución:**

```cpp
/*
 * Proyecto Semana 3: Lámpara RGB Interactiva
 * Modo 1: Control manual con potenciómetros
 * Modo 2: Ciclo automático de colores (arcoíris)
 * Modo 3: Efecto respiración en color fijo
 */

// Pines PWM para LED RGB
const int PIN_ROJO = 11;
const int PIN_VERDE = 10;
const int PIN_AZUL = 9;

// Pines analógicos para potenciómetros
const int POT_ROJO = A0;
const int POT_VERDE = A1;
const int POT_AZUL = A2;

// Pin del botón
const int BOTON_MODO = 2;

// Variables de control
int modoActual = 0;
const int TOTAL_MODOS = 3;

// Variables para botón con debounce
int estadoBotonAnterior = HIGH;
unsigned long ultimoDebounce = 0;
const unsigned long DELAY_DEBOUNCE = 50;

// Variables para efecto arcoíris
int matizArcoiris = 0;

// Variables para respiración
int brilloResp = 0;
int incrementoResp = 5;

void setup() {
    pinMode(PIN_ROJO, OUTPUT);
    pinMode(PIN_VERDE, OUTPUT);
    pinMode(PIN_AZUL, OUTPUT);
    pinMode(BOTON_MODO, INPUT_PULLUP);

    Serial.begin(9600);
    Serial.println("=== Lampara RGB Interactiva ===");
    imprimirModo();
}

void loop() {
    // Leer botón con debounce
    int lecturaBoton = digitalRead(BOTON_MODO);
    if (lecturaBoton != estadoBotonAnterior) {
        ultimoDebounce = millis();
    }
    if ((millis() - ultimoDebounce) > DELAY_DEBOUNCE) {
        if (lecturaBoton == LOW && estadoBotonAnterior == HIGH) {
            modoActual = (modoActual + 1) % TOTAL_MODOS;
            imprimirModo();
        }
    }
    estadoBotonAnterior = lecturaBoton;

    // Ejecutar modo actual
    switch (modoActual) {
        case 0:
            modoManual();
            break;
        case 1:
            modoArcoiris();
            break;
        case 2:
            modoRespiracion();
            break;
    }
}

void imprimirModo() {
    Serial.print("Modo: ");
    switch (modoActual) {
        case 0: Serial.println("Manual (Potenciometros)"); break;
        case 1: Serial.println("Arcoiris Automatico"); break;
        case 2: Serial.println("Respiracion"); break;
    }
}

// Modo 1: Control manual
void modoManual() {
    int rojo = map(analogRead(POT_ROJO), 0, 1023, 0, 255);
    int verde = map(analogRead(POT_VERDE), 0, 1023, 0, 255);
    int azul = map(analogRead(POT_AZUL), 0, 1023, 0, 255);

    setColor(rojo, verde, azul);
}

// Modo 2: Ciclo de colores
void modoArcoiris() {
    int rojo, verde, azul;

    // Convertir matiz (0-360) a RGB
    if (matizArcoiris < 60) {
        rojo = 255;
        verde = map(matizArcoiris, 0, 60, 0, 255);
        azul = 0;
    } else if (matizArcoiris < 120) {
        rojo = map(matizArcoiris, 60, 120, 255, 0);
        verde = 255;
        azul = 0;
    } else if (matizArcoiris < 180) {
        rojo = 0;
        verde = 255;
        azul = map(matizArcoiris, 120, 180, 0, 255);
    } else if (matizArcoiris < 240) {
        rojo = 0;
        verde = map(matizArcoiris, 180, 240, 255, 0);
        azul = 255;
    } else if (matizArcoiris < 300) {
        rojo = map(matizArcoiris, 240, 300, 0, 255);
        verde = 0;
        azul = 255;
    } else {
        rojo = 255;
        verde = 0;
        azul = map(matizArcoiris, 300, 360, 255, 0);
    }

    setColor(rojo, verde, azul);

    matizArcoiris = (matizArcoiris + 1) % 360;
    delay(20);
}

// Modo 3: Efecto respiración
void modoRespiracion() {
    // Color fijo: Cian (0, 255, 255)
    int factor = map(brilloResp, 0, 255, 0, 100);

    setColor(0,
             map(factor, 0, 100, 0, 255),
             map(factor, 0, 100, 0, 255));

    brilloResp += incrementoResp;
    if (brilloResp <= 0 || brilloResp >= 255) {
        incrementoResp = -incrementoResp;
    }

    delay(20);
}

// Función para establecer color RGB
void setColor(int rojo, int verde, int azul) {
    analogWrite(PIN_ROJO, rojo);
    analogWrite(PIN_VERDE, verde);
    analogWrite(PIN_AZUL, azul);
}
```

**Extensiones Opcionales:**

1. **Más modos:** Agregar modo estroboscópico, parpadeo aleatorio
2. **Guardar color:** Usar un botón para guardar color actual
3. **Colores predefinidos:** Botones para colores específicos

---

## 📖 Recursos

### Documentación

- [analogWrite() Reference](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)
- [tone() Reference](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/)
- [PWM Tutorial](https://www.arduino.cc/en/Tutorial/Foundations/PWM)

### Tutoriales

- [Fading a LED](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fading)
- [Play a Melody](https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody)

---

## ✅ Checklist de Completitud

- [ ] Ejercicio 1: Fade LED completado
- [ ] Ejercicio 2: Control con potenciómetro funcionando
- [ ] Ejercicio 3: Semáforo con transiciones suaves
- [ ] Ejercicio 4: Piano básico operativo
- [ ] Proyecto: Lámpara RGB con 3 modos
- [ ] Concepto de PWM entendido
- [ ] Función map() aplicada correctamente
- [ ] Circuitos guardados en Tinkercad

---

## 🎓 Evaluación

| Componente                 | Porcentaje |
| -------------------------- | ---------- |
| Ejercicios prácticos (1-4) | 40%        |
| Proyecto de la semana      | 50%        |
| Creatividad y extensiones  | 10%        |

---

## 📝 Notas Importantes

1. **Solo pines PWM:** analogWrite() solo funciona en pines marcados con ~
2. **Buzzer pasivo vs activo:** tone() solo funciona con buzzer pasivo
3. **LED RGB:** Verificar si es cátodo o ánodo común
4. **map() no limita valores:** Usar constrain() si es necesario

---

**Dedicación:** 4 horas | **Anterior:** [← Semana 2](../semana-02/README.md) | **Siguiente:** [Semana 4 →](../semana-04/README.md)
