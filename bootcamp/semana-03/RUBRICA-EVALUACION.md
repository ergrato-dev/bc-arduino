# 📋 Rúbrica de Evaluación - Semana 3

> Criterios detallados para evaluar las prácticas y el proyecto semanal

---

## 📊 Resumen de Puntuación

| Componente | Peso | Puntos Máximos |
|------------|------|----------------|
| Ejercicios Prácticos | 40% | 40 |
| Proyecto Semanal | 40% | 40 |
| Calidad del Código | 20% | 20 |
| **Total** | **100%** | **100** |

---

## 💻 Ejercicios Prácticos (40 puntos)

### Práctica 1: LED Fade Básico (10 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| Circuito correcto | 2 | LED con resistencia en pin PWM |
| Código compila | 2 | Sin errores ni warnings |
| Efecto fade funciona | 3 | Transición suave visible |
| Uso de millis() | 2 | Implementación no bloqueante |
| Documentación | 1 | Comentarios explicativos |

### Práctica 2: Control RGB (10 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| Circuito correcto | 2 | RGB con 3 resistencias, cátodo a GND |
| Código compila | 2 | Sin errores ni warnings |
| Colores correctos | 3 | Al menos 5 colores distinguibles |
| Transiciones suaves | 2 | Cambio gradual entre colores |
| Documentación | 1 | Comentarios explicativos |

### Práctica 3: Control con Potenciómetro (10 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| Circuito correcto | 2 | Pot conectado a pin analógico |
| Código compila | 2 | Sin errores ni warnings |
| Mapeo correcto | 3 | Uso de map() de 0-1023 a 0-255 |
| Respuesta en tiempo real | 2 | Brillo cambia al girar pot |
| Documentación | 1 | Comentarios explicativos |

### Práctica 4: Melodía con Buzzer (10 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| Circuito correcto | 2 | Buzzer pasivo en pin digital |
| Código compila | 2 | Sin errores ni warnings |
| Notas correctas | 3 | Frecuencias musicales precisas |
| Melodía reconocible | 2 | Secuencia coherente |
| Documentación | 1 | Comentarios explicativos |

---

## 🔨 Proyecto Semanal: Lámpara RGB (40 puntos)

### Funcionalidad (25 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| **Modo Estático** | 5 | Muestra color fijo seleccionable |
| **Modo Respiración** | 5 | Fade in/out suave del color actual |
| **Modo Arcoíris** | 5 | Transición continua por espectro |
| **Modo Fiesta** | 5 | Cambios rápidos aleatorios |
| **Control de brillo** | 5 | Potenciómetro ajusta intensidad |

### Hardware (10 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| LED RGB conectado | 3 | Con resistencias apropiadas |
| Botones funcionales | 3 | Debounce implementado |
| Potenciómetro conectado | 2 | Terminal central a A0 |
| Buzzer conectado | 2 | Feedback sonoro al cambiar |

### Extras (5 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| Feedback sonoro | 2 | Tonos al cambiar modo/color |
| Serial Monitor info | 2 | Muestra estado actual |
| Extensión adicional | 1 | Funcionalidad extra creativa |

---

## 📝 Calidad del Código (20 puntos)

### Estructura y Organización (8 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| Secciones claras | 2 | Separación con comentarios |
| Funciones modulares | 3 | Responsabilidad única |
| Orden lógico | 1 | Flujo coherente |
| Sin código muerto | 2 | No hay código comentado innecesario |

### Nomenclatura (6 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| Variables en inglés | 2 | camelCase: `ledPin`, `brightness` |
| Constantes UPPER_CASE | 2 | `LED_PIN`, `MAX_VALUE` |
| Nombres descriptivos | 2 | Significado claro sin abreviaturas |

### Documentación (6 puntos)

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| Encabezado del proyecto | 2 | Qué, para qué, cómo |
| Comentarios en funciones | 2 | Propósito de cada función |
| Comentarios inline | 2 | Explicación de lógica compleja |

---

## ⭐ Niveles de Desempeño

### Escala General

| Nivel | Rango | Descripción |
|-------|-------|-------------|
| **Excelente** | 90-100 | Supera expectativas, código ejemplar |
| **Bueno** | 80-89 | Cumple todos los requisitos |
| **Satisfactorio** | 70-79 | Cumple requisitos mínimos |
| **En desarrollo** | 60-69 | Requiere mejoras significativas |
| **Insuficiente** | <60 | No cumple requisitos mínimos |

### Criterio de Aprobación

- **Mínimo para aprobar**: 70 puntos
- **Requisito obligatorio**: Proyecto funcional

---

## 🚫 Penalizaciones

| Infracción | Penalización |
|------------|--------------|
| Código no compila | -10 puntos |
| Plagio detectado | -100% (reprobado) |
| Entrega tardía (por día) | -5 puntos |
| Sin documentación | -5 puntos |
| Uso de delay() en proyecto | -3 puntos |
| Variables en español | -2 puntos |

---

## 🏆 Bonificaciones

| Logro | Bonificación |
|-------|--------------|
| Extensión creativa implementada | +5 puntos |
| Código excepcionalmente limpio | +3 puntos |
| Documentación ejemplar | +2 puntos |
| Video demostrativo de calidad | +2 puntos |

> **Nota**: La puntuación máxima con bonificaciones es 112/100

---

## 📤 Formato de Entrega

### Archivos Requeridos

```
entrega-semana-03/
├── practicas/
│   ├── practica-01-fade.ino
│   ├── practica-02-rgb.ino
│   ├── practica-03-pot.ino
│   └── practica-04-buzzer.ino
├── proyecto/
│   ├── lampara_rgb.ino
│   ├── circuito.png          # Foto o screenshot
│   └── demo.mp4              # Video 30s (opcional pero recomendado)
└── README.md                  # Notas personales (opcional)
```

### Formato del Video Demostrativo

- **Duración**: 30-60 segundos
- **Contenido**: Mostrar todos los modos funcionando
- **Calidad**: Mínimo 720p
- **Audio**: Que se escuche el buzzer

---

## ✅ Checklist del Evaluador

### Para cada práctica:
- [ ] ¿El código compila sin errores?
- [ ] ¿El circuito está correctamente conectado?
- [ ] ¿La funcionalidad esperada se cumple?
- [ ] ¿Hay comentarios explicativos?
- [ ] ¿Se siguen las convenciones de nomenclatura?

### Para el proyecto:
- [ ] ¿Todos los modos funcionan correctamente?
- [ ] ¿El potenciómetro controla el brillo?
- [ ] ¿Los botones responden con debounce?
- [ ] ¿Hay feedback sonoro?
- [ ] ¿Se usa millis() en lugar de delay()?
- [ ] ¿El código está bien documentado?

---

## 📞 Soporte

Si tienes dudas sobre los criterios de evaluación:

1. Revisa la documentación de la semana
2. Consulta el glosario de términos
3. Pregunta en el foro del bootcamp
4. Contacta al instructor

---

> 💡 **Recuerda**: El objetivo no es solo obtener puntos, sino aprender. Un código bien documentado y funcional demuestra verdadera comprensión del tema.
