# Práctica 4: Melodía con Buzzer

> ⭐⭐⭐ Nivel: Avanzado · ⏱️ 25 minutos

---

## 🎯 Objetivo

Crear melodías usando un buzzer pasivo, aprendiendo a usar `tone()`, arrays de notas y duraciones.

---

## 📦 Materiales

| Componente | Cantidad |
|------------|----------|
| Arduino Uno | 1 |
| Buzzer pasivo | 1 |
| Protoboard | 1 |
| Cables jumper | 2 |

---

## 🔌 Diagrama de Conexión

```
    Arduino Uno              Buzzer Pasivo
    ┌─────────────┐         ┌─────────┐
    │             │         │   (+)   │
    │          8  ├─────────┤    🔊   │
    │             │         │   (-)   │
    │         GND ├─────────┤         │
    └─────────────┘         └─────────┘

Nota: El pin positivo (+) del buzzer suele 
tener una marca o ser más largo
```

### Tabla de Conexiones

| Arduino | Buzzer |
|---------|--------|
| Pin 8 | Terminal + |
| GND | Terminal - |

---

## 💻 Código

### Parte 1: Notas Musicales

```cpp
/*
 * =================================================
 * PROYECTO: Melodía con Buzzer
 * =================================================
 * 
 * ¿Qué hace?
 * Toca melodías programadas usando un buzzer pasivo,
 * permitiendo crear secuencias de notas musicales.
 * 
 * ¿Para qué?
 * - Alertas sonoras personalizadas
 * - Proyectos musicales
 * - Retroalimentación auditiva
 * 
 * ¿Cómo funciona?
 * 1. Define frecuencias de notas como constantes
 * 2. Almacena melodía en arrays (notas + duraciones)
 * 3. Usa tone() para reproducir cada nota
 * 
 * Hardware: Buzzer pasivo en pin 8
 * Compatibilidad Tinkercad: ✅
 * =================================================
 */

// ==================================================
// DEFINICIÓN DE NOTAS (Frecuencias en Hz)
// ==================================================
#define NOTE_C4  262   // Do
#define NOTE_D4  294   // Re
#define NOTE_E4  330   // Mi
#define NOTE_F4  349   // Fa
#define NOTE_G4  392   // Sol
#define NOTE_A4  440   // La
#define NOTE_B4  494   // Si
#define NOTE_C5  523   // Do (octava alta)
#define NOTE_D5  587   // Re (octava alta)
#define NOTE_E5  659   // Mi (octava alta)
#define REST     0     // Silencio

// ==================================================
// DEFINICIÓN DE PINES
// ==================================================
const int BUZZER_PIN = 8;

// ==================================================
// SETUP
// ==================================================
void setup() {
    Serial.begin(9600);
    Serial.println("Reproductor de melodías");
    
    // Tocar escala como prueba
    playScale();
}

// ==================================================
// LOOP
// ==================================================
void loop() {
    // Menú por Serial
    if (Serial.available()) {
        char option = Serial.read();
        
        switch (option) {
            case '1':
                playScale();
                break;
            case '2':
                playMaryHadALittleLamb();
                break;
            case '3':
                playBeethoven();
                break;
            case '4':
                playSuperMario();
                break;
        }
    }
}

// ==================================================
// FUNCIONES DE MELODÍAS
// ==================================================

/**
 * Toca una nota con duración específica
 */
void playNote(int frequency, int duration) {
    if (frequency == REST) {
        delay(duration);
    } else {
        tone(BUZZER_PIN, frequency, duration);
        delay(duration);
    }
    // Pequeña pausa entre notas
    noTone(BUZZER_PIN);
    delay(50);
}

/**
 * Escala musical completa
 */
void playScale() {
    Serial.println("Tocando: Escala DO-RE-MI");
    
    int notes[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
                   NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
    
    for (int i = 0; i < 8; i++) {
        playNote(notes[i], 250);
    }
    
    // Escala descendente
    for (int i = 7; i >= 0; i--) {
        playNote(notes[i], 250);
    }
    
    noTone(BUZZER_PIN);
}
```

### Parte 2: Melodías Conocidas

