# 🏗️ Guía de Diseño - Knight Rider

> Documento técnico con especificaciones de arquitectura y diseño del circuito

---

## 📐 Especificaciones Técnicas

### Parámetros Eléctricos

| Parámetro              | Valor    | Notas              |
| ---------------------- | -------- | ------------------ |
| Voltaje de operación   | 5V DC    | Desde Arduino      |
| Corriente por LED      | ~13.6 mA | Con R = 220Ω       |
| Corriente total máxima | ~82 mA   | 6 LEDs simultáneos |
| Consumo típico         | ~13.6 mA | 1 LED a la vez     |

### Cálculo de Resistencia

```
┌─────────────────────────────────────────────────────────────┐
│                CÁLCULO PARA CADA LED                        │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   Datos:                                                    │
│   • Vs = 5V (voltaje Arduino)                              │
│   • Vf = 2V (voltaje LED rojo típico)                      │
│   • If = 20mA (corriente deseada)                          │
│                                                             │
│   Fórmula:                                                  │
│   R = (Vs - Vf) / If                                       │
│   R = (5V - 2V) / 0.020A                                   │
│   R = 150Ω (mínimo)                                        │
│                                                             │
│   Valor usado: 220Ω (estándar, más seguro)                 │
│                                                             │
│   Corriente real:                                           │
│   I = (5V - 2V) / 220Ω = 13.6mA ✓                         │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 🔌 Esquemático del Circuito

### Diagrama Simplificado

```
                     +5V (desde pines digitales)
                           │
        ┌──────┬───────┬───┴───┬───────┬───────┬──────┐
        │      │       │       │       │       │      │
       [R]    [R]     [R]     [R]     [R]     [R]    220Ω
        │      │       │       │       │       │     cada uno
        │      │       │       │       │       │
       ▼│     ▼│      ▼│      ▼│      ▼│      ▼│     LED
       ─┼─    ─┼─     ─┼─     ─┼─     ─┼─     ─┼─
        │      │       │       │       │       │
        └──────┴───────┴───────┴───────┴───────┴──────┐
                                                       │
                                                      GND
                                                    (común)
```

### Circuito Individual (1 LED)

```
    Pin Arduino (3-8)
           │
           │
          ┌┴┐
          │ │  R = 220Ω
          │ │  P = I²R = (0.0136)² × 220 = 0.04W
          └┬┘  (cualquier resistencia 1/4W funciona)
           │
           │
          ╱│╲
         ╱ │ ╲  LED
        ╱  │  ╲ Vf ≈ 2V
       ────┼────
           │
           │
           ▼
          GND
```

---

## 📊 Diagrama de Tiempos

### Secuencia Completa (1 ciclo)

```
┌─────────────────────────────────────────────────────────────────────┐
│                    DIAGRAMA DE TIEMPOS                              │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│  Tiempo (ms):  0   80  160  240  320  400  480  560  640  720      │
│                │    │    │    │    │    │    │    │    │    │      │
│  LED 0:        ████─────────────────────────────────────────────   │
│  LED 1:        ────████─────────────────────────────────────████   │
│  LED 2:        ────────████─────────────────────────────████────   │
│  LED 3:        ────────────████─────────────────────████────────   │
│  LED 4:        ────────────────████─────────────████────────────   │
│  LED 5:        ────────────────────████─────────────────────────   │
│                │    │    │    │    │    │    │    │    │    │      │
│                └─IDA─────────────────┴─VUELTA───────────────┘      │
│                                                                     │
│  Duración IDA:    6 × 80ms = 480ms                                 │
│  Duración VUELTA: 4 × 80ms = 320ms (sin repetir extremos)          │
│  Ciclo completo:  800ms                                            │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

### Cálculo de Frecuencia

```
┌─────────────────────────────────────────┐
│  Con DELAY_MS = 80:                     │
│                                         │
│  LEDs en IDA: 6                         │
│  LEDs en VUELTA: 4 (excluye extremos)   │
│  Total pasos: 10                        │
│                                         │
│  Tiempo ciclo = 10 × 80ms = 800ms       │
│  Frecuencia = 1000/800 = 1.25 Hz        │
│  (1.25 ciclos por segundo)              │
└─────────────────────────────────────────┘
```

