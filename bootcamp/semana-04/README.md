# Semana 4: Entradas Analógicas y Sensores

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Comprender la conversión analógica-digital (ADC)
- Leer valores de potenciómetros
- Implementar sensores de luz (LDR/fotorresistencias)
- Utilizar sensores de temperatura (TMP36)
- Calibrar y mapear lecturas de sensores

---

## 📚 Contenido Teórico

### 1. Conversión Analógica-Digital (ADC) (45 min)

#### ¿Qué es una Señal Analógica?

```
Señal Analógica: Valores continuos (infinitos valores posibles)
- Ejemplo: Voltaje de 0V a 5V puede ser 2.347V, 3.891V, etc.

Señal Digital: Valores discretos (cantidad finita de valores)
- Arduino Uno: 10 bits = 2^10 = 1024 valores posibles (0-1023)
```

#### ADC en Arduino Uno

```
Resolución: 10 bits
Rango de entrada: 0V a 5V
Valores posibles: 0 a 1023

Conversión:
┌──────────────────────────────────┐
│  0V   → analogRead() → 0        │
│  2.5V → analogRead() → ~512     │
│  5V   → analogRead() → 1023     │
└──────────────────────────────────┘

Fórmula para voltaje real:
Voltaje = (lectura / 1023.0) × 5.0
```

#### Pines Analógicos

```
Arduino Uno tiene 6 entradas analógicas:
A0, A1, A2, A3, A4, A5

    ┌─────────────────────────┐
    │    ARDUINO UNO          │
    │                         │
    │ A0 ← Entrada Analógica  │
    │ A1 ← Entrada Analógica  │
    │ A2 ← Entrada Analógica  │
    │ A3 ← Entrada Analógica  │
    │ A4 ← (también SDA I2C)  │
    │ A5 ← (también SCL I2C)  │
    └─────────────────────────┘
```

#### Función analogRead()

```cpp
// Sintaxis
int valor = analogRead(pin);

// pin: A0 a A5
// valor: 0 a 1023

// No necesita pinMode() para entradas analógicas
// La lectura toma aproximadamente 100 microsegundos
```

---

### 2. Divisor de Voltaje (30 min)

#### Concepto

Muchos sensores (LDR, termistores) cambian su resistencia según una variable física. Para leerlos con Arduino, usamos un **divisor de voltaje**.

```
Divisor de Voltaje:

    5V
     │
    [R1]  ← Resistencia fija o variable
     │
     ├──── Pin Analógico
     │
    [R2]  ← Resistencia fija o variable
     │
    GND

    V_out = V_in × (R2 / (R1 + R2))
```

#### Configuraciones Comunes

```
Con LDR (fotorresistencia):

Configuración 1: Mayor luz = Mayor lectura
    5V ──[LDR]──┬──[10kΩ]── GND
                │
               A0

Configuración 2: Mayor luz = Menor lectura
    5V ──[10kΩ]──┬──[LDR]── GND
                 │
                A0
```

---

### 3. Sensores en Tinkercad (30 min)

#### Sensores Disponibles

| Sensor                 | Tipo                 | Disponible en Tinkercad |
| ---------------------- | -------------------- | :---------------------: |
| Potenciómetro          | Resistivo            |           ✅            |
| Fotorresistencia (LDR) | Resistivo            |           ✅            |
| TMP36                  | Voltaje proporcional |           ✅            |
| Flex Sensor            | Resistivo            |           ✅            |
| Force Sensor           | Resistivo            |           ✅            |
| Ultrasónico HC-SR04    | Digital              |           ✅            |
| PIR                    | Digital              |           ✅            |

---

### 4. Calibración de Sensores (30 min)

#### Proceso de Calibración

```cpp
// Variables para calibración
int valorMinimo = 1023;  // Inicia con máximo
int valorMaximo = 0;     // Inicia con mínimo

// Durante el periodo de calibración, mover el sensor
// por todo su rango para encontrar min/max reales
void calibrar() {
    unsigned long tiempoInicio = millis();
    while (millis() - tiempoInicio < 5000) {  // 5 segundos
        int lectura = analogRead(A0);

        if (lectura > valorMaximo) {
            valorMaximo = lectura;
        }
        if (lectura < valorMinimo) {
            valorMinimo = lectura;
        }
    }
}

// Después usar map() con los valores calibrados
int valorMapeado = map(analogRead(A0), valorMinimo, valorMaximo, 0, 100);
```

---

## 💻 Ejercicios Prácticos

### Ejercicio 1: Lectura de Potenciómetro (30 min)

