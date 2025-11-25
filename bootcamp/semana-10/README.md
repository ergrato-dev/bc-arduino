# Semana 10: Proyecto Final e Integración

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Integrar múltiples conceptos aprendidos en un proyecto
- Diseñar sistemas completos desde especificaciones
- Documentar proyectos de manera profesional
- Presentar y defender decisiones técnicas
- Planificar próximos pasos de aprendizaje

---

## 📋 Estructura de la Semana

```
SEMANA 10 - PROYECTO FINAL

┌─────────────────────────────────────────────────────────────┐
│                                                             │
│   FASE 1: PLANIFICACIÓN (30 min)                           │
│   ├── Selección de proyecto                                 │
│   ├── Definición de requisitos                             │
│   └── Diseño de arquitectura                               │
│                                                             │
│   FASE 2: DESARROLLO (2h 30min)                            │
│   ├── Implementación por módulos                           │
│   ├── Pruebas unitarias                                    │
│   └── Integración de componentes                           │
│                                                             │
│   FASE 3: DOCUMENTACIÓN Y PRESENTACIÓN (1h)                │
│   ├── Documentación técnica                                │
│   ├── Preparación de demo                                  │
│   └── Presentación del proyecto                            │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 🎨 Opciones de Proyecto Final

Selecciona UNA de las siguientes opciones o propone una propia:

### Opción A: Sistema Domótico Integral

**Descripción:** Sistema de automatización del hogar con múltiples sensores y actuadores.

**Componentes:**

- Arduino Uno R3
- DHT11 (temperatura/humedad)
- LDR (luz)
- PIR (movimiento)
- Servomotor (persiana)
- Relé (luz)
- LCD 16x2
- Buzzer
- LEDs indicadores

**Funcionalidades:**

- Control automático de iluminación
- Apertura/cierre de persianas según luz
- Detección de presencia
- Monitoreo de clima interior
- Alarma configurable
- Menú de configuración en LCD

```
┌─────────────────────────────────────────────────────────────┐
│              SISTEMA DOMÓTICO INTEGRAL                      │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   ┌─────────┐      ┌──────────────┐      ┌─────────┐       │
│   │  DHT11  │──────│              │──────│  RELÉ   │       │
│   │  PIR    │──────│    ARDUINO   │──────│  SERVO  │       │
│   │  LDR    │──────│    UNO R3    │──────│ BUZZER  │       │
│   │ BOTONES │──────│              │──────│  LEDS   │       │
│   └─────────┘      └──────┬───────┘      └─────────┘       │
│                           │                                 │
│                    ┌──────┴───────┐                        │
│                    │  LCD 16x2    │                        │
│                    │  I2C         │                        │
│                    └──────────────┘                        │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### Opción B: Robot Seguidor Avanzado

**Descripción:** Robot móvil con múltiples modos de operación.

**Componentes:**

- Arduino Uno R3
- 2x Motores DC con L298N
- HC-SR04 (ultrasonido)
- 2x Sensores IR línea
- Servomotor (cabeza radar)
- LEDs indicadores
- Buzzer

**Funcionalidades:**

- Modo seguidor de línea
- Modo evita obstáculos
- Modo radar (escaneo de entorno)
- Cambio de modo por comando serial
- Indicadores LED de estado
- Feedback sonoro

