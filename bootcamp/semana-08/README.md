# Semana 8: Sensores Avanzados

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Medir distancias con sensor ultrasónico HC-SR04
- Detectar movimiento con sensor PIR
- Leer temperatura y humedad con DHT11
- Integrar múltiples sensores en un sistema
- Aplicar filtros y procesamiento de datos

---

## 📚 Contenido Teórico

### 1. Sensor Ultrasónico HC-SR04 (45 min)

#### Principio de Funcionamiento

```
El HC-SR04 mide distancias mediante ondas ultrasónicas

1. Arduino envía pulso de 10µs al pin TRIG
2. Sensor emite 8 pulsos de ultrasonido a 40kHz
3. Ondas viajan, rebotan en objeto y regresan
4. Sensor activa pin ECHO durante el tiempo de viaje
5. Arduino mide duración del pulso ECHO

         ┌──────────┐
    ─────│ HC-SR04  │─────►  )))))) →  OBJETO
         │          │                    ↓
    ←────│          │←────  ((((((  ←───┘
         └──────────┘

    Distancia = (Tiempo × Velocidad del sonido) / 2
    Distancia (cm) = Tiempo (µs) × 0.034 / 2
```

#### Especificaciones

```
HC-SR04:
- Rango: 2cm - 400cm
- Precisión: ±3mm
- Ángulo de detección: ~15°
- Voltaje: 5V
- Corriente: 15mA
- Frecuencia: 40kHz

Pines:
  VCC → 5V
  TRIG → Pin digital (salida)
  ECHO → Pin digital (entrada)
  GND → GND
```

#### Código Básico

```cpp
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    Serial.begin(9600);
}

long medirDistancia() {
    // Enviar pulso de 10µs
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Medir duración del pulso ECHO
    long duracion = pulseIn(ECHO_PIN, HIGH);

    // Calcular distancia en cm
    long distancia = duracion * 0.034 / 2;

    return distancia;
}
```

---

### 2. Sensor PIR (30 min)

#### Funcionamiento

```
PIR = Passive Infrared (Infrarrojo Pasivo)

Detecta cambios en la radiación infrarroja causados por movimiento

       ┌─────────────────────┐
       │    ○ ○ ○ ○ ○ ○     │  ← Lente Fresnel
       │    ┌───────────┐    │
       │    │  SENSOR   │    │
       │    │  PYRO     │    │
       │    └───────────┘    │
       │  [●]         [●]    │  ← Potenciómetros
       │  Sens.       Tiempo │
       │                     │
       │  VCC  OUT  GND      │
       └───┼────┼────┼───────┘
           │    │    │
          5V  Pin   GND

Ajustes:
- Sensibilidad: Alcance de detección
- Tiempo: Duración de señal HIGH tras detección
```

#### Código Básico

```cpp
const int PIR_PIN = 2;

void setup() {
    pinMode(PIR_PIN, INPUT);
    Serial.begin(9600);

    // Tiempo de calibración del sensor (30-60 seg)
    Serial.println("Calibrando sensor PIR...");
    delay(30000);
    Serial.println("Listo!");
}

void loop() {
    if (digitalRead(PIR_PIN) == HIGH) {
        Serial.println("¡Movimiento detectado!");
    }
    delay(100);
}
```

---

### 3. Sensor DHT11 (45 min)

#### Características

```
DHT11 = Sensor digital de temperatura y humedad

Especificaciones:
- Temperatura: 0°C a 50°C (±2°C precisión)
- Humedad: 20% a 90% RH (±5% precisión)
- Resolución: 1°C / 1% RH
- Tiempo de muestreo: 1 segundo mínimo

Pines (vista frontal):
  ┌─────────────┐
  │    DHT11    │
  │             │
  │  ┌───────┐  │
  │  │       │  │
  │  │  :::  │  │
  │  │       │  │
  │  └───────┘  │
  │  1  2  3  4 │
  └──┼──┼──┼──┼─┘
     │  │  │  │
    VCC Data NC GND
```

#### Librería DHT

```cpp
#include <DHT.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
}

void loop() {
    // Esperar mínimo 2 segundos entre lecturas
    delay(2000);

    float humedad = dht.readHumidity();
    float temperatura = dht.readTemperature();

    // Verificar errores de lectura
    if (isnan(humedad) || isnan(temperatura)) {
        Serial.println("Error leyendo DHT!");
        return;
    }

    // Calcular índice de calor
    float indiceCalor = dht.computeHeatIndex(temperatura, humedad, false);

    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.print("% | Temp: ");
    Serial.print(temperatura);
    Serial.print("°C | Sensacion: ");
    Serial.print(indiceCalor);
    Serial.println("°C");
}
```

