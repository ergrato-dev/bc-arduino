# 🔨 Proyecto Integrador: Knight Rider - Secuenciador de LEDs

> ⏱️ **Tiempo estimado:** 1.5 horas  
> ⭐⭐⭐ **Dificultad:** Intermedio  
> 🎯 **Compatibilidad Tinkercad:** ✅  
> 📊 **Valor:** 40 puntos (40% de la semana)

---

## 📋 Descripción General

El proyecto **Knight Rider** consiste en crear un secuenciador de 6 LEDs que simula el icónico efecto de luz del auto fantástico (KITT). Los LEDs se iluminan de forma secuencial, primero de izquierda a derecha, luego de derecha a izquierda, creando un efecto de "barrido" continuo.

Este proyecto integra todos los conocimientos adquiridos durante la semana:
- Control de múltiples salidas digitales
- Uso de arrays y bucles
- Cálculo de resistencias
- Organización de código con funciones

---

## 🎯 Objetivos de Aprendizaje

Al completar este proyecto, habrás demostrado dominio de:

- [ ] Diseño y construcción de circuitos con múltiples componentes
- [ ] Programación con arrays para manejo eficiente de pines
- [ ] Implementación de secuencias bidireccionales
- [ ] Organización de código modular con funciones
- [ ] Documentación técnica de proyectos
- [ ] Aplicación práctica de la Ley de Ohm

---

## ✨ Características

### Funcionalidades Principales (Obligatorias)

| # | Funcionalidad | Descripción |
|---|---------------|-------------|
| 1 | **Secuencia IDA** | LEDs se encienden de izquierda a derecha, uno a la vez |
| 2 | **Secuencia VUELTA** | LEDs regresan de derecha a izquierda |
| 3 | **Ciclo continuo** | La secuencia se repite indefinidamente |
| 4 | **Transiciones suaves** | Velocidad apropiada para efecto visual fluido |

### Funcionalidades Opcionales (Bonus)

| # | Funcionalidad | Puntos Extra |
|---|---------------|--------------|
| 1 | Velocidad variable (3 niveles) | +2 pts |
| 2 | Efecto "estela" (LED anterior se apaga gradualmente) | +2 pts |
| 3 | Modo aleatorio | +1 pt |
| 4 | Indicador de inicio (todos parpadean 3 veces) | +1 pt |
| 5 | Uso de millis() en lugar de delay() | +3 pts |

---

## 🏗️ Arquitectura del Proyecto

### Diagrama de Bloques

```
┌─────────────────────────────────────────────────────────────────┐
│                    KNIGHT RIDER - ARQUITECTURA                  │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  ┌──────────────┐                                              │
│  │    SETUP     │                                              │
│  │              │                                              │
│  │ • Config pins│                                              │
│  │ • Init Serial│                                              │
│  │ • Bienvenida │                                              │
│  └──────┬───────┘                                              │
│         │                                                       │
│         ▼                                                       │
│  ┌──────────────┐         ┌──────────────────────────────┐     │
│  │    LOOP      │────────▶│       SECUENCIA PRINCIPAL    │     │
│  │              │         │                              │     │
│  │  Ciclo       │         │  ┌─────────┐   ┌─────────┐  │     │
│  │  infinito    │         │  │  IDA    │──▶│ VUELTA  │  │     │
│  │              │         │  │ 0→1→2→  │   │ ←4←3←2← │  │     │
│  │              │         │  │ →3→4→5  │   │ ←1←0    │  │     │
│  └──────────────┘         │  └─────────┘   └─────────┘  │     │
│                           └──────────────────────────────┘     │
│                                      │                          │
│                                      ▼                          │
│  ┌───────────────────────────────────────────────────────┐     │
│  │                 FUNCIONES AUXILIARES                   │     │
│  │                                                        │     │
│  │  • allOff()      - Apagar todos los LEDs              │     │
│  │  • lightOnly(n)  - Encender solo LED n                │     │
│  │  • sequenceForward()  - Secuencia ida                 │     │
│  │  • sequenceBackward() - Secuencia vuelta              │     │
│  │                                                        │     │
│  └───────────────────────────────────────────────────────┘     │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

### Estructura del Código

```
proyecto-knight-rider/
│
├── knight_rider.ino          // Archivo principal
│
└── Secciones del código:
    ├── Constantes (pines, tiempos)
    ├── Variables globales
    ├── setup()
    ├── loop()
    └── Funciones auxiliares
        ├── allOff()
        ├── allOn()
        ├── lightOnly()
        ├── sequenceForward()
        ├── sequenceBackward()
        └── startupAnimation()
