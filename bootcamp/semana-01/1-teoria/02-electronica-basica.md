# Módulo 02: Electrónica Básica

> ⏱️ **Tiempo estimado:** 25 minutos  
> 📚 **Nivel:** Principiante  
> 🎯 **Compatibilidad Tinkercad:** ✅

---

## 🎯 Objetivos del Módulo

Al finalizar este módulo, serás capaz de:

- [ ] Explicar la Ley de Ohm y sus aplicaciones
- [ ] Identificar y calcular valores de resistencias
- [ ] Leer el código de colores de resistencias
- [ ] Calcular la resistencia necesaria para un LED
- [ ] Entender polaridad y conexión de LEDs

---

## 📚 Contenido

### 2.1 Conceptos Fundamentales

Antes de conectar cualquier componente, necesitas entender tres conceptos básicos:

#### El Triángulo de la Electricidad

```
                    ┌─────────────┐
                    │             │
                    │   VOLTAJE   │
                    │     (V)     │
                    │   Voltios   │
                    │             │
                    └──────┬──────┘
                          / \
                         /   \
                        /     \
                       /       \
        ┌─────────────┴─┐   ┌──┴─────────────┐
        │               │   │                │
        │  CORRIENTE    │   │  RESISTENCIA   │
        │     (I)       │   │      (R)       │
        │   Amperios    │   │    Ohmios      │
        │               │   │                │
        └───────────────┘   └────────────────┘
```

| Concepto        | Símbolo | Unidad       | Analogía del Agua          |
| --------------- | ------- | ------------ | -------------------------- |
| **Voltaje**     | V       | Voltios (V)  | Presión del agua           |
| **Corriente**   | I       | Amperios (A) | Cantidad de agua que fluye |
| **Resistencia** | R       | Ohmios (Ω)   | Tamaño de la tubería       |

#### Analogía del Sistema de Agua

```
┌─────────────────────────────────────────────────────────────┐
│                ANALOGÍA: ELECTRICIDAD = AGUA                │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│    TANQUE DE AGUA              BATERÍA/FUENTE               │
│    ┌─────────┐                 ┌─────────┐                  │
│    │░░░░░░░░░│ Nivel alto     │ + 5V    │ Voltaje alto     │
│    │░░░░░░░░░│ = más presión  │         │ = más "presión"  │
│    │░░░░░░░░░│                │         │                  │
│    └────┬────┘                └────┬────┘                  │
│         │                          │                        │
│    ┌────┴────┐                ┌────┴────┐                  │
│    │ VÁLVULA │                │RESISTOR │                  │
│    │         │ Controla       │         │ Controla         │
│    │ ══════  │ el flujo       │ ═/\/\/═ │ la corriente     │
│    └────┬────┘                └────┬────┘                  │
│         │                          │                        │
│         ▼                          ▼                        │
│    ┌─────────┐                ┌─────────┐                  │
│    │ TURBINA │                │   LED   │                  │
│    │   ◯    │ Hace trabajo   │   ◄█►   │ Emite luz        │
│    └────┬────┘                └────┬────┘                  │
│         │                          │                        │
│         ▼                          ▼                        │
│    ───────────                ───────────                   │
│      DESAGÜE                     GND (0V)                   │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 2.2 Ley de Ohm

La **Ley de Ohm** es la fórmula fundamental de la electrónica:

```
┌─────────────────────────────────────────┐
│                                         │
│            V = I × R                    │
│                                         │
│   Voltaje = Corriente × Resistencia     │
│                                         │
└─────────────────────────────────────────┘
```

#### Despejando Variables

| Quieres calcular    | Fórmula   | Ejemplo                        |
| ------------------- | --------- | ------------------------------ |
| **Voltaje (V)**     | V = I × R | I=0.02A, R=220Ω → V=4.4V       |
| **Corriente (I)**   | I = V / R | V=5V, R=1000Ω → I=0.005A (5mA) |
| **Resistencia (R)** | R = V / I | V=3V, I=0.02A → R=150Ω         |

#### Truco del Triángulo

```
        ┌───────┐
        │   V   │     Tapa lo que buscas:
        ├───┬───┤
        │ I │ R │     • Tapas V → queda I×R
        └───┴───┘     • Tapas I → queda V/R
                      • Tapas R → queda V/I
