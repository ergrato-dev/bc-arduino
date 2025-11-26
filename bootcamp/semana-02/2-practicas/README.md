# 🔬 Prácticas - Semana 02

> **Entradas y Salidas Digitales**  
> Tiempo total estimado: 1.5 horas

---

## 📋 Ejercicios

| # | Práctica | Tiempo | Dificultad | Tinkercad |
|---|----------|--------|------------|-----------|
| 01 | [Botón y LED Básico](./01-boton-led-basico.md) | 20 min | ⭐ Básico | ✅ |
| 02 | [Toggle LED con Debounce](./02-toggle-led-debounce.md) | 25 min | ⭐⭐ Intermedio | ✅ |
| 03 | [Contador de Pulsaciones](./03-contador-pulsaciones.md) | 25 min | ⭐⭐ Intermedio | ✅ |
| 04 | [Control Múltiples LEDs](./04-control-multiples-leds.md) | 20 min | ⭐⭐⭐ Avanzado | ✅ |

---

## 🎯 Objetivos de las Prácticas

Al completar estos ejercicios serás capaz de:

- [ ] Conectar botones con INPUT_PULLUP
- [ ] Implementar debounce funcional con millis()
- [ ] Crear sistemas de conteo confiables
- [ ] Manejar múltiples entradas y salidas
- [ ] Aplicar patrones de código reutilizables

---

## 🛠️ Materiales Necesarios

### Para Tinkercad (Simulación)
- Arduino Uno R3
- Protoboard
- LEDs (varios colores)
- Resistencias 220Ω (para LEDs)
- Pulsadores (Push buttons)
- Cables de conexión

### Para Hardware Físico (Opcional)
Los mismos componentes más:
- Cable USB para programar
- Arduino IDE instalado

---

## 📐 Esquema de Conexiones Base

```
CONEXIÓN TÍPICA: BOTÓN + LED

Arduino Uno R3
┌─────────────────────────────────────┐
│                                     │
│   Pin 13 ──[220Ω]──►LED──┐         │
│                          │         │
│   Pin 2 ─────────────────┼─BTN─┐   │
│                          │     │   │
│   GND ───────────────────┴─────┘   │
│                                     │
└─────────────────────────────────────┘

Notas:
- LED: Ánodo (+) a resistencia, Cátodo (-) a GND
- Botón: Un terminal a Pin, otro a GND
- INPUT_PULLUP elimina necesidad de resistencia en botón
```

---

## 📝 Flujo de Trabajo Recomendado

```
Para cada práctica:

1. 📖 Leer objetivos y teoría relacionada
         │
         ▼
2. 🔌 Armar circuito en Tinkercad
         │
         ▼
3. 💻 Escribir código paso a paso
         │
         ▼
4. 🧪 Probar y depurar
         │
         ▼
5. 📊 Verificar con Serial Monitor
         │
         ▼
6. ✅ Completar desafíos extras
```

---

## 💡 Tips para las Prácticas

### En Tinkercad
- Usa el botón "Start Simulation" para probar
- El Serial Monitor está en la parte inferior
- Puedes pausar la simulación para revisar conexiones

### Debugging
```cpp
// Agrega mensajes de debug para entender el flujo
Serial.println("Estado actual: " + String(buttonState));
Serial.println("Tiempo: " + String(millis()));
```

### Errores Comunes
1. **LED no enciende**: Verificar polaridad y resistencia
2. **Botón no responde**: Verificar INPUT_PULLUP y conexión a GND
3. **Lecturas erráticas**: Falta debounce
4. **Toggle no funciona**: Detectar flanco, no estado

---

## ✅ Checklist de Prácticas

- [ ] Práctica 01: Botón y LED Básico completada
- [ ] Práctica 02: Toggle LED con Debounce completada
- [ ] Práctica 03: Contador de Pulsaciones completada
- [ ] Práctica 04: Control Múltiples LEDs completada
- [ ] Todos los desafíos extras intentados

---

## 📊 Criterios de Evaluación

| Criterio | Peso | Descripción |
|----------|------|-------------|
| Funcionalidad | 40% | El circuito y código funcionan correctamente |
| Código limpio | 30% | Nomenclatura, estructura, comentarios |
| Debounce | 20% | Implementación correcta sin delay() |
| Desafíos | 10% | Completar retos adicionales |

---

## ➡️ Comenzar

[Práctica 01: Botón y LED Básico →](./01-boton-led-basico.md)
