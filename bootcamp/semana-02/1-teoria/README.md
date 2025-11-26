# 📚 Teoría - Semana 02

> **Entradas y Salidas Digitales**  
> Tiempo total estimado: 1 hora 40 minutos

---

## 📋 Módulos

| # | Módulo | Tiempo | Descripción |
|---|--------|--------|-------------|
| 01 | [Fundamentos de I/O Digital](./01-fundamentos-io-digital.md) | 20 min | Estados HIGH/LOW, pinMode, digitalRead, digitalWrite |
| 02 | [Resistencias Pull-up y Pull-down](./02-resistencias-pull-up-down.md) | 25 min | Pin flotante, pull-up/down externos, INPUT_PULLUP |
| 03 | [Debouncing](./03-debouncing.md) | 25 min | Rebote mecánico, solución con millis() |
| 04 | [Máquinas de Estados](./04-maquinas-de-estados.md) | 30 min | FSM con enum y switch-case |

---

## 🎯 Objetivos de Aprendizaje

Al completar esta sección teórica serás capaz de:

### Fundamentos (Módulo 01)
- [ ] Diferenciar señales digitales de analógicas
- [ ] Configurar pines como entrada/salida
- [ ] Usar `pinMode()`, `digitalRead()`, `digitalWrite()`

### Resistencias (Módulo 02)
- [ ] Identificar el problema del pin flotante
- [ ] Implementar pull-up y pull-down externos
- [ ] Usar `INPUT_PULLUP` para simplificar circuitos

### Debounce (Módulo 03)
- [ ] Comprender el rebote mecánico
- [ ] Implementar debounce con `millis()`
- [ ] Evitar `delay()` para código no bloqueante

### FSM (Módulo 04)
- [ ] Diseñar máquinas de estados simples
- [ ] Implementar FSM con `enum` y `switch-case`
- [ ] Aplicar FSM a problemas de control

---

## 📖 Orden de Estudio Recomendado

```
┌─────────────────────────────────────────────────────────────┐
│                                                             │
│   01 Fundamentos ──► 02 Resistencias ──► 03 Debounce       │
│        │                   │                  │             │
│        ▼                   ▼                  ▼             │
│   Entender I/O       Conexiones          Lecturas           │
│   básico             correctas           estables           │
│                                                             │
│                            │                                │
│                            ▼                                │
│                    04 Máquinas de Estados                   │
│                            │                                │
│                            ▼                                │
│                    Sistemas complejos                       │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 💡 Conceptos Clave

### Estados Digitales
```
HIGH = 5V = 1 = Encendido
LOW  = 0V = 0 = Apagado
```

### Funciones Principales
```cpp
pinMode(pin, modo);        // INPUT, OUTPUT, INPUT_PULLUP
digitalRead(pin);          // Retorna HIGH o LOW
digitalWrite(pin, estado); // Envía HIGH o LOW
```

### Patrón de Debounce
```cpp
if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    // Estado estable
}
```

### Patrón FSM
```cpp
enum State { STATE_A, STATE_B };
State currentState = STATE_A;

switch (currentState) {
    case STATE_A: /* acciones */ break;
    case STATE_B: /* acciones */ break;
}
```

---

## 📚 Recursos de Apoyo

### Diagramas (en `/0-assets/`)
- `01-digital-io-estados.svg` - Estados HIGH/LOW
- `02-pull-down-circuito.svg` - Pull-down externo
- `03-pull-up-circuito.svg` - Pull-up externo
- `04-input-pullup-interno.svg` - Pull-up interno
- `05-debouncing-diagrama.svg` - Problema y solución
- `07-maquina-estados.svg` - Diagrama FSM

### Referencias Oficiales
- [Arduino Digital Pins](https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins)
- [Arduino Reference](https://www.arduino.cc/reference/en/)

---

## ✅ Checklist de Teoría

- [ ] Leí el Módulo 01: Fundamentos de I/O Digital
- [ ] Leí el Módulo 02: Resistencias Pull-up y Pull-down
- [ ] Leí el Módulo 03: Debouncing
- [ ] Leí el Módulo 04: Máquinas de Estados
- [ ] Completé las autoevaluaciones de cada módulo
- [ ] Revisé los diagramas de referencia

---

## ➡️ Siguiente Sección

[Prácticas: Ejercicios Guiados →](../2-practicas/README.md)
