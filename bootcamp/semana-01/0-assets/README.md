# 🎨 Assets - Semana 01

> **Introducción a Arduino y Electrónica Básica**  
> Diagramas y recursos visuales de apoyo

---

## 📋 Índice de Diagramas

| #   | Archivo                              | Usado en         | Descripción                          |
| --- | ------------------------------------ | ---------------- | ------------------------------------ |
| 01  | `01-arduino-uno-pinout.svg`          | Teoría Módulo 01 | Diagrama de pines del Arduino Uno R3 |
| 02  | `02-ley-ohm-triangulo.svg`           | Teoría Módulo 02 | Triángulo de la Ley de Ohm (V, I, R) |
| 03  | `03-led-resistencia-circuito.svg`    | Teoría Módulo 02 | Circuito básico LED con resistencia  |
| 04  | `04-codigo-colores-resistencias.svg` | Teoría Módulo 02 | Tabla de código de colores           |
| 05  | `05-estructura-sketch.svg`           | Teoría Módulo 03 | Estructura de un programa Arduino    |
| 06  | `06-tinkercad-interfaz.svg`          | Teoría Módulo 03 | Interfaz del simulador Tinkercad     |
| 07  | `07-practica-semaforo.svg`           | Práctica 03      | Diagrama del circuito semáforo       |
| 08  | `08-proyecto-knight-rider.svg`       | Proyecto         | Diagrama del secuenciador de LEDs    |

---

## 🎨 Convenciones de Diseño

### Paleta de Colores

| Elemento         | Color             | Hex       |
| ---------------- | ----------------- | --------- |
| Fondo            | Negro/Gris oscuro | `#1e1e1e` |
| Texto principal  | Blanco            | `#ffffff` |
| Texto secundario | Gris claro        | `#cccccc` |
| Arduino (placa)  | Azul Arduino      | `#00979c` |
| LED Rojo         | Rojo              | `#ff4444` |
| LED Verde        | Verde             | `#44ff44` |
| LED Amarillo     | Amarillo          | `#ffff44` |
| LED Azul         | Azul              | `#4444ff` |
| Resistencias     | Beige             | `#d4b896` |
| Cables positivo  | Rojo              | `#ff0000` |
| Cables negativo  | Negro             | `#333333` |
| Cables señal     | Verde/Azul        | Variado   |

### Especificaciones

- **Formato:** SVG (vectorial, escalable)
- **Tema:** Dark theme para reducir fatiga visual
- **Sin degradados:** Colores sólidos únicamente
- **Fuentes:** Sans-serif (Arial, Helvetica)
- **Tamaño base:** 800×600 px (ajustable)

---

## 📁 Estado de los Assets

| Archivo                              | Estado       | Notas                       |
| ------------------------------------ | ------------ | --------------------------- |
| `01-arduino-uno-pinout.svg`          | 📝 Pendiente | Diagrama detallado de pines |
| `02-ley-ohm-triangulo.svg`           | 📝 Pendiente | Triángulo interactivo       |
| `03-led-resistencia-circuito.svg`    | 📝 Pendiente | Circuito básico             |
| `04-codigo-colores-resistencias.svg` | 📝 Pendiente | Tabla visual                |
| `05-estructura-sketch.svg`           | 📝 Pendiente | Flujo setup/loop            |
| `06-tinkercad-interfaz.svg`          | 📝 Pendiente | Captura anotada             |
| `07-practica-semaforo.svg`           | 📝 Pendiente | Circuito práctica 03        |
| `08-proyecto-knight-rider.svg`       | 📝 Pendiente | Circuito proyecto           |

> **Nota:** Los diagramas ASCII en el README.md principal sirven como referencia temporal hasta que se creen los SVG definitivos.

---

## 🔧 Herramientas Recomendadas

### Para crear SVGs:

- **Figma** (gratuito online) - [figma.com](https://www.figma.com)
- **Inkscape** (gratuito desktop) - [inkscape.org](https://inkscape.org)
- **draw.io** (gratuito online) - [draw.io](https://draw.io)

### Para circuitos:

- **Fritzing** - Diagramas de circuitos profesionales
- **Tinkercad** - Exportar capturas de circuitos
- **KiCad** - Esquemáticos técnicos

---

## 📐 Plantilla Base SVG

```xml
<?xml version="1.0" encoding="UTF-8"?>
<svg xmlns="http://www.w3.org/2000/svg"
     viewBox="0 0 800 600"
     width="800" height="600">

  <!-- Fondo oscuro -->
  <rect width="100%" height="100%" fill="#1e1e1e"/>

  <!-- Título -->
  <text x="400" y="40"
        font-family="Arial, sans-serif"
        font-size="24"
        fill="#ffffff"
        text-anchor="middle">
    Título del Diagrama
  </text>

  <!-- Contenido aquí -->

  <!-- Footer -->
  <text x="400" y="580"
        font-family="Arial, sans-serif"
        font-size="12"
        fill="#666666"
        text-anchor="middle">
    Bootcamp Arduino - Semana 01
  </text>

</svg>
```

---

## 🖼️ Previews

> Los previews se agregarán conforme se creen los diagramas SVG.

### 01 - Arduino Uno Pinout

```
┌─────────────────────────────────────────┐
│           [Preview pendiente]           │
│                                         │
│    Diagrama de pines Arduino Uno R3     │
│                                         │
└─────────────────────────────────────────┘
```

### 02 - Triángulo Ley de Ohm

```
         ┌───────┐
         │   V   │
         └───┬───┘
            / \
           /   \
      ┌───┴─┐ ┌─┴───┐
      │  I  │ │  R  │
      └─────┘ └─────┘

V = I × R  |  I = V / R  |  R = V / I
```

### 03 - Circuito LED con Resistencia

```
    5V ──────┬──────────────────┐
             │                  │
            [R]                 │
           220Ω                 │
             │                  │
             ├───────[LED]──────┤
             │        ↓         │
            GND ────────────────┘
```

---

## 🔗 Referencias

- [Módulo 01 - Teoría](../1-teoria/01-introduccion-microcontroladores.md)
- [Módulo 02 - Teoría](../1-teoria/02-electronica-basica.md)
- [Módulo 03 - Teoría](../1-teoria/03-arduino-ide-tinkercad.md)
- [Prácticas](../2-practicas/README.md)
- [Proyecto](../3-proyecto/README.md)

---

<div align="center">

**Assets Semana 01 - Bootcamp Arduino**

</div>
