# 💻 Práctica 02: LED Externo con Resistencia

> ⏱️ **Tiempo estimado:** 25 minutos  
> ⭐⭐ **Dificultad:** Básico  
> 🎯 **Compatibilidad Tinkercad:** ✅

---

## 📋 Información General

| Campo               | Valor                                                        |
| ------------------- | ------------------------------------------------------------ |
| **Dificultad**      | ⭐⭐ Básico                                                  |
| **Tiempo estimado** | 25 minutos                                                   |
| **Componentes**     | Arduino Uno, LED, Resistencia 220Ω, Protoboard, Cables       |
| **Conceptos**       | Circuitos, Ley de Ohm, polaridad LED, resistencia limitadora |

---

## 🎯 Objetivos

Al completar esta práctica, serás capaz de:

- [ ] Armar tu primer circuito en protoboard
- [ ] Calcular la resistencia correcta para un LED
- [ ] Identificar la polaridad de un LED
- [ ] Conectar componentes externos al Arduino
- [ ] Aplicar la Ley de Ohm en un caso real

---

## 📝 Descripción

En esta práctica conectarás un **LED externo** al Arduino usando una **resistencia limitadora**. Aprenderás a calcular el valor de la resistencia necesaria para proteger el LED y a armar el circuito en una protoboard.

---

## 🔧 Requisitos Técnicos

### Componentes

| Componente       | Cantidad | Notas                    |
| ---------------- | -------- | ------------------------ |
| Arduino Uno R3   | 1        | Físico o Tinkercad       |
| LED Rojo         | 1        | Cualquier color funciona |
| Resistencia 220Ω | 1        | Rojo-Rojo-Marrón-Dorado  |
| Protoboard       | 1        | Mini o estándar          |
| Cables jumper    | 2        | Macho-macho              |

### Diagrama de Componentes

```
┌─────────────────────────────────────────────────────────────┐
│                      COMPONENTES                            │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   LED (Diodo Emisor de Luz)      Resistencia 220Ω          │
│                                                             │
│        ┌───┐                     ┌──────────────┐          │
│        │ ◯ │                     │▐█▌▐█▌▐█▌  ▐█▌│          │
│        │   │                     │ROJ ROJ MAR ORO│          │
│        └─┬─┘                     └──────────────┘          │
│         / \                       2   2  x10  ±5%          │
│    (+) /   \ (-)                  = 220Ω                   │
│       /     \                                               │
│   Ánodo    Cátodo                                          │
│   (largo)  (corto)                                          │
│            (lado plano)                                     │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 📐 Cálculo de la Resistencia

Antes de armar el circuito, calculemos la resistencia necesaria:

### Datos

| Parámetro | Valor | Descripción                   |
| --------- | ----- | ----------------------------- |
| Vs        | 5V    | Voltaje de salida del Arduino |
| Vf        | 2V    | Voltaje directo del LED rojo  |
| If        | 20mA  | Corriente deseada (0.020A)    |

### Fórmula

```
R = (Vs - Vf) / If
R = (5V - 2V) / 0.020A
R = 3V / 0.020A
R = 150Ω
```

### Valor Comercial

El valor calculado es 150Ω, pero usaremos **220Ω** porque:

- Es un valor comercial muy común
- Proporciona un margen de seguridad
- El LED brillará un poco menos pero durará más

Con 220Ω, la corriente real será:

```
I = (5V - 2V) / 220Ω = 13.6mA (seguro y suficiente)
```

---

## 📋 Instrucciones

### Paso 1: Preparar el Entorno

**En Tinkercad:**

1. Crea un nuevo circuito
2. Arrastra: Arduino Uno, Protoboard pequeña, LED, Resistencia
3. En la resistencia, cambia el valor a **220Ω**

### Paso 2: Entender la Protoboard

```
┌─────────────────────────────────────────────────────────────┐
│                    PROTOBOARD (MINI)                        │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   (+) ●●●●●●●●●●●●●●●●●●●●●●●●●● Fila de alimentación +     │
│   (-) ●●●●●●●●●●●●●●●●●●●●●●●●●● Fila de tierra (GND)       │
│       ─────────────────────────                             │
│       a b c d e   f g h i j                                 │
│    1  ● ● ● ● ●   ● ● ● ● ●                                │
│    2  ● ● ● ● ●   ● ● ● ● ●  ◄── Filas conectadas          │
│    3  ● ● ● ● ●   ● ● ● ● ●      horizontalmente           │
│    4  ● ● ● ● ●   ● ● ● ● ●      (a-e) y (f-j)             │
│    5  ● ● ● ● ●   ● ● ● ● ●                                │
│       ...                                                   │
│                                                             │
│   Nota: El canal central separa los dos lados              │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Paso 3: Armar el Circuito

**Diagrama de Conexiones:**

