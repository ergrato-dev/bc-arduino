# Semana 9: Introducción a IoT con Arduino R4 WiFi

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Entender las diferencias entre Arduino Uno R3 y R4
- Comprender conceptos fundamentales de IoT
- Conocer protocolos de comunicación (HTTP, MQTT)
- Diseñar arquitecturas de sistemas IoT
- Preparar proyectos para conectividad (conceptual)

---

## 📚 Contenido Teórico

### 1. Arduino Uno R4 vs R3 (45 min)

#### Comparativa Detallada

```
┌──────────────────────────────────────────────────────────────┐
│                    COMPARATIVA ARDUINO UNO                   │
├────────────────────┬─────────────────┬───────────────────────┤
│   Característica   │   UNO R3        │   UNO R4 WiFi         │
├────────────────────┼─────────────────┼───────────────────────┤
│ Microcontrolador   │ ATmega328P      │ Renesas RA4M1         │
│ Arquitectura       │ AVR 8-bit       │ ARM Cortex-M4 32-bit  │
│ Velocidad          │ 16 MHz          │ 48 MHz                │
│ Flash              │ 32 KB           │ 256 KB                │
│ SRAM               │ 2 KB            │ 32 KB                 │
│ EEPROM             │ 1 KB            │ 8 KB                  │
│ DAC                │ No              │ Sí (12-bit)           │
│ CAN Bus            │ No              │ Sí                    │
│ WiFi               │ No              │ Sí (ESP32-S3)         │
│ Bluetooth          │ No              │ Sí (BLE)              │
│ Matriz LED         │ No              │ Sí (12x8)             │
│ Voltaje lógico     │ 5V              │ 5V                    │
│ Compatibilidad     │ -               │ Compatible con R3     │
│ Tinkercad          │ ✅              │ ❌                    │
└────────────────────┴─────────────────┴───────────────────────┘
```

#### Nuevas Capacidades del R4

```
Arduino Uno R4 WiFi - Características Destacadas:

1. CONECTIVIDAD
   ┌──────────────────┐
   │ WiFi 802.11 b/g/n│ ← 2.4 GHz
   │ Bluetooth 5 LE   │ ← Low Energy
   │ USB-C            │ ← Más robusto
   └──────────────────┘

2. MATRIZ LED INTEGRADA
   ┌────────────────────────┐
   │ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○│  12 columnas
   │ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○│  × 8 filas
   │ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○│  = 96 LEDs
   │ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○│
   │ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○│
   │ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○│
   │ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○│
   │ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○│
   └────────────────────────┘

3. DAC (Convertidor Digital-Analógico)
   - Salida de voltaje real (no PWM)
   - Ideal para audio y señales analógicas

4. RTC (Real Time Clock)
   - Reloj de tiempo real integrado
   - Mantiene hora sin batería externa
```

---

### 2. Fundamentos de IoT (45 min)

#### ¿Qué es IoT?

```
IoT = Internet of Things (Internet de las Cosas)

Red de dispositivos físicos conectados que recopilan
e intercambian datos a través de internet.

                    ┌─────────────┐
                    │   CLOUD     │
                    │  (Servidor) │
                    └──────┬──────┘
                           │
           ┌───────────────┼───────────────┐
           │               │               │
    ┌──────┴─────┐  ┌──────┴─────┐  ┌──────┴─────┐
    │  SENSOR    │  │  SENSOR    │  │ ACTUADOR   │
    │   Temp     │  │  Humedad   │  │   Relé     │
    │  Arduino   │  │  Arduino   │  │  Arduino   │
    └────────────┘  └────────────┘  └────────────┘
           │               │               │
           └───────────────┴───────────────┘
                    Red Local/WiFi
```

#### Arquitectura IoT Típica

