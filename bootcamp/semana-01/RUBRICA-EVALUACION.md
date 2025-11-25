# 📊 Rúbrica de Evaluación - Semana 01

> **Introducción a Arduino y Electrónica Básica**  
> Total: 100 puntos | Nivel: Principiante

---

## 📋 Distribución de Puntos

| Componente          | Peso     | Puntos  |
| ------------------- | -------- | ------- |
| Teoría              | 20%      | 20      |
| Prácticas (4)       | 40%      | 40      |
| Proyecto Integrador | 40%      | 40      |
| **TOTAL**           | **100%** | **100** |

---

## 1️⃣ Evaluación Teórica (20 pts)

### Comprensión de Conceptos (10 pts)

| Criterio           | Puntos | Descripción                                                                   |
| ------------------ | ------ | ----------------------------------------------------------------------------- |
| Microcontroladores | 3      | Identifica qué es un microcontrolador y sus componentes principales           |
| Anatomía Arduino   | 3      | Reconoce los pines del Arduino Uno (digitales, analógicos, PWM, alimentación) |
| Electrónica Básica | 4      | Comprende Ley de Ohm y puede calcular resistencias para LEDs                  |

### Aplicación de Conocimientos (10 pts)

| Criterio                | Puntos | Descripción                                                |
| ----------------------- | ------ | ---------------------------------------------------------- |
| Cálculo de Resistencias | 4      | Calcula correctamente la resistencia necesaria para un LED |
| Lectura de Resistencias | 3      | Interpreta código de colores de resistencias               |
| Estructura de Código    | 3      | Explica el propósito de `setup()` y `loop()`               |

---

## 2️⃣ Prácticas (40 pts)

### Práctica 01: Blink LED Integrado (8 pts) ⭐

| Criterio      | Puntos | Excelente                           | Aceptable                    | Insuficiente     |
| ------------- | ------ | ----------------------------------- | ---------------------------- | ---------------- |
| Funcionalidad | 4      | LED parpadea correctamente          | Parpadea con errores menores | No funciona      |
| Código limpio | 2      | Bien documentado, constantes usadas | Documentación básica         | Sin comentarios  |
| Variaciones   | 2      | Implementa 2+ variaciones de tiempo | Implementa 1 variación       | Solo código base |

### Práctica 02: LED Externo con Resistencia (10 pts) ⭐⭐

| Criterio           | Puntos | Excelente                                   | Aceptable             | Insuficiente         |
| ------------------ | ------ | ------------------------------------------- | --------------------- | -------------------- |
| Circuito correcto  | 4      | Conexiones perfectas, resistencia calculada | Conexiones correctas  | Circuito con errores |
| Funcionalidad      | 3      | LED funciona según especificación           | Funciona parcialmente | No funciona          |
| Código documentado | 3      | Comentarios ¿qué?, ¿para qué?, ¿cómo?       | Comentarios básicos   | Sin documentación    |

### Práctica 03: Semáforo Básico (10 pts) ⭐⭐

| Criterio            | Puntos | Excelente                                 | Aceptable              | Insuficiente         |
| ------------------- | ------ | ----------------------------------------- | ---------------------- | -------------------- |
| Secuencia correcta  | 4      | Verde→Amarillo→Rojo con tiempos realistas | Secuencia funciona     | Secuencia incorrecta |
| Conexiones          | 3      | 3 LEDs con resistencias individuales      | Conexiones funcionales | Errores de conexión  |
| Organización código | 3      | Funciones separadas, constantes claras    | Código organizado      | Código desordenado   |

### Práctica 04: Patrón de Luces Personalizado (12 pts) ⭐⭐⭐

| Criterio       | Puntos | Excelente                         | Aceptable               | Insuficiente      |
| -------------- | ------ | --------------------------------- | ----------------------- | ----------------- |
| Creatividad    | 4      | Patrón original y elaborado       | Patrón funcional        | Patrón muy básico |
| Implementación | 4      | Código eficiente con arrays/loops | Implementación correcta | Código repetitivo |
| Documentación  | 4      | Explicación completa del patrón   | Documentación básica    | Sin explicación   |

---

## 3️⃣ Proyecto Integrador (40 pts)

### Proyecto: Secuenciador de LEDs "Knight Rider"

**Descripción:** Crear una secuencia de 6 LEDs que se iluminan de forma secuencial ida y vuelta, simulando el efecto del auto fantástico.

### Criterios de Evaluación

| Criterio               | Puntos | Descripción                                            |
| ---------------------- | ------ | ------------------------------------------------------ |
| **Funcionalidad**      | 15     |                                                        |
| - Secuencia ida        | 5      | LEDs se encienden de izquierda a derecha               |
| - Secuencia vuelta     | 5      | LEDs regresan de derecha a izquierda                   |
| - Fluidez              | 5      | Transiciones suaves, velocidad apropiada               |
| **Circuito**           | 10     |                                                        |
| - Conexiones correctas | 5      | 6 LEDs con resistencias, cables organizados            |
| - Diagrama documentado | 5      | Incluye diagrama o descripción de conexiones           |
| **Código**             | 10     |                                                        |
| - Uso de arrays        | 4      | Utiliza arrays para los pines de LEDs                  |
| - Estructura modular   | 3      | Funciones separadas para cada comportamiento           |
| - Comentarios          | 3      | Documentación completa (qué, para qué, cómo)           |
| **Extras**             | 5      |                                                        |
| - Velocidad variable   | 2      | Implementa cambio de velocidad                         |
| - Efectos adicionales  | 3      | Modos alternativos (todos encendidos, aleatorio, etc.) |

