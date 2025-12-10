# Práctica 2: Control LED RGB

> ⭐⭐ Nivel: Intermedio · ⏱️ 25 minutos

---

## 🎯 Objetivo

Controlar un LED RGB para mostrar diferentes colores usando tres canales PWM, creando mezclas de colores y transiciones.

---

## 📦 Materiales

| Componente             | Cantidad |
| ---------------------- | -------- |
| Arduino Uno            | 1        |
| LED RGB (cátodo común) | 1        |
| Resistencia 220Ω       | 3        |
| Protoboard             | 1        |
| Cables jumper          | 6        |

---

## 🔌 Diagrama de Conexión

```
    Arduino Uno                      LED RGB
    ┌─────────────┐                 (Cátodo Común)
    │             │                     │
    │         ~9  ├────[220Ω]──────── R │ (Rojo)
    │             │                     │
    │        ~10  ├────[220Ω]──────── G │ (Verde)
    │             │                     │
    │        ~11  ├────[220Ω]──────── B │ (Azul)
    │             │                     │
    │         GND ├──────────────────  -│ (Cátodo/GND)
    └─────────────┘                     │

Nota: El cátodo es la pata más larga en LED RGB cátodo común
```

### Tabla de Conexiones

| Arduino | Resistencia | LED RGB    |
| ------- | ----------- | ---------- |
| Pin ~9  | 220Ω        | Rojo (R)   |
| Pin ~10 | 220Ω        | Verde (G)  |
| Pin ~11 | 220Ω        | Azul (B)   |
| GND     | —           | Cátodo (-) |

---

## 💻 Código

### Parte 1: Colores Básicos

```cpp
/*
 * =================================================
 * PROYECTO: Control LED RGB - Colores Básicos
 * =================================================
 *
 * ¿Qué hace?
 * Muestra los 7 colores básicos del modelo RGB,
 * cambiando cada segundo.
 *
 * ¿Para qué?
 * - Iluminación decorativa
 * - Indicadores de estado multicolor
 * - Aprender mezcla de colores RGB
 *
 * ¿Cómo funciona?
 * 1. Define función setColor() para los 3 canales
 * 2. Combina R, G, B en diferentes proporciones
 * 3. Cada combinación produce un color diferente
 *
 * Hardware: LED RGB + 3x 220Ω en pines 9,10,11
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// DEFINICIÓN DE PINES
// ==================================================
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

// ==================================================
// SETUP
// ==================================================
void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    Serial.begin(9600);
    Serial.println("Control RGB iniciado");
}

// ==================================================
// LOOP
// ==================================================
void loop() {
    // Rojo puro
    Serial.println("Color: ROJO");
    setColor(255, 0, 0);
    delay(1000);

    // Verde puro
    Serial.println("Color: VERDE");
    setColor(0, 255, 0);
    delay(1000);

    // Azul puro
    Serial.println("Color: AZUL");
    setColor(0, 0, 255);
    delay(1000);

    // Amarillo (Rojo + Verde)
    Serial.println("Color: AMARILLO");
    setColor(255, 255, 0);
    delay(1000);

    // Cian (Verde + Azul)
    Serial.println("Color: CIAN");
    setColor(0, 255, 255);
    delay(1000);

    // Magenta (Rojo + Azul)
    Serial.println("Color: MAGENTA");
    setColor(255, 0, 255);
    delay(1000);

    // Blanco (Todos)
    Serial.println("Color: BLANCO");
    setColor(255, 255, 255);
    delay(1000);

    // Apagado
    Serial.println("LED apagado");
    setColor(0, 0, 0);
    delay(1000);
}

// ==================================================
// FUNCIÓN: Establecer color RGB
// ==================================================
/**
 * Establece el color del LED RGB
 *
 * @param red   Intensidad rojo (0-255)
 * @param green Intensidad verde (0-255)
 * @param blue  Intensidad azul (0-255)
 */
void setColor(int red, int green, int blue) {
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}
```

### Parte 2: Efecto Arcoíris

