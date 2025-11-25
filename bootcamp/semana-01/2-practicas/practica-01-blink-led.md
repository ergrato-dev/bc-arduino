# 💻 Práctica 01: Blink LED Integrado

> ⏱️ **Tiempo estimado:** 20 minutos  
> ⭐ **Dificultad:** Principiante  
> 🎯 **Compatibilidad Tinkercad:** ✅

---

## 📋 Información General

| Campo               | Valor                                           |
| ------------------- | ----------------------------------------------- |
| **Dificultad**      | ⭐ Principiante                                 |
| **Tiempo estimado** | 20 minutos                                      |
| **Componentes**     | Arduino Uno R3 (solo)                           |
| **Conceptos**       | digitalWrite, delay, pinMode, estructura sketch |

---

## 🎯 Objetivos

Al completar esta práctica, serás capaz de:

- [ ] Escribir y cargar tu primer programa en Arduino
- [ ] Usar las funciones `pinMode()` y `digitalWrite()`
- [ ] Controlar tiempos con `delay()`
- [ ] Entender el ciclo setup/loop
- [ ] Modificar parámetros para cambiar comportamiento

---

## 📝 Descripción

El **Blink** es el "Hola Mundo" del mundo Arduino. Consiste en hacer parpadear el LED integrado que viene en la placa Arduino Uno, conectado al pin 13.

Este ejercicio no requiere componentes externos, lo que lo hace perfecto para verificar que tu entorno de desarrollo funciona correctamente.

---

## 🔧 Requisitos Técnicos

### Hardware

- Arduino Uno R3 (físico o simulado en Tinkercad)

### Software

- Tinkercad Circuits (recomendado para principiantes)
- O Arduino IDE 2.x (para hardware físico)

---

## 📋 Instrucciones

### Paso 1: Crear el Proyecto

**En Tinkercad:**