**Objetivo:** Leer valores del potenciómetro y mostrar en monitor serial.

**Componentes:**

- Arduino Uno R3
- 1 Potenciómetro 10kΩ

**Diagrama:**

```
Potenciómetro (3 terminales):
  Terminal 1: 5V
  Terminal 2 (central): A0
  Terminal 3: GND
```

**Código:**

```cpp
/*
 * Ejercicio 1: Lectura de Potenciómetro
 * Muestra valor raw, voltaje y porcentaje
 */

const int POT_PIN = A0;

void setup() {
    Serial.begin(9600);
    Serial.println("=== Lectura de Potenciometro ===");
}

void loop() {
    // Leer valor analógico (0-1023)
    int valorRaw = analogRead(POT_PIN);

    // Convertir a voltaje (0-5V)
    float voltaje = (valorRaw / 1023.0) * 5.0;

    // Convertir a porcentaje (0-100%)
    int porcentaje = map(valorRaw, 0, 1023, 0, 100);

    // Mostrar resultados
    Serial.print("Raw: ");
    Serial.print(valorRaw);
    Serial.print("\tVoltaje: ");
    Serial.print(voltaje, 2);  // 2 decimales
    Serial.print("V\tPorcentaje: ");
    Serial.print(porcentaje);
    Serial.println("%");

    delay(200);
}
```

---

### Ejercicio 2: Sensor de Luz (LDR) (45 min)

**Objetivo:** Crear un sistema de iluminación automática con LDR.

**Componentes:**

- Arduino Uno R3
- 1 Fotorresistencia (LDR)
- 1 Resistencia 10kΩ
- 1 LED
- 1 Resistencia 220Ω

**Diagrama:**

```
LDR con divisor de voltaje:
  5V ──[LDR]──┬──[10kΩ]── GND
              │
             A0

LED:
  Pin 9 (PWM) ──[220Ω]──[LED]── GND
```

**Código:**

```cpp
/*
 * Ejercicio 2: Luz Automática
 * LED se enciende cuando hay poca luz
 */

const int LDR_PIN = A0;
const int LED_PIN = 9;

// Umbrales (ajustar según iluminación)
const int UMBRAL_OSCURO = 300;
const int UMBRAL_CLARO = 700;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    Serial.println("=== Sensor de Luz ===");
}

void loop() {
    int valorLuz = analogRead(LDR_PIN);

    // Clasificar nivel de luz
    String estadoLuz;
    int brilloLED;

    if (valorLuz < UMBRAL_OSCURO) {
        estadoLuz = "OSCURO";
        brilloLED = 255;  // LED al máximo
    } else if (valorLuz > UMBRAL_CLARO) {
        estadoLuz = "CLARO";
        brilloLED = 0;    // LED apagado
    } else {
        estadoLuz = "MEDIO";
        // Brillo proporcional inverso
        brilloLED = map(valorLuz, UMBRAL_OSCURO, UMBRAL_CLARO, 255, 0);
    }

    analogWrite(LED_PIN, brilloLED);

    Serial.print("Luz: ");
    Serial.print(valorLuz);
    Serial.print(" - ");
    Serial.print(estadoLuz);
    Serial.print(" - LED: ");
    Serial.println(brilloLED);

    delay(100);
}
```

---

### Ejercicio 3: Sensor de Temperatura TMP36 (45 min)

**Objetivo:** Leer temperatura y mostrar en grados Celsius y Fahrenheit.

**Componentes:**

- Arduino Uno R3
- 1 Sensor TMP36

**Diagrama:**

```
TMP36 (vista frontal, lado plano):
         ┌───┐
         │   │
     ┌───┴───┴───┐
     │  │   │   │
    5V  A0  GND

  Pin 1: 5V (izquierda)
  Pin 2: Señal → A0 (centro)
  Pin 3: GND (derecha)
```

**Código:**

