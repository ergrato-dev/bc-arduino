# Módulo 3: Motores y Actuadores con PWM

> ⏱️ Tiempo estimado: 15 minutos

---

## 🎯 Objetivos

- Controlar la velocidad de un motor DC
- Entender el uso de transistores como switch
- Implementar diodo de protección (flyback)

---

## ⚡ El Problema de los Motores

### Limitaciones de Arduino

Arduino **NO puede alimentar motores directamente** porque:

| Característica           | Arduino | Motor DC pequeño |
| ------------------------ | ------- | ---------------- |
| Corriente máxima por pin | 40 mA   | 100-500 mA       |
| Voltaje                  | 5V      | 3-12V            |

```
⚠️ Conectar un motor directamente puede dañar el Arduino
```

### La Solución: Transistores

Un **transistor** actúa como un "interruptor electrónico" que:

- Se controla con una señal pequeña (del Arduino)
- Permite pasar corriente grande (para el motor)

---

## 🔌 Circuito Básico con Transistor

### Componentes Necesarios

| Componente     | Valor           | Función                  |
| -------------- | --------------- | ------------------------ |
| Transistor NPN | TIP120 o 2N2222 | Switch de potencia       |
| Resistencia    | 1kΩ             | Limitar corriente a base |
| Diodo          | 1N4007          | Protección flyback       |
| Motor DC       | 5-12V           | Actuador                 |

### Diagrama de Conexión

```
                          +Vmotor (5V-12V)
                              │
                              │
                         ┌────┴────┐
                         │  DIODO  │
                         │ 1N4007  │
                         │ ◄──────►│
                         └────┬────┘
                              │
                    ┌─────────┴─────────┐
                    │                   │
                    │      MOTOR        │
                    │       (M)         │
                    │                   │
                    └─────────┬─────────┘
                              │
                              │ Colector (C)
                         ┌────┴────┐
    Pin PWM ───[1kΩ]─────┤   NPN   │
    Arduino              │ TIP120  │
                         └────┬────┘
                              │ Emisor (E)
                              │
                             GND (común Arduino + Motor)
```

---

## 💻 Código de Control

### Control de Velocidad Básico

```cpp
/*
 * Control de Velocidad Motor DC
 *
 * ¿Qué hace? Controla la velocidad de un motor DC usando PWM
 * ¿Para qué? Ventiladores, bombas, ruedas de robots
 * ¿Cómo? PWM al transistor que controla la corriente del motor
 *
 * Hardware:
 * - Motor DC 5V
 * - Transistor TIP120 o 2N2222
 * - Resistencia 1kΩ
 * - Diodo 1N4007
 *
 * Compatible con Tinkercad ✅
 */

const int MOTOR_PIN = 9;  // Pin PWM

void setup() {
    Serial.begin(9600);
    Serial.println("Control de Motor DC");
}

void loop() {
    // Velocidad mínima (motor apenas gira)
    Serial.println("Velocidad: 25%");
    analogWrite(MOTOR_PIN, 64);
    delay(2000);

    // Velocidad media
    Serial.println("Velocidad: 50%");
    analogWrite(MOTOR_PIN, 127);
    delay(2000);

    // Velocidad alta
    Serial.println("Velocidad: 75%");
    analogWrite(MOTOR_PIN, 191);
    delay(2000);

    // Velocidad máxima
    Serial.println("Velocidad: 100%");
    analogWrite(MOTOR_PIN, 255);
    delay(2000);

    // Detener motor
    Serial.println("Motor detenido");
    analogWrite(MOTOR_PIN, 0);
    delay(2000);
}
```

### Rampa de Aceleración

```cpp
/*
 * Aceleración suave del motor
 * Evita arranques bruscos que consumen mucha corriente
 */

const int MOTOR_PIN = 9;

void setup() {
    // Inicialización
}

void loop() {
    // Acelerar suavemente
    accelerate(0, 255, 2000);  // De 0 a 255 en 2 segundos
    delay(1000);

    // Desacelerar suavemente
    accelerate(255, 0, 2000);  // De 255 a 0 en 2 segundos
    delay(1000);
}

/**
 * Acelera o desacelera el motor suavemente
 *
 * @param startSpeed Velocidad inicial (0-255)
 * @param endSpeed   Velocidad final (0-255)
 * @param duration   Tiempo total en ms
 */
void accelerate(int startSpeed, int endSpeed, int duration) {
    int steps = abs(endSpeed - startSpeed);
    int stepDelay = duration / steps;
    int stepDirection = (endSpeed > startSpeed) ? 1 : -1;

    for (int speed = startSpeed;
         (stepDirection > 0) ? (speed <= endSpeed) : (speed >= endSpeed);
         speed += stepDirection) {
        analogWrite(MOTOR_PIN, speed);
        delay(stepDelay);
    }
}
```

---

## ⚠️ El Diodo Flyback

### ¿Por qué es necesario?

Los motores son **cargas inductivas**. Cuando se apagan:

1. El campo magnético colapsa
2. Genera un **pico de voltaje inverso** (hasta 100V+)
3. Este pico puede **destruir el transistor**

### Función del Diodo

```
Motor encendido:
    +V ──────► Motor ──────► Transistor ──► GND

Motor apagado (sin diodo):
    El motor genera voltaje inverso que viaja hacia el transistor
    ⚡ DAÑO AL TRANSISTOR

Motor apagado (con diodo):
    El diodo absorbe la corriente inversa
    La energía se disipa de forma segura
    ✅ TRANSISTOR PROTEGIDO
```

### Conexión del Diodo

```
El diodo se conecta en PARALELO con el motor
Con la banda (cátodo) hacia el +V

    +V ←──┬──────────────────┬──► Motor +
          │     ▼ Diodo      │
          └────────|◄────────┘
                   Motor -
```

---

## 🔋 Fuente de Alimentación

### Regla de Oro

```
⚠️ Siempre usar fuente EXTERNA para motores

Arduino 5V → Solo para señales y LEDs (max 500mA total)
Fuente externa → Para motores (1A o más)
```

### Conexión de GND Común

```
┌─────────────┐     ┌─────────────┐
│   ARDUINO   │     │   FUENTE    │
│             │     │   EXTERNA   │
│   Pin 9 ────┼─────┼───► Motor   │
│             │     │             │
│   GND ──────┼─────┼── GND ──────┤
└─────────────┘     └─────────────┘
                          │
                      IMPORTANTE:
                    GND debe ser común
```

---

## 📊 Tabla de Transistores Comunes

| Transistor | Tipo           | Corriente Max | Uso                |
| ---------- | -------------- | ------------- | ------------------ |
| 2N2222     | NPN            | 800 mA        | Motores pequeños   |
| TIP120     | NPN Darlington | 5A            | Motores medianos   |
| TIP122     | NPN Darlington | 5A            | Alternativa TIP120 |
| IRF520     | MOSFET         | 9A            | Cargas grandes     |

---

## 📝 Resumen

| Concepto         | Descripción                            |
| ---------------- | -------------------------------------- |
| Transistor       | Switch electrónico para cargas grandes |
| Resistencia base | 1kΩ para limitar corriente             |
| Diodo flyback    | Protección contra picos inductivos     |
| Fuente externa   | Alimentación separada para motores     |
| GND común        | Arduino y fuente comparten GND         |

---

## ➡️ Siguiente

[Generación de Sonido →](./04-generacion-sonido.md)