```
                        ARDUINO UNO
    ┌─────────────────────────────────────────┐
    │                                         │
    │  Pin 8 ─────────────┐                   │
    │                     │                   │
    │                     │                   │
    │   GND ──────────────│───────┐           │
    │                     │       │           │
    └─────────────────────│───────│───────────┘
                          │       │
                          │       │
    ┌─────────────────────│───────│───────────┐
    │   PROTOBOARD        │       │           │
    │                     │       │           │
    │   Fila 1: ──────────┴─[R]───┤           │
    │           Pin 8    220Ω    │           │
    │                             │           │
    │   Fila 2: ─────────[LED]────┤           │
    │                    ▼       │           │
    │                  Ánodo     │           │
    │                             │           │
    │   Fila 3: ──────Cátodo─────┴─── GND    │
    │                                         │
    └─────────────────────────────────────────┘
```

**Conexiones paso a paso:**

| Paso | Desde                        | Hacia                        | Cable/Componente   |
| ---- | ---------------------------- | ---------------------------- | ------------------ |
| 1    | Arduino Pin 8                | Protoboard fila 1, columna a | Cable jumper       |
| 2    | Protoboard fila 1, columna c | Protoboard fila 2, columna c | Resistencia 220Ω   |
| 3    | Protoboard fila 2, columna e | Protoboard fila 3, columna e | LED (ánodo arriba) |
| 4    | Protoboard fila 3, columna a | Arduino GND                  | Cable jumper       |

### Paso 4: Verificar Polaridad del LED