```

#### Ejemplo Práctico

**Problema:** Tienes una fuente de 5V y una resistencia de 1kΩ. ¿Cuánta corriente fluye?

```cpp
/*
 * Cálculo de corriente con Ley de Ohm
 *
 * Datos:
 *   V = 5V (voltaje de Arduino)
 *   R = 1000Ω (1kΩ)
 *
 * Fórmula:
 *   I = V / R
 *   I = 5V / 1000Ω
 *   I = 0.005A = 5mA
 */
```

---

### 2.3 Resistencias

Las resistencias son componentes que **limitan el flujo de corriente**. Son esenciales para proteger otros componentes como LEDs.

#### Símbolo y Apariencia

```
Esquemático (US):      Esquemático (EU):      Físico:

    ───/\/\/\/───          ───▭▭▭───          ┌──────────────┐
                                              │▐█▌▐█▌▐█▌▐█▌  │
                                              └──────────────┘
                                               Bandas de color
```

#### Código de Colores

```
┌─────────────────────────────────────────────────────────────┐
│              CÓDIGO DE COLORES DE RESISTENCIAS              │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   COLOR      │  VALOR  │  MULTIPLICADOR  │  TOLERANCIA     │
│   ───────────┼─────────┼─────────────────┼──────────────   │
│   Negro      │    0    │      ×1         │      -          │
│   Marrón     │    1    │      ×10        │    ±1%          │
│   Rojo       │    2    │      ×100       │    ±2%          │
│   Naranja    │    3    │      ×1,000     │      -          │
│   Amarillo   │    4    │      ×10,000    │      -          │
│   Verde      │    5    │      ×100,000   │    ±0.5%        │
│   Azul       │    6    │      ×1,000,000 │    ±0.25%       │
│   Violeta    │    7    │      ×10M       │    ±0.1%        │
│   Gris       │    8    │      ×100M      │      -          │
│   Blanco     │    9    │      ×1G        │      -          │
│   Dorado     │    -    │      ×0.1       │    ±5%          │
│   Plateado   │    -    │      ×0.01      │    ±10%         │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

#### Nemotécnico para Recordar

> **N**egro, **M**arrón, **R**ojo, **N**aranja, **A**marillo, **V**erde, **A**zul, **V**ioleta, **G**ris, **B**lanco
>
> "**N**o **M**e **R**ío **N**ada **A**unque **V**enga **A**cá **V**arias **G**entes **B**uenas"

#### Ejemplos de Lectura

**Resistencia de 220Ω:**

```
┌────────────────────────────────────┐
│  ▐█▌   ▐█▌   ▐█▌        ▐█▌       │
│ ROJO  ROJO  MARRÓN    DORADO      │
│  (2)   (2)   (×10)     (±5%)      │
│                                    │
│  22 × 10 = 220Ω ±5%               │
└────────────────────────────────────┘
```

**Resistencia de 1kΩ (1000Ω):**

```
┌────────────────────────────────────┐
│  ▐█▌   ▐█▌   ▐█▌        ▐█▌       │
│MARRÓN NEGRO  ROJO     DORADO      │
│  (1)   (0)   (×100)    (±5%)      │
│                                    │
│  10 × 100 = 1000Ω = 1kΩ ±5%       │
└────────────────────────────────────┘
```

**Resistencia de 10kΩ:**

```
┌────────────────────────────────────┐
│  ▐█▌   ▐█▌   ▐█▌        ▐█▌       │
│MARRÓN NEGRO NARANJA   DORADO      │
│  (1)   (0)   (×1000)   (±5%)      │
│                                    │
│  10 × 1000 = 10000Ω = 10kΩ ±5%    │
└────────────────────────────────────┘
```