```cpp
/*
 * Ejercicio 3: Termómetro Digital
 * Lee temperatura con sensor TMP36
 */

const int SENSOR_PIN = A0;

void setup() {
    Serial.begin(9600);
    Serial.println("=== Termometro Digital ===");
    Serial.println("Sensor: TMP36");
    Serial.println();
}

void loop() {
    // Leer sensor (promedio de varias lecturas para estabilidad)
    int suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += analogRead(SENSOR_PIN);
        delay(10);
    }
    int valorRaw = suma / 10;

    // Convertir a voltaje
    // TMP36 tiene rango de 0.1V a 2.0V para -40°C a 125°C
    float voltaje = (valorRaw / 1023.0) * 5.0;

    // Convertir voltaje a temperatura
    // TMP36: 10mV por °C, con offset de 500mV (0°C = 0.5V)
    float temperaturaCelsius = (voltaje - 0.5) * 100.0;

    // Convertir a Fahrenheit
    float temperaturaFahrenheit = (temperaturaCelsius * 9.0 / 5.0) + 32.0;

    // Mostrar resultados
    Serial.print("Raw: ");
    Serial.print(valorRaw);
    Serial.print(" | Voltaje: ");
    Serial.print(voltaje, 3);
    Serial.print("V | Temp: ");
    Serial.print(temperaturaCelsius, 1);
    Serial.print("°C / ");
    Serial.print(temperaturaFahrenheit, 1);
    Serial.println("°F");

    // Indicador de estado
    if (temperaturaCelsius < 18) {
        Serial.println("   Estado: FRIO");
    } else if (temperaturaCelsius < 25) {
        Serial.println("   Estado: CONFORTABLE");
    } else if (temperaturaCelsius < 30) {
        Serial.println("   Estado: CALIDO");
    } else {
        Serial.println("   Estado: CALIENTE!");
    }

    Serial.println();
    delay(1000);
}
```

---

### Ejercicio 4: Sistema de Alerta de Temperatura (45 min)

**Objetivo:** Crear alertas visuales y sonoras según temperatura.

**Componentes:**

- Arduino Uno R3
- 1 Sensor TMP36
- 3 LEDs (Azul, Verde, Rojo)
- 3 Resistencias 220Ω
- 1 Buzzer

**Diagrama:**

```
TMP36:
  5V ── Pin 1
  A0 ── Pin 2
  GND ── Pin 3

LEDs:
  Pin 11 ──[220Ω]──[LED Azul]── GND   (Frío)
  Pin 10 ──[220Ω]──[LED Verde]── GND  (Normal)
  Pin 9  ──[220Ω]──[LED Rojo]── GND   (Caliente)

Buzzer:
  Pin 8 ──[Buzzer]── GND
```

**Código:**

```cpp
/*
 * Ejercicio 4: Sistema de Alerta de Temperatura
 * LEDs y buzzer indican rangos de temperatura
 */

const int SENSOR_PIN = A0;
const int LED_FRIO = 11;     // Azul
const int LED_NORMAL = 10;   // Verde
const int LED_CALIENTE = 9;  // Rojo
const int BUZZER_PIN = 8;

// Umbrales de temperatura (°C)
const float TEMP_FRIA = 18.0;
const float TEMP_CALIENTE = 28.0;

void setup() {
    pinMode(LED_FRIO, OUTPUT);
    pinMode(LED_NORMAL, OUTPUT);
    pinMode(LED_CALIENTE, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    Serial.begin(9600);
    Serial.println("=== Sistema de Alerta ===");
}

void loop() {
    float temperatura = leerTemperatura();

    // Apagar todos los LEDs
    apagarTodosLEDs();

    // Determinar estado y activar indicadores
    if (temperatura < TEMP_FRIA) {
        // Frío - LED Azul
        digitalWrite(LED_FRIO, HIGH);
        Serial.print("FRIO: ");
    } else if (temperatura > TEMP_CALIENTE) {
        // Caliente - LED Rojo + Alarma
        digitalWrite(LED_CALIENTE, HIGH);
        tone(BUZZER_PIN, 1000, 200);  // Beep de alarma
        Serial.print("CALIENTE: ");
    } else {
        // Normal - LED Verde
        digitalWrite(LED_NORMAL, HIGH);
        Serial.print("NORMAL: ");
    }

    Serial.print(temperatura, 1);
    Serial.println("°C");

    delay(500);
}

float leerTemperatura() {
    // Promedio de lecturas
    long suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += analogRead(SENSOR_PIN);
        delay(5);
    }
    float voltaje = (suma / 10.0 / 1023.0) * 5.0;
    return (voltaje - 0.5) * 100.0;
}

void apagarTodosLEDs() {
    digitalWrite(LED_FRIO, LOW);
    digitalWrite(LED_NORMAL, LOW);
    digitalWrite(LED_CALIENTE, LOW);
}
```

---

## 🔨 Proyecto de la Semana: Estación Meteorológica Básica

**Descripción:** Sistema que muestra temperatura y nivel de luz con indicadores visuales.

**Componentes:**

- Arduino Uno R3
- 1 Sensor TMP36
- 1 LDR + Resistencia 10kΩ
- 6 LEDs (3 para temperatura, 3 para luz)
- 6 Resistencias 220Ω
- 1 Buzzer