```

---

## 📦 Hardware Requerido

### Lista de Componentes

| Componente | Cantidad | Especificación | Costo Aprox. |
|------------|----------|----------------|--------------|
| Arduino Uno R3 | 1 | Compatible Tinkercad | $10-15 |
| LED 5mm | 6 | Rojo (o color preferido) | $0.50 |
| Resistencia | 6 | 220Ω (Rojo-Rojo-Marrón) | $0.30 |
| Protoboard | 1 | 400 puntos mínimo | $3-5 |
| Cables jumper | 10+ | Macho-macho | $2-3 |

### Diagrama de Conexiones

```
                              ARDUINO UNO
    ┌─────────────────────────────────────────────────────────┐
    │                                                         │
    │   Pin 3  ───┐                                           │
    │   Pin 4  ───│──┐                                        │
    │   Pin 5  ───│──│──┐                                     │
    │   Pin 6  ───│──│──│──┐                                  │
    │   Pin 7  ───│──│──│──│──┐                               │
    │   Pin 8  ───│──│──│──│──│──┐                            │
    │             │  │  │  │  │  │                            │
    │   GND ──────│──│──│──│──│──│────┐                       │
    │             │  │  │  │  │  │    │                       │
    └─────────────│──│──│──│──│──│────│───────────────────────┘
                  │  │  │  │  │  │    │
    ┌─────────────│──│──│──│──│──│────│───────────────────────┐
    │  PROTOBOARD │  │  │  │  │  │    │                       │
    │             │  │  │  │  │  │    │                       │
    │   LED 0 ────┴──│──│──│──│──│────┤   ┌─────────────────┐ │
    │   [R]─[◄]      │  │  │  │  │    │   │ DISPOSICIÓN     │ │
    │                │  │  │  │  │    │   │                 │ │
    │   LED 1 ───────┴──│──│──│──│────┤   │  ◯ ◯ ◯ ◯ ◯ ◯   │ │
    │   [R]─[◄]         │  │  │  │    │   │  0 1 2 3 4 5   │ │
    │                   │  │  │  │    │   │                 │ │
    │   LED 2 ──────────┴──│──│──│────┤   │  ← IDA         │ │
    │   [R]─[◄]            │  │  │    │   │    VUELTA →    │ │
    │                      │  │  │    │   │                 │ │
    │   LED 3 ─────────────┴──│──│────┤   └─────────────────┘ │
    │   [R]─[◄]               │  │    │                       │
    │                         │  │    │                       │
    │   LED 4 ────────────────┴──│────┤                       │
    │   [R]─[◄]                  │    │                       │
    │                            │    │                       │
    │   LED 5 ───────────────────┴────┤                       │
    │   [R]─[◄]                       │                       │
    │                                 │                       │
    │   Línea GND ────────────────────┘                       │
    │                                                         │
    └─────────────────────────────────────────────────────────┘

    [R] = Resistencia 220Ω
    [◄] = LED (ánodo hacia resistencia, cátodo hacia GND)