---

### 2.4 LEDs (Diodos Emisores de Luz)

Los **LEDs** son componentes que emiten luz cuando la corriente fluye a través de ellos. Son **polarizados**, lo que significa que tienen un lado positivo y uno negativo.

#### Anatomía del LED

```
        Vista lateral:           Vista superior:

            ┌───┐
            │   │                    ╭───╮
            │ █ │ ◄── Ánodo (+)     │   │
            │   │     (pata larga)  │ ◯ │ ◄── Lado plano = Cátodo
            │   │                    │   │
            └─┬─┘                    ╰───╯
             / \
            /   \
    Ánodo ─┘     └─ Cátodo (-)
    (+)             (pata corta)
```

#### Símbolo del LED

```
        Ánodo (+)     Cátodo (-)
            │             │
            │      ▶│     │
            ├──────▶│─────┤
            │      ▶│     │
            │    ↗  ↗     │
                (luz)
```

#### Especificaciones Típicas de LEDs

| Color    | Voltaje Directo (Vf) | Corriente Típica | Corriente Máxima |
| -------- | -------------------- | ---------------- | ---------------- |
| Rojo     | 1.8 - 2.2V           | 10-20 mA         | 30 mA            |
| Amarillo | 2.0 - 2.4V           | 10-20 mA         | 30 mA            |
| Verde    | 2.0 - 3.0V           | 10-20 mA         | 30 mA            |
| Azul     | 3.0 - 3.5V           | 10-20 mA         | 30 mA            |
| Blanco   | 3.0 - 3.5V           | 10-20 mA         | 30 mA            |

> ⚠️ **IMPORTANTE:** Nunca conectes un LED directamente a 5V sin resistencia. ¡Se quemará!

---

### 2.5 Cálculo de Resistencia para LED

Esta es la fórmula más importante para principiantes:

```
┌─────────────────────────────────────────┐
│                                         │
│        R = (Vs - Vf) / I                │
│                                         │
│   Donde:                                │
│   • Vs = Voltaje de la fuente (5V)      │
│   • Vf = Voltaje del LED (~2V)          │
│   • I  = Corriente deseada (~0.020A)    │
│                                         │
└─────────────────────────────────────────┘
```

#### Ejemplo: LED Rojo en Arduino

```
┌─────────────────────────────────────────────────────────────┐
│                    CÁLCULO DE RESISTENCIA                   │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   Datos:                                                    │
│   • Vs = 5V (voltaje Arduino)                              │
│   • Vf = 2V (LED rojo típico)                              │
│   • I  = 20mA = 0.020A (corriente deseada)                 │
│                                                             │
│   Cálculo:                                                  │
│   R = (5V - 2V) / 0.020A                                   │
│   R = 3V / 0.020A                                          │
│   R = 150Ω                                                 │
│                                                             │
│   Resistencia comercial: 150Ω o 220Ω (más seguro)          │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

#### Circuito Básico LED + Resistencia

```
                    Arduino
    ┌─────────────────────────────────────┐
    │                                     │
    │  Pin 13 ─────────┐                  │
    │                  │                  │
    │                 [R] 220Ω            │
    │                  │                  │
    │                  │                  │
    │                 ▼│ LED              │
    │                ──┼──                │
    │                  │                  │
    │                  │                  │
    │   GND ───────────┘                  │
    │                                     │
    └─────────────────────────────────────┘