---

## 🏛️ Arquitectura del Software

### Diagrama de Flujo

```
┌─────────────────────────────────────────────────────────────────┐
│                      FLUJO DEL PROGRAMA                         │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│                         ┌─────────┐                             │
│                         │  INICIO │                             │
│                         └────┬────┘                             │
│                              │                                  │
│                              ▼                                  │
│                    ┌─────────────────┐                          │
│                    │     setup()     │                          │
│                    │                 │                          │
│                    │ • Configurar    │                          │
│                    │   pines OUTPUT  │                          │
│                    │ • Iniciar Serial│                          │
│                    │ • Animación     │                          │
│                    │   inicio        │                          │
│                    └────────┬────────┘                          │
│                              │                                  │
│           ┌──────────────────┼──────────────────┐               │
│           │                  ▼                  │               │
│           │         ┌───────────────┐           │               │
│           │         │    loop()     │           │               │
│           │         └───────┬───────┘           │               │
│           │                 │                   │               │
│           │                 ▼                   │               │
│           │   ┌─────────────────────────┐       │               │
│           │   │   sequenceForward()     │       │               │
│           │   │                         │       │               │
│           │   │   for i = 0 to 5:       │       │               │
│           │   │     lightOnly(i)        │       │               │
│           │   │     delay(DELAY_MS)     │       │               │
│           │   └────────────┬────────────┘       │               │
│           │                │                    │               │
│           │                ▼                    │               │
│           │   ┌─────────────────────────┐       │               │
│           │   │   sequenceBackward()    │       │               │
│           │   │                         │       │               │
│           │   │   for i = 4 to 1:       │       │               │
│           │   │     lightOnly(i)        │       │               │
│           │   │     delay(DELAY_MS)     │       │               │
│           │   └────────────┬────────────┘       │               │
│           │                │                    │               │
│           └────────────────┴────────────────────┘               │
│                        (repite infinitamente)                   │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

### Jerarquía de Funciones

```
┌─────────────────────────────────────────────────────────────┐
│                  JERARQUÍA DE FUNCIONES                     │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  main() [Arduino internamente]                              │
│    │                                                        │
│    ├── setup()                                              │
│    │     ├── pinMode()  ×6                                  │
│    │     ├── Serial.begin()                                 │
│    │     └── startupAnimation()                             │
│    │           ├── allOn()                                  │
│    │           │     └── digitalWrite() ×6                  │
│    │           └── allOff()                                 │
│    │                 └── digitalWrite() ×6                  │
│    │                                                        │
│    └── loop() [infinito]                                    │
│          ├── sequenceForward()                              │
│          │     └── lightOnly() ×6                           │
│          │           └── digitalWrite() ×6                  │
│          │                                                  │
│          └── sequenceBackward()                             │
│                └── lightOnly() ×4                           │
│                      └── digitalWrite() ×6                  │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 📋 Especificación de Funciones

### allOff()

```cpp
/**
 * @brief Apaga todos los LEDs del array
 *
 * @details Itera sobre todos los pines definidos en LED_PINS
 *          y establece cada uno en LOW (0V)
 *
 * @param ninguno
 * @return void
 *
 * @example
 *   allOff();  // Todos los LEDs se apagan
 */
void allOff() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], LOW);
    }
}
```

### allOn()

```cpp
/**
 * @brief Enciende todos los LEDs del array
 *
 * @details Itera sobre todos los pines definidos en LED_PINS
 *          y establece cada uno en HIGH (5V)
 *
 * @param ninguno
 * @return void
 *
 * @warning Consumo máximo: ~82mA con 6 LEDs
 *
 * @example
 *   allOn();  // Todos los LEDs se encienden
 */
void allOn() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], HIGH);
    }
}
```

### lightOnly(int position)