```

### Tabla de Conexiones

| LED | Pin Arduino | Resistencia | Notas |
|-----|-------------|-------------|-------|
| LED 0 (izquierda) | Pin 3 | 220Ω | Inicio de secuencia |
| LED 1 | Pin 4 | 220Ω | |
| LED 2 | Pin 5 | 220Ω | |
| LED 3 | Pin 6 | 220Ω | |
| LED 4 | Pin 7 | 220Ω | |
| LED 5 (derecha) | Pin 8 | 220Ω | Fin de secuencia |
| Todos cátodos | GND | - | Tierra común |

---

## 💻 Código Base

```cpp
/*
 * =================================================
 * PROYECTO: Knight Rider - Secuenciador de LEDs
 * =================================================
 * 
 * ¿Qué hace?
 * Crea el efecto de luz del auto fantástico (KITT):
 * 6 LEDs que se iluminan secuencialmente de izquierda
 * a derecha y luego de derecha a izquierda.
 * 
 * ¿Para qué?
 * - Proyecto integrador Semana 01
 * - Demostrar dominio de salidas digitales
 * - Practicar arrays y bucles
 * - Crear efectos visuales atractivos
 * 
 * ¿Cómo funciona?
 * 1. setup() configura los 6 pines como salida
 * 2. loop() ejecuta la secuencia ida/vuelta
 * 3. Funciones auxiliares manejan los LEDs
 * 4. La velocidad se puede ajustar con DELAY_MS
 * 
 * Hardware requerido:
 * - Arduino Uno R3
 * - 6 LEDs (cualquier color)
 * - 6 Resistencias 220Ω
 * - Protoboard y cables
 * 
 * Conexiones:
 * - Pin 3 → R220 → LED 0 → GND
 * - Pin 4 → R220 → LED 1 → GND
 * - Pin 5 → R220 → LED 2 → GND
 * - Pin 6 → R220 → LED 3 → GND
 * - Pin 7 → R220 → LED 4 → GND
 * - Pin 8 → R220 → LED 5 → GND
 * 
 * Autor: [Tu nombre]
 * Fecha: [Fecha]
 * Versión: 1.0
 * 
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// CONSTANTES
// ==================================================

// Número total de LEDs
const int NUM_LEDS = 6;

// Array con los pines de cada LED (en orden de izquierda a derecha)
const int LED_PINS[NUM_LEDS] = {3, 4, 5, 6, 7, 8};

// Velocidad de la secuencia (milisegundos entre cada LED)
// Valores recomendados: 50 (rápido), 80 (normal), 120 (lento)
const int DELAY_MS = 80;

// ==================================================
// SETUP
// ==================================================
void setup() {
    // Configurar todos los pines de LEDs como salida
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(LED_PINS[i], OUTPUT);
    }
    
    // Iniciar comunicación Serial para debugging
    Serial.begin(9600);
    Serial.println("================================");
    Serial.println("   KNIGHT RIDER v1.0");
    Serial.println("   Secuenciador de LEDs");
    Serial.println("================================");
    
    // Animación de inicio (opcional)
    startupAnimation();
}

// ==================================================
// LOOP
// ==================================================
void loop() {
    // Secuencia IDA: de izquierda a derecha (0 → 5)
    sequenceForward();
    
    // Secuencia VUELTA: de derecha a izquierda (4 → 1)
    // Nota: empezamos en 4 y terminamos en 1 para no repetir extremos
    sequenceBackward();
}

// ==================================================
// FUNCIONES AUXILIARES
// ==================================================

/**
 * Apaga todos los LEDs
 */
void allOff() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], LOW);
    }
}

/**
 * Enciende todos los LEDs
 */
void allOn() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], HIGH);
    }
}

/**
 * Enciende solo el LED en la posición indicada
 * @param position Índice del LED (0 a NUM_LEDS-1)
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

/**
 * Secuencia de ida: ilumina LEDs de izquierda a derecha
 */
void sequenceForward() {
    for (int i = 0; i < NUM_LEDS; i++) {
        lightOnly(i);
        delay(DELAY_MS);
    }
}

/**
 * Secuencia de vuelta: ilumina LEDs de derecha a izquierda
 * Excluye los extremos para evitar repetición
 */
void sequenceBackward() {
    for (int i = NUM_LEDS - 2; i > 0; i--) {
        lightOnly(i);
        delay(DELAY_MS);
    }
}

/**
 * Animación de inicio: parpadea todos los LEDs 3 veces
 */
