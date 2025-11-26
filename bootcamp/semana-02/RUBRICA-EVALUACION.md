# 📋 Rúbrica de Evaluación - Semana 02

> **Entradas y Salidas Digitales**  
> Sistema de evaluación por competencias (100 puntos)

---

## 📊 Distribución de Puntos

| Componente | Peso | Puntos | Descripción |
|------------|------|--------|-------------|
| **Conocimientos** | 30% | 30 | Comprensión teórica de I/O digital |
| **Habilidades** | 40% | 40 | Ejecución de prácticas |
| **Competencias** | 30% | 30 | Proyecto integrador |
| **TOTAL** | 100% | **100** | |

---

## 📚 Conocimientos (30 puntos)

### Teoría de Entradas/Salidas Digitales (10 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 10 | Explica diferencia INPUT/OUTPUT, estados HIGH/LOW, y flujo de corriente |
| Bueno | 8 | Comprende conceptos básicos con pequeñas imprecisiones |
| Suficiente | 6 | Conocimiento parcial, confunde algunos conceptos |
| Insuficiente | 0-5 | No demuestra comprensión de I/O digital |

### Resistencias Pull-Up/Pull-Down (10 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 10 | Explica estado flotante, diferencia pull-up/down, y cuándo usar cada una |
| Bueno | 8 | Comprende el concepto pero confunde aplicaciones |
| Suficiente | 6 | Conoce las resistencias pero no entiende el estado flotante |
| Insuficiente | 0-5 | No comprende el propósito de las resistencias |

### Técnicas de Debounce (10 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 10 | Explica rebote mecánico, implementa debounce por software correctamente |
| Bueno | 8 | Comprende el problema pero implementación con errores menores |
| Suficiente | 6 | Conoce el concepto pero no puede implementarlo |
| Insuficiente | 0-5 | No comprende qué es el rebote mecánico |

---

## 🔧 Habilidades Prácticas (40 puntos)

### Práctica 01: Lectura de Botón Simple (8 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 8 | Circuito correcto, código funcional, documentado |
| Bueno | 6-7 | Funciona con pequeños errores de documentación |
| Suficiente | 4-5 | Funciona parcialmente o tiene errores de conexión |
| Insuficiente | 0-3 | No funciona o circuito incorrecto |

### Práctica 02: Botón con Pull-Up Interno (8 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 8 | Usa INPUT_PULLUP correctamente, lógica invertida entendida |
| Bueno | 6-7 | Funciona pero no explica la lógica invertida |
| Suficiente | 4-5 | Configuración correcta pero comportamiento erróneo |
| Insuficiente | 0-3 | No implementa pull-up interno correctamente |

### Práctica 03: Toggle LED con Botón (12 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 12 | Toggle funciona perfectamente, debounce implementado |
| Bueno | 9-11 | Toggle funciona con rebotes ocasionales |
| Suficiente | 6-8 | Toggle inconsistente, sin debounce |
| Insuficiente | 0-5 | No logra implementar toggle |

### Práctica 04: Contador con Display Serial (12 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 12 | Contador funciona, debounce correcto, display en Serial Monitor |
| Bueno | 9-11 | Funciona con pequeños problemas de rebote |
| Suficiente | 6-8 | Cuenta pero tiene errores de debounce |
| Insuficiente | 0-5 | No implementa contador funcional |

---

## 🏆 Competencias - Proyecto Integrador (30 puntos)

### Proyecto: Sistema de Control de Iluminación

#### Funcionalidad (12 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 12 | Todas las funciones operativas: múltiples modos, botones responsivos |
| Bueno | 9-11 | Mayoría de funciones operan correctamente |
| Suficiente | 6-8 | Funcionalidad básica implementada |
| Insuficiente | 0-5 | Sistema no funcional o muy incompleto |

#### Calidad del Código (10 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 10 | Código modular, bien documentado, nombres descriptivos, debounce correcto |
| Bueno | 7-9 | Código funcional con documentación parcial |
| Suficiente | 4-6 | Código funciona pero desorganizado |
| Insuficiente | 0-3 | Código confuso, sin comentarios, malas prácticas |

#### Implementación de Debounce (8 pts)

| Criterio | Pts | Indicador |
|----------|-----|-----------|
| Excelente | 8 | Debounce por millis() implementado correctamente en todos los botones |
| Bueno | 6-7 | Debounce funciona pero usa delay() |
| Suficiente | 4-5 | Debounce parcial o inconsistente |
| Insuficiente | 0-3 | Sin debounce o implementación incorrecta |

---

## 📈 Escala de Calificación

| Nota | Rango | Descripción |
|------|-------|-------------|
| **A** | 90-100 | Excelente - Dominio completo de entradas/salidas digitales |
| **B** | 80-89 | Muy Bueno - Comprensión sólida con áreas menores de mejora |
| **C** | 70-79 | Bueno - Comprensión adecuada, necesita práctica |
| **D** | 60-69 | Suficiente - Conocimientos básicos, requiere refuerzo |
| **F** | < 60 | Insuficiente - No alcanza los objetivos mínimos |

---

## ✅ Checklist de Evaluación

### Conocimientos Teóricos
- [ ] Diferencia entre INPUT y OUTPUT
- [ ] Estados HIGH y LOW
- [ ] Concepto de estado flotante
- [ ] Diferencia entre pull-up y pull-down
- [ ] Uso de INPUT_PULLUP
- [ ] Problema del rebote mecánico
- [ ] Técnicas de debounce

### Habilidades Prácticas
- [ ] Práctica 01 completada y funcional
- [ ] Práctica 02 completada y funcional
- [ ] Práctica 03 completada con debounce
- [ ] Práctica 04 completada con contador

### Proyecto Integrador
- [ ] Circuito construido correctamente
- [ ] Código compilado sin errores
- [ ] Todas las funciones operativas
- [ ] Debounce implementado
- [ ] Código documentado

---

## 📝 Criterios de Entrega

### Formato de Entrega
1. **Circuitos en Tinkercad** - Enlaces compartibles
2. **Código fuente** - Archivos .ino comentados
3. **Documentación** - Breve descripción del funcionamiento

### Fechas
- **Prácticas 01-04:** Durante la semana
- **Proyecto:** Final de la semana

### Penalizaciones
- Entrega tardía: -10% por día
- Sin documentación: -15%
- Código sin comentarios: -10%

---

## 🎯 Objetivos de Aprendizaje Evaluados

| Objetivo | Evaluado en |
|----------|-------------|
| Configurar pines como entrada/salida | Prácticas 01-04, Proyecto |
| Leer estado de botones | Todas las prácticas |
| Implementar pull-up/pull-down | Prácticas 01-02, Proyecto |
| Aplicar técnicas de debounce | Prácticas 03-04, Proyecto |
| Crear sistemas interactivos | Proyecto integrador |

---

<div align="center">

**[⬅️ Volver a Semana 02](./README.md)**

</div>