```
┌─────────────────────────────────────────────────────────────┐
│                ROBOT SEGUIDOR AVANZADO                      │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│              ┌─────────────────┐                           │
│              │    SERVO        │                           │
│              │  ┌─────────┐    │                           │
│              │  │ HC-SR04 │    │  ← Cabeza giratoria       │
│              │  └─────────┘    │                           │
│              └────────┬────────┘                           │
│         ┌─────────────┴─────────────┐                      │
│         │        ARDUINO            │                      │
│         │         UNO R3            │                      │
│         └─────────────┬─────────────┘                      │
│              ┌────────┴────────┐                           │
│         ┌────┴────┐       ┌────┴────┐                      │
│         │ MOTOR L │       │ MOTOR R │                      │
│         │ L298N   │       │ L298N   │                      │
│         └─────────┘       └─────────┘                      │
│              │                 │                           │
│            ○───○             ○───○  ← Sensores IR          │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### Opción C: Estación Meteorológica Completa

**Descripción:** Estación de monitoreo ambiental con registro de datos.

**Componentes:**

- Arduino Uno R3
- DHT22 (temperatura/humedad)
- BMP180 (presión atmosférica)
- LDR (luminosidad)
- Sensor lluvia
- LCD 20x4 I2C
- Módulo SD Card
- RTC DS3231
- LEDs indicadores

**Funcionalidades:**

- Lectura multi-sensor
- Cálculo de índice UV estimado
- Predicción básica del tiempo
- Registro en SD card con timestamp
- Estadísticas (min, max, promedio)
- Exportación de datos CSV

```
┌─────────────────────────────────────────────────────────────┐
│            ESTACIÓN METEOROLÓGICA COMPLETA                  │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   SENSORES              ARDUINO             SALIDAS         │
│   ┌───────┐         ┌───────────┐        ┌───────────┐     │
│   │ DHT22 │────────▶│           │───────▶│ LCD 20x4  │     │
│   │ BMP180│────────▶│   UNO R3  │───────▶│ SD Card   │     │
│   │  LDR  │────────▶│           │───────▶│ LEDs      │     │
│   │ Lluvia│────────▶│           │        └───────────┘     │
│   │ RTC   │────────▶│           │                          │
│   └───────┘         └───────────┘                          │
│                                                             │
│   FUNCIONES:                                                │
│   ├── Lectura cada 1 minuto                                │
│   ├── Guardado en SD cada 5 minutos                        │
│   ├── Formato CSV con timestamp                            │
│   └── Predicción basada en tendencias                      │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### Opción D: Sistema de Control de Acceso

**Descripción:** Control de acceso con múltiples métodos de autenticación.

**Componentes:**

- Arduino Uno R3
- Teclado matricial 4x4
- LCD 16x2 I2C
- Servomotor (cerradura)
- Buzzer
- LEDs (verde/rojo)
- Sensor magnético puerta

**Funcionalidades:**

- Autenticación por PIN
- Múltiples usuarios (hasta 5)
- Registro de accesos
- Alarma por intentos fallidos
- Modo master para configuración
- Apertura temporizada

```
┌─────────────────────────────────────────────────────────────┐
│              SISTEMA DE CONTROL DE ACCESO                   │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│      ┌─────────────┐        ┌─────────────┐                │
│      │   TECLADO   │        │    LCD      │                │
│      │    4x4      │        │   16x2      │                │
│      │             │        │ ┌─────────┐ │                │
│      │ 1 2 3 A     │        │ │**** PIN │ │                │
│      │ 4 5 6 B     │        │ │         │ │                │
│      │ 7 8 9 C     │        │ └─────────┘ │                │
│      │ * 0 # D     │        └──────┬──────┘                │
│      └──────┬──────┘               │                       │
│             │       ┌──────────────┴──────────────┐        │
│             └──────▶│         ARDUINO             │        │
│                     │          UNO R3             │        │
│                     └──────────────┬──────────────┘        │
│                           ┌────────┴────────┐              │
│                           │                 │              │
│                      ┌────┴────┐       ┌────┴────┐        │
│                      │  SERVO  │       │ SENSOR  │        │
│                      │CERRADURA│       │ PUERTA  │        │
│                      └─────────┘       └─────────┘        │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 📝 Plantilla de Documentación del Proyecto

### Portada

```markdown
# [NOMBRE DEL PROYECTO]

**Bootcamp Arduino - Proyecto Final**

**Autor:** [Tu nombre]
**Fecha:** [Fecha de entrega]
**Versión:** 1.0

---
```

### Índice

```markdown
## Índice

1. Descripción del Proyecto
2. Objetivos
3. Especificaciones Técnicas
4. Diseño del Sistema
5. Lista de Materiales
6. Esquemático de Conexiones
7. Código Fuente
8. Instrucciones de Uso
9. Pruebas Realizadas
10. Conclusiones
11. Posibles Mejoras
12. Referencias
```

### Sección 1: Descripción

```markdown
## 1. Descripción del Proyecto

### 1.1 Resumen Ejecutivo

[Descripción breve del proyecto en 2-3 oraciones]

### 1.2 Problema a Resolver

[¿Qué problema resuelve este proyecto?]

### 1.3 Solución Propuesta

[¿Cómo aborda el problema tu solución?]

### 1.4 Público Objetivo

[¿Para quién está diseñado?]
```

### Sección 4: Diseño del Sistema

```markdown
## 4. Diseño del Sistema

### 4.1 Diagrama de Bloques