1. Ve a [tinkercad.com](https://www.tinkercad.com/) e inicia sesión
2. Clic en **Circuits** → **Create new Circuit**
3. Arrastra un **Arduino Uno R3** al área de trabajo
4. Renombra el proyecto: "Practica-01-Blink-LED"

**En Arduino IDE:**

1. Abre Arduino IDE
2. **File** → **New Sketch**
3. Guarda como "practica-01-blink-led"

### Paso 2: Identificar el LED Integrado

El Arduino Uno tiene un LED integrado marcado como "L" cerca del pin 13:

```
┌─────────────────────────────────────────┐
│                                         │
│            ARDUINO UNO R3               │
│                                         │
│                    ┌───┐                │
│                    │ L │◄─── LED integrado
│                    └───┘     (Pin 13)   │
│                                         │
│                              Pin 13 ────┤
│                                         │
└─────────────────────────────────────────┘
```

### Paso 3: Escribir el Código

Copia el siguiente código en el editor:

```cpp
/*
 * =================================================
 * PRÁCTICA 01: Blink LED Integrado
 * =================================================
 *
 * ¿Qué hace?
 * Hace parpadear el LED integrado del Arduino (pin 13)
 * encendiéndolo y apagándolo cada segundo.
 *
 * ¿Para qué?
 * - Verificar que el Arduino funciona correctamente
 * - Aprender la estructura básica de un sketch
 * - Practicar con digitalWrite() y delay()
 *
 * ¿Cómo funciona?
 * 1. setup() configura el pin 13 como salida
 * 2. loop() ejecuta un ciclo infinito:
 *    - Enciende LED (HIGH = 5V)
 *    - Espera 1 segundo
 *    - Apaga LED (LOW = 0V)
 *    - Espera 1 segundo
 *    - Repite...
 *
 * Hardware requerido:
 * - Arduino Uno R3 (el LED está integrado)
 *
 * Conexiones:
 * - Ninguna externa requerida
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// CONSTANTES
// ==================================================

// Pin del LED integrado en Arduino Uno
const int LED_PIN = 13;

// Tiempo de encendido/apagado en milisegundos
const int BLINK_DELAY = 1000;  // 1000ms = 1 segundo

// ==================================================
// SETUP - Se ejecuta UNA vez al inicio
// ==================================================
void setup() {
    // Configurar el pin del LED como SALIDA
    // OUTPUT significa que el pin enviará voltaje (no lo recibirá)
    pinMode(LED_PIN, OUTPUT);
}

// ==================================================
// LOOP - Se ejecuta INFINITAMENTE después de setup()
// ==================================================
void loop() {
    // Encender el LED
    // HIGH envía 5V al pin, lo que enciende el LED
    digitalWrite(LED_PIN, HIGH);

    // Esperar 1 segundo (1000 milisegundos)
    // Durante este tiempo, el LED permanece encendido
    delay(BLINK_DELAY);

    // Apagar el LED
    // LOW envía 0V al pin, lo que apaga el LED
    digitalWrite(LED_PIN, LOW);

    // Esperar 1 segundo
    // Durante este tiempo, el LED permanece apagado
    delay(BLINK_DELAY);

    // Al terminar loop(), automáticamente vuelve a empezar
}
```

### Paso 4: Ejecutar la Simulación

**En Tinkercad:**

1. Clic en el botón **"Start Simulation"** (verde)
2. Observa el LED "L" en el Arduino parpadeando
3. Clic en **"Stop Simulation"** para detener

**En Arduino IDE:**

1. Clic en **Verify** (✓) para compilar
2. Clic en **Upload** (→) para cargar al Arduino
3. Observa el LED físico parpadeando

### Paso 5: Experimentar con Variaciones

Modifica el código para probar diferentes comportamientos:

#### Variación A: Parpadeo Rápido

```cpp
const int BLINK_DELAY = 100;  // 100ms = 0.1 segundo
```

#### Variación B: Parpadeo Lento

```cpp
const int BLINK_DELAY = 2000;  // 2000ms = 2 segundos
```

#### Variación C: Parpadeo Asimétrico

```cpp
void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(200);   // Encendido breve

    digitalWrite(LED_PIN, LOW);
    delay(800);   // Apagado largo
}
```

---

## 🎨 Resultado Esperado

```
┌─────────────────────────────────────────────────────────┐
│                    COMPORTAMIENTO                        │
├─────────────────────────────────────────────────────────┤
│                                                          │
│   Tiempo (segundos):  0    1    2    3    4    5        │
│                       │    │    │    │    │    │        │
│   Estado LED:         ████      ████      ████          │
│                       ON  OFF   ON  OFF   ON  OFF       │
│                                                          │
│   El LED parpadea con ciclo de 2 segundos:              │
│   - 1 segundo encendido                                  │
│   - 1 segundo apagado                                    │
│                                                          │
└─────────────────────────────────────────────────────────┘
```

---

## 💡 Pistas

<details>
<summary>Pista 1: ¿El LED no parpadea?</summary>

Verifica que:

- El código no tiene errores de sintaxis (compila sin errores)
- Estás usando el pin correcto (13 para LED integrado)
- La simulación está iniciada (botón verde)

</details>

<details>
<summary>Pista 2: ¿Cómo hacer que parpadee más rápido?</summary>

Reduce el valor de `BLINK_DELAY`. Por ejemplo:

```cpp
const int BLINK_DELAY = 250;  // Parpadeo 4 veces por segundo
```

</details>

<details>
<summary>Pista 3: ¿Cómo crear el patrón SOS?</summary>

El código Morse para SOS es: `... --- ...` (3 cortos, 3 largos, 3 cortos)

```cpp
void loop() {
    // S: 3 cortos
    for(int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(200);
        digitalWrite(LED_PIN, LOW);
        delay(200);
    }
    delay(400);  // Pausa entre letras

    // O: 3 largos
    for(int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(600);
        digitalWrite(LED_PIN, LOW);
        delay(200);
    }
    delay(400);

    // S: 3 cortos
    for(int i = 0; i < 3; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(200);
        digitalWrite(LED_PIN, LOW);
        delay(200);
    }
    delay(1000);  // Pausa antes de repetir
}
```

</details>

---

## ✅ Criterios de Evaluación

| Criterio          | Puntos | Descripción                                     |
| ----------------- | ------ | ----------------------------------------------- |
| **Funcionalidad** | 4      | LED parpadea correctamente según especificación |
| **Código limpio** | 2      | Constantes usadas, comentarios presentes        |
| **Variaciones**   | 2      | Implementa al menos 2 variaciones de tiempo     |
| **Total**         | **8**  |                                                 |

### Niveles de Logro

| Nivel        | Puntos | Descripción                                                            |
| ------------ | ------ | ---------------------------------------------------------------------- |
| Excelente    | 7-8    | Funciona perfectamente, código bien documentado, múltiples variaciones |
| Bueno        | 5-6    | Funciona, documentación básica, al menos una variación                 |
| Suficiente   | 3-4    | Funciona con código base                                               |
| Insuficiente | 0-2    | No funciona o código incompleto                                        |

---

## 🚀 Desafío Extra (Opcional)

### Desafío: Código Morse

Implementa un programa que parpadee tu nombre en código Morse.

**Tabla de Código Morse:**

| Letra | Código | Letra | Código |
| ----- | ------ | ----- | ------ |
| A     | .-     | N     | -.     |
| B     | -...   | O     | ---    |
| C     | -.-.   | P     | .--.   |
| D     | -..    | Q     | --.-   |
| E     | .      | R     | .-.    |
| F     | ..-.   | S     | ...    |
| G     | --.    | T     | -      |
| H     | ....   | U     | ..-    |
| I     | ..     | V     | ...-   |
| J     | .---   | W     | .--    |
| K     | -.-    | X     | -..-   |
| L     | .-..   | Y     | -.--   |
| M     | --     | Z     | --..   |

**Convención de tiempos:**

- Punto (.) = LED encendido 200ms
- Raya (-) = LED encendido 600ms
- Entre símbolos = 200ms apagado
- Entre letras = 600ms apagado
- Entre palabras = 1400ms apagado

---

## 📚 Recursos Relacionados

| Recurso                         | Enlace                                                                                        |
| ------------------------------- | --------------------------------------------------------------------------------------------- |
| Teoría: Arduino IDE             | [Módulo 03](../1-teoria/03-arduino-ide-tinkercad.md)                                          |
| Arduino Reference: digitalWrite | [arduino.cc](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/) |
| Arduino Reference: delay        | [arduino.cc](https://www.arduino.cc/reference/en/language/functions/time/delay/)              |

---

## 📝 Reflexión

Antes de continuar a la siguiente práctica, responde:

1. ¿Qué pasa si olvidas el `delay()` después de `digitalWrite(HIGH)`?
2. ¿Por qué usamos constantes (`const int`) en lugar de escribir `13` directamente?
3. ¿Cuántas veces por segundo parpadea el LED con `delay(250)`?

---

<div align="center">

[⬅️ Índice Prácticas](./README.md) | [Práctica 02 ➡️](./practica-02-led-externo.md)

</div>