```cpp
/**
 * Mary Had a Little Lamb
 */
void playMaryHadALittleLamb() {
    Serial.println("Tocando: Mary Had a Little Lamb");
    
    int melody[] = {
        NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4,
        NOTE_E4, NOTE_E4, NOTE_E4, REST,
        NOTE_D4, NOTE_D4, NOTE_D4, REST,
        NOTE_E4, NOTE_G4, NOTE_G4, REST,
        NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4,
        NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
        NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4,
        NOTE_C4
    };
    
    int durations[] = {
        300, 300, 300, 300,
        300, 300, 600, 300,
        300, 300, 600, 300,
        300, 300, 600, 300,
        300, 300, 300, 300,
        300, 300, 300, 300,
        300, 300, 300, 300,
        600
    };
    
    int length = sizeof(melody) / sizeof(melody[0]);
    
    for (int i = 0; i < length; i++) {
        playNote(melody[i], durations[i]);
    }
    
    noTone(BUZZER_PIN);
}

/**
 * Beethoven - Para Elisa (intro)
 */
void playBeethoven() {
    Serial.println("Tocando: Para Elisa (intro)");
    
    int melody[] = {
        NOTE_E5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5,
        NOTE_B4, NOTE_D5, NOTE_C5, NOTE_A4
    };
    
    int durations[] = {
        150, 150, 150, 150, 150,
        150, 150, 150, 400
    };
    
    int length = sizeof(melody) / sizeof(melody[0]);
    
    for (int i = 0; i < length; i++) {
        playNote(melody[i], durations[i]);
    }
    
    noTone(BUZZER_PIN);
}

/**
 * Super Mario Bros (intro simplificado)
 */
void playSuperMario() {
    Serial.println("Tocando: Super Mario (intro)");
    
    int melody[] = {
        NOTE_E5, NOTE_E5, REST, NOTE_E5,
        REST, NOTE_C5, NOTE_E5, REST,
        NOTE_G4, REST, REST, REST,
        NOTE_G4, REST, REST, REST
    };
    
    int durations[] = {
        150, 150, 150, 150,
        150, 150, 150, 150,
        150, 150, 150, 150,
        300, 150, 150, 150
    };
    
    int length = sizeof(melody) / sizeof(melody[0]);
    
    for (int i = 0; i < length; i++) {
        playNote(melody[i], durations[i]);
    }
    
    noTone(BUZZER_PIN);
}
```

---

## 🎼 Referencia de Notas

### Octava 4 (Central)

| Nota | Nombre | Frecuencia |
|------|--------|------------|
| C4 | Do | 262 Hz |
| D4 | Re | 294 Hz |
| E4 | Mi | 330 Hz |
| F4 | Fa | 349 Hz |
| G4 | Sol | 392 Hz |
| A4 | La | 440 Hz |
| B4 | Si | 494 Hz |

### Octava 5 (Alta)

| Nota | Nombre | Frecuencia |
|------|--------|------------|
| C5 | Do | 523 Hz |
| D5 | Re | 587 Hz |
| E5 | Mi | 659 Hz |
| F5 | Fa | 698 Hz |
| G5 | Sol | 784 Hz |

---

## 🧪 Pruebas

### Verificación

- [ ] Escala suena completa
- [ ] Las melodías son reconocibles
- [ ] No hay ruido entre notas
- [ ] El menú Serial funciona

### Experimentos

1. **Tempo**: Multiplica todas las duraciones por 0.5 (rápido) o 2 (lento)
2. **Transposición**: Suma o resta valor fijo a frecuencias
3. **Nueva melodía**: Crea tu propia secuencia de notas

---

## 🎯 Desafíos

<details>
<summary><strong>Desafío 1: Teclado musical</strong></summary>

Cada tecla del Serial toca una nota diferente.

```cpp
void loop() {
    if (Serial.available()) {
        char key = Serial.read();
        
        switch (key) {
            case 'a': tone(BUZZER_PIN, NOTE_C4); break;
            case 's': tone(BUZZER_PIN, NOTE_D4); break;
            case 'd': tone(BUZZER_PIN, NOTE_E4); break;
            case 'f': tone(BUZZER_PIN, NOTE_F4); break;
            case 'g': tone(BUZZER_PIN, NOTE_G4); break;
            case 'h': tone(BUZZER_PIN, NOTE_A4); break;
            case 'j': tone(BUZZER_PIN, NOTE_B4); break;
            case 'k': tone(BUZZER_PIN, NOTE_C5); break;
            case ' ': noTone(BUZZER_PIN); break;
        }
    }
}
```
</details>

<details>
<summary><strong>Desafío 2: Sirena de policía</strong></summary>

Efecto de sirena con barrido de frecuencia.

```cpp
void policeSiren() {
    // Subida
    for (int freq = 400; freq <= 800; freq += 10) {
        tone(BUZZER_PIN, freq);
        delay(10);
    }
    
    // Bajada
    for (int freq = 800; freq >= 400; freq -= 10) {
        tone(BUZZER_PIN, freq);
        delay(10);
    }
}

void loop() {
    policeSiren();
}
```
</details>

---

## ❓ Solución de Problemas

| Problema | Causa | Solución |
|----------|-------|----------|
| Sin sonido | Buzzer activo | Usar buzzer pasivo |
| Sonido débil | Polaridad incorrecta | Invertir conexión |
| Ruido entre notas | Sin pausa | Agregar noTone() y delay |
| Frecuencia incorrecta | Error en define | Verificar frecuencias |

---

## 📝 Conceptos Aprendidos

- ✅ Uso de `tone()` y `noTone()`
- ✅ Definición de constantes con `#define`
- ✅ Arrays para almacenar melodías
- ✅ Relación frecuencia-nota musical

---

## ➡️ Siguiente Sección

[Proyecto Semanal →](../3-proyecto/README.md)