```cpp
/**
 * @brief Enciende únicamente el LED en la posición especificada
 *
 * @details Apaga todos los LEDs excepto el indicado por 'position'.
 *          Útil para crear efectos de secuencia donde solo un LED
 *          está encendido a la vez.
 *
 * @param position Índice del LED a encender (0 a NUM_LEDS-1)
 *
 * @return void
 *
 * @note Si position está fuera de rango, todos los LEDs se apagan
 *
 * @example
 *   lightOnly(0);  // Enciende solo el primer LED
 *   lightOnly(3);  // Enciende solo el cuarto LED
 */
void lightOnly(int position) {
    for (int i = 0; i < NUM_LEDS; i++) {
        if (i == position) {
            digitalWrite(LED_PINS[i], HIGH);
        } else {
            digitalWrite(LED_PINS[i], LOW);
        }
    }
}
```

---

## 🎨 Consideraciones de Diseño Visual

### Disposición de LEDs

```
┌─────────────────────────────────────────────────────────────┐
│              OPCIONES DE DISPOSICIÓN                        │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  OPCIÓN A: Línea Horizontal (Recomendada)                  │
│                                                             │
│     ◯    ◯    ◯    ◯    ◯    ◯                            │
│     0    1    2    3    4    5                              │
│     ←────────────────────────→                              │
│           Efecto de barrido                                 │
│                                                             │
│  OPCIÓN B: Línea Vertical                                   │
│                                                             │
│     ◯ 0                                                     │
│     ◯ 1                                                     │
│     ◯ 2    Efecto de cascada                               │
│     ◯ 3                                                     │
│     ◯ 4                                                     │
│     ◯ 5                                                     │
│                                                             │
│  OPCIÓN C: Arco (Avanzado)                                 │
│                                                             │
│        ◯ 2    ◯ 3                                          │
│     ◯ 1          ◯ 4                                       │
│   ◯ 0               ◯ 5                                    │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Separación Entre LEDs

| Separación | Efecto Visual          | Uso Recomendado               |
| ---------- | ---------------------- | ----------------------------- |
| 1 cm       | Compacto, luz continua | Indicadores pequeños          |
| 2 cm       | Distinción clara       | **Recomendado para proyecto** |
| 3+ cm      | Muy separado           | Instalaciones grandes         |

---

## 🔧 Variantes de Implementación

### Variante 1: Con Estela (Trail Effect)

```cpp
// Mantiene 2 LEDs encendidos para efecto de estela
void lightWithTrail(int position) {
    allOff();
    digitalWrite(LED_PINS[position], HIGH);

    // LED anterior (más tenue si usáramos PWM)
    if (position > 0) {
        digitalWrite(LED_PINS[position - 1], HIGH);
    }
}
```

### Variante 2: Con millis() (No bloqueante)

```cpp
unsigned long previousMillis = 0;
int currentLed = 0;
bool goingForward = true;

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= DELAY_MS) {
        previousMillis = currentMillis;

        lightOnly(currentLed);

        if (goingForward) {
            currentLed++;
            if (currentLed >= NUM_LEDS) {
                goingForward = false;
                currentLed = NUM_LEDS - 2;
            }
        } else {
            currentLed--;
            if (currentLed < 0) {
                goingForward = true;
                currentLed = 1;
            }
        }
    }
}
```

---

## 📝 Checklist de Diseño

### Hardware

- [ ] 6 LEDs del mismo tipo/color
- [ ] 6 resistencias de 220Ω verificadas
- [ ] Protoboard con suficiente espacio
- [ ] Cables de colores organizados
- [ ] LEDs en línea recta
- [ ] Separación uniforme entre LEDs

### Software

- [ ] Array de pines definido correctamente
- [ ] Funciones auxiliares implementadas
- [ ] Secuencia ida funcional
- [ ] Secuencia vuelta sin repetir extremos
- [ ] Velocidad ajustada para buen efecto
- [ ] Comentarios completos

### Documentación

- [ ] Diagrama de conexiones
- [ ] Código comentado
- [ ] README con instrucciones
- [ ] Capturas/GIF del resultado

---

<div align="center">

[⬅️ README Proyecto](./README.md) | [Ejemplos ➡️](./EJEMPLOS-DATOS.md)

</div>