**Nota:** DHT11 no está disponible en Tinkercad. Para simulación, usar TMP36 para temperatura.

---

### 4. Filtrado de Datos (30 min)

#### Promedio Móvil

```cpp
const int NUM_LECTURAS = 10;
int lecturas[NUM_LECTURAS];
int indice = 0;
long total = 0;

void setup() {
    // Inicializar array
    for (int i = 0; i < NUM_LECTURAS; i++) {
        lecturas[i] = 0;
    }
}

int promedioMovil(int nuevaLectura) {
    total -= lecturas[indice];
    lecturas[indice] = nuevaLectura;
    total += lecturas[indice];
    indice = (indice + 1) % NUM_LECTURAS;

    return total / NUM_LECTURAS;
}
```

#### Filtro de Mediana

```cpp
int filtroMediana(int pin, int numMuestras) {
    int muestras[numMuestras];

    // Tomar muestras
    for (int i = 0; i < numMuestras; i++) {
        muestras[i] = analogRead(pin);
        delay(10);
    }

    // Ordenar (bubble sort simple)
    for (int i = 0; i < numMuestras - 1; i++) {
        for (int j = i + 1; j < numMuestras; j++) {
            if (muestras[j] < muestras[i]) {
                int temp = muestras[i];
                muestras[i] = muestras[j];
                muestras[j] = temp;
            }
        }
    }

    // Retornar mediana
    return muestras[numMuestras / 2];
}
```

---

## 💻 Ejercicios Prácticos

### Ejercicio 1: Medidor de Distancia (45 min)

**Objetivo:** Medir distancias y mostrar en monitor serial con indicadores.

**Componentes:**

- Arduino Uno R3
- HC-SR04
- 3 LEDs (Verde, Amarillo, Rojo)
- 3 Resistencias 220Ω

**Diagrama:**

```
HC-SR04:
  VCC → 5V
  TRIG → Pin 9
  ECHO → Pin 10
  GND → GND

LEDs:
  Pin 11 → LED Verde (lejos)
  Pin 12 → LED Amarillo (medio)
  Pin 13 → LED Rojo (cerca)
```

**Código:**

```cpp
/*
 * Ejercicio 1: Medidor de Distancia
 * Visualización con LEDs según proximidad
 */

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_LEJOS = 11;
const int LED_MEDIO = 12;
const int LED_CERCA = 13;

// Umbrales en cm
const int UMBRAL_CERCA = 20;
const int UMBRAL_MEDIO = 50;

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_LEJOS, OUTPUT);
    pinMode(LED_MEDIO, OUTPUT);
    pinMode(LED_CERCA, OUTPUT);

    Serial.begin(9600);
    Serial.println("=== Medidor de Distancia ===");
}

void loop() {
    long distancia = medirDistancia();

    // Actualizar LEDs
    apagarLEDs();

    if (distancia < UMBRAL_CERCA) {
        digitalWrite(LED_CERCA, HIGH);
        Serial.print("CERCA! ");
    } else if (distancia < UMBRAL_MEDIO) {
        digitalWrite(LED_MEDIO, HIGH);
        Serial.print("MEDIO  ");
    } else {
        digitalWrite(LED_LEJOS, HIGH);
        Serial.print("LEJOS  ");
    }

    // Mostrar distancia
    Serial.print("Distancia: ");
    if (distancia > 400 || distancia < 2) {
        Serial.println("Fuera de rango");
    } else {
        Serial.print(distancia);
        Serial.print(" cm  ");
        imprimirBarra(distancia);
    }

    delay(100);
}

long medirDistancia() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duracion = pulseIn(ECHO_PIN, HIGH, 30000);
    return duracion * 0.034 / 2;
}

void apagarLEDs() {
    digitalWrite(LED_LEJOS, LOW);
    digitalWrite(LED_MEDIO, LOW);
    digitalWrite(LED_CERCA, LOW);
}

void imprimirBarra(long distancia) {
    int barras = map(distancia, 0, 100, 20, 0);
    Serial.print("[");
    for (int i = 0; i < 20; i++) {
        Serial.print(i < barras ? "#" : "-");
    }
    Serial.println("]");
}
```

---

### Ejercicio 2: Detector de Movimiento (30 min)

**Objetivo:** Sistema de alarma con sensor PIR.

