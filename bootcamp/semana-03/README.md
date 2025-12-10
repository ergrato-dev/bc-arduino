# 📅 Semana 3: Salidas Analógicas (PWM)

> 🎯 Domina el control de brillo, velocidad y sonido con Modulación por Ancho de Pulso

---

## 📋 Información General

| Campo | Detalle |
|-------|---------|
| **Duración** | 4 horas |
| **Nivel** | Principiante-Intermedio |
| **Prerequisitos** | Semana 1 y 2 completadas |
| **Hardware** | Arduino Uno, LEDs, RGB, Potenciómetro, Buzzer |
| **Simulador** | ✅ 100% compatible con Tinkercad |

---

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, serás capaz de:

- [ ] Comprender qué es PWM y cómo simula voltaje analógico
- [ ] Usar `analogWrite()` para controlar brillo de LEDs
- [ ] Controlar un LED RGB y mezclar colores
- [ ] Leer potenciómetros con `analogRead()` y mapear valores
- [ ] Generar tonos y melodías con `tone()` y buzzer
- [ ] Implementar efectos visuales no bloqueantes con `millis()`
- [ ] Integrar múltiples componentes en un proyecto completo

---

## 📚 Contenido de la Semana

### 📁 Estructura de Carpetas

```
semana-03/
├── README.md                    ← Estás aquí
├── RUBRICA-EVALUACION.md        # Criterios de evaluación
├── 0-assets/                    # Diagramas SVG
│   ├── 01-pwm-concepto.svg
│   ├── 02-duty-cycle.svg
│   ├── 03-pines-pwm-arduino.svg
│   ├── 04-circuito-led-fade.svg
│   ├── 05-led-rgb-catodo.svg
│   ├── 06-motor-dc-transistor.svg
│   ├── 07-buzzer-pasivo.svg
│   └── 08-proyecto-lampara-rgb.svg
├── 1-teoria/                    # Contenido teórico
│   ├── README.md
│   ├── 01-fundamentos-pwm.md
│   ├── 02-control-leds-pwm.md
│   ├── 03-motores-actuadores.md
│   └── 04-generacion-sonido.md
├── 2-practicas/                 # Ejercicios guiados
│   ├── README.md
│   ├── 01-led-fade-basico.md
│   ├── 02-control-rgb.md
│   ├── 03-control-potenciometro.md
│   └── 04-melodia-buzzer.md
├── 3-proyecto/                  # Proyecto semanal
│   └── README.md
├── 4-recursos/                  # Material adicional
│   └── README.md
└── 5-glosario/                  # Términos clave
    └── README.md
```

---

## ⏱️ Distribución del Tiempo (4 horas)

| Actividad | Tiempo | Descripción |
|-----------|--------|-------------|
| 📖 Teoría | 1h | Fundamentos PWM, LEDs, motores, sonido |
| 💻 Prácticas | 1.5h | 4 ejercicios guiados |
| 🔨 Proyecto | 1.5h | Lámpara RGB Inteligente |

---

## 📖 Módulos Teóricos

### [1. Fundamentos de PWM](./1-teoria/01-fundamentos-pwm.md)
- ¿Qué es PWM?
- Duty Cycle explicado
- `analogWrite()` en Arduino
- Pines PWM disponibles

### [2. Control de LEDs con PWM](./1-teoria/02-control-leds-pwm.md)
- Fade de LEDs
- LED RGB y mezcla de colores
- Efectos visuales
- Código no bloqueante

### [3. Motores y Actuadores](./1-teoria/03-motores-actuadores.md)
- Control de velocidad de motores DC
- Transistores como interruptores
- Puente H (L293D)
- Servomotores

### [4. Generación de Sonido](./1-teoria/04-generacion-sonido.md)
- Función `tone()`
- Buzzer activo vs pasivo
- Frecuencias y notas musicales
- Creación de melodías

---

## 💻 Prácticas

| # | Práctica | Nivel | Tiempo | Descripción |
|---|----------|-------|--------|-------------|
| 1 | [LED Fade Básico](./2-practicas/01-led-fade-basico.md) | ⭐ | 15 min | Efecto respiración en LED |
| 2 | [Control RGB](./2-practicas/02-control-rgb.md) | ⭐⭐ | 25 min | Mezcla de colores RGB |
| 3 | [Control con Potenciómetro](./2-practicas/03-control-potenciometro.md) | ⭐⭐ | 20 min | Brillo variable con pot |
| 4 | [Melodía con Buzzer](./2-practicas/04-melodia-buzzer.md) | ⭐⭐⭐ | 25 min | Crear melodías musicales |

---

## 🔨 Proyecto Semanal

### [Lámpara RGB Inteligente](./3-proyecto/README.md)

Construye una lámpara LED RGB con:

