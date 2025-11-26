# 🎨 Assets - Semana 02

> **Entradas y Salidas Digitales**  
> Diagramas y recursos visuales de apoyo

---

## 📋 Índice de Diagramas

| #   | Archivo                              | Usado en         | Descripción                              |
| --- | ------------------------------------ | ---------------- | ---------------------------------------- |
| 01  | `01-digital-io-estados.svg`          | Teoría Módulo 01 | Estados HIGH/LOW y flujo de corriente    |
| 02  | `02-pull-down-circuito.svg`          | Teoría Módulo 02 | Circuito con resistencia pull-down       |
| 03  | `03-pull-up-circuito.svg`            | Teoría Módulo 02 | Circuito con resistencia pull-up         |
| 04  | `04-input-pullup-interno.svg`        | Teoría Módulo 02 | Resistencia pull-up interna Arduino      |
| 05  | `05-debounce-problema.svg`           | Teoría Módulo 03 | Visualización del rebote mecánico        |
| 06  | `06-debounce-solucion.svg`           | Teoría Módulo 03 | Señal limpia después de debounce         |
| 07  | `07-practica-toggle-led.svg`         | Práctica 03      | Diagrama circuito toggle LED             |
| 08  | `08-proyecto-control-iluminacion.svg`| Proyecto         | Diagrama del sistema de control          |

---

## 🎨 Convenciones de Diseño

### Paleta de Colores

| Elemento           | Color             | Hex       |
| ------------------ | ----------------- | --------- |
| Fondo              | Negro/Gris oscuro | `#1e1e1e` |
| Texto principal    | Blanco            | `#ffffff` |
| Texto secundario   | Gris claro        | `#cccccc` |
| Arduino (placa)    | Azul Arduino      | `#00979c` |
| Señal HIGH         | Verde brillante   | `#44ff44` |
| Señal LOW          | Rojo              | `#ff4444` |
| Estado flotante    | Amarillo          | `#ffaa00` |
| Resistencias       | Beige             | `#d4b896` |
| Botón presionado   | Verde             | `#00aa00` |
| Botón no presionado| Gris              | `#666666` |
| Cables positivo    | Rojo              | `#ff0000` |
| Cables negativo    | Negro             | `#333333` |
| Cables señal       | Verde/Azul        | Variado   |

### Especificaciones

- **Formato:** SVG (vectorial, escalable)
- **Tema:** Dark theme para reducir fatiga visual
- **Sin degradados:** Colores sólidos únicamente
- **Fuentes:** Sans-serif (Arial, Helvetica)
- **Tamaño base:** 800×500 px (ajustable)

---

## 📁 Estado de los Assets

| Archivo                              | Estado       | Notas                         |
| ------------------------------------ | ------------ | ----------------------------- |
| `01-digital-io-estados.svg`          | ✅ Completo  | Estados HIGH/LOW              |
| `02-pull-down-circuito.svg`          | ✅ Completo  | Pull-down externo             |
| `03-pull-up-circuito.svg`            | ✅ Completo  | Pull-up externo               |
| `04-input-pullup-interno.svg`        | ✅ Completo  | INPUT_PULLUP Arduino          |
| `05-debounce-problema.svg`           | ✅ Completo  | Señal con rebotes             |
| `06-debounce-solucion.svg`           | ✅ Completo  | Señal después de debounce     |
| `07-practica-toggle-led.svg`         | ✅ Completo  | Circuito práctica 03          |
| `08-proyecto-control-iluminacion.svg`| ✅ Completo  | Circuito proyecto integrador  |

---

## 🔧 Uso de los Assets

### En Markdown

```markdown
![Estados Digital I/O](./0-assets/01-digital-io-estados.svg)
```

### Tamaño Recomendado

```html
<img src="./0-assets/01-digital-io-estados.svg" width="600" alt="Estados Digital I/O">
```

---

## 📐 Plantilla Base SVG

```xml
<?xml version="1.0" encoding="UTF-8"?>
<svg xmlns="http://www.w3.org/2000/svg"
     viewBox="0 0 800 500"
     width="800" height="500">

  <!-- Fondo oscuro -->
  <rect width="100%" height="100%" fill="#1e1e1e"/>

  <!-- Título -->
  <text x="400" y="40"
        font-family="Arial, sans-serif"
        font-size="24"
        fill="#ffffff"
        text-anchor="middle"
        font-weight="bold">
    Título del Diagrama
  </text>

  <!-- Contenido aquí -->

  <!-- Footer -->
  <text x="400" y="485"
        font-family="Arial, sans-serif"
        font-size="10"
        fill="#666666"
        text-anchor="middle">
    Bootcamp Arduino - Semana 02
  </text>

</svg>
```

---

<div align="center">

**[⬅️ Volver a Semana 02](../README.md)**

</div>
