# Módulo 03: Arduino IDE y Tinkercad

> ⏱️ **Tiempo estimado:** 15 minutos  
> 📚 **Nivel:** Principiante  
> 🎯 **Compatibilidad Tinkercad:** ✅

---

## 🎯 Objetivos del Módulo

Al finalizar este módulo, serás capaz de:

- [ ] Configurar una cuenta en Tinkercad
- [ ] Crear y simular un circuito básico
- [ ] Entender la estructura de un sketch Arduino
- [ ] Escribir tu primer programa (Blink)
- [ ] Usar el Serial Monitor para debugging

---

## 📚 Contenido

### 3.1 Introducción a Tinkercad

**Tinkercad Circuits** es un simulador gratuito online que permite diseñar y probar circuitos con Arduino sin necesidad de hardware físico.

#### Ventajas de Tinkercad

| Ventaja | Descripción |
|---------|-------------|
| **Gratuito** | Sin costo, solo necesitas una cuenta |
| **Online** | No requiere instalación |
| **Seguro** | No puedes quemar componentes reales |
| **Educativo** | Ideal para aprender sin riesgos |
| **Compartible** | Fácil compartir proyectos |

#### Limitaciones

| Limitación | Alternativa |
|------------|-------------|
| Solo Arduino Uno R3 | Wokwi para otras placas |
| No todas las librerías | Hardware real para proyectos avanzados |
| Requiere internet | Arduino IDE offline |

---

### 3.2 Configuración de Tinkercad

#### Paso 1: Crear Cuenta

