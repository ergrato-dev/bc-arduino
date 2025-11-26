# 📗 Semana 02: Entradas y Salidas Digitales

> **Bootcamp Arduino** · Semana 2 de 10  
> ⏱️ Dedicación: 4 horas · 📊 Nivel: Principiante-Intermedio

---

## 🎯 Objetivos de Aprendizaje

Al completar esta semana, serás capaz de:

- [ ] Comprender la diferencia entre señales digitales HIGH y LOW
- [ ] Configurar pines como entrada y salida usando `pinMode()`
- [ ] Leer el estado de botones con `digitalRead()`
- [ ] Controlar LEDs con `digitalWrite()`
- [ ] Entender resistencias pull-up y pull-down
- [ ] Implementar debouncing por software con `millis()`
- [ ] Detectar flancos de subida y bajada
- [ ] Crear máquinas de estados finitos (FSM) básicas
- [ ] Manejar múltiples entradas y salidas simultáneamente

---

## 📋 Contenido de la Semana

### 📁 Estructura

```
semana-02/
├── README.md                    ← Estás aquí
├── RUBRICA-EVALUACION.md        # Criterios de evaluación
├── 0-assets/                    # Diagramas y recursos visuales
│   ├── README.md
│   └── *.svg                    # 8 diagramas técnicos
├── 1-teoria/                    # Contenido teórico
│   ├── README.md
│   ├── 01-fundamentos-io-digital.md
│   ├── 02-resistencias-pull-up-down.md
│   ├── 03-debouncing.md
│   └── 04-maquinas-de-estados.md
├── 2-practicas/                 # Ejercicios prácticos
│   ├── README.md
│   ├── 01-boton-led-basico.md
│   ├── 02-toggle-led-debounce.md
│   ├── 03-contador-pulsaciones.md
│   └── 04-control-multiples-leds.md
├── 3-proyecto/                  # Proyecto de la semana
│   ├── README.md
│   ├── panel-control.ino
│   └── DOCUMENTACION.md
├── 4-recursos/                  # Material adicional
│   └── README.md
└── 5-glosario/                  # Términos clave
    └── README.md
```

---

## 🗺️ Navegación Rápida

| Sección | Descripción | Tiempo Est. |
|---------|-------------|-------------|
| [📊 Assets](./0-assets/README.md) | Diagramas y esquemáticos | - |
| [📚 Teoría](./1-teoria/README.md) | 4 módulos teóricos | ~60 min |
| [💻 Prácticas](./2-practicas/README.md) | 4 ejercicios prácticos | ~90 min |
| [🔨 Proyecto](./3-proyecto/README.md) | Panel de Control de Iluminación | ~90 min |
| [📖 Recursos](./4-recursos/README.md) | Enlaces y material adicional | - |
| [📖 Glosario](./5-glosario/README.md) | Términos y definiciones | - |

---

## 📚 Teoría (60 minutos)

### Módulos

| # | Módulo | Descripción | Duración |
|---|--------|-------------|----------|
| 1 | [Fundamentos I/O Digital](./1-teoria/01-fundamentos-io-digital.md) | Estados digitales, funciones básicas | 15 min |
| 2 | [Resistencias Pull-up/down](./1-teoria/02-resistencias-pull-up-down.md) | Evitar pines flotantes | 15 min |
| 3 | [Debouncing](./1-teoria/03-debouncing.md) | Eliminar rebotes de botones | 20 min |
| 4 | [Máquinas de Estados](./1-teoria/04-maquinas-de-estados.md) | FSM con enum y switch | 10 min |

### Conceptos Clave

