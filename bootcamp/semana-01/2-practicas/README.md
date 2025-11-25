# 💻 Prácticas - Semana 01

> **Introducción a Arduino y Electrónica Básica**  
> Tiempo estimado: 1.5 horas | 4 prácticas

---

## 📋 Índice de Prácticas

| # | Práctica | Dificultad | Tiempo | Descripción |
|---|----------|------------|--------|-------------|
| 01 | [Blink LED Integrado](./practica-01-blink-led.md) | ⭐ | 20 min | LED integrado parpadeando |
| 02 | [LED Externo con Resistencia](./practica-02-led-externo.md) | ⭐⭐ | 25 min | Circuito con LED externo |
| 03 | [Semáforo Básico](./practica-03-semaforo.md) | ⭐⭐ | 25 min | Secuencia de 3 LEDs |
| 04 | [Patrón de Luces Personalizado](./practica-04-patron-luces.md) | ⭐⭐⭐ | 30 min | Diseño creativo con múltiples LEDs |

---

## 🎯 Objetivos de las Prácticas

Al completar todas las prácticas, habrás:

- [ ] Controlado el LED integrado del Arduino
- [ ] Construido tu primer circuito con componentes externos
- [ ] Aplicado la Ley de Ohm para calcular resistencias
- [ ] Programado secuencias de múltiples LEDs
- [ ] Usado funciones para organizar el código
- [ ] Experimentado con diferentes patrones de iluminación

---

## 🗺️ Progresión de Dificultad

```
┌─────────────────────────────────────────────────────────────────┐
│                  PROGRESIÓN DE PRÁCTICAS                        │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  PRÁCTICA 1          PRÁCTICA 2          PRÁCTICA 3             │
│  ┌─────────┐         ┌─────────┐         ┌─────────┐           │
│  │  ⭐     │────────▶│  ⭐⭐   │────────▶│  ⭐⭐   │           │
│  │         │         │         │         │         │           │
│  │  Blink  │         │   LED   │         │Semáforo │           │
│  │  LED    │         │ Externo │         │ 3 LEDs  │           │
│  │integrado│         │         │         │         │           │
│  └─────────┘         └─────────┘         └─────────┘           │
│       │                   │                   │                 │
│       ▼                   ▼                   ▼                 │
│  • digitalWrite      • Circuito          • Secuencias          │
│  • delay()           • Resistencias      • Tiempos             │
│  • Estructura        • Ley de Ohm        • Funciones           │
│                                                                 │
│                                          ┌─────────┐           │
│                                          │  ⭐⭐⭐  │           │
│                              ───────────▶│         │           │
│                                          │ Patrón  │           │
│                                          │  Luces  │           │
│                                          │ Creativo│           │
│                                          └─────────┘           │
│                                               │                 │
│                                               ▼                 │
│                                          • Arrays              │
│                                          • Creatividad         │
│                                          • Código modular      │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

---

## 📦 Componentes Necesarios

### Lista Completa para Todas las Prácticas

| Componente | Cantidad | Usado en |
|------------|----------|----------|
| Arduino Uno R3 | 1 | Todas |
| LED Rojo | 2 | P02, P03, P04 |
| LED Amarillo | 1 | P03, P04 |
| LED Verde | 2 | P03, P04 |
| Resistencia 220Ω | 5 | P02, P03, P04 |
| Cables jumper | ~15 | P02, P03, P04 |
| Protoboard | 1 | P02, P03, P04 |

> 💡 **Nota:** Si usas Tinkercad, todos estos componentes están disponibles en el simulador.

---

## 🔧 Preparación del Entorno

### Para Simulación (Tinkercad)

1. Inicia sesión en [tinkercad.com](https://www.tinkercad.com/)
2. Ve a **Circuits** → **Create new Circuit**
3. Arrastra **Arduino Uno R3** al área de trabajo
4. ¡Listo para empezar!

### Para Hardware Real

1. Conecta Arduino al computador via USB
2. Abre Arduino IDE
3. Selecciona **Tools** → **Board** → **Arduino Uno**
4. Selecciona **Tools** → **Port** → *tu puerto COM*

---

## 📊 Criterios de Evaluación

| Práctica | Puntos | Criterios Principales |
|----------|--------|----------------------|
| P01 | 8 pts | Funcionalidad, código limpio, variaciones |
| P02 | 10 pts | Circuito correcto, cálculos, documentación |
| P03 | 10 pts | Secuencia correcta, tiempos, organización |
| P04 | 12 pts | Creatividad, implementación, documentación |
| **Total** | **40 pts** | |

Ver [Rúbrica Completa](../RUBRICA-EVALUACION.md) para detalles.

---

## 💡 Consejos Generales

### Antes de Empezar

- [ ] Lee toda la práctica antes de comenzar
- [ ] Verifica que tienes todos los componentes
- [ ] Ten la documentación de referencia a mano

### Durante la Práctica

- [ ] Escribe el código paso a paso
- [ ] Prueba cada parte antes de continuar
- [ ] Usa Serial Monitor para debugging
- [ ] Documenta tu código con comentarios

### Al Terminar

- [ ] Verifica que cumples todos los criterios
- [ ] Guarda tu proyecto en Tinkercad
- [ ] Captura pantalla o GIF del resultado

---

## ⚠️ Errores Comunes a Evitar

| Error | Consecuencia | Prevención |
|-------|--------------|------------|
| LED sin resistencia | LED quemado | Siempre usar 220Ω mínimo |
| Conexiones flojas | Comportamiento errático | Verificar conexiones |
| Pin incorrecto | No funciona | Verificar número de pin |
| Olvidar GND | Circuito no cierra | Siempre conectar tierra |
| Polaridad LED | LED no enciende | Pata larga = positivo |

---

## ✅ Checklist de Completitud

### Práctica 01: Blink LED
- [ ] LED parpadea a 1 segundo
- [ ] Código documentado
- [ ] Variación de tiempo implementada

### Práctica 02: LED Externo
- [ ] Circuito armado correctamente
- [ ] Resistencia calculada
- [ ] LED funciona con código

### Práctica 03: Semáforo
- [ ] Secuencia Verde→Amarillo→Rojo
- [ ] Tiempos realistas
- [ ] Código organizado en funciones

### Práctica 04: Patrón Personalizado
- [ ] Patrón creativo implementado
- [ ] Uso de arrays
- [ ] Documentación completa

---

## 🔗 Recursos de Apoyo

| Recurso | Enlace |
|---------|--------|
| Teoría Módulo 02 | [Electrónica Básica](../1-teoria/02-electronica-basica.md) |
| Teoría Módulo 03 | [Arduino IDE y Tinkercad](../1-teoria/03-arduino-ide-tinkercad.md) |
| Arduino Reference | [arduino.cc/reference](https://www.arduino.cc/reference/en/) |
| Simulador | [tinkercad.com/circuits](https://www.tinkercad.com/circuits) |

---

<div align="center">

[⬅️ Teoría](../1-teoria/README.md) | [Semana 01](../README.md) | [Práctica 01 ➡️](./practica-01-blink-led.md)

</div>