```
┌─────────────────────────────────────────────────────────────┐
│                    CAPAS DE IoT                             │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  CAPA DE APLICACIÓN                                         │
│  ┌─────────────────────────────────────────────────────┐   │
│  │  Dashboard Web  │  App Móvil  │  Análisis de Datos  │   │
│  └─────────────────────────────────────────────────────┘   │
│                           ↑                                 │
│  CAPA DE PROCESAMIENTO    │                                 │
│  ┌─────────────────────────────────────────────────────┐   │
│  │  Cloud Server  │  Base de Datos  │  APIs REST/MQTT  │   │
│  └─────────────────────────────────────────────────────┘   │
│                           ↑                                 │
│  CAPA DE RED              │                                 │
│  ┌─────────────────────────────────────────────────────┐   │
│  │  WiFi  │  Bluetooth  │  LoRa  │  Zigbee  │  Ethernet│   │
│  └─────────────────────────────────────────────────────┘   │
│                           ↑                                 │
│  CAPA DE PERCEPCIÓN       │                                 │
│  ┌─────────────────────────────────────────────────────┐   │
│  │  Sensores  │  Actuadores  │  Microcontroladores     │   │
│  └─────────────────────────────────────────────────────┘   │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 3. Protocolos de Comunicación (45 min)

#### HTTP (HyperText Transfer Protocol)

```
HTTP = Protocolo de transferencia de hipertexto

Características:
- Basado en petición-respuesta
- Sin estado (stateless)
- Puerto 80 (HTTP) o 443 (HTTPS)

Métodos principales:
┌──────────┬─────────────────────────────────────┐
│  Método  │  Uso                                │
├──────────┼─────────────────────────────────────┤
│  GET     │  Obtener datos del servidor         │
│  POST    │  Enviar datos al servidor           │
│  PUT     │  Actualizar datos existentes        │
│  DELETE  │  Eliminar datos                     │
└──────────┴─────────────────────────────────────┘

Ejemplo de flujo:
┌────────────┐                    ┌────────────┐
│   Arduino  │ ──── GET /temp ───→│   Server   │
│    R4      │ ←── 200 OK, 25.5 ──│            │
└────────────┘                    └────────────┘
```

#### MQTT (Message Queuing Telemetry Transport)

```
MQTT = Protocolo ligero de mensajería pub/sub

Características:
- Publicar/Suscribir (pub/sub)
- Muy ligero (ideal para IoT)
- Persistencia de mensajes
- QoS (Quality of Service) configurable
- Puerto 1883 (o 8883 para TLS)

Arquitectura:
┌────────────┐    PUBLISH    ┌────────────┐
│  Sensor    │ ─────────────→│   BROKER   │
│ (Publisher)│  topic:       │   (MQTT)   │
│            │  home/temp    │            │
└────────────┘               └─────┬──────┘
                                   │
                           SUBSCRIBE│
                            home/temp
                                   │
                             ┌─────↓──────┐
                             │    App     │
                             │(Subscriber)│
                             └────────────┘

Topics (temas):
- home/livingroom/temperature
- home/kitchen/humidity
- sensor/+/status  (+ = comodín de un nivel)
- home/#           (# = comodín multinivel)
```

#### Comparativa HTTP vs MQTT

```
┌────────────────┬─────────────────┬─────────────────┐
│  Aspecto       │  HTTP           │  MQTT           │
├────────────────┼─────────────────┼─────────────────┤
│ Modelo         │ Request/Response│ Publish/Subscribe│
│ Overhead       │ Alto            │ Bajo            │
│ Conexión       │ Sin estado      │ Persistente     │
│ Bidireccional  │ Limitado        │ Sí              │
│ IoT idóneo     │ APIs REST       │ Sensores tiempo │
│                │                 │ real            │
│ Batería        │ Mayor consumo   │ Menor consumo   │
└────────────────┴─────────────────┴─────────────────┘
```

---

### 4. Servicios en la Nube para IoT (30 min)

#### Plataformas Populares

```
┌─────────────────────────────────────────────────────────────┐
│              PLATAFORMAS IoT CLOUD                          │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  GRATUITAS / FREEMIUM:                                      │
│  ┌───────────────────────────────────────────────────────┐ │
│  │ • ThingSpeak (Mathworks) - Ideal para principiantes   │ │
│  │ • Blynk - App móvil fácil                            │ │
│  │ • Adafruit IO - Dashboards sencillos                 │ │
│  │ • Arduino IoT Cloud - Integración nativa             │ │
│  │ • IFTTT - Automatizaciones simples                   │ │
│  └───────────────────────────────────────────────────────┘ │
│                                                             │
│  EMPRESARIALES:                                             │
│  ┌───────────────────────────────────────────────────────┐ │
│  │ • AWS IoT Core                                        │ │
│  │ • Google Cloud IoT                                    │ │
│  │ • Microsoft Azure IoT Hub                            │ │
│  │ • IBM Watson IoT                                      │ │
│  └───────────────────────────────────────────────────────┘ │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