### Rúbrica Detallada del Proyecto

#### Funcionalidad (15 pts)

| Nivel        | Puntos | Descripción                                        |
| ------------ | ------ | -------------------------------------------------- |
| Excelente    | 13-15  | Secuencia perfecta, fluida, sin parpadeos extraños |
| Muy Bueno    | 10-12  | Secuencia correcta con mínimos defectos            |
| Bueno        | 7-9    | Funciona pero con errores visibles                 |
| Suficiente   | 4-6    | Parcialmente funcional                             |
| Insuficiente | 0-3    | No cumple la funcionalidad básica                  |

#### Circuito (10 pts)

| Nivel        | Puntos | Descripción                                   |
| ------------ | ------ | --------------------------------------------- |
| Excelente    | 9-10   | Circuito limpio, bien organizado, documentado |
| Muy Bueno    | 7-8    | Conexiones correctas, documentación básica    |
| Bueno        | 5-6    | Funcional pero desorganizado                  |
| Suficiente   | 3-4    | Funciona con errores menores                  |
| Insuficiente | 0-2    | Conexiones incorrectas o incompletas          |

#### Código (10 pts)

| Nivel        | Puntos | Descripción                              |
| ------------ | ------ | ---------------------------------------- |
| Excelente    | 9-10   | Código limpio, modular, bien documentado |
| Muy Bueno    | 7-8    | Buen código con documentación aceptable  |
| Bueno        | 5-6    | Código funcional, organización básica    |
| Suficiente   | 3-4    | Código funciona pero desorganizado       |
| Insuficiente | 0-2    | Código ilegible o no funcional           |

---

## 📈 Escala de Calificación

| Rango  | Calificación    | Descripción                                        |
| ------ | --------------- | -------------------------------------------------- |
| 90-100 | ⭐ Excelente    | Dominio completo, trabajo excepcional              |
| 80-89  | 🌟 Muy Bueno    | Comprensión sólida, buen desempeño                 |
| 70-79  | ✅ Bueno        | Cumple expectativas, áreas de mejora identificadas |
| 60-69  | ⚠️ Suficiente   | Conocimiento básico, necesita refuerzo             |
| 0-59   | ❌ Insuficiente | No cumple requisitos mínimos                       |

---

## 🎁 Bonificaciones y Penalizaciones

### Bonificaciones (Máximo +10 pts)

| Criterio                                             | Puntos Extra |
| ---------------------------------------------------- | ------------ |
| Implementación de efectos adicionales creativos      | +3           |
| Código excepcionalmente documentado                  | +2           |
| Uso de técnicas avanzadas (millis en lugar de delay) | +3           |
| Ayuda a compañeros documentada                       | +2           |

### Penalizaciones

| Criterio                                        | Puntos |
| ----------------------------------------------- | ------ |
| Entrega tardía (por día)                        | -10    |
| Código copiado sin atribución                   | -20    |
| Circuito no funcional sin intentos documentados | -5     |
| Falta de comentarios en código                  | -5     |

---

## ✅ Checklist de Entrega

### Prácticas

- [ ] Práctica 01 completada y probada en Tinkercad
- [ ] Práctica 02 completada con circuito y código
- [ ] Práctica 03 completada con secuencia de semáforo
- [ ] Práctica 04 completada con patrón personalizado
- [ ] Todos los códigos con comentarios

### Proyecto Integrador

- [ ] Enlace a proyecto en Tinkercad (público o compartido)
- [ ] Código fuente con documentación completa
- [ ] Descripción del funcionamiento
- [ ] Captura de pantalla o GIF del funcionamiento
- [ ] Lista de componentes utilizados

### Documentación

- [ ] Respuestas a preguntas teóricas
- [ ] Reflexión personal sobre el aprendizaje

---

## 📝 Notas para el Evaluador

### Al evaluar Tinkercad:

1. Verificar que la simulación inicie correctamente
2. Comprobar que no haya conexiones en corto
3. Validar que los LEDs no excedan corriente máxima
4. Revisar que el código compile sin errores

### Al evaluar código:

1. Priorizar funcionalidad sobre estilo
2. Valorar el uso de constantes sobre "números mágicos"
3. Verificar nomenclatura en inglés para código
4. Revisar documentación en español

### Criterios de simulación Tinkercad:

- ✅ Compatible: Arduino Uno R3, LEDs básicos, resistencias
- ⚠️ Limitación: No soporta todas las librerías
- 📝 Aceptar capturas si hay problemas de acceso

---

## 🔗 Referencias

- [README Semana 01](./README.md)
- [Proyecto Integrador](./3-proyecto/README.md)
- [Prácticas](./2-practicas/README.md)

---

<div align="center">

**Semana 01 - Rúbrica de Evaluación v1.0**

[⬅️ Anterior](../README.md) | [📋 Índice](../README.md) | [Siguiente ➡️](../semana-02/README.md)

</div>