```
┌─────────────────────────────────────────────────────────────┐
│                    FLUJO DE LA SEMANA                       │
│                                                             │
│   Señales      Configuración     Entrada      Salida        │
│   Digitales → de Pines       → de Datos  → de Control      │
│   HIGH/LOW    pinMode()       digitalRead() digitalWrite()  │
│                                                             │
│                         ↓                                   │
│                                                             │
│   Pull-up/     Debouncing      Detección    Máquinas       │
│   Pull-down →  con millis() → de Flancos → de Estados      │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 💻 Prácticas (90 minutos)

### Ejercicios

| # | Práctica | Nivel | Componentes | Tiempo |
|---|----------|-------|-------------|--------|
| 1 | [Botón y LED Básico](./2-practicas/01-boton-led-basico.md) | ⭐ | 1 LED, 1 Botón, 2 Resistencias | 20 min |
| 2 | [Toggle LED con Debounce](./2-practicas/02-toggle-led-debounce.md) | ⭐⭐ | 1 LED, 1 Botón, 2 Resistencias | 25 min |
| 3 | [Contador de Pulsaciones](./2-practicas/03-contador-pulsaciones.md) | ⭐⭐ | 3 LEDs, 1 Botón, 4 Resistencias | 20 min |
| 4 | [Control Múltiples LEDs](./2-practicas/04-control-multiples-leds.md) | ⭐⭐⭐ | 4 LEDs, 2 Botones, 6 Resistencias | 25 min |

### Progresión de Dificultad

```
Práctica 1     Práctica 2     Práctica 3     Práctica 4
    ⭐      →     ⭐⭐      →     ⭐⭐      →     ⭐⭐⭐
  Básico       Intermedio    Intermedio     Avanzado
   
  - Encender   - Toggle      - Contador     - 4 LEDs
  - 1 LED      - Debounce    - 3 LEDs       - 2 Botones
  - 1 Botón    - millis()    - Serial       - Múltiples modos
```

---

## 🔨 Proyecto: Panel de Control de Iluminación

### Descripción

Un sistema de control de iluminación con 4 LEDs y 4 botones que implementa 3 modos de operación diferentes.

### Características

| Modo | Descripción | Botón |
|------|-------------|-------|
| Individual | Control directo LED-Botón | BTN_MODE |
| Secuencia | Animación automática configurable | BTN_SPEED |
| Intensidad | PWM simulado con variación de brillo | BTN_PATTERN |

### Archivos del Proyecto

| Archivo | Descripción |
|---------|-------------|
| [README.md](./3-proyecto/README.md) | Especificaciones completas |
| [panel-control.ino](./3-proyecto/panel-control.ino) | Código fuente completo |
| [DOCUMENTACION.md](./3-proyecto/DOCUMENTACION.md) | Documentación técnica |

### Diagrama de Conexiones

```
                    PANEL DE CONTROL
    ┌──────────────────────────────────────────┐
    │                                          │
    │   [BTN1]──┬──[BTN2]──┬──[BTN3]──┬──[BTN4]│
    │     │     │    │     │    │     │    │   │
    │    D2    D3   D4    D5   D6    D7   D8   │
    │                                          │
    │   [LED1]────[LED2]────[LED3]────[LED4]   │
    │     │        │         │         │       │
    │    D9       D10       D11       D12      │
    │                                          │
    └──────────────────────────────────────────┘