```cpp
/*
 * Efecto Arcoíris - Transición suave de colores
 * Añadir después del código anterior
 */

void loop() {
    rainbowCycle();
}

/**
 * Ciclo completo de arcoíris
 * Transición: R→Y→G→C→B→M→R
 */
void rainbowCycle() {
    // Rojo a Amarillo (subir verde)
    for (int g = 0; g <= 255; g += 5) {
        setColor(255, g, 0);
        delay(15);
    }

    // Amarillo a Verde (bajar rojo)
    for (int r = 255; r >= 0; r -= 5) {
        setColor(r, 255, 0);
        delay(15);
    }

    // Verde a Cian (subir azul)
    for (int b = 0; b <= 255; b += 5) {
        setColor(0, 255, b);
        delay(15);
    }

    // Cian a Azul (bajar verde)
    for (int g = 255; g >= 0; g -= 5) {
        setColor(0, g, 255);
        delay(15);
    }

    // Azul a Magenta (subir rojo)
    for (int r = 0; r <= 255; r += 5) {
        setColor(r, 0, 255);
        delay(15);
    }

    // Magenta a Rojo (bajar azul)
    for (int b = 255; b >= 0; b -= 5) {
        setColor(255, 0, b);
        delay(15);
    }
}
```

---

## 🎨 Tabla de Colores

| Color    | R   | G   | B   | Código                    |
| -------- | --- | --- | --- | ------------------------- |
| Rojo     | 255 | 0   | 0   | `setColor(255, 0, 0)`     |
| Verde    | 0   | 255 | 0   | `setColor(0, 255, 0)`     |
| Azul     | 0   | 0   | 255 | `setColor(0, 0, 255)`     |
| Amarillo | 255 | 255 | 0   | `setColor(255, 255, 0)`   |
| Cian     | 0   | 255 | 255 | `setColor(0, 255, 255)`   |
| Magenta  | 255 | 0   | 255 | `setColor(255, 0, 255)`   |
| Blanco   | 255 | 255 | 255 | `setColor(255, 255, 255)` |
| Naranja  | 255 | 128 | 0   | `setColor(255, 128, 0)`   |
| Rosa     | 255 | 105 | 180 | `setColor(255, 105, 180)` |
| Púrpura  | 128 | 0   | 128 | `setColor(128, 0, 128)`   |

---

## 🧪 Pruebas

### Verificación

- [ ] Los 3 colores primarios (R,G,B) funcionan
- [ ] Los colores secundarios se mezclan correctamente
- [ ] El blanco muestra los 3 colores encendidos
- [ ] El efecto arcoíris transiciona suavemente

### Experimentos

1. **Intensidad**: Prueba valores bajos (0-50) para colores tenues
2. **Velocidad arcoíris**: Cambia `delay(15)` a otros valores
3. **Colores personalizados**: Crea tus propias combinaciones

---

## 🎯 Desafíos

<details>
<summary><strong>Desafío 1: Modo aleatorio</strong></summary>

Genera colores aleatorios cada segundo.

```cpp
void loop() {
    int r = random(0, 256);
    int g = random(0, 256);
    int b = random(0, 256);

    setColor(r, g, b);

    Serial.print("Color: R=");
    Serial.print(r);
    Serial.print(" G=");
    Serial.print(g);
    Serial.print(" B=");
    Serial.println(b);

    delay(1000);
}
```

</details>

<details>
<summary><strong>Desafío 2: Fade entre colores</strong></summary>

Transición suave entre dos colores específicos.

```cpp
void fadeToColor(int r1, int g1, int b1, int r2, int g2, int b2, int steps) {
    for (int i = 0; i <= steps; i++) {
        int r = r1 + ((r2 - r1) * i / steps);
        int g = g1 + ((g2 - g1) * i / steps);
        int b = b1 + ((b2 - b1) * i / steps);

        setColor(r, g, b);
        delay(20);
    }
}

void loop() {
    // Fade de rojo a azul
    fadeToColor(255, 0, 0, 0, 0, 255, 50);
    delay(500);

    // Fade de azul a verde
    fadeToColor(0, 0, 255, 0, 255, 0, 50);
    delay(500);

    // Fade de verde a rojo
    fadeToColor(0, 255, 0, 255, 0, 0, 50);
    delay(500);
}
```

</details>

---

## ❓ Solución de Problemas

| Problema               | Causa                   | Solución                    |
| ---------------------- | ----------------------- | --------------------------- |
| Solo un color funciona | Conexión incorrecta     | Verificar cada cable        |
| Colores invertidos     | LED ánodo común         | Invertir lógica (255-valor) |
| Blanco no es puro      | Intensidades diferentes | Ajustar valores R,G,B       |
| LED no enciende        | Cátodo no conectado     | Verificar GND               |

---

## 📝 Conceptos Aprendidos

- ✅ Control de 3 canales PWM simultáneos
- ✅ Mezcla de colores RGB
- ✅ Función auxiliar para abstraer control
- ✅ Transiciones suaves entre colores

---

## ➡️ Siguiente

[Control con Potenciómetro →](./03-control-potenciometro.md)