**Componentes:**

- Arduino Uno R3
- Sensor PIR
- LED Rojo
- Buzzer

**Diagrama:**

```
PIR:
  VCC → 5V
  OUT → Pin 2
  GND → GND

LED → Pin 9
Buzzer → Pin 8
```

**Código:**

```cpp
/*
 * Ejercicio 2: Alarma con PIR
 * Detecta movimiento y activa alarma
 */

const int PIR_PIN = 2;
const int LED_PIN = 9;
const int BUZZER_PIN = 8;

bool alarmaActivada = false;
bool movimientoDetectado = false;

unsigned long tiempoDeteccion = 0;
const unsigned long DURACION_ALARMA = 5000;

void setup() {
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    Serial.begin(9600);
    Serial.println("=== Sistema de Alarma ===");
    Serial.println("Calibrando sensor...");

    // Esperar calibración (reducido para simulación)
    for (int i = 5; i > 0; i--) {
        Serial.print(i);
        Serial.println("...");
        delay(1000);
    }

    Serial.println("Sistema ACTIVO");
    alarmaActivada = true;
}

void loop() {
    if (alarmaActivada) {
        // Leer sensor PIR
        if (digitalRead(PIR_PIN) == HIGH) {
            if (!movimientoDetectado) {
                movimientoDetectado = true;
                tiempoDeteccion = millis();
                Serial.println("!!! MOVIMIENTO DETECTADO !!!");
            }
        }

        // Manejar alarma
        if (movimientoDetectado) {
            // Efecto de alarma
            static unsigned long ultimoToggle = 0;
            static bool estadoLED = false;

            if (millis() - ultimoToggle >= 100) {
                ultimoToggle = millis();
                estadoLED = !estadoLED;
                digitalWrite(LED_PIN, estadoLED);

                if (estadoLED) {
                    tone(BUZZER_PIN, 2000);
                } else {
                    noTone(BUZZER_PIN);
                }
            }

            // Terminar alarma después de duración
            if (millis() - tiempoDeteccion >= DURACION_ALARMA) {
                movimientoDetectado = false;
                digitalWrite(LED_PIN, LOW);
                noTone(BUZZER_PIN);
                Serial.println("Alarma reseteada. Monitoreando...");
            }
        }
    }

    // Verificar comandos serial
    if (Serial.available() > 0) {
        char cmd = Serial.read();
        if (cmd == 'A' || cmd == 'a') {
            alarmaActivada = !alarmaActivada;
            Serial.print("Alarma: ");
            Serial.println(alarmaActivada ? "ACTIVADA" : "DESACTIVADA");
        }
    }
}
```

---

### Ejercicio 3: Sensor de Parking (45 min)

**Objetivo:** Sistema de ayuda al estacionamiento con ultrasonido.

**Componentes:**

- Arduino Uno R3
- HC-SR04
- Buzzer
- LCD 16x2

**Código:**

```cpp
/*
 * Ejercicio 3: Sensor de Parking
 * Aviso sonoro y visual de proximidad
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int BUZZER_PIN = 8;

// Configuración
const int DIST_MAX = 100;    // cm
const int DIST_ALERTA = 30;  // cm
const int DIST_PELIGRO = 10; // cm

// Caracteres LCD
byte barraLlena[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111};
byte barraVacia[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    lcd.begin(16, 2);
    lcd.createChar(0, barraLlena);
    lcd.createChar(1, barraVacia);

    lcd.print("Sensor Parking");
    lcd.setCursor(0, 1);
    lcd.print("Iniciando...");
    delay(2000);
}

void loop() {
    long distancia = medirDistanciaFiltrada();

    // Actualizar LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Dist: ");

    if (distancia > DIST_MAX) {
        lcd.print("---");
    } else {
        lcd.print(distancia);
        lcd.print(" cm");
    }

    // Barra de proximidad
    lcd.setCursor(0, 1);
    if (distancia <= DIST_MAX) {
        int nivel = map(distancia, DIST_MAX, 0, 0, 16);
        for (int i = 0; i < 16; i++) {
            lcd.write(i < nivel ? byte(0) : byte(1));
        }
    }

    // Señal sonora
    if (distancia <= DIST_PELIGRO) {
        tone(BUZZER_PIN, 2000);  // Continuo
        lcd.setCursor(12, 0);
        lcd.print("STOP");
    } else if (distancia <= DIST_ALERTA) {
        // Beep rápido
        tone(BUZZER_PIN, 1500, 50);
    } else if (distancia <= DIST_MAX / 2) {
        // Beep lento
        static unsigned long ultimoBeep = 0;
        if (millis() - ultimoBeep >= 500) {
            ultimoBeep = millis();
            tone(BUZZER_PIN, 1000, 50);
        }
    } else {
        noTone(BUZZER_PIN);
    }

    delay(100);
}

long medirDistanciaFiltrada() {
    // Promedio de 3 lecturas
    long suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += medirDistancia();
        delay(20);
    }
    return suma / 3;
}

long medirDistancia() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duracion = pulseIn(ECHO_PIN, HIGH, 30000);
    if (duracion == 0) return 999;
    return duracion * 0.034 / 2;
}
```