┌─────────────────────────────────────────────────────────────┐
│ │
│ [Dibujar diagrama de bloques del sistema] │
│ │
└─────────────────────────────────────────────────────────────┘

### 4.2 Diagrama de Estados

┌────────┐ evento1 ┌────────┐
│ ESTADO │ ───────────────▶ │ ESTADO │
│ A │ │ B │
└────────┘ └────────┘

### 4.3 Diagrama de Flujo

[Incluir flowchart del algoritmo principal]
```

### Sección 5: Lista de Materiales (BOM)

```markdown
## 5. Lista de Materiales (BOM)

| #   | Componente     | Cantidad | Especificación   | Disponible en Tinkercad |
| --- | -------------- | -------- | ---------------- | ----------------------- |
| 1   | Arduino Uno R3 | 1        | ATmega328P       | ✅                      |
| 2   | [Componente]   | [N]      | [Especificación] | [✅/❌]                 |
| 3   | ...            | ...      | ...              | ...                     |
```

---

## 💻 Ejemplo de Estructura de Código

```cpp
/*
 * =================================================
 * PROYECTO FINAL: [Nombre del Proyecto]
 * =================================================
 *
 * Descripción: [Descripción breve]
 * Autor: [Tu nombre]
 * Fecha: [Fecha]
 * Versión: 1.0
 *
 * Hardware requerido:
 * - Arduino Uno R3
 * - [Lista de componentes]
 *
 * Conexiones:
 * - [Pin] -> [Componente]
 * - ...
 *
 * Librerías requeridas:
 * - [Lista de librerías]
 *
 * =================================================
 */

// ==================================================
// LIBRERÍAS
// ==================================================
#include <Wire.h>
// [Otras librerías]

// ==================================================
// DEFINICIÓN DE PINES
// ==================================================
#define PIN_LED     13
#define PIN_SENSOR  A0
// [Más definiciones]

// ==================================================
// CONSTANTES DE CONFIGURACIÓN
// ==================================================
const unsigned long INTERVALO_LECTURA = 1000;
const float UMBRAL_ALERTA = 30.0;
// [Más constantes]

// ==================================================
// ESTRUCTURAS DE DATOS
// ==================================================
struct ConfiguracionSistema {
    bool modoActivo;
    float umbralAlto;
    float umbralBajo;
    // [Más campos]
};

struct EstadoSistema {
    float valorActual;
    bool alertaActiva;
    unsigned long ultimaLectura;
    // [Más campos]
};

// ==================================================
// VARIABLES GLOBALES
// ==================================================
ConfiguracionSistema config;
EstadoSistema estado;

// ==================================================
// SETUP - INICIALIZACIÓN
// ==================================================
void setup() {
    // Inicializar comunicación serial
    Serial.begin(9600);

    // Inicializar pines
    inicializarPines();

    // Inicializar módulos
    inicializarModulos();

    // Cargar configuración
    cargarConfiguracion();

    // Mostrar mensaje de inicio
    mostrarMensajeInicio();
}

// ==================================================
// LOOP - BUCLE PRINCIPAL
// ==================================================
void loop() {
    // 1. Leer sensores
    leerSensores();

    // 2. Procesar datos
    procesarDatos();

    // 3. Actualizar salidas
    actualizarSalidas();

    // 4. Manejar comunicación
    manejarComunicacion();

    // 5. Verificar alertas
    verificarAlertas();
}

// ==================================================
// FUNCIONES DE INICIALIZACIÓN
// ==================================================
void inicializarPines() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_SENSOR, INPUT);
    // [Más inicializaciones]
}

void inicializarModulos() {
    // Inicializar LCD, sensores I2C, etc.
}

void cargarConfiguracion() {
    // Valores por defecto o cargar de EEPROM
    config.modoActivo = true;
    config.umbralAlto = UMBRAL_ALERTA;
    // [Más valores]
}

void mostrarMensajeInicio() {
    Serial.println("==============================");
    Serial.println("  [NOMBRE DEL PROYECTO]");
    Serial.println("  Versión 1.0");
    Serial.println("==============================");
    Serial.println();
}

// ==================================================
// FUNCIONES DE SENSORES
// ==================================================
void leerSensores() {
    unsigned long ahora = millis();

    if (ahora - estado.ultimaLectura >= INTERVALO_LECTURA) {
        estado.ultimaLectura = ahora;

        // Leer sensor
        int valorRaw = analogRead(PIN_SENSOR);
        estado.valorActual = convertirValor(valorRaw);
    }
}