```

---

## ⏱️ Distribución del Tiempo

```
┌──────────────────────────────────────────────────────────────┐
│                    4 HORAS SEMANALES                         │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│   ████████████████  Teoría        60 min (25%)               │
│   ██████████████████████████  Prácticas   90 min (37.5%)     │
│   ██████████████████████████  Proyecto    90 min (37.5%)     │
│                                                              │
│   Total: 240 minutos = 4 horas                              │
│                                                              │
└──────────────────────────────────────────────────────────────┘
```

---

## 📦 Componentes Necesarios

### Lista de Materiales

| Componente | Cantidad | Uso Principal |
|------------|----------|---------------|
| Arduino Uno R3 | 1 | Microcontrolador |
| LED Rojo 5mm | 2 | Indicadores |
| LED Verde 5mm | 1 | Indicadores |
| LED Amarillo 5mm | 1 | Indicadores |
| Resistencia 220Ω | 4 | Limitadoras LED |
| Pulsador táctil | 4 | Entradas |
| Resistencia 10kΩ | 4 | Pull-down (opcional) |
| Protoboard | 1 | Montaje |
| Cables jumper | ~20 | Conexiones |

### Nota sobre Simulación

> ✅ **Todos los ejercicios son compatibles con Tinkercad**  
> Los estudiantes sin hardware físico pueden completar la semana completa usando el simulador online.

---

## ✅ Checklist de Completitud

### Teoría
- [ ] Módulo 1: Fundamentos I/O Digital
- [ ] Módulo 2: Resistencias Pull-up/down
- [ ] Módulo 3: Debouncing
- [ ] Módulo 4: Máquinas de Estados

### Prácticas
- [ ] Práctica 1: Botón y LED Básico
- [ ] Práctica 2: Toggle LED con Debounce
- [ ] Práctica 3: Contador de Pulsaciones
- [ ] Práctica 4: Control Múltiples LEDs

### Proyecto
- [ ] Panel de Control completado
- [ ] Modo Individual funcionando
- [ ] Modo Secuencia funcionando
- [ ] Modo Intensidad funcionando
- [ ] Documentación completada

---

## 📊 Evaluación

### Distribución de Puntos

| Componente | Peso | Puntos |
|------------|------|--------|
| Teoría (Quizzes) | 20% | 20 |
| Prácticas (4 ejercicios) | 40% | 40 |
| Proyecto | 40% | 40 |
| **Total** | **100%** | **100** |

### Criterios Detallados

Ver [RUBRICA-EVALUACION.md](./RUBRICA-EVALUACION.md) para criterios completos.

---

## 🔗 Navegación del Bootcamp

| Anterior | Actual | Siguiente |
|----------|--------|-----------|
| [← Semana 01: Introducción](../semana-01/README.md) | **Semana 02** | [Semana 03: PWM →](../semana-03/README.md) |

---

## 📖 Recursos Adicionales

- [Recursos externos y enlaces](./4-recursos/README.md)
- [Glosario de términos](./5-glosario/README.md)
- [Arduino Reference - Digital I/O](https://www.arduino.cc/reference/en/)

---

## 💡 Tips para el Éxito

1. **Practica en Tinkercad** antes de usar hardware real
2. **Usa Serial Monitor** para depurar tu código
3. **Implementa debounce** siempre que uses botones
4. **Evita `delay()`** - usa `millis()` para código no bloqueante
5. **Documenta tu código** con comentarios claros
6. **Prueba cada parte** antes de integrar

---

## ❓ Preguntas Frecuentes

<details>
<summary><strong>¿Por qué mi botón lee valores aleatorios?</strong></summary>

El pin está "flotante". Necesitas una resistencia pull-up o pull-down para mantener un estado definido cuando el botón no está presionado.

```cpp
// Solución 1: Pull-up interno
pinMode(BUTTON_PIN, INPUT_PULLUP);

// Solución 2: Pull-down externo con resistencia 10kΩ a GND
pinMode(BUTTON_PIN, INPUT);
```
</details>

<details>
<summary><strong>¿Por qué el LED no se enciende?</strong></summary>

Verifica:
1. Polaridad del LED (ánodo +, cátodo -)
2. Resistencia limitadora conectada
3. Pin configurado como OUTPUT
4. digitalWrite(pin, HIGH) en el código
</details>

<details>
<summary><strong>¿Por qué el botón registra múltiples pulsaciones?</strong></summary>

Es el "rebote" mecánico. Implementa debouncing:

```cpp
if (millis() - lastDebounceTime > DEBOUNCE_DELAY) {
    // Procesar pulsación
    lastDebounceTime = millis();
}
```
</details>

<details>
<summary><strong>¿Puedo usar INPUT_PULLUP sin resistencia externa?</strong></summary>

¡Sí! Arduino tiene resistencias internas de ~20-50kΩ. La lógica se invierte: botón presionado = LOW.

```cpp
pinMode(BUTTON_PIN, INPUT_PULLUP);
// Botón conecta pin a GND
// Sin presionar: HIGH
// Presionado: LOW
```
</details>

---

<div align="center">

**🎓 Semana 02 - Entradas y Salidas Digitales**

*Bootcamp Arduino · 4 horas de dedicación semanal*

[⬅️ Semana 01](../semana-01/README.md) · [Inicio](../../README.md) · [Semana 03 ➡️](../semana-03/README.md)

</div>