```

#### Código Correspondiente

```cpp
/*
 * =================================================
 * LED con Resistencia - Circuito Básico
 * =================================================
 *
 * ¿Qué hace?
 * Enciende y apaga un LED conectado al pin 13
 *
 * ¿Para qué?
 * Demostrar el control básico de salidas digitales
 * y la importancia de la resistencia limitadora
 *
 * ¿Cómo funciona?
 * 1. Pin 13 en HIGH → 5V → corriente fluye → LED enciende
 * 2. Pin 13 en LOW  → 0V → no hay corriente → LED apaga
 *
 * Conexiones:
 * - Pin 13 → Resistencia 220Ω → LED (ánodo)
 * - LED (cátodo) → GND
 *
 * Cálculo de resistencia:
 * R = (5V - 2V) / 0.020A = 150Ω (usamos 220Ω por seguridad)
 *
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

const int LED_PIN = 13;  // Pin donde conectamos el LED

void setup() {
    pinMode(LED_PIN, OUTPUT);  // Configurar pin como salida
}

void loop() {
    digitalWrite(LED_PIN, HIGH);  // Enciende LED (5V)
    delay(1000);                  // Espera 1 segundo
    digitalWrite(LED_PIN, LOW);   // Apaga LED (0V)
    delay(1000);                  // Espera 1 segundo
}
```

---

### 2.6 Tabla de Resistencias Comunes para LEDs

| Fuente   | LED Rojo/Amarillo (2V) | LED Verde (2.2V) | LED Azul/Blanco (3.2V) |
| -------- | ---------------------- | ---------------- | ---------------------- |
| **3.3V** | 68Ω                    | 56Ω              | 10Ω (no recomendado)   |
| **5V**   | 150-220Ω               | 150-220Ω         | 100Ω                   |
| **9V**   | 330-470Ω               | 330-470Ω         | 270-330Ω               |
| **12V**  | 470-560Ω               | 470-560Ω         | 390-470Ω               |

> 💡 **Consejo:** Cuando dudes, usa **220Ω**. Es seguro para la mayoría de LEDs con fuentes de 5V.

---

## 💡 Puntos Clave

1. **V = I × R** - La Ley de Ohm es fundamental
2. **Siempre usar resistencia con LEDs** - Protege el LED y el Arduino
3. **LEDs son polarizados** - Pata larga = positivo
4. **220Ω es el valor "seguro"** - Funciona para la mayoría de casos con 5V
5. **Código de colores** - Practica hasta memorizarlo

---

## ⚠️ Errores Comunes

| Error                | Consecuencia                          | Solución                             |
| -------------------- | ------------------------------------- | ------------------------------------ |
| LED sin resistencia  | LED se quema, posible daño al Arduino | Siempre usar resistencia             |
| LED al revés         | No enciende                           | Verificar polaridad (pata larga = +) |
| Resistencia muy alta | LED muy tenue                         | Calcular correctamente o usar 220Ω   |
| Resistencia muy baja | LED muy brillante, corta vida         | Mínimo 100Ω para LEDs con 5V         |
| Confundir kΩ con Ω   | Valores incorrectos                   | 1kΩ = 1000Ω                          |

---

## ✅ Autoevaluación

1. ¿Cuánta corriente fluye por una resistencia de 330Ω conectada a 5V?
2. ¿Qué valor tiene una resistencia Marrón-Negro-Rojo-Dorado?
3. ¿Por qué un LED necesita resistencia?
4. ¿Qué pasa si conectas un LED al revés?
5. ¿Cuál es el voltaje típico de un LED rojo?

<details>
<summary>💡 Ver respuestas</summary>

1. **I = V/R = 5V/330Ω = 0.015A = 15mA**
2. **1-0-×100 = 1000Ω = 1kΩ** (±5% tolerancia)
3. **Para limitar la corriente** y evitar que se queme. Sin resistencia, fluiría demasiada corriente.
4. **No enciende** - Los LEDs solo conducen en una dirección (son diodos).
5. **~2V** (entre 1.8V y 2.2V)

</details>

---

## 🔗 Referencias

- [Ley de Ohm - SparkFun](https://learn.sparkfun.com/tutorials/voltage-current-resistance-and-ohms-law)
- [LEDs - Adafruit](https://learn.adafruit.com/all-about-leds)
- [Calculadora de Resistencias](https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-resistor-color-code)

---

<div align="center">

[⬅️ Módulo 01](./01-introduccion-microcontroladores.md) | [Índice](./README.md) | [Módulo 03 ➡️](./03-arduino-ide-tinkercad.md)

</div>