#### Arduino IoT Cloud

```
Arduino IoT Cloud - Características:

┌─────────────────────────────────────────────────────────────┐
│                                                             │
│  THINGS (Dispositivos)                                      │
│  ├── Variables (sincronizadas automáticamente)              │
│  ├── Dashboard (widgets visuales)                           │
│  └── Triggers (automatizaciones)                            │
│                                                             │
│  WIDGETS DISPONIBLES:                                       │
│  ┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐                  │
│  │Gauge│ │Chart│ │Switch│ │Slider│ │Map │                  │
│  └─────┘ └─────┘ └─────┘ └─────┘ └─────┘                  │
│                                                             │
│  CÓDIGO GENERADO:                                           │
│  - thingProperties.h (configuración)                        │
│  - sketch.ino (lógica principal)                            │
│  - Sincronización automática de variables                   │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 💻 Ejercicios Prácticos (Conceptuales y Simulados)

**Nota:** Dado que Tinkercad no soporta Arduino R4 WiFi, los ejercicios de esta semana combinan:

1. Ejercicios de preparación de código en Arduino Uno R3
2. Diseño conceptual de arquitecturas IoT
3. Código listo para WiFi (para implementar con hardware real)

---

### Ejercicio 1: Preparación de Datos para IoT (45 min)

**Objetivo:** Crear un sistema que prepare datos de sensores en formato JSON para transmisión.

**Componentes (Tinkercad):**

- Arduino Uno R3
- TMP36
- LDR

**Código:**

```cpp
/*
 * Ejercicio 1: Preparación de Datos IoT
 * Formatea datos de sensores como JSON para APIs
 */

const int TEMP_PIN = A0;
const int LUZ_PIN = A1;

// Identificador del dispositivo
const char* DEVICE_ID = "arduino_sensor_01";

unsigned long ultimoEnvio = 0;
const unsigned long INTERVALO_ENVIO = 5000;  // 5 segundos

void setup() {
    Serial.begin(9600);

    Serial.println("=== SIMULADOR DE CLIENTE IoT ===");
    Serial.println("Formato: JSON para API REST");
    Serial.println();
}

void loop() {
    if (millis() - ultimoEnvio >= INTERVALO_ENVIO) {
        ultimoEnvio = millis();

        // Leer sensores
        float temperatura = leerTemperatura();
        int luz = analogRead(LUZ_PIN);
        int luminosidad = map(luz, 0, 1023, 0, 100);

        // Crear JSON
        String json = crearJSON(temperatura, luminosidad);

        // Simular envío
        Serial.println("--- ENVIANDO DATOS ---");
        Serial.print("POST /api/sensors HTTP/1.1\n");
        Serial.print("Host: mi-servidor-iot.com\n");
        Serial.print("Content-Type: application/json\n");
        Serial.print("Content-Length: ");
        Serial.println(json.length());
        Serial.println();
        Serial.println(json);
        Serial.println("--- FIN ENVÍO ---\n");
    }
}

float leerTemperatura() {
    int raw = analogRead(TEMP_PIN);
    float voltaje = (raw / 1023.0) * 5.0;
    return (voltaje - 0.5) * 100.0;
}

String crearJSON(float temp, int luz) {
    String json = "{";
    json += "\"device_id\":\"" + String(DEVICE_ID) + "\",";
    json += "\"timestamp\":" + String(millis()) + ",";
    json += "\"data\":{";
    json += "\"temperature\":" + String(temp, 1) + ",";
    json += "\"temperature_unit\":\"C\",";
    json += "\"luminosity\":" + String(luz) + ",";
    json += "\"luminosity_unit\":\"%\"";
    json += "},";
    json += "\"status\":\"ok\"";
    json += "}";

    return json;
}
```

---

### Ejercicio 2: Simulador de MQTT (45 min)

**Objetivo:** Entender el patrón publish/subscribe de MQTT.

**Código:**

```cpp
/*
 * Ejercicio 2: Simulador MQTT
 * Simula publicación de mensajes MQTT por serial
 */

const int TEMP_PIN = A0;
const int BTN_PIN = 2;

// Configuración MQTT simulada
const char* MQTT_BROKER = "mqtt.ejemplo.com";
const char* TOPIC_TEMP = "casa/sala/temperatura";
const char* TOPIC_ESTADO = "casa/sala/estado";
const char* TOPIC_COMANDO = "casa/sala/comando";

