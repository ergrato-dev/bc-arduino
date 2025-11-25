# Semana 7: Motores y Actuadores

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Controlar servomotores con la librería Servo
- Manejar motores DC con puente H (L293D)
- Entender el funcionamiento de motores paso a paso
- Implementar control de relés para cargas
- Crear sistemas de movimiento automatizados

---

## 📚 Contenido Teórico

### 1. Servomotores (45 min)

#### Características

```
Servo = Motor con control de posición angular

Tipos comunes:
- Micro servo (SG90): 180° de rotación, ~1.5kg·cm torque
- Servo estándar: 180° de rotación, ~3-4kg·cm torque
- Servo de rotación continua: Gira 360° continuamente

Señal de control:
- PWM con periodo de 20ms (50Hz)
- Pulso de 1ms = 0°
- Pulso de 1.5ms = 90° (centro)
- Pulso de 2ms = 180°
```

#### Conexiones

```
Servo (3 cables):
  Marrón/Negro → GND
  Rojo → 5V (o fuente externa para servos grandes)
  Naranja/Amarillo → Pin PWM Arduino

    ┌──────────────┐
    │    SERVO     │
    │  ┌────────┐  │
    │  │   ⚙️   │  │
    │  └────────┘  │
    │ ─┬──┬──┬─    │
    └──┼──┼──┼─────┘
       │  │  │
      GND 5V PWM
```

#### Librería Servo

```cpp
#include <Servo.h>

Servo miServo;

void setup() {
    miServo.attach(9);  // Pin PWM

    // Configuración opcional con límites
    // miServo.attach(pin, min_us, max_us);
    // miServo.attach(9, 544, 2400);
}

void loop() {
    miServo.write(90);      // Mover a 90 grados
    miServo.writeMicroseconds(1500);  // Control preciso

    int posicion = miServo.read();  // Leer última posición
}
```

---

### 2. Motores DC y Puente H (45 min)

#### Concepto de Puente H

```
Puente H = Circuito para controlar dirección de motor DC

       5V                    5V
        │                     │
    ┌───┴───┐             ┌───┴───┐
    │  S1   │             │  S2   │
    │   ○   │             │   ○   │
    └───┬───┘             └───┬───┘
        │   ┌─────────┐       │
        └───┤    M    ├───────┘  ← Motor
            └─────────┘
        ┌───┐             ┌───┐
        │S3 │             │S4 │
        │ ○ │             │ ○ │
        └─┬─┘             └─┬─┘
          │                 │
         GND               GND

S1+S4 cerrados: Gira en una dirección
S2+S3 cerrados: Gira en dirección opuesta
S1+S3 ó S2+S4: Freno
Todos abiertos: Motor libre
```

#### IC L293D

```
L293D = Driver dual de puente H

            ┌────────────────┐
  Enable 1 ─┤1            16├─ VCC1 (5V lógica)
   Input 1 ─┤2            15├─ Input 4
  Output 1 ─┤3            14├─ Output 4
       GND ─┤4            13├─ GND
       GND ─┤5            12├─ GND
  Output 2 ─┤6            11├─ Output 3
   Input 2 ─┤7            10├─ Input 3
 VCC2(Vmotor)─┤8             9├─ Enable 2
            └────────────────┘

Capacidades:
- 2 motores DC o 1 motor paso a paso
- Corriente: 600mA por canal (1.2A pico)
- Voltaje motor: hasta 36V
```

#### Control de Velocidad y Dirección

```cpp
// Pines para motor 1
const int ENABLE1 = 9;   // PWM para velocidad
const int INPUT1 = 7;    // Dirección
const int INPUT2 = 6;    // Dirección

void setup() {
    pinMode(ENABLE1, OUTPUT);
    pinMode(INPUT1, OUTPUT);
    pinMode(INPUT2, OUTPUT);
}

// Adelante
void adelante(int velocidad) {
    digitalWrite(INPUT1, HIGH);
    digitalWrite(INPUT2, LOW);
    analogWrite(ENABLE1, velocidad);  // 0-255
}

// Atrás
void atras(int velocidad) {
    digitalWrite(INPUT1, LOW);
    digitalWrite(INPUT2, HIGH);
    analogWrite(ENABLE1, velocidad);
}

// Frenar
void frenar() {
    digitalWrite(INPUT1, HIGH);
    digitalWrite(INPUT2, HIGH);
    analogWrite(ENABLE1, 255);
}

// Parar (libre)
void parar() {
    analogWrite(ENABLE1, 0);
}
```

---

### 3. Motores Paso a Paso (30 min)