float convertirValor(int valorRaw) {
    // Conversión específica según el sensor
    return (valorRaw / 1023.0) * 100.0;
}

// ==================================================
// FUNCIONES DE PROCESAMIENTO
// ==================================================
void procesarDatos() {
    // Aplicar filtros, promedios, etc.
}

// ==================================================
// FUNCIONES DE SALIDA
// ==================================================
void actualizarSalidas() {
    // Actualizar LEDs, LCD, actuadores
    if (estado.alertaActiva) {
        digitalWrite(PIN_LED, HIGH);
    } else {
        digitalWrite(PIN_LED, LOW);
    }
}

// ==================================================
// FUNCIONES DE COMUNICACIÓN
// ==================================================
void manejarComunicacion() {
    if (Serial.available() > 0) {
        String comando = Serial.readStringUntil('\n');
        comando.trim();
        procesarComando(comando);
    }
}

void procesarComando(String cmd) {
    cmd.toUpperCase();

    if (cmd == "STATUS") {
        mostrarEstado();
    } else if (cmd == "HELP") {
        mostrarAyuda();
    }
    // [Más comandos]
}

void mostrarEstado() {
    Serial.println("--- Estado del Sistema ---");
    Serial.print("Valor actual: ");
    Serial.println(estado.valorActual);
    Serial.print("Alerta: ");
    Serial.println(estado.alertaActiva ? "SI" : "No");
}

void mostrarAyuda() {
    Serial.println("--- Comandos disponibles ---");
    Serial.println("STATUS - Mostrar estado");
    Serial.println("HELP   - Esta ayuda");
}

// ==================================================
// FUNCIONES DE ALERTAS
// ==================================================
void verificarAlertas() {
    estado.alertaActiva = (estado.valorActual > config.umbralAlto);

    if (estado.alertaActiva) {
        activarAlerta();
    } else {
        desactivarAlerta();
    }
}

void activarAlerta() {
    // Acciones de alerta
}

void desactivarAlerta() {
    // Desactivar alerta
}
```

---

## 🎤 Guía de Presentación

### Estructura de la Presentación (10-15 min)

```
PRESENTACIÓN DEL PROYECTO FINAL

1. INTRODUCCIÓN (2 min)
   ├── Nombre del proyecto
   ├── Objetivo principal
   └── Problema que resuelve

2. DEMOSTRACIÓN (5 min)
   ├── Funcionamiento en vivo
   ├── Modos de operación
   └── Casos de uso

3. ASPECTOS TÉCNICOS (3 min)
   ├── Arquitectura del sistema
   ├── Decisiones de diseño
   └── Desafíos superados

4. APRENDIZAJES (2 min)
   ├── Conceptos aplicados
   ├── Nuevas habilidades
   └── Áreas de mejora

5. CONCLUSIONES (2 min)
   ├── Resultados obtenidos
   ├── Posibles mejoras futuras
   └── Próximos pasos

6. PREGUNTAS (2 min)
```

### Criterios de Evaluación de Presentación

| Aspecto                 | Excelente | Bueno | Necesita Mejorar |
| ----------------------- | --------- | ----- | ---------------- |
| Claridad de explicación | 5         | 3     | 1                |
| Demostración funcional  | 5         | 3     | 1                |
| Dominio técnico         | 5         | 3     | 1                |
| Documentación           | 5         | 3     | 1                |
| Respuestas a preguntas  | 5         | 3     | 1                |

---

## 🛠️ Código Base: Sistema Domótico (Ejemplo Completo)

```cpp
/*
 * =================================================
 * PROYECTO FINAL: Sistema Domótico Integral
 * =================================================
 *
 * Sistema de automatización del hogar con control
 * de iluminación, clima y seguridad.
 *
 * Compatible con Tinkercad
 * =================================================
 */

// ==================================================
// LIBRERÍAS
// ==================================================
#include <LiquidCrystal.h>
#include <Servo.h>

// ==================================================
// PINES
// ==================================================
// Entradas analógicas
#define PIN_TEMP    A0      // TMP36
#define PIN_LUZ     A1      // LDR
#define PIN_POT     A2      // Potenciómetro (setpoint)