// Estado
bool sistemaActivo = true;
int estadoBtnAnterior = HIGH;

void setup() {
    pinMode(BTN_PIN, INPUT_PULLUP);
    Serial.begin(9600);

    Serial.println("=== SIMULADOR MQTT ===");
    Serial.print("Broker: ");
    Serial.println(MQTT_BROKER);
    Serial.println();

    // Simular conexión
    simularConexion();

    // Simular suscripción
    simularSuscripcion(TOPIC_COMANDO);
}

void loop() {
    // Publicar temperatura periódicamente
    static unsigned long ultimaPublicacion = 0;
    if (millis() - ultimaPublicacion >= 10000) {
        ultimaPublicacion = millis();

        float temp = leerTemperatura();
        String payload = "{\"valor\":" + String(temp, 1) + ",\"unidad\":\"C\"}";
        simularPublicacion(TOPIC_TEMP, payload);
    }

    // Detectar cambio de estado con botón
    int estadoBtn = digitalRead(BTN_PIN);
    if (estadoBtn == LOW && estadoBtnAnterior == HIGH) {
        sistemaActivo = !sistemaActivo;
        String estado = sistemaActivo ? "activo" : "inactivo";
        simularPublicacion(TOPIC_ESTADO, estado);
        delay(50);
    }
    estadoBtnAnterior = estadoBtn;

    // Simular recepción de comandos por serial
    if (Serial.available() > 0) {
        String comando = Serial.readStringUntil('\n');
        comando.trim();
        simularRecepcion(TOPIC_COMANDO, comando);
        procesarComando(comando);
    }
}

float leerTemperatura() {
    int raw = analogRead(TEMP_PIN);
    float voltaje = (raw / 1023.0) * 5.0;
    return (voltaje - 0.5) * 100.0;
}

void simularConexion() {
    Serial.println("[MQTT] Conectando...");
    delay(500);
    Serial.print("[MQTT] Conectado a ");
    Serial.println(MQTT_BROKER);
    Serial.println();
}

void simularSuscripcion(const char* topic) {
    Serial.print("[MQTT] SUBSCRIBE: ");
    Serial.println(topic);
}

void simularPublicacion(const char* topic, String payload) {
    Serial.println("---------------------------");
    Serial.print("[MQTT] PUBLISH ");
    Serial.println(topic);
    Serial.print("Payload: ");
    Serial.println(payload);
    Serial.println("---------------------------");
}

void simularRecepcion(const char* topic, String mensaje) {
    Serial.println("***************************");
    Serial.print("[MQTT] RECEIVED on ");
    Serial.println(topic);
    Serial.print("Message: ");
    Serial.println(mensaje);
    Serial.println("***************************");
}

void procesarComando(String comando) {
    comando.toLowerCase();

    if (comando == "on") {
        sistemaActivo = true;
        Serial.println("Sistema ACTIVADO por comando remoto");
    } else if (comando == "off") {
        sistemaActivo = false;
        Serial.println("Sistema DESACTIVADO por comando remoto");
    } else if (comando == "status") {
        String estado = "{\"activo\":" + String(sistemaActivo ? "true" : "false");
        estado += ",\"temperatura\":" + String(leerTemperatura(), 1) + "}";
        simularPublicacion(TOPIC_ESTADO, estado);
    }
}
```

---

### Ejercicio 3: Dashboard Serial (45 min)

**Objetivo:** Crear una interfaz de monitoreo que simule un dashboard IoT.

**Código:**

```cpp
/*
 * Ejercicio 3: Dashboard Serial
 * Simula interfaz de monitoreo IoT
 */

const int TEMP_PIN = A0;
const int LUZ_PIN = A1;
const int POT_PIN = A2;

// Umbrales configurables
float umbralTempAlta = 28.0;
float umbralTempBaja = 18.0;
int umbralLuzBaja = 30;

// Estadísticas
float tempMin = 100;
float tempMax = 0;
float tempSum = 0;
int numLecturas = 0;

unsigned long tiempoInicio;

void setup() {
    Serial.begin(9600);
    tiempoInicio = millis();

    mostrarBanner();
}

