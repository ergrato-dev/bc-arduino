# Módulo 4: Generación de Sonido

> ⏱️ Tiempo estimado: 10 minutos

---

## 🎯 Objetivos

- Usar la función `tone()` para generar sonidos
- Entender la diferencia entre buzzer activo y pasivo
- Crear melodías simples

---

## 🔊 Tipos de Buzzer

### Comparación

| Característica    | Buzzer Activo    | Buzzer Pasivo       |
| ----------------- | ---------------- | ------------------- |
| Oscilador interno | ✅ Sí            | ❌ No               |
| Control           | Solo ON/OFF      | Frecuencia variable |
| Tonos             | Solo uno (fijo)  | Múltiples           |
| Precio            | Más caro         | Más barato          |
| Función Arduino   | `digitalWrite()` | `tone()`            |

### Identificación Visual

```
Buzzer ACTIVO:
- Tiene etiqueta o marca
- A veces tiene circuito visible
- Suena al aplicar solo voltaje

Buzzer PASIVO:
- Sin circuito adicional
- Necesita señal de frecuencia
- Parece un speaker pequeño
```

---

## 🎵 La Función tone()

### Sintaxis

```cpp
tone(pin, frequency);           // Tono continuo
tone(pin, frequency, duration); // Tono por X milisegundos
noTone(pin);                    // Detener tono
```

| Parámetro   | Descripción              | Rango    |
| ----------- | ------------------------ | -------- |
| `pin`       | Pin digital (cualquiera) | 0-13     |
| `frequency` | Frecuencia en Hz         | 31-65535 |
| `duration`  | Duración en ms           | Opcional |

### Ejemplo Básico

```cpp
/*
 * Beep Simple
 *
 * ¿Qué hace? Genera un beep de 1 segundo
 * ¿Para qué? Alertas, confirmación de acciones
 * ¿Cómo? tone() con frecuencia de 1000 Hz
 *
 * Conexión: Buzzer pasivo entre pin 8 y GND
 * Compatible con Tinkercad ✅
 */

const int BUZZER_PIN = 8;

void setup() {
    // No requiere configuración especial
}

void loop() {
    // Beep de 1 segundo
    tone(BUZZER_PIN, 1000, 1000);  // 1000 Hz por 1000 ms
    delay(2000);  // Esperar 2 segundos antes de repetir
}
```

---

## 🎼 Notas Musicales

### Frecuencias Estándar (Octava 4)

| Nota | Nombre    | Frecuencia (Hz) |
| ---- | --------- | --------------- |
| C4   | Do        | 262             |
| D4   | Re        | 294             |
| E4   | Mi        | 330             |
| F4   | Fa        | 349             |
| G4   | Sol       | 392             |
| A4   | La        | 440             |
| B4   | Si        | 494             |
| C5   | Do (alto) | 523             |

### Definición de Constantes

```cpp
// Notas musicales (frecuencias en Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// Silencio
#define REST     0
```

---

## 🎹 Escala Musical

```cpp
/*
 * Escala Musical DO-RE-MI
 *
 * ¿Qué hace? Toca una escala musical completa
 * ¿Para qué? Aprender a generar melodías
 * ¿Cómo? Array de frecuencias + loop
 */

const int BUZZER_PIN = 8;

// Notas de la escala
int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
int noteDuration = 250;  // Duración de cada nota en ms

void setup() {
    // Tocar escala una vez
    for (int i = 0; i < 8; i++) {
        tone(BUZZER_PIN, melody[i], noteDuration);
        delay(noteDuration + 50);  // Pequeña pausa entre notas
    }
    noTone(BUZZER_PIN);
}

void loop() {
    // Nada que repetir
}
```

---

## 🎶 Melodías Famosas

### Cumpleaños Feliz (Fragmento)

```cpp
/*
 * Cumpleaños Feliz - Primeras notas
 */

const int BUZZER_PIN = 8;

// Notas
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440

void setup() {
    // "Happy Birthday to you"
    playNote(NOTE_C4, 150);
    playNote(NOTE_C4, 150);
    playNote(NOTE_D4, 300);
    playNote(NOTE_C4, 300);
    playNote(NOTE_F4, 300);
    playNote(NOTE_E4, 600);

    delay(300);

    // "Happy Birthday to you"
    playNote(NOTE_C4, 150);
    playNote(NOTE_C4, 150);
    playNote(NOTE_D4, 300);
    playNote(NOTE_C4, 300);
    playNote(NOTE_G4, 300);
    playNote(NOTE_F4, 600);
}

void loop() {
    // Melodía solo se toca una vez
}

void playNote(int frequency, int duration) {
    tone(BUZZER_PIN, frequency, duration);
    delay(duration + 50);
}
```

### Sonidos de Sistema

```cpp
/*
 * Sonidos de notificación comunes
 */

const int BUZZER_PIN = 8;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        char cmd = Serial.read();

        switch (cmd) {
            case '1':
                soundSuccess();
                break;
            case '2':
                soundError();
                break;
            case '3':
                soundWarning();
                break;
            case '4':
                soundNotification();
                break;
        }
    }
}

// Sonido de éxito (ascendente)
void soundSuccess() {
    tone(BUZZER_PIN, 523, 100);  // C5
    delay(100);
    tone(BUZZER_PIN, 659, 100);  // E5
    delay(100);
    tone(BUZZER_PIN, 784, 200);  // G5
    delay(200);
    noTone(BUZZER_PIN);
}

// Sonido de error (descendente)
void soundError() {
    tone(BUZZER_PIN, 400, 200);
    delay(200);
    tone(BUZZER_PIN, 300, 200);
    delay(200);
    tone(BUZZER_PIN, 200, 400);
    delay(400);
    noTone(BUZZER_PIN);
}

// Sonido de advertencia (intermitente)
void soundWarning() {
    for (int i = 0; i < 3; i++) {
        tone(BUZZER_PIN, 1000, 100);
        delay(200);
    }
    noTone(BUZZER_PIN);
}

// Sonido de notificación (corto)
void soundNotification() {
    tone(BUZZER_PIN, 1200, 50);
    delay(100);
    tone(BUZZER_PIN, 1500, 50);
    delay(50);
    noTone(BUZZER_PIN);
}
```

---

## ⚠️ Consideraciones

### Limitaciones de tone()

```cpp
// Solo puede generar UN tono a la vez
// Si llamas tone() en otro pin, detiene el anterior

tone(8, 440);   // Empieza en pin 8
tone(9, 880);   // Detiene pin 8, inicia en pin 9
```

### Interferencia con PWM

```cpp
// tone() usa Timer2 (igual que PWM en pines 3 y 11)
// Usar tone() puede afectar PWM en esos pines

// Solución: Usar otros pines PWM (5, 6, 9, 10)
```

### Buzzer vs Speaker

```cpp
// Buzzer: Solo frecuencias (sin volumen variable)
// Speaker: Puede reproducir audio real con DAC

// Arduino Uno solo tiene buzzer simple
// Para audio real: usar módulo DFPlayer o DAC externo
```

---

## 📝 Resumen

| Función               | Descripción       |
| --------------------- | ----------------- |
| `tone(pin, freq)`     | Tono continuo     |
| `tone(pin, freq, ms)` | Tono por duración |
| `noTone(pin)`         | Detener tono      |
| Rango útil            | 100-5000 Hz       |
| Timer usado           | Timer2            |

---

## ➡️ Siguiente Sección

[Prácticas →](../2-practicas/README.md)