// Entradas digitales
#define PIN_PIR     2       // Sensor movimiento
#define PIN_BTN_MENU 3      // Botón menú
#define PIN_BTN_OK   4      // Botón OK

// Salidas
#define PIN_SERVO   9       // Servo persiana
#define PIN_RELE    10      // Relé luz
#define PIN_BUZZER  11      // Buzzer
#define PIN_LED_OK  12      // LED estado OK
#define PIN_LED_ALERTA 13   // LED alerta

// LCD
LiquidCrystal lcd(7, 6, 5, A3, A4, A5);

// Servo
Servo servoPersiana;

// ==================================================
// CONFIGURACIÓN
// ==================================================
struct Config {
    float tempAlerta = 30.0;
    float tempMinima = 18.0;
    int luzMinima = 30;       // % luz para encender
    bool modoAuto = true;
    int tiempoPIR = 30;       // segundos
};

Config config;

// ==================================================
// ESTADO
// ==================================================
struct Estado {
    // Sensores
    float temperatura;
    int luminosidad;
    bool movimiento;

    // Actuadores
    bool luzEncendida;
    int posicionPersiana;  // 0-180

    // Sistema
    unsigned long ultimoMovimiento;
    bool alertaActiva;
    int menuActual;
    unsigned long tiempoDisplay;
};

Estado estado;

// ==================================================
// CARACTERES PERSONALIZADOS LCD
// ==================================================
byte charTemp[] = {
    B00100,
    B01010,
    B01010,
    B01110,
    B01110,
    B11111,
    B11111,
    B01110
};

byte charLuz[] = {
    B00000,
    B10101,
    B01110,
    B11111,
    B11111,
    B01110,
    B10101,
    B00000
};

byte charCasa[] = {
    B00000,
    B00100,
    B01110,
    B11111,
    B10001,
    B10001,
    B11111,
    B00000
};

// ==================================================
// MENÚS
// ==================================================
enum MenuOpciones {
    MENU_PRINCIPAL,
    MENU_LUZ,
    MENU_CLIMA,
    MENU_CONFIG,
    MENU_INFO
};

const char* menuTextos[] = {
    "Sistema Normal",
    "Control Luz",
    "Control Clima",
    "Configuracion",
    "Informacion"
};

// ==================================================
// SETUP
// ==================================================
void setup() {
    Serial.begin(9600);

    // Pines de entrada
    pinMode(PIN_PIR, INPUT);
    pinMode(PIN_BTN_MENU, INPUT_PULLUP);
    pinMode(PIN_BTN_OK, INPUT_PULLUP);

    // Pines de salida
    pinMode(PIN_RELE, OUTPUT);
    pinMode(PIN_BUZZER, OUTPUT);
    pinMode(PIN_LED_OK, OUTPUT);
    pinMode(PIN_LED_ALERTA, OUTPUT);

    // Inicializar servo
    servoPersiana.attach(PIN_SERVO);
    servoPersiana.write(0);

    // Inicializar LCD
    lcd.begin(16, 2);
    lcd.createChar(0, charTemp);
    lcd.createChar(1, charLuz);
    lcd.createChar(2, charCasa);

    // Splash screen
    mostrarSplash();

    // Estado inicial
    estado.menuActual = MENU_PRINCIPAL;
    estado.tiempoDisplay = millis();

    Serial.println("Sistema Domotico Iniciado");
    Serial.println("Comandos: STATUS, AUTO, MANUAL, LUZ, HELP");
}

// ==================================================
// LOOP
// ==================================================
void loop() {
    // Leer sensores
    leerSensores();

    // Leer botones
    manejarBotones();

    // Lógica de automatización
    if (config.modoAuto) {
        automatizacion();
    }

    // Verificar alertas
    verificarAlertas();

    // Actualizar display
    actualizarDisplay();

    // Actualizar LEDs
    actualizarLEDs();

    // Comandos serial
    manejarSerial();

    delay(100);
}

// ==================================================
// FUNCIONES DE SENSORES
// ==================================================
void leerSensores() {
    // Temperatura (TMP36)
    int rawTemp = analogRead(PIN_TEMP);
    float voltage = (rawTemp / 1023.0) * 5.0;
    estado.temperatura = (voltage - 0.5) * 100.0;

    // Luminosidad (LDR)
    int rawLuz = analogRead(PIN_LUZ);
    estado.luminosidad = map(rawLuz, 0, 1023, 100, 0);

    // Movimiento (PIR)
    bool movimientoActual = digitalRead(PIN_PIR);
    if (movimientoActual) {
        estado.ultimoMovimiento = millis();
    }
    estado.movimiento = movimientoActual;
}

