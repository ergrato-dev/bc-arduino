# Semana 1: Introducción a Arduino y Electrónica Básica

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Comprender qué es un microcontrolador y sus aplicaciones
- Identificar los componentes principales de una placa Arduino Uno
- Configurar y utilizar el simulador Tinkercad
- Entender conceptos básicos de electrónica (V, I, R, Ley de Ohm)
- Escribir y cargar el primer programa en Arduino
- Controlar un LED con código

---

## 📚 Contenido Teórico

### 1. Introducción a Microcontroladores (45 min)

#### ¿Qué es un Microcontrolador?

Un microcontrolador es un pequeño computador en un solo chip que incluye:

- **CPU (Procesador):** Ejecuta las instrucciones
- **Memoria Flash:** Almacena el programa (no volátil)
- **SRAM:** Memoria para variables durante ejecución
- **EEPROM:** Memoria persistente para datos
- **Periféricos:** Pines de entrada/salida, temporizadores, ADC, etc.

#### Arduino: ¿Qué es?

Arduino es una plataforma de hardware y software libre que incluye:

- **Hardware:** Placas de desarrollo basadas en microcontroladores
- **Software:** IDE (Entorno de Desarrollo Integrado) gratuito
- **Comunidad:** Amplia documentación y ejemplos

#### Comparativa de Placas Arduino Uno

| Característica       | Uno R3     | Uno R4 Minima | Uno R4 WiFi | Uno Q      |
| -------------------- | ---------- | ------------- | ----------- | ---------- |
| Microcontrolador     | ATmega328P | RA4M1         | RA4M1       | ATmega328P |
| Velocidad            | 16 MHz     | 48 MHz        | 48 MHz      | 16 MHz     |
| Flash                | 32 KB      | 256 KB        | 256 KB      | 32 KB      |
| SRAM                 | 2 KB       | 32 KB         | 32 KB       | 2 KB       |
| WiFi                 | ❌         | ❌            | ✅          | ❌         |
| Bluetooth            | ❌         | ❌            | ✅          | ❌         |
| Conector Qwiic       | ❌         | ❌            | ❌          | ✅         |
| Compatible Tinkercad | ✅         | ❌            | ❌          | ❌         |

---

### 2. Anatomía del Arduino Uno R3 (30 min)

```
                    ┌─────────────────────────────────────┐
                    │    USB        ICSP         RESET    │
                    │     ▼          ▼             ▼      │
    ┌───────────────┼─────┴──────────┴─────────────┴──────┤
    │ IOREF         │                                     │
    │ RESET         │                                     │
    │ 3.3V          │         ARDUINO UNO R3              │
    │ 5V            │                                     │
    │ GND           │      ATmega328P                     │
    │ GND           │         16 MHz                      │
    │ Vin           │                                     │
    ├───────────────┤                                     │
    │ A0            │                                     │
    │ A1            │                                     │
    │ A2            │                                     │
    │ A3            │                                     │
    │ A4 (SDA)      │                                     │
    │ A5 (SCL)      │                                     │
    └───────────────┼─────────────────────────────────────┤
                    │  0  1  2  3  4  5  6  7  8  9 10 11 12 13  │
                    │  RX TX        ~     ~  ~     ~ ~  ~        │
                    │                     PWM PINS               │
                    └─────────────────────────────────────────────┘
```

#### Pines Importantes:

- **Digital (0-13):** Entrada/Salida digital (HIGH/LOW)
- **PWM (~):** Pines 3, 5, 6, 9, 10, 11 - Salida analógica simulada
- **Analógicos (A0-A5):** Entrada analógica (0-1023)
- **Alimentación:** 5V, 3.3V, GND, Vin
- **Comunicación:** TX(1), RX(0) para serial; A4(SDA), A5(SCL) para I2C

---

### 3. Conceptos de Electrónica Básica (45 min)

#### Ley de Ohm

```
V = I × R

Donde:
- V = Voltaje (Voltios - V)
- I = Corriente (Amperios - A)
- R = Resistencia (Ohmios - Ω)
```

