# 📚 Teoría - Semana 03

> **Salidas Analógicas (PWM)**  
> Contenido teórico: ~60 minutos

---

## 📋 Módulos

| #   | Módulo                                             | Descripción                         | Duración |
| --- | -------------------------------------------------- | ----------------------------------- | -------- |
| 1   | [Fundamentos PWM](./01-fundamentos-pwm.md)         | Concepto, duty cycle, analogWrite() | 20 min   |
| 2   | [Control de LEDs](./02-control-leds-pwm.md)        | Fade, RGB, efectos visuales         | 15 min   |
| 3   | [Motores y Actuadores](./03-motores-actuadores.md) | Motor DC, servos, transistores      | 15 min   |
| 4   | [Generación de Sonido](./04-generacion-sonido.md)  | tone(), noTone(), melodías          | 10 min   |

---

## 🎯 Objetivos de Aprendizaje

Al completar esta sección teórica:

- [ ] Comprender qué es PWM y cómo simula voltajes analógicos
- [ ] Calcular duty cycle y valores de analogWrite()
- [ ] Identificar los 6 pines PWM de Arduino Uno
- [ ] Crear efectos de fade y control de brillo
- [ ] Mezclar colores con LED RGB
- [ ] Controlar velocidad de motores DC
- [ ] Generar tonos y melodías con buzzer

---

## 🗺️ Mapa Conceptual

```
                    ┌─────────────────┐
                    │      PWM        │
                    │ Pulse Width     │
                    │ Modulation      │
                    └────────┬────────┘
                             │
         ┌───────────────────┼───────────────────┐
         │                   │                   │
         ▼                   ▼                   ▼
┌─────────────────┐ ┌─────────────────┐ ┌─────────────────┐
│   Control de    │ │   Control de    │ │  Generación de  │
│      LEDs       │ │    Motores      │ │     Sonido      │
├─────────────────┤ ├─────────────────┤ ├─────────────────┤
│ • Fade in/out   │ │ • Velocidad DC  │ │ • tone()        │
│ • LED RGB       │ │ • Transistores  │ │ • Frecuencias   │
│ • Efectos       │ │ • Diodo flyback │ │ • Melodías      │
└─────────────────┘ └─────────────────┘ └─────────────────┘
```

---

## ⚡ Conceptos Clave

### PWM en Arduino Uno

| Característica         | Valor                     |
| ---------------------- | ------------------------- |
| Pines PWM              | 3, 5, 6, 9, 10, 11        |
| Resolución             | 8 bits (0-255)            |
| Frecuencia (pines 5,6) | ~980 Hz                   |
| Frecuencia (otros)     | ~490 Hz                   |
| Función                | `analogWrite(pin, valor)` |

### Fórmula del Duty Cycle

```
Duty Cycle (%) = (valor_analogWrite / 255) × 100

Voltaje Promedio = (Duty Cycle / 100) × 5V
```

### Ejemplos Rápidos

| Duty Cycle | analogWrite() | Voltaje Promedio |
| ---------- | ------------- | ---------------- |
| 0%         | 0             | 0V               |
| 25%        | 64            | 1.25V            |
| 50%        | 127           | 2.5V             |
| 75%        | 191           | 3.75V            |
| 100%       | 255           | 5V               |

---

## ➡️ Navegación

[← Assets](../0-assets/README.md) · [Prácticas →](../2-practicas/README.md)