// ==================================================
// AUTOMATIZACIÓN
// ==================================================
void automatizacion() {
    // Control de luz automático
    bool hayPresencia = (millis() - estado.ultimoMovimiento) < (config.tiempoPIR * 1000UL);
    bool luzInsuficiente = estado.luminosidad < config.luzMinima;

    if (hayPresencia && luzInsuficiente) {
        encenderLuz();
    } else if (!hayPresencia) {
        apagarLuz();
    }

    // Control de persiana automático
    int nuevaPosicion;
    if (estado.luminosidad > 80) {
        nuevaPosicion = 45;   // Semi-cerrada
    } else if (estado.luminosidad > 50) {
        nuevaPosicion = 90;   // Media
    } else {
        nuevaPosicion = 180;  // Abierta
    }

    moverPersiana(nuevaPosicion);
}

void encenderLuz() {
    if (!estado.luzEncendida) {
        digitalWrite(PIN_RELE, HIGH);
        estado.luzEncendida = true;
        Serial.println("Luz: ENCENDIDA");
    }
}

void apagarLuz() {
    if (estado.luzEncendida) {
        digitalWrite(PIN_RELE, LOW);
        estado.luzEncendida = false;
        Serial.println("Luz: APAGADA");
    }
}

void moverPersiana(int posicion) {
    if (abs(posicion - estado.posicionPersiana) > 5) {
        estado.posicionPersiana = posicion;
        servoPersiana.write(posicion);
        Serial.print("Persiana: ");
        Serial.println(posicion);
    }
}

// ==================================================
// ALERTAS
// ==================================================
void verificarAlertas() {
    bool alertaTemp = estado.temperatura > config.tempAlerta ||
                      estado.temperatura < config.tempMinima;

    if (alertaTemp && !estado.alertaActiva) {
        estado.alertaActiva = true;
        tone(PIN_BUZZER, 2000, 500);
        Serial.println("ALERTA: Temperatura fuera de rango!");
    } else if (!alertaTemp) {
        estado.alertaActiva = false;
    }
}

// ==================================================
// DISPLAY
// ==================================================
void mostrarSplash() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(byte(2));
    lcd.print(" DOMOTICA PRO");
    lcd.setCursor(0, 1);
    lcd.print("  Iniciando...");
    delay(2000);
    lcd.clear();
}

void actualizarDisplay() {
    static unsigned long ultimaAct = 0;

    if (millis() - ultimaAct < 500) return;
    ultimaAct = millis();

    lcd.setCursor(0, 0);

    switch (estado.menuActual) {
        case MENU_PRINCIPAL:
            mostrarPrincipal();
            break;
        case MENU_LUZ:
            mostrarMenuLuz();
            break;
        case MENU_CLIMA:
            mostrarMenuClima();
            break;
        case MENU_CONFIG:
            mostrarMenuConfig();
            break;
        case MENU_INFO:
            mostrarMenuInfo();
            break;
    }
}

void mostrarPrincipal() {
    // Línea 1: Temperatura y luz
    lcd.setCursor(0, 0);
    lcd.write(byte(0));  // Icono temp
    lcd.print(estado.temperatura, 1);
    lcd.print("C ");
    lcd.write(byte(1));  // Icono luz
    lcd.print(estado.luminosidad);
    lcd.print("%  ");

    // Línea 2: Estado
    lcd.setCursor(0, 1);
    lcd.print("L:");
    lcd.print(estado.luzEncendida ? "ON " : "OFF");
    lcd.print(" P:");
    lcd.print(estado.posicionPersiana);
    lcd.print("  ");
    lcd.print(config.modoAuto ? "A" : "M");
}

void mostrarMenuLuz() {
    lcd.setCursor(0, 0);
    lcd.print("Control de Luz  ");
    lcd.setCursor(0, 1);
    lcd.print("Estado: ");
    lcd.print(estado.luzEncendida ? "ON     " : "OFF    ");
}

void mostrarMenuClima() {
    lcd.setCursor(0, 0);
    lcd.print("Temperatura:    ");
    lcd.setCursor(0, 1);
    lcd.print(estado.temperatura, 1);
    lcd.print("C Lim:");
    lcd.print(config.tempAlerta, 0);
    lcd.print("   ");
}