#### Concepto

```
Motor Paso a Paso = Motor que se mueve en incrementos discretos

Tipos:
- Unipolar: 5 o 6 cables
- Bipolar: 4 cables

28BYJ-48 (común y económico):
- Unipolar de 5 cables
- 64 pasos por revolución (interno)
- Relación de engranajes: 1:64
- Pasos reales: 64 × 64 = 4096 pasos/vuelta
- Ángulo por paso: 360°/4096 ≈ 0.088°
```

#### Secuencias de Paso

```
Paso completo (4 pasos por ciclo):
  Paso    Bobina A   Bobina B   Bobina C   Bobina D
    1        ON         OFF        OFF        OFF
    2        OFF        ON         OFF        OFF
    3        OFF        OFF        ON         OFF
    4        OFF        OFF        OFF        ON

Medio paso (8 pasos por ciclo - más suave):
  Paso    A   B   C   D
    1     ON  OFF OFF OFF
    2     ON  ON  OFF OFF
    3     OFF ON  OFF OFF
    4     OFF ON  ON  OFF
    5     OFF OFF ON  OFF
    6     OFF OFF ON  ON
    7     OFF OFF OFF ON
    8     ON  OFF OFF ON
```

---

### 4. Relés (30 min)

#### Funcionamiento

```
Relé = Interruptor electromagnético

Ventajas:
- Aisla circuito de control del de potencia
- Permite controlar cargas AC con Arduino
- Puede manejar altas corrientes

Módulo Relé típico:
┌─────────────────────────────┐
│  ┌──────┐   ┌──────────┐   │
│  │ LED  │   │  RELÉ    │   │
│  └──────┘   │  ┌────┐  │   │
│             │  │ ⚡ │  │   │
│  IN  GND  VCC │  └────┘  │   │
│  │    │    │  └──────────┘   │
│  ●    ●    ●   NC  COM  NO   │
└──┼────┼────┼───┼───┼────┼───┘
   │    │    │   │   │    │
  Pin  GND  5V   Terminales de carga

NC = Normalmente Cerrado (conectado cuando relé OFF)
NO = Normalmente Abierto (conectado cuando relé ON)
COM = Común
```

#### Precauciones

```cpp
// IMPORTANTE: Los relés consumen corriente al activarse
// Usar transistor o módulo con optoacoplador

// Patrón de uso seguro:
const int RELE_PIN = 7;

void setup() {
    pinMode(RELE_PIN, OUTPUT);
    digitalWrite(RELE_PIN, LOW);  // Empezar apagado
}

void activarRele() {
    digitalWrite(RELE_PIN, HIGH);
}

void desactivarRele() {
    digitalWrite(RELE_PIN, LOW);
}
```

---

## 💻 Ejercicios Prácticos

### Ejercicio 1: Control de Servo con Potenciómetro (30 min)

**Objetivo:** Controlar posición del servo con un potenciómetro.

**Componentes:**

- Arduino Uno R3
- 1 Micro Servo
- 1 Potenciómetro 10kΩ

**Diagrama:**

```
Servo:
  GND → GND
  VCC → 5V
  Señal → Pin 9

Potenciómetro → A0
```

**Código:**

```cpp
/*
 * Ejercicio 1: Servo con Potenciómetro
 * El pot controla la posición del servo
 */

#include <Servo.h>

Servo miServo;
const int POT_PIN = A0;
const int SERVO_PIN = 9;

void setup() {
    miServo.attach(SERVO_PIN);
    Serial.begin(9600);
}

void loop() {
    int valorPot = analogRead(POT_PIN);
    int angulo = map(valorPot, 0, 1023, 0, 180);

    miServo.write(angulo);

    Serial.print("Pot: ");
    Serial.print(valorPot);
    Serial.print(" -> Angulo: ");
    Serial.println(angulo);

    delay(15);  // Dar tiempo al servo
}
```

---

### Ejercicio 2: Barrido Automático de Servo (30 min)

**Objetivo:** Crear un movimiento de barrido automático.

**Componentes:**

- Arduino Uno R3
- 1 Micro Servo

**Código:**

```cpp
/*
 * Ejercicio 2: Barrido de Servo
 * El servo se mueve de 0° a 180° y viceversa
 */

#include <Servo.h>

Servo miServo;
const int SERVO_PIN = 9;

int angulo = 0;
int incremento = 1;
int velocidadDelay = 15;

void setup() {
    miServo.attach(SERVO_PIN);
    Serial.begin(9600);
}

void loop() {
    miServo.write(angulo);

    angulo += incremento;

    if (angulo >= 180 || angulo <= 0) {
        incremento = -incremento;
        Serial.println(angulo >= 180 ? "Vuelta..." : "Ida...");
    }

    delay(velocidadDelay);
}
```