```
┌─────────────────────────────────────────────────────────────┐
│                  VERIFICAR POLARIDAD LED                    │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   CORRECTO ✅                    INCORRECTO ❌              │
│                                                             │
│   Pin 8                          Pin 8                      │
│     │                              │                        │
│    [R] 220Ω                       [R] 220Ω                  │
│     │                              │                        │
│     ▼                              │                        │
│    ─┼─  LED                       ─┼─  LED                  │
│     │   (Ánodo +)                  ▲   (Cátodo -)           │
│     │                              │                        │
│    GND                            GND                       │
│                                                             │
│   La corriente fluye              La corriente NO fluye     │
│   de + hacia -                    (LED es un diodo)         │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Paso 5: Escribir el Código

```cpp
/*
 * =================================================
 * PRÁCTICA 02: LED Externo con Resistencia
 * =================================================
 *
 * ¿Qué hace?
 * Controla un LED externo conectado al pin 8,
 * haciéndolo parpadear con diferentes patrones.
 *
 * ¿Para qué?
 * - Aprender a conectar componentes externos
 * - Aplicar la Ley de Ohm en un circuito real
 * - Entender la importancia de la resistencia limitadora
 *
 * ¿Cómo funciona?
 * 1. Pin 8 configurado como salida
 * 2. digitalWrite(HIGH) envía 5V al circuito
 * 3. La corriente fluye: Pin 8 → Resistencia → LED → GND
 * 4. La resistencia limita la corriente a ~13.6mA
 *
 * Hardware requerido:
 * - Arduino Uno R3
 * - LED (cualquier color)
 * - Resistencia 220Ω
 * - Protoboard y cables
 *
 * Conexiones:
 * - Pin 8 → Resistencia 220Ω → LED (ánodo)
 * - LED (cátodo) → GND
 *
 * Cálculo de resistencia:
 * R = (5V - 2V) / 0.020A = 150Ω → Usamos 220Ω (seguro)
 * I = (5V - 2V) / 220Ω = 13.6mA
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// CONSTANTES
// ==================================================

// Pin donde conectamos el LED externo
const int LED_PIN = 8;

// Tiempos de parpadeo (en milisegundos)
const int TIME_ON = 500;   // Tiempo encendido
const int TIME_OFF = 500;  // Tiempo apagado

// ==================================================
// SETUP
// ==================================================
void setup() {
    // Configurar pin del LED como salida
    pinMode(LED_PIN, OUTPUT);

    // Iniciar Serial para debugging
    Serial.begin(9600);
    Serial.println("LED Externo - Práctica 02");
    Serial.println("========================");
}

// ==================================================
// LOOP
// ==================================================
void loop() {
    // Encender LED
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED: ON");
    delay(TIME_ON);

    // Apagar LED
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED: OFF");
    delay(TIME_OFF);
}
```

### Paso 6: Probar el Circuito

1. **Verifica las conexiones** antes de iniciar
2. **Inicia la simulación** (o carga al Arduino)
3. **Observa el LED** - debe parpadear cada 0.5 segundos
4. **Abre Serial Monitor** para ver los mensajes

---

## 🎨 Resultado Esperado

```
┌─────────────────────────────────────────────────────────────┐
│                    CIRCUITO FUNCIONANDO                     │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   El LED externo debe parpadear:                           │
│   - 500ms encendido (brillo visible)                       │
│   - 500ms apagado                                          │
│                                                             │
│   Serial Monitor muestra:                                   │
│   ┌─────────────────────────────┐                          │
│   │ LED Externo - Práctica 02   │                          │
│   │ ========================    │                          │
│   │ LED: ON                     │                          │
│   │ LED: OFF                    │                          │
│   │ LED: ON                     │                          │
│   │ LED: OFF                    │                          │
│   │ ...                         │                          │
│   └─────────────────────────────┘                          │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 💡 Pistas

<details>
<summary>Pista 1: El LED no enciende</summary>

Verifica:

1. **Polaridad del LED** - ¿Está el ánodo (pata larga) hacia el pin 8?
2. **Conexiones** - ¿Están en la misma fila de la protoboard?
3. **GND** - ¿Está conectado el circuito a tierra?
4. **Pin correcto** - ¿El código usa el mismo pin que el circuito?

</details>

<details>
<summary>Pista 2: El LED está muy tenue</summary>

Posibles causas:

- Resistencia muy alta (¿usaste 2.2kΩ en lugar de 220Ω?)
- Verifica el código de colores de la resistencia
- En Tinkercad, haz clic en la resistencia y verifica el valor

</details>

<details>
<summary>Pista 3: El LED se quemó (en hardware real)</summary>

Esto pasa si:

- No usaste resistencia
- Usaste resistencia muy pequeña (<100Ω)
- Conectaste a Vin (12V) en lugar de un pin digital (5V)

**Solución:** Reemplaza el LED y usa resistencia de 220Ω

</details>

---

## ✅ Criterios de Evaluación

| Criterio               | Puntos | Descripción                                 |
| ---------------------- | ------ | ------------------------------------------- |
| **Circuito correcto**  | 4      | Conexiones correctas, resistencia calculada |
| **Funcionalidad**      | 3      | LED parpadea según especificación           |
| **Código documentado** | 3      | Comentarios explicando qué, para qué, cómo  |
| **Total**              | **10** |                                             |

### Rúbrica Detallada

| Criterio      | Excelente (100%)               | Bueno (75%)           | Suficiente (50%)             | Insuficiente    |
| ------------- | ------------------------------ | --------------------- | ---------------------------- | --------------- |
| Circuito      | Perfecto, cálculo documentado  | Correcto, sin cálculo | Funciona con errores menores | No funciona     |
| Funcionalidad | LED funciona perfectamente     | Funciona con ajustes  | Funciona parcialmente        | No funciona     |
| Documentación | Completa (qué, para qué, cómo) | Comentarios básicos   | Pocos comentarios            | Sin comentarios |

---

## 🚀 Desafío Extra (Opcional)

### Desafío A: Efecto "Respiración" (Fade)

Aunque este tema se verá en la Semana 3 (PWM), puedes intentar simular un efecto de "respiración" con parpadeos rápidos:

```cpp
void loop() {
    // Simular fade-in con parpadeos cada vez más largos
    for(int i = 1; i <= 10; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(i * 10);  // 10, 20, 30... 100ms
        digitalWrite(LED_PIN, LOW);
        delay((11-i) * 10);  // 100, 90, 80... 10ms
    }

    // Simular fade-out
    for(int i = 10; i >= 1; i--) {
        digitalWrite(LED_PIN, HIGH);
        delay(i * 10);
        digitalWrite(LED_PIN, LOW);
        delay((11-i) * 10);
    }
}
```

### Desafío B: Múltiples Velocidades

Agrega un contador que cambie la velocidad cada 10 parpadeos:

```cpp
int blinkCount = 0;
int currentDelay = 500;

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(currentDelay);
    digitalWrite(LED_PIN, LOW);
    delay(currentDelay);

    blinkCount++;

    if(blinkCount >= 10) {
        blinkCount = 0;
        currentDelay = currentDelay / 2;  // Más rápido
        if(currentDelay < 50) {
            currentDelay = 500;  // Reiniciar
        }
        Serial.print("Nueva velocidad: ");
        Serial.println(currentDelay);
    }
}
```

---

## 📚 Recursos Relacionados

| Recurso                     | Enlace                                                                                                               |
| --------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| Teoría: Electrónica Básica  | [Módulo 02](../1-teoria/02-electronica-basica.md)                                                                    |
| Calculadora de Resistencias | [digikey.com](https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-resistor-color-code) |
| LEDs - Guía Completa        | [sparkfun.com](https://learn.sparkfun.com/tutorials/light-emitting-diodes-leds)                                      |

---

## 📝 Reflexión

Antes de continuar, responde:

1. ¿Qué pasaría si usas una resistencia de 1kΩ en lugar de 220Ω?
2. ¿Por qué es importante conectar el cátodo del LED a GND y no al revés?
3. Si quisieras que el LED brillara más, ¿qué valor de resistencia usarías? (sin bajar de 100Ω)

---

<div align="center">

[⬅️ Práctica 01](./practica-01-blink-led.md) | [Índice](./README.md) | [Práctica 03 ➡️](./practica-03-semaforo.md)

</div>