void mostrarMenuConfig() {
    lcd.setCursor(0, 0);
    lcd.print("Modo: ");
    lcd.print(config.modoAuto ? "AUTO    " : "MANUAL  ");
    lcd.setCursor(0, 1);
    lcd.print("PIR Delay: ");
    lcd.print(config.tiempoPIR);
    lcd.print("s ");
}

void mostrarMenuInfo() {
    lcd.setCursor(0, 0);
    lcd.print("Domotica v1.0   ");
    lcd.setCursor(0, 1);
    lcd.print("Bootcamp Arduino");
}

// ==================================================
// BOTONES
// ==================================================
void manejarBotones() {
    static bool btnMenuAnterior = HIGH;
    static bool btnOKAnterior = HIGH;

    bool btnMenu = digitalRead(PIN_BTN_MENU);
    bool btnOK = digitalRead(PIN_BTN_OK);

    // Botón menú - cambiar menú
    if (btnMenu == LOW && btnMenuAnterior == HIGH) {
        estado.menuActual = (estado.menuActual + 1) % 5;
        tone(PIN_BUZZER, 1000, 50);
        lcd.clear();
    }

    // Botón OK - acción en menú actual
    if (btnOK == LOW && btnOKAnterior == HIGH) {
        ejecutarAccionMenu();
        tone(PIN_BUZZER, 1500, 50);
    }

    btnMenuAnterior = btnMenu;
    btnOKAnterior = btnOK;
}

void ejecutarAccionMenu() {
    switch (estado.menuActual) {
        case MENU_LUZ:
            if (estado.luzEncendida) apagarLuz();
            else encenderLuz();
            break;

        case MENU_CONFIG:
            config.modoAuto = !config.modoAuto;
            Serial.print("Modo: ");
            Serial.println(config.modoAuto ? "AUTO" : "MANUAL");
            break;
    }
}

// ==================================================
// LEDS
// ==================================================
void actualizarLEDs() {
    // LED OK - parpadea en auto, fijo en manual
    static unsigned long ultimoParpadeo = 0;
    static bool ledEstado = false;

    if (config.modoAuto) {
        if (millis() - ultimoParpadeo >= 1000) {
            ultimoParpadeo = millis();
            ledEstado = !ledEstado;
            digitalWrite(PIN_LED_OK, ledEstado);
        }
    } else {
        digitalWrite(PIN_LED_OK, HIGH);
    }

    // LED Alerta
    if (estado.alertaActiva) {
        digitalWrite(PIN_LED_ALERTA, (millis() / 250) % 2);
    } else {
        digitalWrite(PIN_LED_ALERTA, LOW);
    }
}

// ==================================================
// SERIAL
// ==================================================
void manejarSerial() {
    if (Serial.available() > 0) {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();
        cmd.toUpperCase();

        if (cmd == "STATUS") {
            imprimirEstado();
        } else if (cmd == "AUTO") {
            config.modoAuto = true;
            Serial.println("Modo AUTO activado");
        } else if (cmd == "MANUAL") {
            config.modoAuto = false;
            Serial.println("Modo MANUAL activado");
        } else if (cmd == "LUZ ON") {
            encenderLuz();
        } else if (cmd == "LUZ OFF") {
            apagarLuz();
        } else if (cmd.startsWith("PERSIANA ")) {
            int pos = cmd.substring(9).toInt();
            moverPersiana(constrain(pos, 0, 180));
        } else if (cmd == "HELP") {
            imprimirAyuda();
        }
    }
}

void imprimirEstado() {
    Serial.println("========== ESTADO DEL SISTEMA ==========");
    Serial.print("Temperatura: ");
    Serial.print(estado.temperatura, 1);
    Serial.println(" C");
    Serial.print("Luminosidad: ");
    Serial.print(estado.luminosidad);
    Serial.println(" %");
    Serial.print("Movimiento: ");
    Serial.println(estado.movimiento ? "SI" : "No");
    Serial.print("Luz: ");
    Serial.println(estado.luzEncendida ? "ENCENDIDA" : "APAGADA");
    Serial.print("Persiana: ");
    Serial.println(estado.posicionPersiana);
    Serial.print("Modo: ");
    Serial.println(config.modoAuto ? "AUTO" : "MANUAL");
    Serial.print("Alerta: ");
    Serial.println(estado.alertaActiva ? "ACTIVA" : "Ninguna");
    Serial.println("=========================================");
}