---

### Ejercicio 3: Motor DC con Control de Velocidad (45 min)

**Objetivo:** Controlar velocidad y dirección de motor DC.

**Componentes:**

- Arduino Uno R3
- Motor DC
- L293D (o módulo puente H)
- Potenciómetro 10kΩ
- Botón

**Diagrama:**

```
L293D:
  Pin 1 (Enable) → Pin 9 (PWM)
  Pin 2 (Input 1) → Pin 7
  Pin 3 (Output 1) → Motor terminal 1
  Pin 4,5 → GND
  Pin 6 (Output 2) → Motor terminal 2
  Pin 7 (Input 2) → Pin 6
  Pin 8 → Alimentación motor (5-12V)
  Pin 16 → 5V

Potenciómetro → A0
Botón → Pin 2 (cambio de dirección)
```

**Código:**

```cpp
/*
 * Ejercicio 3: Motor DC Controlado
 * Pot controla velocidad, botón cambia dirección
 */

const int ENABLE_PIN = 9;
const int INPUT1_PIN = 7;
const int INPUT2_PIN = 6;
const int POT_PIN = A0;
const int BTN_PIN = 2;

bool direccion = true;  // true = adelante
int estadoBtnAnterior = HIGH;

void setup() {
    pinMode(ENABLE_PIN, OUTPUT);
    pinMode(INPUT1_PIN, OUTPUT);
    pinMode(INPUT2_PIN, OUTPUT);
    pinMode(BTN_PIN, INPUT_PULLUP);

    Serial.begin(9600);
    Serial.println("Control Motor DC");
}

void loop() {
    // Leer velocidad del potenciómetro
    int valorPot = analogRead(POT_PIN);
    int velocidad = map(valorPot, 0, 1023, 0, 255);

    // Detectar cambio de dirección
    int estadoBtn = digitalRead(BTN_PIN);
    if (estadoBtn == LOW && estadoBtnAnterior == HIGH) {
        direccion = !direccion;
        Serial.print("Direccion: ");
        Serial.println(direccion ? "Adelante" : "Atras");
        delay(50);  // Debounce simple
    }
    estadoBtnAnterior = estadoBtn;

    // Aplicar dirección
    if (direccion) {
        digitalWrite(INPUT1_PIN, HIGH);
        digitalWrite(INPUT2_PIN, LOW);
    } else {
        digitalWrite(INPUT1_PIN, LOW);
        digitalWrite(INPUT2_PIN, HIGH);
    }

    // Aplicar velocidad
    analogWrite(ENABLE_PIN, velocidad);

    // Mostrar estado
    static unsigned long ultimoLog = 0;
    if (millis() - ultimoLog > 500) {
        ultimoLog = millis();
        Serial.print("Velocidad: ");
        Serial.print(map(velocidad, 0, 255, 0, 100));
        Serial.println("%");
    }
}
```

---

### Ejercicio 4: Múltiples Servos (45 min)

**Objetivo:** Controlar 2 servos independientemente.

**Componentes:**

- Arduino Uno R3
- 2 Micro Servos
- 2 Potenciómetros 10kΩ

**Código:**

```cpp
/*
 * Ejercicio 4: Dos Servos Independientes
 * Cada pot controla un servo
 */

#include <Servo.h>

Servo servo1;
Servo servo2;

const int SERVO1_PIN = 9;
const int SERVO2_PIN = 10;
const int POT1_PIN = A0;
const int POT2_PIN = A1;

// Suavizado
int anguloActual1 = 90;
int anguloActual2 = 90;
const int SUAVIZADO = 5;  // Velocidad de suavizado

void setup() {
    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN);

    // Posición inicial
    servo1.write(90);
    servo2.write(90);

    Serial.begin(9600);
}

void loop() {
    // Leer objetivos
    int objetivo1 = map(analogRead(POT1_PIN), 0, 1023, 0, 180);
    int objetivo2 = map(analogRead(POT2_PIN), 0, 1023, 0, 180);

    // Suavizar movimiento
    anguloActual1 = suavizar(anguloActual1, objetivo1, SUAVIZADO);
    anguloActual2 = suavizar(anguloActual2, objetivo2, SUAVIZADO);

    // Aplicar
    servo1.write(anguloActual1);
    servo2.write(anguloActual2);

    // Debug
    Serial.print("S1: ");
    Serial.print(anguloActual1);
    Serial.print("° | S2: ");
    Serial.print(anguloActual2);
    Serial.println("°");

    delay(20);
}

int suavizar(int actual, int objetivo, int velocidad) {
    if (actual < objetivo) {
        actual += min(velocidad, objetivo - actual);
    } else if (actual > objetivo) {
        actual -= min(velocidad, actual - objetivo);
    }
    return actual;
}
```