- 🎨 **4 modos**: Estático, Respiración, Arcoíris, Fiesta
- 🌈 **8 colores** predefinidos con transiciones suaves
- 💡 **Control de brillo** con potenciómetro
- 🔊 **Feedback sonoro** al cambiar modo/color
- ⚡ **Código no bloqueante** con `millis()`

**Componentes**: LED RGB, Potenciómetro, 2 Botones, Buzzer

---

## 🧮 Funciones Clave de la Semana

```cpp
// Salida PWM (0-255)
analogWrite(pin, value);

// Lectura analógica (0-1023)
int val = analogRead(pin);

// Mapeo de rangos
int mapped = map(value, 0, 1023, 0, 255);

// Generación de tono
tone(pin, frequency);
tone(pin, frequency, duration);
noTone(pin);

// Temporización no bloqueante
unsigned long currentTime = millis();
```

---

## 📊 Evaluación

### Distribución de Puntos

| Componente | Peso | Puntos |
|------------|------|--------|
| Ejercicios Prácticos (4) | 40% | 40 |
| Proyecto Semanal | 40% | 40 |
| Calidad del Código | 20% | 20 |
| **Total** | **100%** | **100** |

### Criterios de Calidad

- ✅ Código compila sin errores ni warnings
- ✅ Variables y funciones en inglés (camelCase)
- ✅ Comentarios explicativos en español
- ✅ Uso de constantes para pines y configuración
- ✅ Implementación no bloqueante donde corresponda

📋 Ver [Rúbrica de Evaluación](./RUBRICA-EVALUACION.md) para detalles completos.

---

## ✅ Checklist de Completitud

### Teoría
- [ ] Leí el módulo de Fundamentos PWM
- [ ] Leí el módulo de Control de LEDs
- [ ] Leí el módulo de Motores y Actuadores
- [ ] Leí el módulo de Generación de Sonido

### Prácticas
- [ ] Completé Práctica 1: LED Fade Básico
- [ ] Completé Práctica 2: Control RGB
- [ ] Completé Práctica 3: Control con Potenciómetro
- [ ] Completé Práctica 4: Melodía con Buzzer

### Proyecto
- [ ] Circuito armado correctamente
- [ ] Código compila sin errores
- [ ] Todos los modos funcionan
- [ ] Control de brillo funciona
- [ ] Feedback sonoro funciona
- [ ] Código documentado

### Entrega
- [ ] Código fuente (.ino)
- [ ] Foto/screenshot del circuito
- [ ] Video demostrativo (30s)

---

## 📦 Materiales de la Semana

### Hardware Requerido

| Componente | Cantidad | Notas |
|------------|----------|-------|
| Arduino Uno | 1 | R3 o R4 |
| LED Rojo 5mm | 2 | Para prácticas |
| LED RGB (cátodo común) | 1 | 4 pines |
| Resistencia 220Ω | 5 | Para LEDs |
| Potenciómetro 10kΩ | 1 | Rotativo |
| Pulsador táctil | 2 | Para proyecto |
| Buzzer pasivo | 1 | Compatible con tone() |
| Protoboard | 1 | 400+ puntos |
| Cables jumper | 20+ | Varios colores |

### Software

- Arduino IDE 2.x
- Tinkercad (para simulación)

---

## 🔗 Recursos Adicionales

- 📖 [Recursos y Referencias](./4-recursos/README.md)
- 📖 [Glosario de Términos](./5-glosario/README.md)
- 🔗 [Arduino PWM Reference](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)
- 🔗 [Tinkercad Circuits](https://www.tinkercad.com/circuits)

---

## 🧭 Navegación del Bootcamp

| ← Anterior | Actual | Siguiente → |
|------------|--------|-------------|
| [Semana 2: I/O Digital](../semana-02/README.md) | **Semana 3: PWM** | [Semana 4: Entradas Analógicas](../semana-04/README.md) |

---

## 💡 Consejos para esta Semana

1. **Practica en simulador primero** - Tinkercad es tu amigo
2. **Entiende el duty cycle** - Es la base de todo PWM
3. **Usa Serial Monitor** - Para debug de valores
4. **Evita delay()** - Aprende a usar millis()
5. **Experimenta con colores** - El RGB tiene millones de combinaciones

---

> 🎉 **¡Éxito en la Semana 3/home/epti/Documents/epti-dev/sicora-app && git add -A && git commit -m "refactor(go): consolidate modules with go.work and standardize names

- Add go.work to coordinate 9 Go modules as workspace
- Standardize module names to sicora-be-go/[service] format
- Enables cross-module development and shared dependencies

Modules: attendanceservice, evalinservice, kbservice, mevalservice,
projectevalservice, scheduleservice, softwarefactoryservice, userservice" && git push* El control PWM abre un mundo de posibilidades para crear efectos visuales y controlar actuadores de manera precisa.
