# 📄 Documentación Técnica

> **Panel de Control de Iluminación**  
> Semana 02 - Bootcamp Arduino

---

## 📋 Índice

1. [Descripción General](#descripción-general)
2. [Arquitectura del Sistema](#arquitectura-del-sistema)
3. [Hardware](#hardware)
4. [Software](#software)
5. [Modos de Operación](#modos-de-operación)
6. [Diagramas](#diagramas)
7. [Pruebas](#pruebas)
8. [Problemas Conocidos](#problemas-conocidos)

---

## Descripción General

### Propósito
Sistema de control de iluminación que permite operar 4 LEDs mediante 4 botones, con 3 modos de operación diferentes.

### Características Principales
- Control individual de 4 LEDs
- 3 modos de operación intercambiables
- Debounce implementado en todos los botones
- Detección de presión larga para cambio de modo
- Feedback visual y por serial

---

## Arquitectura del Sistema

### Diagrama de Bloques

```
┌─────────────────────────────────────────────────────────────┐
│                      SISTEMA                                │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ┌──────────┐      ┌──────────────┐      ┌──────────┐     │
│  │ ENTRADAS │      │   LÓGICA     │      │ SALIDAS  │     │
│  │          │      │              │      │          │     │
│  │  BTN1 ───┼──────┤              ├──────┼─── LED1  │     │
│  │  BTN2 ───┼──────┤   ARDUINO    ├──────┼─── LED2  │     │
│  │  BTN3 ───┼──────┤   (FSM)      ├──────┼─── LED3  │     │
│  │  BTN4 ───┼──────┤              ├──────┼─── LED4  │     │
│  │          │      │              │      │          │     │
│  └──────────┘      └──────────────┘      └──────────┘     │
│                           │                                │
│                           │                                │
│                    ┌──────┴──────┐                        │
│                    │   SERIAL    │                        │
│                    │   MONITOR   │                        │
│                    └─────────────┘                        │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Máquina de Estados

```
                    ┌─────────────────────┐
                    │                     │
        ┌───────────▼───────────┐        │
        │                       │        │
        │    MODE_INDIVIDUAL    │        │
        │    (Estado Inicial)   │        │
        │                       │        │
        └───────────┬───────────┘        │
                    │                     │
          Long Press BTN1                │
                    │                     │
        ┌───────────▼───────────┐        │
        │                       │        │
        │     MODE_SEQUENCE     │        │
        │                       │        │
        └───────────┬───────────┘        │
                    │                     │
          Long Press BTN1                │
                    │                     │
        ┌───────────▼───────────┐        │
        │                       │        │
        │    MODE_INTENSITY     │────────┘
        │                       │  Long Press BTN1
        └───────────────────────┘
```

---

## Hardware

### Especificaciones de Componentes

| Componente | Especificación | Función |
|------------|----------------|---------|
| Arduino Uno R3 | ATmega328P @ 16MHz | Microcontrolador |
| LED Rojo | 2V, 20mA | Indicador 1 |
| LED Amarillo | 2V, 20mA | Indicador 2 |
| LED Verde | 2.2V, 20mA | Indicador 3 |
| LED Azul | 3.2V, 20mA | Indicador 4 |
| Resistencias | 220Ω ±5% | Limitadoras de corriente |
| Pulsadores | NO, 12mm | Entradas de usuario |

### Cálculo de Resistencias

Para un LED típico con Arduino (5V):

```
R = (Vcc - Vled) / I
R = (5V - 2V) / 20mA
R = 150Ω (mínimo)

Usamos 220Ω por seguridad:
I = (5V - 2V) / 220Ω = 13.6mA ✓
```

### Consumo de Corriente

| Estado | Corriente | Notas |
|--------|-----------|-------|
| Reposo | ~50mA | Solo Arduino |
| 1 LED | ~64mA | +14mA por LED |
| 4 LEDs | ~106mA | Todos encendidos |

---

## Software

### Estructura del Código

```
panel-control.ino
│
├── CONSTANTES
│   ├── Pines
│   ├── Tiempos
│   └── Velocidades
│
├── ENUMERACIONES
│   └── OperationMode
│
├── ESTRUCTURAS
│   └── Button
│
├── VARIABLES GLOBALES
│   ├── Estados
│   └── Timers
│
├── setup()
│   ├── Inicializar pines
│   ├── Inicializar botones
│   └── Serial begin
│
├── loop()
│   ├── checkModeChange()
│   └── switch(currentMode)
│       ├── modeIndividual()
│       ├── modeSequence()
│       └── modeIntensity()
│
└── FUNCIONES AUXILIARES
    ├── checkButtonPress()
    ├── allLedsOff()
    ├── allLedsOn()
    ├── blinkAllLeds()
    └── printCurrentMode()
```

### Algoritmo de Debounce

```cpp
bool checkButtonPress(int btnIndex) {
    bool pressed = false;
    int reading = digitalRead(BTN_PINS[btnIndex]);

    // 1. Detectar cambio
    if (reading != buttons[btnIndex].lastState) {
        buttons[btnIndex].lastDebounce = millis();
    }

    // 2. Verificar estabilidad (50ms)
    if ((millis() - buttons[btnIndex].lastDebounce) > DEBOUNCE_DELAY) {
        if (reading != buttons[btnIndex].state) {
            buttons[btnIndex].state = reading;

            // 3. Solo flanco de bajada
            if (buttons[btnIndex].state == LOW) {
                pressed = true;
            }
        }
    }

    buttons[btnIndex].lastState = reading;
    return pressed;
}
```

### Detección de Presión Larga

```cpp
// Inicio de presión
if (reading == LOW && state == HIGH) {
    pressStart = millis();
}

// Verificar duración
if (reading == LOW && pressStart != 0) {
    if ((millis() - pressStart) > LONG_PRESS_TIME) {
        // Presión larga detectada
        changeMode();
    }
}
```

---

## Modos de Operación

### Modo 0: Individual

| Entrada | Acción | Salida |
|---------|--------|--------|
| BTN1 (corto) | Toggle | LED1 cambia estado |
| BTN2 | Toggle | LED2 cambia estado |
| BTN3 | Toggle | LED3 cambia estado |
| BTN4 | Toggle | LED4 cambia estado |
| BTN1 (largo) | Cambio de modo | → Modo 1 |

### Modo 1: Secuencia

| Entrada | Acción | Efecto |
|---------|--------|--------|
| BTN1 (corto) | Iniciar | Comienza secuencia |
| BTN2 | Detener | Para y apaga LEDs |
| BTN3 | Dirección | Invierte sentido |
| BTN4 | Pausa | Congela/Continúa |
| BTN1 (largo) | Cambio de modo | → Modo 2 |

### Modo 2: Intensidad

| Entrada | Acción | Rango |
|---------|--------|-------|
| BTN3 | +Velocidad | Min: 50ms |
| BTN4 | -Velocidad | Max: 500ms |
| BTN1 (largo) | Cambio de modo | → Modo 0 |

---

## Diagramas

### Diagrama de Tiempo (Debounce)

```
Lectura real:     ┌─┐┌┐┌─┐     ┌───────────────────
                  │ ││││ │     │
              ────┘ └┘└┘ └─────┘

Tiempo:       |←─ rebotes ─→|←─ estable ─→|

lastDebounce: ↑   ↑ ↑ ↑      ↑

Estado
confirmado:   ─────────────────┐
                               │
              ─────────────────┘
                               ↑
                        (después de 50ms estable)
```

### Diagrama de Secuencia

```
Tiempo →
        ┌───┐       ┌───┐       ┌───┐       ┌───┐
LED1    │   │       │   │       │   │       │   │
        └───┘       └───┘       └───┘       └───┘
            ┌───┐       ┌───┐       ┌───┐
LED2        │   │       │   │       │   │
            └───┘       └───┘       └───┘
                ┌───┐       ┌───┐       ┌───┐
LED3            │   │       │   │       │   │
                └───┘       └───┘       └───┘
                    ┌───┐       ┌───┐       ┌───┐
LED4                │   │       │   │       │   │
                    └───┘       └───┘       └───┘
        |←─200ms─→|
```

---

## Pruebas

### Lista de Verificación

#### Modo Individual
- [ ] BTN1 hace toggle de LED1
- [ ] BTN2 hace toggle de LED2
- [ ] BTN3 hace toggle de LED3
- [ ] BTN4 hace toggle de LED4
- [ ] No hay rebotes (un toggle por pulsación)

#### Modo Secuencia
- [ ] BTN1 inicia secuencia
- [ ] BTN2 detiene y apaga
- [ ] BTN3 invierte dirección
- [ ] BTN4 pausa/continúa
- [ ] Secuencia fluida sin parpadeos

#### Modo Intensidad
- [ ] BTN3 acelera parpadeo
- [ ] BTN4 ralentiza parpadeo
- [ ] Límites respetados (50-500ms)
- [ ] Todos los LEDs sincrónicos

#### General
- [ ] Presión larga cambia modo
- [ ] 3 parpadeos al cambiar modo
- [ ] Serial muestra información correcta

---

## Problemas Conocidos

### 1. Sensibilidad de Presión Larga

**Problema**: A veces la presión larga no se detecta.

**Causa**: El tiempo de 2000ms puede ser difícil de mantener.

**Solución**: Reducir a 1500ms si es necesario.

```cpp
const unsigned long LONG_PRESS_TIME = 1500;  // Más accesible
```

### 2. Velocidad Máxima en Intensidad

**Problema**: A 50ms el parpadeo puede ser imperceptible.

**Causa**: El ojo humano no distingue cambios tan rápidos.

**Solución**: Aumentar el mínimo a 100ms.

```cpp
const unsigned long SPEED_MIN = 100;
```

---

## Mejoras Futuras

1. **EEPROM**: Guardar el último modo y restaurar al reiniciar
2. **PWM**: Usar analogWrite() para intensidad real
3. **Buzzer**: Agregar feedback sonoro
4. **LCD**: Mostrar modo actual en pantalla
5. **IR Remote**: Control remoto para cambiar modos

---

## Referencias

- [Arduino Reference: digitalRead()](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/)
- [Arduino Reference: millis()](https://www.arduino.cc/reference/en/language/functions/time/millis/)
- [Debounce Tutorial](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce)

---

## Autor

**Bootcamp Arduino - Semana 02**  
Entradas y Salidas Digitales