**Diagrama:**

```
Sensores:
  TMP36 → A0
  LDR (divisor de voltaje) → A1

LEDs Temperatura (de frío a caliente):
  Pin 11 ──[220Ω]──[LED Azul]
  Pin 10 ──[220Ω]──[LED Verde]
  Pin 9  ──[220Ω]──[LED Rojo]

LEDs Luz (de oscuro a brillante):
  Pin 6 ──[220Ω]──[LED]
  Pin 5 ──[220Ω]──[LED]
  Pin 3 ──[220Ω]──[LED]

Buzzer:
  Pin 8 ──[Buzzer]── GND
```

**Código Solución:**

```cpp
/*
 * Proyecto Semana 4: Estación Meteorológica
 * Monitoreo de temperatura y luz ambiental
 */

// Pines de sensores
const int TEMP_PIN = A0;
const int LUZ_PIN = A1;

// LEDs de temperatura
const int LED_TEMP[] = {11, 10, 9};  // Azul, Verde, Rojo
const int NUM_LEDS_TEMP = 3;

// LEDs de luz
const int LED_LUZ[] = {6, 5, 3};
const int NUM_LEDS_LUZ = 3;

// Buzzer
const int BUZZER_PIN = 8;

// Umbrales
const float TEMP_BAJA = 18.0;
const float TEMP_MEDIA = 22.0;
const float TEMP_ALTA = 26.0;
const float TEMP_CRITICA = 30.0;

const int LUZ_MUY_OSCURO = 200;
const int LUZ_OSCURO = 400;
const int LUZ_MEDIO = 600;
const int LUZ_CLARO = 800;

// Intervalo de actualización
unsigned long ultimaActualizacion = 0;
const unsigned long INTERVALO = 1000;

void setup() {
    // Configurar LEDs
    for (int i = 0; i < NUM_LEDS_TEMP; i++) {
        pinMode(LED_TEMP[i], OUTPUT);
    }
    for (int i = 0; i < NUM_LEDS_LUZ; i++) {
        pinMode(LED_LUZ[i], OUTPUT);
    }
    pinMode(BUZZER_PIN, OUTPUT);

    Serial.begin(9600);
    Serial.println("========================================");
    Serial.println("    ESTACION METEOROLOGICA BASICA      ");
    Serial.println("========================================");
    Serial.println();

    // Secuencia de inicio
    secuenciaInicio();
}

void loop() {
    if (millis() - ultimaActualizacion >= INTERVALO) {
        ultimaActualizacion = millis();

        // Leer sensores
        float temperatura = leerTemperatura();
        int nivelLuz = analogRead(LUZ_PIN);

        // Actualizar indicadores
        actualizarLEDsTemperatura(temperatura);
        actualizarLEDsLuz(nivelLuz);

        // Verificar alertas
        verificarAlertas(temperatura, nivelLuz);

        // Mostrar en serial
        mostrarDatos(temperatura, nivelLuz);
    }
}

float leerTemperatura() {
    long suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += analogRead(TEMP_PIN);
        delay(2);
    }
    float voltaje = (suma / 10.0 / 1023.0) * 5.0;
    return (voltaje - 0.5) * 100.0;
}

void actualizarLEDsTemperatura(float temp) {
    // Apagar todos
    for (int i = 0; i < NUM_LEDS_TEMP; i++) {
        digitalWrite(LED_TEMP[i], LOW);
    }

    // Encender según rango
    if (temp < TEMP_BAJA) {
        digitalWrite(LED_TEMP[0], HIGH);  // Solo azul
    } else if (temp < TEMP_MEDIA) {
        digitalWrite(LED_TEMP[0], HIGH);
        digitalWrite(LED_TEMP[1], HIGH);  // Azul + Verde
    } else if (temp < TEMP_ALTA) {
        digitalWrite(LED_TEMP[1], HIGH);  // Solo verde
    } else if (temp < TEMP_CRITICA) {
        digitalWrite(LED_TEMP[1], HIGH);
        digitalWrite(LED_TEMP[2], HIGH);  // Verde + Rojo
    } else {
        digitalWrite(LED_TEMP[2], HIGH);  // Solo rojo
    }
}

void actualizarLEDsLuz(int luz) {
    int ledsEncendidos = 0;

    if (luz > LUZ_MUY_OSCURO) ledsEncendidos = 1;
    if (luz > LUZ_OSCURO) ledsEncendidos = 2;
    if (luz > LUZ_MEDIO) ledsEncendidos = 3;

    // Actualizar LEDs como barra de nivel
    for (int i = 0; i < NUM_LEDS_LUZ; i++) {
        if (i < ledsEncendidos) {
            analogWrite(LED_LUZ[i], map(luz, 0, 1023, 50, 255));
        } else {
            analogWrite(LED_LUZ[i], 0);
        }
    }
}

void verificarAlertas(float temp, int luz) {
    // Alerta de temperatura crítica
    if (temp >= TEMP_CRITICA) {
        tone(BUZZER_PIN, 2000, 100);
    }

    // Alerta de muy oscuro
    if (luz < LUZ_MUY_OSCURO) {
        tone(BUZZER_PIN, 500, 50);
    }
}

void mostrarDatos(float temp, int luz) {
    Serial.println("----------------------------------------");

    // Temperatura
    Serial.print("Temperatura: ");
    Serial.print(temp, 1);
    Serial.print(" C  [");
    if (temp < TEMP_BAJA) Serial.print("FRIO");
    else if (temp < TEMP_ALTA) Serial.print("NORMAL");
    else if (temp < TEMP_CRITICA) Serial.print("CALIDO");
    else Serial.print("CRITICO!");
    Serial.println("]");

    // Luz
    int porcentajeLuz = map(luz, 0, 1023, 0, 100);
    Serial.print("Luz: ");
    Serial.print(luz);
    Serial.print(" (");
    Serial.print(porcentajeLuz);
    Serial.print("%)  [");
    if (luz < LUZ_MUY_OSCURO) Serial.print("MUY OSCURO");
    else if (luz < LUZ_OSCURO) Serial.print("OSCURO");
    else if (luz < LUZ_MEDIO) Serial.print("MEDIO");
    else if (luz < LUZ_CLARO) Serial.print("CLARO");
    else Serial.print("MUY CLARO");
    Serial.println("]");

    // Barra visual de luz
    Serial.print("Nivel: [");
    int barras = map(luz, 0, 1023, 0, 20);
    for (int i = 0; i < 20; i++) {
        Serial.print(i < barras ? "#" : "-");
    }
    Serial.println("]");
}

void secuenciaInicio() {
    // Test de LEDs
    for (int i = 0; i < NUM_LEDS_TEMP; i++) {
        digitalWrite(LED_TEMP[i], HIGH);
        delay(150);
    }
    for (int i = 0; i < NUM_LEDS_LUZ; i++) {
        analogWrite(LED_LUZ[i], 255);
        delay(150);
    }

    tone(BUZZER_PIN, 1000, 100);
    delay(150);
    tone(BUZZER_PIN, 1500, 100);

    delay(500);

    // Apagar todos
    for (int i = 0; i < NUM_LEDS_TEMP; i++) {
        digitalWrite(LED_TEMP[i], LOW);
    }
    for (int i = 0; i < NUM_LEDS_LUZ; i++) {
        analogWrite(LED_LUZ[i], 0);
    }
}
```