void startupAnimation() {
    Serial.println("Iniciando...");
    
    for (int i = 0; i < 3; i++) {
        allOn();
        delay(200);
        allOff();
        delay(200);
    }
    
    Serial.println("¡Listo!");
    delay(500);
}
```

---

## ⏱️ Tiempo Estimado

| Fase | Tiempo | Actividad |
|------|--------|-----------|
| 1 | 15 min | Lectura de especificaciones |
| 2 | 20 min | Armado del circuito |
| 3 | 30 min | Programación y pruebas |
| 4 | 15 min | Documentación |
| 5 | 10 min | Mejoras opcionales |
| **Total** | **~90 min** | |

---

## 📊 Evaluación

Ver [RUBRICA-EVALUACION.md](../RUBRICA-EVALUACION.md) para criterios detallados.

### Resumen de Puntos

| Criterio | Puntos |
|----------|--------|
| Funcionalidad (secuencia ida/vuelta) | 15 |
| Circuito (conexiones, documentación) | 10 |
| Código (arrays, funciones, comentarios) | 10 |
| Extras opcionales | 5 |
| **Total** | **40** |

---

## 📋 Entregables

- [ ] Enlace a proyecto en Tinkercad (compartido como público)
- [ ] Código fuente (.ino) con documentación completa
- [ ] Captura de pantalla o GIF del funcionamiento
- [ ] Breve descripción del proyecto (qué hace, cómo funciona)

---

## 💡 Tips de Implementación

### Armado del Circuito

1. **Empieza simple:** Conecta primero 2 LEDs y prueba
2. **Verifica polaridad:** Pata larga del LED = positivo
3. **Organiza los cables:** Usa colores consistentes
4. **Prueba cada LED:** Antes de conectar el siguiente

### Programación

1. **Prueba incremental:** Haz funcionar la secuencia ida antes de agregar vuelta
2. **Usa Serial:** Para ver qué está ejecutando el código
3. **Ajusta velocidad:** DELAY_MS entre 50-150 para buen efecto
4. **Comenta todo:** Tu yo del futuro te lo agradecerá

### Debugging

| Problema | Posible Causa | Solución |
|----------|---------------|----------|
| LED no enciende | Polaridad invertida | Girar el LED |
| Secuencia incorrecta | Pines mal conectados | Verificar array vs circuito |
| Parpadeo errático | Conexión floja | Revisar cables |
| Solo enciende uno | GND no conectado | Verificar tierra común |

---

## 🚀 Extensiones Sugeridas

Una vez completado el proyecto básico, puedes agregar:

### Nivel 1: Velocidad Variable
```cpp
const int SPEEDS[] = {50, 80, 120};  // Rápido, normal, lento
int currentSpeed = 1;  // Índice de velocidad actual
```

### Nivel 2: Efecto Estela
```cpp
void lightWithTrail(int position) {
    allOff();
    // LED principal brillante
    digitalWrite(LED_PINS[position], HIGH);
    // LED anterior más tenue (simulado con parpadeo rápido)
    if(position > 0) {
        // Implementar con PWM en semana 3
    }
}
```

### Nivel 3: Múltiples Modos
```cpp
enum Mode { KNIGHT_RIDER, FILL, RANDOM, ALTERNATE };
Mode currentMode = KNIGHT_RIDER;
```

---

## 🔗 Recursos

| Recurso | Enlace |
|---------|--------|
| Guía de Diseño | [GUIA-DISENO.md](./GUIA-DISENO.md) |
| Ejemplos y Datos | [EJEMPLOS-DATOS.md](./EJEMPLOS-DATOS.md) |
| Rúbrica | [RUBRICA-EVALUACION.md](../RUBRICA-EVALUACION.md) |
| Teoría Arrays | [arduino.cc](https://www.arduino.cc/reference/en/language/variables/data-types/array/) |

---

<div align="center">

[⬅️ Prácticas](../2-practicas/README.md) | [Semana 01](../README.md) | [Recursos ➡️](../4-recursos/README.md)

</div>