---

## 🔨 Proyecto de la Semana: Brazo Robótico Simple

**Descripción:** Brazo robótico de 2 ejes con control por joystick/potenciómetros.

**Componentes:**

- Arduino Uno R3
- 2 Servomotores
- 2 Potenciómetros (o 1 joystick)
- 1 Botón (para posiciones guardadas)
- LCD 16x2 (opcional)

**Código Solución:**

```cpp
/*
 * Proyecto Semana 7: Brazo Robótico
 * Control de 2 servos con memoria de posiciones
 */

#include <Servo.h>

Servo servoBase;
Servo servoBrazo;

// Pines
const int SERVO_BASE_PIN = 9;
const int SERVO_BRAZO_PIN = 10;
const int POT_BASE_PIN = A0;
const int POT_BRAZO_PIN = A1;
const int BTN_GUARDAR = 2;
const int BTN_REPRODUCIR = 3;

// Configuración de servos
const int BASE_MIN = 0;
const int BASE_MAX = 180;
const int BRAZO_MIN = 30;   // Limitar para evitar colisiones
const int BRAZO_MAX = 150;

// Posiciones actuales
int anguloBase = 90;
int anguloBrazo = 90;

// Memoria de posiciones
const int MAX_POSICIONES = 10;
int posicionesBase[MAX_POSICIONES];
int posicionesBrazo[MAX_POSICIONES];
int numPosiciones = 0;

// Estados
bool modoReproduccion = false;
int indiceReproduccion = 0;
unsigned long ultimoMovimiento = 0;
const int TIEMPO_ENTRE_POSICIONES = 1000;

// Debounce
unsigned long ultimoDebounce = 0;
const unsigned long DEBOUNCE_DELAY = 200;

void setup() {
    servoBase.attach(SERVO_BASE_PIN);
    servoBrazo.attach(SERVO_BRAZO_PIN);

    pinMode(BTN_GUARDAR, INPUT_PULLUP);
    pinMode(BTN_REPRODUCIR, INPUT_PULLUP);

    // Posición inicial
    servoBase.write(90);
    servoBrazo.write(90);

    Serial.begin(9600);
    Serial.println("=== BRAZO ROBOTICO ===");
    Serial.println("Controles:");
    Serial.println("  Pot 1: Base");
    Serial.println("  Pot 2: Brazo");
    Serial.println("  Btn 1: Guardar posicion");
    Serial.println("  Btn 2: Reproducir secuencia");
    Serial.println();
}

void loop() {
    manejarBotones();

    if (modoReproduccion) {
        reproducirSecuencia();
    } else {
        controlManual();
    }
}

void manejarBotones() {
    if (millis() - ultimoDebounce > DEBOUNCE_DELAY) {
        // Botón guardar
        if (digitalRead(BTN_GUARDAR) == LOW) {
            ultimoDebounce = millis();
            guardarPosicion();
        }

        // Botón reproducir
        if (digitalRead(BTN_REPRODUCIR) == LOW) {
            ultimoDebounce = millis();
            toggleReproduccion();
        }
    }
}

void controlManual() {
    // Leer potenciómetros
    int valorBase = analogRead(POT_BASE_PIN);
    int valorBrazo = analogRead(POT_BRAZO_PIN);

    // Mapear a rangos permitidos
    int objetivoBase = map(valorBase, 0, 1023, BASE_MIN, BASE_MAX);
    int objetivoBrazo = map(valorBrazo, 0, 1023, BRAZO_MIN, BRAZO_MAX);

    // Suavizar movimiento
    anguloBase = suavizarMovimiento(anguloBase, objetivoBase, 3);
    anguloBrazo = suavizarMovimiento(anguloBrazo, objetivoBrazo, 3);

    // Aplicar
    servoBase.write(anguloBase);
    servoBrazo.write(anguloBrazo);

    // Mostrar estado periódicamente
    static unsigned long ultimoLog = 0;
    if (millis() - ultimoLog > 500) {
        ultimoLog = millis();
        mostrarEstado();
    }

    delay(20);
}

void guardarPosicion() {
    if (numPosiciones < MAX_POSICIONES) {
        posicionesBase[numPosiciones] = anguloBase;
        posicionesBrazo[numPosiciones] = anguloBrazo;
        numPosiciones++;

        Serial.print("Posicion ");
        Serial.print(numPosiciones);
        Serial.print(" guardada: Base=");
        Serial.print(anguloBase);
        Serial.print(", Brazo=");
        Serial.println(anguloBrazo);
    } else {
        Serial.println("Memoria llena!");
    }
}

void toggleReproduccion() {
    if (numPosiciones == 0) {
        Serial.println("No hay posiciones guardadas");
        return;
    }

    modoReproduccion = !modoReproduccion;
    indiceReproduccion = 0;

    if (modoReproduccion) {
        Serial.println("Iniciando reproduccion...");
    } else {
        Serial.println("Reproduccion detenida");
    }
}

void reproducirSecuencia() {
    if (millis() - ultimoMovimiento >= TIEMPO_ENTRE_POSICIONES) {
        ultimoMovimiento = millis();

        // Mover a posición guardada
        int objetivoBase = posicionesBase[indiceReproduccion];
        int objetivoBrazo = posicionesBrazo[indiceReproduccion];

        Serial.print("Moviendo a posicion ");
        Serial.print(indiceReproduccion + 1);
        Serial.print(": Base=");
        Serial.print(objetivoBase);
        Serial.print(", Brazo=");
        Serial.println(objetivoBrazo);

        // Movimiento suave hacia la posición
        moverSuave(objetivoBase, objetivoBrazo);

        // Siguiente posición
        indiceReproduccion++;
        if (indiceReproduccion >= numPosiciones) {
            indiceReproduccion = 0;  // Reiniciar ciclo
        }
    }
}

void moverSuave(int objetivoBase, int objetivoBrazo) {
    // Movimiento interpolado
    int pasos = 50;
    int inicioBase = anguloBase;
    int inicioBrazo = anguloBrazo;

    for (int i = 0; i <= pasos; i++) {
        anguloBase = map(i, 0, pasos, inicioBase, objetivoBase);
        anguloBrazo = map(i, 0, pasos, inicioBrazo, objetivoBrazo);

        servoBase.write(anguloBase);
        servoBrazo.write(anguloBrazo);

        delay(10);
    }
}

int suavizarMovimiento(int actual, int objetivo, int velocidad) {
    if (actual < objetivo) {
        return actual + min(velocidad, objetivo - actual);
    } else if (actual > objetivo) {
        return actual - min(velocidad, actual - objetivo);
    }
    return actual;
}

void mostrarEstado() {
    Serial.print("Base: ");
    Serial.print(anguloBase);
    Serial.print("° | Brazo: ");
    Serial.print(anguloBrazo);
    Serial.print("° | Posiciones: ");
    Serial.print(numPosiciones);
    Serial.print("/");
    Serial.print(MAX_POSICIONES);
    if (modoReproduccion) {
        Serial.print(" [REPRODUCIENDO]");
    }
    Serial.println();
}
```