void loop() {
    static unsigned long ultimaActualizacion = 0;

    if (millis() - ultimaActualizacion >= 2000) {
        ultimaActualizacion = millis();

        // Leer sensores
        float temp = leerTemperatura();
        int luz = map(analogRead(LUZ_PIN), 0, 1023, 0, 100);
        int setpoint = map(analogRead(POT_PIN), 0, 1023, 15, 35);

        // Actualizar estadísticas
        actualizarEstadisticas(temp);

        // Mostrar dashboard
        mostrarDashboard(temp, luz, setpoint);
    }

    // Comandos de configuración
    if (Serial.available() > 0) {
        procesarComando();
    }
}

float leerTemperatura() {
    int raw = analogRead(TEMP_PIN);
    float voltaje = (raw / 1023.0) * 5.0;
    return (voltaje - 0.5) * 100.0;
}

void actualizarEstadisticas(float temp) {
    if (temp < tempMin) tempMin = temp;
    if (temp > tempMax) tempMax = temp;
    tempSum += temp;
    numLecturas++;
}

void mostrarBanner() {
    Serial.println();
    Serial.println("╔══════════════════════════════════════════════╗");
    Serial.println("║          IoT DASHBOARD - SIMULADOR           ║");
    Serial.println("║          Arduino Sensor Monitor              ║");
    Serial.println("╠══════════════════════════════════════════════╣");
    Serial.println("║ Comandos: H=Help, R=Reset stats, C=Config    ║");
    Serial.println("╚══════════════════════════════════════════════╝");
    Serial.println();
}