#### Ejemplo Práctico: LED con Resistencia

```
Para un LED típico:
- Voltaje de fuente: 5V (Arduino)
- Voltaje del LED: ~2V
- Corriente deseada: 20mA (0.020A)

R = (V_fuente - V_LED) / I
R = (5V - 2V) / 0.020A
R = 150Ω (usar 220Ω por seguridad)
```

#### Código de Colores de Resistencias

```
Negro  = 0    Marrón = 1    Rojo    = 2    Naranja = 3
Amarillo = 4  Verde  = 5    Azul    = 6    Violeta = 7
Gris   = 8    Blanco = 9

Ejemplo 220Ω:
Rojo (2) - Rojo (2) - Marrón (×10) = 22 × 10 = 220Ω
```

---

### 4. Configuración de Tinkercad (30 min)

#### Crear Cuenta y Primer Circuito

1. Ir a [tinkercad.com](https://www.tinkercad.com/)
2. Crear cuenta gratuita
3. Seleccionar "Circuits" en el menú
4. Clic en "Create new Circuit"

#### Interfaz de Tinkercad

```
┌─────────────────────────────────────────────────────────────┐
│  [Tinkercad]  Circuits  │  Share  │  Export  │  Start Simulation │
├─────────────────────────────────────────────────────────────┤
│                                          │ Components Panel │
│                                          │ ┌──────────────┐ │
│         ÁREA DE TRABAJO                  │ │ ○ Arduino    │ │
│                                          │ │ ○ Basic      │ │
│    Arrastra componentes aquí             │ │ ○ Input      │ │
│                                          │ │ ○ Output     │ │
│                                          │ │ ○ Power      │ │
│                                          │ └──────────────┘ │
├─────────────────────────────────────────────────────────────┤
│  Code  │  Serial Monitor  │                                 │
└─────────────────────────────────────────────────────────────┘
```

---

### 5. Estructura de un Programa Arduino (30 min)

```cpp
// Comentarios de una línea

/*
   Comentarios de
   múltiples líneas
*/

// Declaración de constantes y variables globales
const int LED_PIN = 13;
int contador = 0;

// setup() - Se ejecuta UNA vez al inicio
void setup() {
    // Configuración inicial
    pinMode(LED_PIN, OUTPUT);
}

// loop() - Se ejecuta INFINITAMENTE después de setup()
void loop() {
    // Código principal que se repite
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
}
```

#### Funciones Básicas

| Función                    | Descripción                            |
| -------------------------- | -------------------------------------- |
| `pinMode(pin, modo)`       | Configura un pin como INPUT o OUTPUT   |
| `digitalWrite(pin, valor)` | Escribe HIGH (5V) o LOW (0V) en un pin |
| `digitalRead(pin)`         | Lee el estado de un pin digital        |
| `delay(ms)`                | Pausa la ejecución por milisegundos    |
| `delayMicroseconds(us)`    | Pausa por microsegundos                |

---

## 💻 Ejercicios Prácticos

### Ejercicio 1: Hola Mundo - Blink LED (30 min)

**Objetivo:** Hacer parpadear el LED integrado en el pin 13.

**Circuito en Tinkercad:**

- Arduino Uno R3
- (El LED del pin 13 está integrado)

**Código:**

```cpp
/*
 * Ejercicio 1: Blink LED
 * Hace parpadear el LED integrado cada segundo
 */

const int LED_PIN = 13;  // LED integrado

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);  // Enciende LED
    delay(1000);                  // Espera 1 segundo
    digitalWrite(LED_PIN, LOW);   // Apaga LED
    delay(1000);                  // Espera 1 segundo
}
```

**Retos adicionales:**

1. Cambia la velocidad del parpadeo a 500ms
2. Crea un patrón SOS en código Morse (... --- ...)

---

### Ejercicio 2: LED Externo con Resistencia (45 min)

**Objetivo:** Conectar y controlar un LED externo.

**Componentes:**

- Arduino Uno R3
- LED (cualquier color)
- Resistencia de 220Ω
- Cables de conexión

**Diagrama de Conexión:**

```
Arduino Pin 8 ──────[ 220Ω ]──────[LED +]────── GND
                                   (ánodo)    (cátodo)
```

**Circuito en Tinkercad:**

1. Arrastra un Arduino Uno
2. Arrastra un LED y una resistencia
3. Conecta: Pin 8 → Resistencia → LED (pata larga) → LED (pata corta) → GND

**Código:**

```cpp
/*
 * Ejercicio 2: LED Externo
 * Control de LED conectado al pin 8
 */

const int LED_EXTERNO = 8;

void setup() {
    pinMode(LED_EXTERNO, OUTPUT);
}

void loop() {
    // Parpadeo normal
    digitalWrite(LED_EXTERNO, HIGH);
    delay(500);
    digitalWrite(LED_EXTERNO, LOW);
    delay(500);
}
```

---

### Ejercicio 3: Semáforo Simple (45 min)

**Objetivo:** Simular un semáforo con 3 LEDs.

**Componentes:**

- Arduino Uno R3
- 1 LED Rojo
- 1 LED Amarillo
- 1 LED Verde
- 3 Resistencias de 220Ω

**Diagrama de Conexión:**

```
Pin 10 ──[ 220Ω ]──[LED Rojo]────── GND
Pin 9  ──[ 220Ω ]──[LED Amarillo]── GND
Pin 8  ──[ 220Ω ]──[LED Verde]───── GND
```

**Código:**

```cpp
/*
 * Ejercicio 3: Semáforo Simple
 * Simula el ciclo de un semáforo
 */

const int LED_ROJO = 10;
const int LED_AMARILLO = 9;
const int LED_VERDE = 8;

// Tiempos en milisegundos
const int TIEMPO_VERDE = 5000;
const int TIEMPO_AMARILLO = 2000;
const int TIEMPO_ROJO = 5000;

void setup() {
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);

    // Apagar todos al inicio
    apagarTodos();
}

void loop() {
    // Verde encendido
    digitalWrite(LED_VERDE, HIGH);
    delay(TIEMPO_VERDE);
    digitalWrite(LED_VERDE, LOW);

    // Amarillo encendido
    digitalWrite(LED_AMARILLO, HIGH);
    delay(TIEMPO_AMARILLO);
    digitalWrite(LED_AMARILLO, LOW);

    // Rojo encendido
    digitalWrite(LED_ROJO, HIGH);
    delay(TIEMPO_ROJO);
    digitalWrite(LED_ROJO, LOW);
}

void apagarTodos() {
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_VERDE, LOW);
}
```

---

### Ejercicio 4: LED con Parpadeo Variable (30 min)

**Objetivo:** Crear patrones de parpadeo usando variables.

**Código:**

```cpp
/*
 * Ejercicio 4: Parpadeo Variable
 * El LED parpadea cada vez más rápido y luego reinicia
 */

const int LED_PIN = 8;
int tiempoDelay = 1000;  // Inicia en 1 segundo
const int DECREMENTO = 100;
const int TIEMPO_MINIMO = 100;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // Parpadeo con tiempo actual
    digitalWrite(LED_PIN, HIGH);
    delay(tiempoDelay);
    digitalWrite(LED_PIN, LOW);
    delay(tiempoDelay);

    // Reducir tiempo
    tiempoDelay = tiempoDelay - DECREMENTO;

    // Reiniciar si llegamos al mínimo
    if (tiempoDelay < TIEMPO_MINIMO) {
        tiempoDelay = 1000;
        delay(2000);  // Pausa antes de reiniciar
    }
}
```

---

## 🔨 Proyecto de la Semana: Secuencia de LEDs "Knight Rider"

**Descripción:** Crear el efecto de luz del auto fantástico (KITT) usando 6 LEDs.

**Componentes:**

- Arduino Uno R3
- 6 LEDs (preferiblemente rojos)
- 6 Resistencias de 220Ω

**Diagrama de Conexión:**

```
Pin 3  ──[ 220Ω ]──[LED 1]── GND
Pin 4  ──[ 220Ω ]──[LED 2]── GND
Pin 5  ──[ 220Ω ]──[LED 3]── GND
Pin 6  ──[ 220Ω ]──[LED 4]── GND
Pin 7  ──[ 220Ω ]──[LED 5]── GND
Pin 8  ──[ 220Ω ]──[LED 6]── GND
```

**Código Solución:**

```cpp
/*
 * Proyecto Semana 1: Knight Rider
 * Efecto de luz que va de izquierda a derecha y viceversa
 */

// Array con los pines de los LEDs
const int NUM_LEDS = 6;
const int LEDS[] = {3, 4, 5, 6, 7, 8};
const int VELOCIDAD = 100;  // milisegundos entre cada LED

void setup() {
    // Configurar todos los pines como salida
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(LEDS[i], OUTPUT);
    }
}

void loop() {
    // Ida: de izquierda a derecha
    for (int i = 0; i < NUM_LEDS; i++) {
        encenderSoloUno(i);
        delay(VELOCIDAD);
    }

    // Vuelta: de derecha a izquierda
    for (int i = NUM_LEDS - 2; i > 0; i--) {
        encenderSoloUno(i);
        delay(VELOCIDAD);
    }
}

// Función que enciende solo un LED y apaga los demás
void encenderSoloUno(int indice) {
    for (int i = 0; i < NUM_LEDS; i++) {
        if (i == indice) {
            digitalWrite(LEDS[i], HIGH);
        } else {
            digitalWrite(LEDS[i], LOW);
        }
    }
}
```

**Variantes del Proyecto (Opcionales):**

1. **Velocidad variable:** Usar un potenciómetro para controlar la velocidad
2. **Efecto estela:** Dejar los LEDs encendidos con desvanecimiento
3. **Patrones múltiples:** Agregar diferentes modos de animación

---

## 📖 Recursos

### Documentación Oficial

- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
- [Arduino Uno R3 Documentation](https://docs.arduino.cc/hardware/uno-rev3)
- [Getting Started with Arduino](https://www.arduino.cc/en/Guide)

### Tutoriales Tinkercad

- [Circuits Learning](https://www.tinkercad.com/learn/circuits)
- [Blink LED Tutorial](https://www.tinkercad.com/learn/circuits/learning)

### Videos Recomendados

- [Arduino Course for Beginners - freeCodeCamp](https://www.youtube.com/watch?v=zJ-LqeX_fLU)
- [Tinkercad Arduino Tutorial](https://www.youtube.com/results?search_query=tinkercad+arduino+tutorial)

---

## ✅ Checklist de Completitud

- [ ] Cuenta de Tinkercad creada y verificada
- [ ] Ejercicio 1: Blink LED completado
- [ ] Ejercicio 2: LED Externo funcionando
- [ ] Ejercicio 3: Semáforo operativo
- [ ] Ejercicio 4: Parpadeo variable implementado
- [ ] Proyecto: Knight Rider completado
- [ ] Circuitos guardados en Tinkercad
- [ ] Código documentado con comentarios

---

## 🎓 Evaluación

| Componente                    | Porcentaje |
| ----------------------------- | ---------- |
| Ejercicios prácticos (1-4)    | 50%        |
| Proyecto de la semana         | 40%        |
| Participación y documentación | 10%        |

### Criterios de Evaluación del Proyecto:

- ✅ Circuito funciona correctamente en simulador
- ✅ Código limpio y comentado
- ✅ Variables con nombres descriptivos
- ✅ Uso correcto de funciones
- ✅ Implementación de al menos una variante opcional

---

## 📝 Notas Importantes

1. **Simular antes de ejecutar:** Siempre verifica en Tinkercad antes de usar hardware real
2. **Resistencias obligatorias:** NUNCA conectes un LED sin resistencia
3. **Polaridad del LED:** El ánodo (pata larga) va al positivo
4. **Corriente máxima:** Los pines de Arduino soportan máximo 20mA

---

**Dedicación:** 4 horas | **Siguiente:** [Semana 2 →](../semana-02/README.md)