---

### Ejercicio 4: Multi-Sensor Logger (45 min)

**Objetivo:** Registrar datos de múltiples sensores.

**Componentes:**

- Arduino Uno R3
- HC-SR04
- TMP36 (simulando DHT11)
- LDR

**Código:**

```cpp
/*
 * Ejercicio 4: Multi-Sensor Logger
 * Registro de múltiples sensores con timestamps
 */

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int TEMP_PIN = A0;
const int LUZ_PIN = A1;

// Configuración de muestreo
unsigned long ultimoMuestreo = 0;
const unsigned long INTERVALO = 2000;
int contadorMuestras = 0;

// Promedios móviles
const int TAMANO_BUFFER = 5;
float bufferTemp[TAMANO_BUFFER];
int bufferDist[TAMANO_BUFFER];
int indiceBuff = 0;

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.begin(9600);

    // Inicializar buffers
    for (int i = 0; i < TAMANO_BUFFER; i++) {
        bufferTemp[i] = 20.0;
        bufferDist[i] = 100;
    }

    Serial.println("=== MULTI-SENSOR LOGGER ===");
    Serial.println("Formato: #,tiempo,temp,distancia,luz");
    Serial.println("---");
}

void loop() {
    if (millis() - ultimoMuestreo >= INTERVALO) {
        ultimoMuestreo = millis();
        contadorMuestras++;

        // Leer sensores
        float temp = leerTemperatura();
        int distancia = medirDistancia();
        int luz = analogRead(LUZ_PIN);

        // Actualizar buffers
        bufferTemp[indiceBuff] = temp;
        bufferDist[indiceBuff] = distancia;
        indiceBuff = (indiceBuff + 1) % TAMANO_BUFFER;

        // Calcular promedios
        float tempProm = calcularPromedioFloat(bufferTemp, TAMANO_BUFFER);
        int distProm = calcularPromedioInt(bufferDist, TAMANO_BUFFER);
        int luzPct = map(luz, 0, 1023, 0, 100);

        // Imprimir datos
        Serial.print(contadorMuestras);
        Serial.print(",");
        Serial.print(millis() / 1000.0, 1);
        Serial.print("s,");
        Serial.print(tempProm, 1);
        Serial.print("C,");
        Serial.print(distProm);
        Serial.print("cm,");
        Serial.print(luzPct);
        Serial.print("%");

        // Alertas
        if (tempProm > 30) Serial.print(" [TEMP ALTA]");
        if (distProm < 20) Serial.print(" [OBJETO CERCA]");
        if (luzPct < 20) Serial.print(" [OSCURO]");

        Serial.println();
    }

    // Comandos
    if (Serial.available() > 0) {
        char cmd = Serial.read();
        if (cmd == 'R' || cmd == 'r') {
            contadorMuestras = 0;
            Serial.println("--- CONTADOR RESETEADO ---");
        }
    }
}

float leerTemperatura() {
    int raw = analogRead(TEMP_PIN);
    float voltaje = (raw / 1023.0) * 5.0;
    return (voltaje - 0.5) * 100.0;
}

int medirDistancia() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duracion = pulseIn(ECHO_PIN, HIGH, 30000);
    if (duracion == 0) return 999;
    return duracion * 0.034 / 2;
}

float calcularPromedioFloat(float* arr, int tam) {
    float suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return suma / tam;
}

int calcularPromedioInt(int* arr, int tam) {
    long suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return suma / tam;
}
```

---

## 🔨 Proyecto de la Semana: Sistema de Seguridad Inteligente

**Descripción:** Sistema que combina todos los sensores para seguridad del hogar.

**Código Solución:**