void mostrarDashboard(float temp, int luz, int setpoint) {
    unsigned long tiempoActivo = (millis() - tiempoInicio) / 1000;

    // Limpiar y dibujar dashboard
    Serial.println("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    Serial.print("│ Tiempo activo: ");
    Serial.print(tiempoActivo / 60);
    Serial.print("m ");
    Serial.print(tiempoActivo % 60);
    Serial.print("s");
    Serial.print("                    Lecturas: ");
    Serial.println(numLecturas);
    Serial.println("├────────────────────────────────────────────");

    // Temperatura
    Serial.print("│ 🌡️ TEMPERATURA: ");
    Serial.print(temp, 1);
    Serial.print("°C ");

    // Indicador de estado
    if (temp > umbralTempAlta) {
        Serial.print("[⚠️ ALTA!]");
    } else if (temp < umbralTempBaja) {
        Serial.print("[❄️ BAJA]");
    } else {
        Serial.print("[✅ OK]");
    }
    Serial.println();

    // Barra de temperatura
    Serial.print("│   ");
    int barraTemp = map(constrain(temp, 10, 40), 10, 40, 0, 30);
    for (int i = 0; i < 30; i++) {
        if (i < barraTemp) Serial.print("█");
        else Serial.print("░");
    }
    Serial.println();

    // Luz
    Serial.print("│ ☀️ LUMINOSIDAD: ");
    Serial.print(luz);
    Serial.print("% ");
    if (luz < umbralLuzBaja) {
        Serial.print("[🌙 OSCURO]");
    } else {
        Serial.print("[💡 OK]");
    }
    Serial.println();

    // Setpoint
    Serial.print("│ 🎚️ SETPOINT: ");
    Serial.print(setpoint);
    Serial.println("°C");

    Serial.println("├────────────────────────────────────────────");

    // Estadísticas
    Serial.println("│ 📊 ESTADÍSTICAS:");
    Serial.print("│    Min: ");
    Serial.print(tempMin, 1);
    Serial.print("°C | Max: ");
    Serial.print(tempMax, 1);
    Serial.print("°C | Prom: ");
    Serial.print(tempSum / numLecturas, 1);
    Serial.println("°C");

    Serial.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
}

void procesarComando() {
    char cmd = Serial.read();

    switch(toupper(cmd)) {
        case 'H':
            Serial.println("\n=== AYUDA ===");
            Serial.println("H - Esta ayuda");
            Serial.println("R - Resetear estadísticas");
            Serial.println("C - Ver configuración");
            Serial.println("=============\n");
            break;

        case 'R':
            tempMin = 100;
            tempMax = 0;
            tempSum = 0;
            numLecturas = 0;
            Serial.println("\n[OK] Estadísticas reseteadas\n");
            break;

        case 'C':
            Serial.println("\n=== CONFIGURACIÓN ===");
            Serial.print("Umbral Temp Alta: ");
            Serial.println(umbralTempAlta);
            Serial.print("Umbral Temp Baja: ");
            Serial.println(umbralTempBaja);
            Serial.print("Umbral Luz Baja: ");
            Serial.println(umbralLuzBaja);
            Serial.println("====================\n");
            break;
    }
}
```

---

### Ejercicio 4: Diseño de Arquitectura IoT (30 min)

**Objetivo:** Diseñar la arquitectura de un sistema IoT completo (ejercicio teórico).

**Actividad:**

Diseña en papel o digitalmente la arquitectura para un **Sistema de Monitoreo de Invernadero** que incluya:

1. **Sensores:**

   - Temperatura ambiente
   - Humedad del suelo
   - Luminosidad
   - Nivel de agua en depósito

2. **Actuadores:**

   - Sistema de riego (bomba)
   - Ventilador
   - Luces de cultivo
   - Calefactor

3. **Conectividad:**
   - Arduino R4 WiFi como nodo central
   - Comunicación MQTT con broker
   - Dashboard web para monitoreo
   - App móvil para alertas

**Plantilla de documentación:**

```
PROYECTO: Sistema de Monitoreo de Invernadero
================================================

1. DESCRIPCIÓN GENERAL
   [Describir el objetivo del sistema]

2. DIAGRAMA DE ARQUITECTURA
   [Dibujar capas: sensores → Arduino → WiFi → Cloud → Apps]

3. SENSORES Y PINES
   ┌─────────────────┬──────────┬────────────┐
   │ Sensor          │ Pin      │ Protocolo  │
   ├─────────────────┼──────────┼────────────┤
   │                 │          │            │
   └─────────────────┴──────────┴────────────┘

4. ACTUADORES Y PINES
   ┌─────────────────┬──────────┬────────────┐
   │ Actuador        │ Pin      │ Tipo       │
   ├─────────────────┼──────────┼────────────┤
   │                 │          │            │
   └─────────────────┴──────────┴────────────┘

5. TOPICS MQTT
   - invernadero/sensores/temperatura
   - invernadero/sensores/humedad
   - invernadero/actuadores/riego/estado
   - invernadero/actuadores/riego/comando

6. REGLAS DE AUTOMATIZACIÓN
   - SI temp > 30°C ENTONCES activar ventilador
   - SI humedad_suelo < 30% ENTONCES activar riego
   - [más reglas...]

7. DASHBOARD
   [Describir widgets necesarios]
```

---

## 🔨 Proyecto de la Semana: Prototipo IoT Ready

**Descripción:** Crear un sistema completo preparado para conectividad IoT.

**Código:**

```cpp
/*
 * Proyecto Semana 9: Sistema IoT-Ready
 * Preparado para conectar a cloud cuando se tenga hardware WiFi
 */

// Simulación de librería WiFi
#define WIFI_AVAILABLE false  // Cambiar a true con R4 WiFi

const int TEMP_PIN = A0;
const int LUZ_PIN = A1;
const int LED_ESTADO = 13;
const int LED_ALERTA = 12;
const int BUZZER = 11;
const int RELE = 10;

// Configuración del dispositivo
struct Configuracion {
    char deviceId[20] = "SENSOR_001";
    char ubicacion[30] = "Sala Principal";
    float tempAlerta = 30.0;
    float tempMinima = 18.0;
    int luzMinima = 20;
    int intervaloEnvio = 30;  // segundos
};

Configuracion config;

// Estado del sistema
struct Estado {
    float temperatura;
    int luminosidad;
    bool alertaActiva;
    bool releActivo;
    unsigned long ultimoEnvio;
    int enviosExitosos;
    int enviosFallidos;
};

Estado estado;

// Buffer de datos (para envío batch)
const int BUFFER_SIZE = 10;
struct Lectura {
    unsigned long timestamp;
    float temperatura;
    int luminosidad;
};
Lectura buffer[BUFFER_SIZE];
int bufferIndex = 0;

void setup() {
    pinMode(LED_ESTADO, OUTPUT);
    pinMode(LED_ALERTA, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(RELE, OUTPUT);

    Serial.begin(9600);

    mostrarInicio();

    // Simular conexión WiFi
    if (WIFI_AVAILABLE) {
        conectarWiFi();
    } else {
        Serial.println("[INFO] Modo offline - datos por serial");
    }

    estado.ultimoEnvio = millis();
}

void loop() {
    // Leer sensores
    leerSensores();

    // Verificar alertas
    verificarAlertas();

    // Actualizar LEDs de estado
    actualizarIndicadores();

    // Enviar datos periódicamente
    if ((millis() - estado.ultimoEnvio) >= config.intervaloEnvio * 1000UL) {
        estado.ultimoEnvio = millis();
        enviarDatos();
    }

    // Procesar comandos
    procesarComandos();

    delay(1000);
}

void leerSensores() {
    // Temperatura
    int raw = analogRead(TEMP_PIN);
    float voltaje = (raw / 1023.0) * 5.0;
    estado.temperatura = (voltaje - 0.5) * 100.0;

    // Luminosidad
    estado.luminosidad = map(analogRead(LUZ_PIN), 0, 1023, 0, 100);

    // Guardar en buffer
    buffer[bufferIndex].timestamp = millis();
    buffer[bufferIndex].temperatura = estado.temperatura;
    buffer[bufferIndex].luminosidad = estado.luminosidad;
    bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
}

void verificarAlertas() {
    bool alertaTemp = estado.temperatura > config.tempAlerta ||
                      estado.temperatura < config.tempMinima;
    bool alertaLuz = estado.luminosidad < config.luzMinima;

    estado.alertaActiva = alertaTemp || alertaLuz;

    // Activar relé de emergencia si temp muy alta
    if (estado.temperatura > config.tempAlerta + 5) {
        digitalWrite(RELE, HIGH);
        estado.releActivo = true;
    } else if (estado.temperatura < config.tempAlerta) {
        digitalWrite(RELE, LOW);
        estado.releActivo = false;
    }
}

void actualizarIndicadores() {
    // LED estado: parpadea si online, fijo si offline
    static unsigned long ultimoParpadeo = 0;
    static bool ledEstado = false;

    if (WIFI_AVAILABLE) {
        if (millis() - ultimoParpadeo >= 1000) {
            ultimoParpadeo = millis();
            ledEstado = !ledEstado;
            digitalWrite(LED_ESTADO, ledEstado);
        }
    } else {
        digitalWrite(LED_ESTADO, HIGH);
    }

    // LED alerta
    if (estado.alertaActiva) {
        digitalWrite(LED_ALERTA, (millis() / 200) % 2);
        if ((millis() / 500) % 2) {
            tone(BUZZER, 1500, 100);
        }
    } else {
        digitalWrite(LED_ALERTA, LOW);
    }
}

void enviarDatos() {
    Serial.println("\n========== TRANSMISIÓN DE DATOS ==========");

    // Crear payload JSON
    String payload = crearPayload();

    if (WIFI_AVAILABLE) {
        // Aquí iría el código real de envío HTTP/MQTT
        Serial.println("[WiFi] Enviando a servidor...");
        // bool exito = enviarHTTP(payload);
        // if (exito) estado.enviosExitosos++;
        // else estado.enviosFallidos++;
    } else {
        // Modo simulación
        Serial.println("[SERIAL] Datos para transmisión:");
        Serial.println(payload);
        estado.enviosExitosos++;
    }

    Serial.println("==========================================\n");
}

String crearPayload() {
    String json = "{\n";
    json += "  \"device\": {\n";
    json += "    \"id\": \"" + String(config.deviceId) + "\",\n";
    json += "    \"ubicacion\": \"" + String(config.ubicacion) + "\",\n";
    json += "    \"firmware\": \"1.0.0\"\n";
    json += "  },\n";
    json += "  \"timestamp\": " + String(millis()) + ",\n";
    json += "  \"sensores\": {\n";
    json += "    \"temperatura\": {\n";
    json += "      \"valor\": " + String(estado.temperatura, 2) + ",\n";
    json += "      \"unidad\": \"C\",\n";
    json += "      \"alerta\": " + String(estado.temperatura > config.tempAlerta ? "true" : "false") + "\n";
    json += "    },\n";
    json += "    \"luminosidad\": {\n";
    json += "      \"valor\": " + String(estado.luminosidad) + ",\n";
    json += "      \"unidad\": \"%\"\n";
    json += "    }\n";
    json += "  },\n";
    json += "  \"actuadores\": {\n";
    json += "    \"rele\": " + String(estado.releActivo ? "true" : "false") + "\n";
    json += "  },\n";
    json += "  \"estadisticas\": {\n";
    json += "    \"envios_ok\": " + String(estado.enviosExitosos) + ",\n";
    json += "    \"envios_error\": " + String(estado.enviosFallidos) + "\n";
    json += "  }\n";
    json += "}";

    return json;
}

void procesarComandos() {
    if (Serial.available() > 0) {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();
        cmd.toUpperCase();

        if (cmd == "STATUS") {
            mostrarEstado();
        } else if (cmd == "CONFIG") {
            mostrarConfiguracion();
        } else if (cmd == "ENVIAR") {
            enviarDatos();
        } else if (cmd == "RELE ON") {
            digitalWrite(RELE, HIGH);
            estado.releActivo = true;
            Serial.println("[OK] Relé activado manualmente");
        } else if (cmd == "RELE OFF") {
            digitalWrite(RELE, LOW);
            estado.releActivo = false;
            Serial.println("[OK] Relé desactivado");
        } else if (cmd == "HELP") {
            mostrarAyuda();
        }
    }
}

void mostrarInicio() {
    Serial.println();
    Serial.println("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    Serial.println("┃     SISTEMA IoT-READY v1.0             ┃");
    Serial.println("┃     Prototipo Bootcamp Arduino         ┃");
    Serial.println("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    Serial.println();
}

void mostrarEstado() {
    Serial.println("\n=== ESTADO DEL SISTEMA ===");
    Serial.print("Temperatura: ");
    Serial.print(estado.temperatura, 1);
    Serial.println("°C");
    Serial.print("Luminosidad: ");
    Serial.print(estado.luminosidad);
    Serial.println("%");
    Serial.print("Alerta: ");
    Serial.println(estado.alertaActiva ? "SI" : "No");
    Serial.print("Relé: ");
    Serial.println(estado.releActivo ? "ACTIVO" : "Inactivo");
    Serial.print("Envíos OK: ");
    Serial.println(estado.enviosExitosos);
    Serial.println("==========================\n");
}

void mostrarConfiguracion() {
    Serial.println("\n=== CONFIGURACIÓN ===");
    Serial.print("ID: ");
    Serial.println(config.deviceId);
    Serial.print("Ubicación: ");
    Serial.println(config.ubicacion);
    Serial.print("Temp Alerta: ");
    Serial.println(config.tempAlerta);
    Serial.print("Intervalo: ");
    Serial.print(config.intervaloEnvio);
    Serial.println("s");
    Serial.println("=====================\n");
}

void mostrarAyuda() {
    Serial.println("\n=== COMANDOS ===");
    Serial.println("STATUS  - Ver estado");
    Serial.println("CONFIG  - Ver config");
    Serial.println("ENVIAR  - Forzar envío");
    Serial.println("RELE ON/OFF - Control relé");
    Serial.println("HELP    - Esta ayuda");
    Serial.println("================\n");
}

void conectarWiFi() {
    // Placeholder para conexión WiFi real
    Serial.println("[WiFi] Conectando...");
    delay(1000);
    Serial.println("[WiFi] Conectado!");
}
```

---

## 📖 Recursos

### Documentación

- [Arduino Uno R4 WiFi](https://docs.arduino.cc/hardware/uno-r4-wifi)
- [Arduino IoT Cloud](https://docs.arduino.cc/cloud/iot-cloud)
- [MQTT Protocol](https://mqtt.org/)

### Plataformas IoT

- [ThingSpeak](https://thingspeak.com/)
- [Blynk](https://blynk.io/)
- [Adafruit IO](https://io.adafruit.com/)

---

## ✅ Checklist de Completitud

- [ ] Ejercicio 1: Datos JSON preparados
- [ ] Ejercicio 2: Simulador MQTT completado
- [ ] Ejercicio 3: Dashboard serial funcionando
- [ ] Ejercicio 4: Arquitectura diseñada
- [ ] Proyecto: Sistema IoT-Ready completo
- [ ] Conceptos HTTP y MQTT entendidos
- [ ] Diferencias R3 vs R4 comprendidas
- [ ] Documentación de arquitectura

---

## 🎓 Evaluación

| Componente                 | Porcentaje |
| -------------------------- | ---------- |
| Ejercicios prácticos (1-4) | 40%        |
| Proyecto de la semana      | 40%        |
| Diseño de arquitectura     | 20%        |

---

**Dedicación:** 4 horas | **Anterior:** [← Semana 8](../semana-08/README.md) | **Siguiente:** [Semana 10 →](../semana-10/README.md)