void imprimirAyuda() {
    Serial.println("========== COMANDOS ==========");
    Serial.println("STATUS       - Ver estado");
    Serial.println("AUTO         - Modo automatico");
    Serial.println("MANUAL       - Modo manual");
    Serial.println("LUZ ON/OFF   - Control luz");
    Serial.println("PERSIANA N   - Mover persiana (0-180)");
    Serial.println("HELP         - Esta ayuda");
    Serial.println("==============================");
}
```

---

## 📖 Recursos Adicionales

### Próximos Pasos de Aprendizaje

```
DESPUÉS DEL BOOTCAMP - CAMINOS DE ESPECIALIZACIÓN

┌─────────────────────────────────────────────────────────────┐
│                                                             │
│  1. IoT AVANZADO                                           │
│     ├── ESP32 / ESP8266                                    │
│     ├── MQTT con broker propio                             │
│     ├── Bases de datos (InfluxDB, MongoDB)                 │
│     └── Dashboards (Grafana, Node-RED)                     │
│                                                             │
│  2. ROBÓTICA                                               │
│     ├── ROS (Robot Operating System)                       │
│     ├── Sensores LIDAR                                     │
│     ├── Visión por computador                              │
│     └── Machine Learning en edge                           │
│                                                             │
│  3. SISTEMAS EMBEBIDOS                                     │
│     ├── ARM Cortex-M (STM32)                              │
│     ├── RTOS (FreeRTOS)                                   │
│     ├── Protocolos industriales (CAN, Modbus)             │
│     └── Diseño de PCBs                                     │
│                                                             │
│  4. PRODUCTO/STARTUP                                       │
│     ├── Prototipado rápido                                │
│     ├── Crowdfunding (Kickstarter)                        │
│     ├── Manufactura y certificaciones                     │
│     └── Desarrollo de producto                            │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Comunidades y Recursos

- **Foros:** Arduino Forum, Reddit r/arduino, Stack Overflow
- **YouTube:** GreatScott!, Andreas Spiess, DroneBot Workshop
- **Cursos:** Coursera, Udemy, edX
- **Makers:** Instructables, Hackster.io

---

## ✅ Checklist Final del Bootcamp

### Conocimientos Adquiridos

- [ ] Fundamentos de electrónica
- [ ] Programación en Arduino C/C++
- [ ] Entradas/salidas digitales
- [ ] PWM y señales analógicas
- [ ] Sensores (temperatura, luz, distancia, movimiento)
- [ ] Actuadores (LEDs, motores, relés)
- [ ] Comunicación serial
- [ ] Displays (7 segmentos, LCD)
- [ ] Protocolos I2C/SPI
- [ ] Conceptos de IoT

### Habilidades Desarrolladas

- [ ] Diseño de circuitos
- [ ] Debugging y troubleshooting
- [ ] Documentación técnica
- [ ] Gestión de proyectos
- [ ] Presentación de proyectos

### Proyecto Final

- [ ] Proyecto seleccionado
- [ ] Diseño completado
- [ ] Implementación funcional
- [ ] Documentación entregada
- [ ] Presentación realizada

---

## 🎓 Certificación

Al completar satisfactoriamente el bootcamp, recibirás:

1. **Certificado de Finalización** - Bootcamp Arduino 10 semanas
2. **Portfolio de Proyectos** - Con todos los proyectos realizados
3. **Código Fuente** - Repositorio con todo el material

### Requisitos para Certificación

| Requisito                        | Mínimo      |
| -------------------------------- | ----------- |
| Asistencia/Participación         | 80%         |
| Ejercicios semanales completados | 70%         |
| Proyectos semanales entregados   | 8 de 10     |
| Proyecto final presentado        | Obligatorio |
| Documentación del proyecto final | Obligatorio |

---

## 🎉 ¡Felicitaciones!

Has completado el **Bootcamp de Arduino**. Ahora tienes las bases sólidas para:

- Desarrollar proyectos de electrónica
- Crear prototipos funcionales
- Continuar aprendiendo IoT y sistemas embebidos
- Contribuir a la comunidad maker

**¡El único límite es tu imaginación!** 🚀

---

**Dedicación:** 4 horas | **Anterior:** [← Semana 9](../semana-09/README.md) | **Inicio:** [README Principal](../../README.md)