```cpp
/*
 * Proyecto Semana 8: Sistema de Seguridad
 * Integración de HC-SR04, PIR, y sensores ambientales
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pines
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int PIR_PIN = 7;
const int TEMP_PIN = A0;
const int LUZ_PIN = A1;
const int LED_VERDE = A2;
const int LED_ROJO = A3;
const int BUZZER_PIN = 8;

// Estados del sistema
enum Estado { DESARMADO, ARMADO, ALERTA };
Estado estadoActual = DESARMADO;

// Configuración
const int DIST_INTRUSION = 50;  // cm
const float TEMP_MAX = 35.0;    // °C
const int LUZ_MIN = 100;        // Para detección nocturna

// Eventos
bool intrusionDetectada = false;
bool movimientoDetectado = false;
bool temperaturaAlta = false;

// Timing
unsigned long tiempoAlerta = 0;
const unsigned long DURACION_ALERTA = 10000;
unsigned long ultimaActualizacion = 0;
const unsigned long INTERVALO_LCD = 500;

// Caracteres LCD
byte candadoCerrado[8] = {B01110,B10001,B10001,B11111,B11011,B11011,B11111,B00000};
byte candadoAbierto[8] = {B01110,B10000,B10000,B11111,B11011,B11011,B11111,B00000};
byte alerta[8] = {B00100,B01110,B01110,B01110,B01110,B00000,B00100,B00000};

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_ROJO, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    lcd.begin(16, 2);
    lcd.createChar(0, candadoCerrado);
    lcd.createChar(1, candadoAbierto);
    lcd.createChar(2, alerta);

    Serial.begin(9600);

    // Pantalla de inicio
    lcd.print("Sistema Seguridad");
    lcd.setCursor(0, 1);
    lcd.print("Iniciando...");

    Serial.println("=== SISTEMA DE SEGURIDAD ===");
    Serial.println("Comandos:");
    Serial.println("  A - Armar sistema");
    Serial.println("  D - Desarmar sistema");
    Serial.println("  S - Estado");

    delay(2000);
    lcd.clear();

    cambiarEstado(DESARMADO);
}

void loop() {
    procesarComandos();

    // Actualizar sensores
    if (estadoActual == ARMADO || estadoActual == ALERTA) {
        verificarSensores();
    }

    // Actualizar display
    if (millis() - ultimaActualizacion >= INTERVALO_LCD) {
        ultimaActualizacion = millis();
        actualizarDisplay();
    }

    // Manejar alerta
    if (estadoActual == ALERTA) {
        manejarAlerta();
    }
}

void procesarComandos() {
    if (Serial.available() > 0) {
        char cmd = Serial.read();

        switch(cmd) {
            case 'A':
            case 'a':
                if (estadoActual == DESARMADO) {
                    Serial.println("Armando sistema...");
                    lcd.clear();
                    lcd.print("Armando...");

                    // Cuenta regresiva
                    for (int i = 5; i > 0; i--) {
                        lcd.setCursor(0, 1);
                        lcd.print(i);
                        lcd.print(" segundos  ");
                        tone(BUZZER_PIN, 1000, 100);
                        delay(1000);
                    }

                    cambiarEstado(ARMADO);
                }
                break;

            case 'D':
            case 'd':
                cambiarEstado(DESARMADO);
                Serial.println("Sistema desarmado");
                break;

            case 'S':
            case 's':
                imprimirEstado();
                break;
        }
    }
}

void verificarSensores() {
    // Verificar distancia (intrusion por proximidad)
    int distancia = medirDistancia();
    if (distancia > 0 && distancia < DIST_INTRUSION) {
        if (!intrusionDetectada) {
            intrusionDetectada = true;
            Serial.println("! INTRUSION por proximidad detectada");
            cambiarEstado(ALERTA);
        }
    }

    // Verificar PIR
    if (digitalRead(PIR_PIN) == HIGH) {
        if (!movimientoDetectado) {
            movimientoDetectado = true;
            Serial.println("! MOVIMIENTO detectado");
            cambiarEstado(ALERTA);
        }
    }

    // Verificar temperatura (posible incendio)
    float temp = leerTemperatura();
    if (temp > TEMP_MAX) {
        if (!temperaturaAlta) {
            temperaturaAlta = true;
            Serial.println("! TEMPERATURA ALTA detectada");
            cambiarEstado(ALERTA);
        }
    }
}

void manejarAlerta() {
    // Efectos de alarma
    static unsigned long ultimoToggle = 0;
    static bool toggle = false;

    if (millis() - ultimoToggle >= 200) {
        ultimoToggle = millis();
        toggle = !toggle;

        digitalWrite(LED_ROJO, toggle);

        if (toggle) {
            tone(BUZZER_PIN, 2000);
        } else {
            tone(BUZZER_PIN, 1500);
        }
    }

    // Auto-reset después de duración
    if (millis() - tiempoAlerta >= DURACION_ALERTA) {
        Serial.println("Alerta reseteada automaticamente");
        resetearAlertas();
        cambiarEstado(ARMADO);
    }
}

void cambiarEstado(Estado nuevoEstado) {
    estadoActual = nuevoEstado;

    switch(nuevoEstado) {
        case DESARMADO:
            digitalWrite(LED_VERDE, HIGH);
            digitalWrite(LED_ROJO, LOW);
            noTone(BUZZER_PIN);
            resetearAlertas();
            break;

        case ARMADO:
            digitalWrite(LED_VERDE, LOW);
            digitalWrite(LED_ROJO, LOW);
            noTone(BUZZER_PIN);
            break;

        case ALERTA:
            tiempoAlerta = millis();
            break;
    }

    actualizarDisplay();
}

void resetearAlertas() {
    intrusionDetectada = false;
    movimientoDetectado = false;
    temperaturaAlta = false;
}

void actualizarDisplay() {
    lcd.setCursor(0, 0);

    switch(estadoActual) {
        case DESARMADO:
            lcd.write(byte(1));
            lcd.print(" DESARMADO     ");
            break;

        case ARMADO:
            lcd.write(byte(0));
            lcd.print(" ARMADO        ");
            break;

        case ALERTA:
            lcd.write(byte(2));
            lcd.print(" !!! ALERTA !!!");
            break;
    }

    // Segunda línea: info de sensores
    lcd.setCursor(0, 1);

    if (estadoActual == ALERTA) {
        if (intrusionDetectada) lcd.print("INTRUSION ");
        else if (movimientoDetectado) lcd.print("MOVIMIENTO");
        else if (temperaturaAlta) lcd.print("TEMP ALTA ");
    } else {
        int dist = medirDistancia();
        float temp = leerTemperatura();

        lcd.print("D:");
        lcd.print(dist);
        lcd.print("cm T:");
        lcd.print((int)temp);
        lcd.print("C    ");
    }
}

void imprimirEstado() {
    Serial.println("--- Estado del Sistema ---");
    Serial.print("Estado: ");
    switch(estadoActual) {
        case DESARMADO: Serial.println("DESARMADO"); break;
        case ARMADO: Serial.println("ARMADO"); break;
        case ALERTA: Serial.println("ALERTA!"); break;
    }
    Serial.print("Distancia: ");
    Serial.print(medirDistancia());
    Serial.println(" cm");
    Serial.print("Temperatura: ");
    Serial.print(leerTemperatura(), 1);
    Serial.println(" C");
    Serial.print("Luz: ");
    Serial.println(analogRead(LUZ_PIN));
    Serial.println("-------------------------");
}

int medirDistancia() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duracion = pulseIn(ECHO_PIN, HIGH, 30000);
    if (duracion == 0) return 999;
    return duracion * 0.034 / 2;
}

float leerTemperatura() {
    int raw = analogRead(TEMP_PIN);
    float voltaje = (raw / 1023.0) * 5.0;
    return (voltaje - 0.5) * 100.0;
}
```

---

## 📖 Recursos

### Documentación

- [HC-SR04 Tutorial](https://www.arduino.cc/en/Tutorial/Ping)
- [PIR Motion Sensor](https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor)
- [DHT Library](https://github.com/adafruit/DHT-sensor-library)

---

## ✅ Checklist de Completitud

- [ ] Ejercicio 1: Medidor de distancia completado
- [ ] Ejercicio 2: Detector de movimiento funcionando
- [ ] Ejercicio 3: Sensor de parking operativo
- [ ] Ejercicio 4: Multi-sensor logger implementado
- [ ] Proyecto: Sistema de seguridad completo
- [ ] Filtrado de datos aplicado
- [ ] Integración de múltiples sensores
- [ ] Circuitos guardados en Tinkercad

---

## 🎓 Evaluación

| Componente                   | Porcentaje |
| ---------------------------- | ---------- |
| Ejercicios prácticos (1-4)   | 40%        |
| Proyecto de la semana        | 50%        |
| Calidad de filtrado de datos | 10%        |

---

**Dedicación:** 4 horas | **Anterior:** [← Semana 7](../semana-07/README.md) | **Siguiente:** [Semana 9 →](../semana-09/README.md)