---

## 📖 Recursos

### Documentación

- [analogRead() Reference](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/)
- [map() Reference](https://www.arduino.cc/reference/en/language/functions/math/map/)
- [TMP36 Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf)

### Tutoriales

- [Analog Input](https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput)
- [Calibration](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Calibration)

---

## ✅ Checklist de Completitud

- [ ] Ejercicio 1: Lectura de potenciómetro completada
- [ ] Ejercicio 2: Sensor de luz funcionando
- [ ] Ejercicio 3: Termómetro digital operativo
- [ ] Ejercicio 4: Sistema de alerta implementado
- [ ] Proyecto: Estación meteorológica completa
- [ ] Concepto de ADC entendido
- [ ] Calibración de sensores aplicada
- [ ] Circuitos guardados en Tinkercad

---

## 🎓 Evaluación

| Componente                 | Porcentaje |
| -------------------------- | ---------- |
| Ejercicios prácticos (1-4) | 40%        |
| Proyecto de la semana      | 50%        |
| Documentación técnica      | 10%        |

---

## 📝 Notas Importantes

1. **Promedio de lecturas:** Los sensores analógicos pueden tener ruido
2. **Tiempo de establecimiento:** Algunos sensores necesitan tiempo para estabilizarse
3. **Divisor de voltaje:** Esencial para sensores resistivos
4. **Calibración:** Los valores varían según componentes y condiciones

---

**Dedicación:** 4 horas | **Anterior:** [← Semana 3](../semana-03/README.md) | **Siguiente:** [Semana 5 →](../semana-05/README.md)