1. Ve a [tinkercad.com](https://www.tinkercad.com/)
2. Clic en **"Registrarse"** o **"Sign Up"**
3. Puedes usar cuenta de Google, Apple, o crear una nueva

#### Paso 2: Acceder a Circuits

```
┌─────────────────────────────────────────────────────────────┐
│  TINKERCAD                                          [User]  │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   ┌───────────┐   ┌───────────┐   ┌───────────┐            │
│   │           │   │           │   │           │            │
│   │    3D     │   │ CIRCUITS  │◄──│ Codeblocks│            │
│   │  Designs  │   │   ★★★     │   │           │            │
│   │           │   │ Clic aquí │   │           │            │
│   └───────────┘   └───────────┘   └───────────┘            │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

#### Paso 3: Crear Nuevo Circuito

1. Clic en **"Circuits"** en el menú lateral
2. Clic en **"Create new Circuit"** (botón verde)
3. Se abre el editor de circuitos

---

### 3.3 Interfaz de Tinkercad Circuits

```
┌─────────────────────────────────────────────────────────────────┐
│  Untitled ▼  │ Share │ Export │ [▶ Start Simulation]           │
├─────────────────────────────────────────────────────────────────┤
│                                          │                      │
│                                          │  COMPONENTES         │
│                                          │  ┌────────────────┐  │
│                                          │  │ 🔍 Search      │  │
│         ÁREA DE TRABAJO                  │  ├────────────────┤  │
│                                          │  │ ○ Basic        │  │
│     Arrastra componentes aquí            │  │ ○ Arduino      │◄─┼─ Clic aquí
│                                          │  │ ○ Input        │  │
│                                          │  │ ○ Output       │  │
│                                          │  │ ○ Power        │  │
│                                          │  │ ○ All          │  │
│                                          │  └────────────────┘  │
├──────────────────────────────────────────┴──────────────────────┤
│  Code ▼  │  Serial Monitor  │  [Components]  [Code]  [Serial]   │
│                                                                  │
│  // Tu código aquí                                              │
│  void setup() {                                                 │
│                                                                  │
│  }                                                               │
│                                                                  │
└──────────────────────────────────────────────────────────────────┘
```

#### Elementos de la Interfaz

| Elemento | Función |
|----------|---------|
| **Start Simulation** | Inicia/detiene la simulación |
| **Components** | Panel de componentes arrastrables |
| **Code** | Editor de código Arduino |
| **Serial Monitor** | Ver mensajes de Serial.print() |
| **Share** | Compartir proyecto |
| **Export** | Descargar código o esquemático |

---

### 3.4 Tu Primer Circuito

Vamos a crear el circuito "Hola Mundo" de Arduino: **Blink LED**.

#### Paso 1: Agregar Arduino

1. En el panel **Components**, selecciona **"Arduino"**
2. Arrastra **"Arduino Uno R3"** al área de trabajo

#### Paso 2: El LED Integrado

El Arduino Uno tiene un **LED integrado** en el pin 13. ¡No necesitas agregar componentes externos para este ejercicio!

```
┌─────────────────────────────────────────┐
│                                         │
│            ARDUINO UNO R3               │
│                                         │
│                              [L]◄─────── LED integrado (Pin 13)
│                                         │
│                                         │
└─────────────────────────────────────────┘
```

#### Paso 3: Escribir el Código

Clic en **"Code"** para abrir el editor y selecciona **"Text"** (no bloques):

```cpp
/*
 * =================================================
 * Blink - El "Hola Mundo" de Arduino
 * =================================================
 *
 * ¿Qué hace?
 * Hace parpadear el LED integrado del Arduino
 *
 * ¿Para qué?
 * Verificar que el Arduino funciona correctamente
 * y entender la estructura básica de un programa
 *
 * ¿Cómo funciona?
 * 1. setup() configura el pin 13 como salida
 * 2. loop() alterna el estado del LED cada segundo
 *
 * Hardware requerido:
 * - Arduino Uno (el LED está integrado en pin 13)
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// CONSTANTES
// ==================================================
const int LED_PIN = 13;  // LED integrado en Arduino Uno

// ==================================================
// SETUP - Se ejecuta UNA vez al inicio
// ==================================================
void setup() {
    // Configurar el pin del LED como SALIDA
    pinMode(LED_PIN, OUTPUT);
}

// ==================================================
// LOOP - Se ejecuta INFINITAMENTE
// ==================================================
void loop() {
    digitalWrite(LED_PIN, HIGH);  // Enciende el LED (5V)
    delay(1000);                  // Espera 1000 ms (1 segundo)
    
    digitalWrite(LED_PIN, LOW);   // Apaga el LED (0V)
    delay(1000);                  // Espera 1000 ms
}
```

#### Paso 4: Simular

1. Clic en **"Start Simulation"** (botón verde)
2. Observa el LED "L" en el Arduino parpadeando
3. Clic en **"Stop Simulation"** para detener

---

### 3.5 Estructura de un Sketch Arduino

Un programa de Arduino (llamado **sketch**) tiene dos funciones obligatorias:

```
┌─────────────────────────────────────────────────────────────┐
│                  ESTRUCTURA DE UN SKETCH                    │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   ┌─────────────────────────────────────────────────────┐   │
│   │  ZONA DE DECLARACIONES (Opcional)                   │   │
│   │  • #include <libreria.h>                            │   │
│   │  • #define CONSTANTE valor                          │   │
│   │  • const int PIN = 13;                              │   │
│   │  • int variable = 0;                                │   │
│   └─────────────────────────────────────────────────────┘   │
│                          │                                  │
│                          ▼                                  │
│   ┌─────────────────────────────────────────────────────┐   │
│   │  void setup() {                                     │   │
│   │      // Se ejecuta UNA VEZ al inicio               │   │
│   │      // Configuración de pines                      │   │
│   │      // Inicialización de Serial                    │   │
│   │      // Setup de librerías                          │   │
│   │  }                                                  │   │
│   └─────────────────────────────────────────────────────┘   │
│                          │                                  │
│                          ▼                                  │
│   ┌─────────────────────────────────────────────────────┐   │
│   │  void loop() {                                      │   │
│   │      // Se ejecuta EN BUCLE INFINITO               │   │
│   │      // Leer sensores                               │   │
│   │      // Procesar datos                              │   │
│   │      // Controlar actuadores                        │   │
│   │  }                     ◄────────────────────────┐   │   │
│   └────────────────────────│────────────────────────│───┘   │
│                            └────────────────────────┘       │
│                              (se repite infinitamente)      │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

#### Funciones Básicas

| Función | Descripción | Ejemplo |
|---------|-------------|---------|
| `pinMode(pin, mode)` | Configura pin como INPUT o OUTPUT | `pinMode(13, OUTPUT);` |
| `digitalWrite(pin, value)` | Escribe HIGH (5V) o LOW (0V) | `digitalWrite(13, HIGH);` |
| `digitalRead(pin)` | Lee estado de un pin (HIGH/LOW) | `int estado = digitalRead(2);` |
| `delay(ms)` | Pausa ejecución por milisegundos | `delay(1000);` |
| `millis()` | Tiempo desde inicio en ms | `unsigned long t = millis();` |

---

### 3.6 Serial Monitor

El **Serial Monitor** es tu herramienta de debugging. Permite ver mensajes desde el Arduino en tu computadora.

#### Configuración

```cpp
void setup() {
    Serial.begin(9600);  // Inicializar comunicación a 9600 baudios
    Serial.println("Arduino iniciado!");
}

void loop() {
    Serial.print("Tiempo: ");
    Serial.print(millis());
    Serial.println(" ms");
    delay(1000);
}
```

#### Funciones Serial

| Función | Descripción |
|---------|-------------|
| `Serial.begin(baudrate)` | Inicia comunicación (típico: 9600) |
| `Serial.print(dato)` | Imprime sin salto de línea |
| `Serial.println(dato)` | Imprime con salto de línea |
| `Serial.read()` | Lee un byte del buffer |
| `Serial.available()` | Bytes disponibles para leer |

#### Usar Serial en Tinkercad

1. Escribe código con `Serial.print()`
2. Inicia la simulación
3. Clic en **"Serial Monitor"** en la parte inferior
4. Observa los mensajes

```
┌─────────────────────────────────────────┐
│  Serial Monitor                    [X]  │
├─────────────────────────────────────────┤
│  Arduino iniciado!                      │
│  Tiempo: 1000 ms                        │
│  Tiempo: 2000 ms                        │
│  Tiempo: 3000 ms                        │
│  ...                                    │
└─────────────────────────────────────────┘
```

---

### 3.7 Ejemplo Completo con Serial

```cpp
/*
 * =================================================
 * Blink con Serial Monitor
 * =================================================
 *
 * ¿Qué hace?
 * Hace parpadear el LED y reporta el estado por Serial
 *
 * ¿Para qué?
 * Aprender a usar Serial Monitor para debugging
 *
 * ¿Cómo funciona?
 * 1. Imprime mensaje de inicio en setup()
 * 2. En cada ciclo, reporta si el LED está ON u OFF
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

const int LED_PIN = 13;
const int BAUD_RATE = 9600;
const int BLINK_DELAY = 1000;

int blinkCount = 0;  // Contador de parpadeos

void setup() {
    // Configurar pin del LED
    pinMode(LED_PIN, OUTPUT);
    
    // Iniciar comunicación Serial
    Serial.begin(BAUD_RATE);
    
    // Mensaje de bienvenida
    Serial.println("=================================");
    Serial.println("   Blink LED con Serial Monitor  ");
    Serial.println("=================================");
    Serial.println();
}

void loop() {
    // Incrementar contador
    blinkCount++;
    
    // Encender LED
    digitalWrite(LED_PIN, HIGH);
    Serial.print("Parpadeo #");
    Serial.print(blinkCount);
    Serial.println(": LED ON");
    delay(BLINK_DELAY);
    
    // Apagar LED
    digitalWrite(LED_PIN, LOW);
    Serial.print("Parpadeo #");
    Serial.print(blinkCount);
    Serial.println(": LED OFF");
    delay(BLINK_DELAY);
    
    Serial.println("---");
}
```

---

## 💡 Puntos Clave

1. **Tinkercad es gratuito y online** - Perfecto para aprender sin hardware
2. **setup() se ejecuta una vez** - Para configuración inicial
3. **loop() se ejecuta infinitamente** - Aquí va la lógica principal
4. **Serial Monitor es tu debugger** - Usa `Serial.println()` para ver qué pasa
5. **pinMode() antes de usar un pin** - Siempre configurar como INPUT o OUTPUT

---

## ⚠️ Errores Comunes

| Error | Síntoma | Solución |
|-------|---------|----------|
| Olvidar `Serial.begin()` | Serial Monitor vacío | Agregar en setup() |
| Olvidar `pinMode()` | Pin no responde | Configurar antes de usar |
| `delay()` muy largo | Programa parece colgado | Reducir tiempo o usar millis() |
| Baudrate incorrecto | Caracteres extraños en Serial | Verificar mismo baudrate |
| Falta `;` al final | Error de compilación | Revisar sintaxis |

---

## ✅ Autoevaluación

1. ¿Cuántas veces se ejecuta `setup()`?
2. ¿Qué función usas para configurar un pin como salida?
3. ¿Qué diferencia hay entre `Serial.print()` y `Serial.println()`?
4. ¿Para qué sirve `delay(500)`?
5. ¿Cuál es el baudrate típico para Serial?

<details>
<summary>💡 Ver respuestas</summary>

1. **Una sola vez**, al encender o reiniciar el Arduino.
2. **`pinMode(pin, OUTPUT);`**
3. **`println()` agrega un salto de línea** al final; `print()` no.
4. **Pausa la ejecución por 500 milisegundos** (medio segundo).
5. **9600 baudios** es el valor más común para principiantes.

</details>

---

## 🔗 Referencias

- [Tinkercad Circuits](https://www.tinkercad.com/circuits)
- [Arduino Reference - setup()](https://www.arduino.cc/reference/en/language/structure/sketch/setup/)
- [Arduino Reference - loop()](https://www.arduino.cc/reference/en/language/structure/sketch/loop/)
- [Arduino Reference - Serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/)

---

<div align="center">

[⬅️ Módulo 02](./02-electronica-basica.md) | [Índice](./README.md) | [Prácticas ➡️](../2-practicas/README.md)

</div>