---

## 📖 Recursos

### Documentación

- [Servo Library](https://www.arduino.cc/reference/en/libraries/servo/)
- [L293D Datasheet](https://www.ti.com/lit/ds/symlink/l293.pdf)

### Tutoriales

- [Servo Motor Tutorial](https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep)
- [DC Motor Control](https://www.arduino.cc/en/Tutorial/TransistorMotorControl)

---

## ✅ Checklist de Completitud

- [ ] Ejercicio 1: Servo con potenciómetro completado
- [ ] Ejercicio 2: Barrido automático funcionando
- [ ] Ejercicio 3: Motor DC con control completo
- [ ] Ejercicio 4: Múltiples servos coordinados
- [ ] Proyecto: Brazo robótico con memoria
- [ ] Servo Library dominada
- [ ] Puente H entendido e implementado
- [ ] Circuitos guardados en Tinkercad

---

## 🎓 Evaluación

| Componente                    | Porcentaje |
| ----------------------------- | ---------- |
| Ejercicios prácticos (1-4)    | 40%        |
| Proyecto de la semana         | 50%        |
| Control preciso de movimiento | 10%        |

---

## 📝 Notas Importantes

1. **Alimentación de servos:** Usar fuente externa para múltiples servos
2. **Límites de movimiento:** Evitar forzar servos contra topes
3. **Disipación de calor:** L293D puede calentarse con cargas altas
4. **Ruido eléctrico:** Motores generan ruido, usar capacitores de bypass

---

**Dedicación:** 4 horas | **Anterior:** [← Semana 6](../semana-06/README.md) | **Siguiente:** [Semana 8 →](../semana-08/README.md)
