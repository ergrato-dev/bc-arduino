# Semana 2: Entradas y Salidas Digitales

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Entender la diferencia entre entradas y salidas digitales
- Leer el estado de botones y switches
- Implementar resistencias pull-up y pull-down
- Aplicar técnicas de debouncing
- Crear sistemas interactivos con botones y LEDs

---

## 📚 Contenido Teórico

### 1. Entradas y Salidas Digitales (45 min)

#### Conceptos Básicos

```
DIGITAL = Solo dos estados posibles

HIGH (1) = 5V = Encendido = Verdadero
LOW  (0) = 0V = Apagado   = Falso
```

#### Configuración de Pines

```cpp
// Como SALIDA - Para controlar dispositivos (LEDs, relés, etc.)
pinMode(pin, OUTPUT);
digitalWrite(pin, HIGH);  // Envía 5V
digitalWrite(pin, LOW);   // Envía 0V

// Como ENTRADA - Para leer dispositivos (botones, sensores)
pinMode(pin, INPUT);
int estado = digitalRead(pin);  // Retorna HIGH o LOW

// Como ENTRADA con pull-up interno
pinMode(pin, INPUT_PULLUP);  // Activa resistencia interna de 20kΩ
```

---

### 2. Resistencias Pull-Up y Pull-Down (30 min)

#### El Problema del Estado Flotante

```
Sin resistencia, un pin de entrada "flota" entre HIGH y LOW
generando lecturas erráticas.

Solución: Usar resistencias pull-up o pull-down
```

#### Pull-Down (Normalmente LOW)

```
          ┌─────────────────┐
    5V ───┤                 │
          │     BOTÓN       ├─── Pin Arduino
    GND ──┼──[10kΩ]─────────┘
          │
          ▼
    Estado normal: LOW (0)
    Al presionar: HIGH (1)
```

#### Pull-Up (Normalmente HIGH)

```
          ┌─────────────────┐
    5V ───┼──[10kΩ]─────────┤
          │                 ├─── Pin Arduino
    GND ──┤     BOTÓN       │
          └─────────────────┘
    Estado normal: HIGH (1)
    Al presionar: LOW (0)
```

#### Pull-Up Interno de Arduino

```cpp
// Arduino tiene resistencias pull-up internas (~20kΩ)
pinMode(botonPin, INPUT_PULLUP);

// Con esto, la lógica es INVERTIDA:
// - Botón NO presionado = HIGH
// - Botón presionado = LOW
```

---

### 3. Debouncing (45 min)

#### El Problema del Rebote

Cuando presionas un botón mecánico, los contactos "rebotan" causando múltiples lecturas en milisegundos.

```
Realidad física del botón:
Presión → ON-OFF-ON-OFF-ON-OFF-ON (rebotes) → Estable ON

Esto puede registrar múltiples "presiones" cuando solo hubo una.
```

#### Solución por Software

```cpp
// Variables para debouncing
const int BOTON_PIN = 2;
int estadoBoton;
int ultimoEstado = HIGH;
unsigned long ultimoTiempoRebote = 0;
const unsigned long TIEMPO_DEBOUNCE = 50;  // milisegundos

void setup() {
    pinMode(BOTON_PIN, INPUT_PULLUP);
}

void loop() {
    int lectura = digitalRead(BOTON_PIN);

    // Si la lectura cambió (posible rebote)
    if (lectura != ultimoEstado) {
        ultimoTiempoRebote = millis();
    }

    // Si pasó suficiente tiempo, la lectura es estable
    if ((millis() - ultimoTiempoRebote) > TIEMPO_DEBOUNCE) {
        if (lectura != estadoBoton) {
            estadoBoton = lectura;

            // Aquí procesamos el cambio real
            if (estadoBoton == LOW) {
                // Botón fue presionado (con INPUT_PULLUP)
            }
        }
    }

    ultimoEstado = lectura;
}
```

#### Solución por Hardware

```
                         ┌─────────────────┐
    Pin Arduino ─────────┤                 │
                         │     BOTÓN       │
    GND ────[10kΩ]───────┤                 │
                │        └─────────────────┘
              ──┴──
              ─────  Capacitor 0.1µF (100nF)
                │
              GND
```

---

### 4. Detección de Flancos (30 min)

#### Tipos de Flancos

```
Flanco de SUBIDA (Rising): LOW → HIGH
    ___      ___
   |   |    |   |
   |   |____|   |____
       ↑
     Aquí

Flanco de BAJADA (Falling): HIGH → LOW
    ___      ___
   |   |    |   |
   |   |____|   |____
           ↑
         Aquí
```

#### Implementación

```cpp
int estadoAnterior = HIGH;
int estadoActual;

void loop() {
    estadoActual = digitalRead(BOTON_PIN);

    // Detectar flanco de bajada (presión con INPUT_PULLUP)
    if (estadoAnterior == HIGH && estadoActual == LOW) {
        // ¡Botón fue presionado!
        ejecutarAccion();
    }

    // Detectar flanco de subida (soltar con INPUT_PULLUP)
    if (estadoAnterior == LOW && estadoActual == HIGH) {
        // ¡Botón fue soltado!
    }

    estadoAnterior = estadoActual;
}
```

---

## 💻 Ejercicios Prácticos

### Ejercicio 1: Botón que Enciende LED (30 min)

**Objetivo:** Encender un LED mientras se mantiene presionado un botón.

**Componentes:**

- Arduino Uno R3
- 1 Botón pulsador
- 1 LED
- 1 Resistencia 220Ω (LED)
- 1 Resistencia 10kΩ (Pull-down)

**Diagrama de Conexión:**

```
Pin 2 ────────────────┬──── Botón ──── 5V
                      │
                   [10kΩ]
                      │
                    GND

Pin 8 ──[220Ω]──[LED]── GND
```

**Código:**

```cpp
/*
 * Ejercicio 1: Botón y LED
 * El LED se enciende mientras el botón está presionado
 */

const int BOTON_PIN = 2;
const int LED_PIN = 8;

void setup() {
    pinMode(BOTON_PIN, INPUT);  // Con resistencia pull-down externa
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int estadoBoton = digitalRead(BOTON_PIN);

    if (estadoBoton == HIGH) {
        digitalWrite(LED_PIN, HIGH);  // Botón presionado
    } else {
        digitalWrite(LED_PIN, LOW);   // Botón soltado
    }
}

// Versión simplificada:
// void loop() {
//     digitalWrite(LED_PIN, digitalRead(BOTON_PIN));
// }
```

---

### Ejercicio 2: Toggle LED con Botón (45 min)

**Objetivo:** Cada presión del botón cambia el estado del LED (encendido/apagado).

**Componentes:**

- Arduino Uno R3
- 1 Botón pulsador
- 1 LED
- 1 Resistencia 220Ω

**Diagrama (usando INPUT_PULLUP):**

```
Pin 2 ──── Botón ──── GND

Pin 8 ──[220Ω]──[LED]── GND
```

**Código:**

```cpp
/*
 * Ejercicio 2: Toggle LED
 * Cada presión del botón cambia el estado del LED
 */

const int BOTON_PIN = 2;
const int LED_PIN = 8;

bool estadoLED = false;
int estadoBotonAnterior = HIGH;

// Variables para debouncing
unsigned long ultimoTiempoDebounce = 0;
const unsigned long DELAY_DEBOUNCE = 50;

void setup() {
    pinMode(BOTON_PIN, INPUT_PULLUP);  // Usa pull-up interno
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int lecturaBoton = digitalRead(BOTON_PIN);

    // Verificar si cambió el estado
    if (lecturaBoton != estadoBotonAnterior) {
        ultimoTiempoDebounce = millis();
    }

    // Si pasó el tiempo de debounce
    if ((millis() - ultimoTiempoDebounce) > DELAY_DEBOUNCE) {
        // Detectar flanco de bajada (presión)
        if (lecturaBoton == LOW && estadoBotonAnterior == HIGH) {
            estadoLED = !estadoLED;  // Invertir estado
            digitalWrite(LED_PIN, estadoLED);
        }
    }

    estadoBotonAnterior = lecturaBoton;
}
```

---

### Ejercicio 3: Contador con Display Serial (45 min)

**Objetivo:** Contar presiones de botón y mostrar en monitor serial.

**Componentes:**

- Arduino Uno R3
- 2 Botones pulsadores

**Diagrama:**

```
Pin 2 ──── Botón (incrementar) ──── GND
Pin 3 ──── Botón (decrementar) ──── GND
```

**Código:**

```cpp
/*
 * Ejercicio 3: Contador con Botones
 * Un botón incrementa, otro decrementa
 */

const int BOTON_INCREMENTAR = 2;
const int BOTON_DECREMENTAR = 3;

int contador = 0;
int estadoIncAnterior = HIGH;
int estadoDecAnterior = HIGH;

unsigned long ultimoDebounceInc = 0;
unsigned long ultimoDecounceDec = 0;
const unsigned long DELAY_DEBOUNCE = 50;

void setup() {
    pinMode(BOTON_INCREMENTAR, INPUT_PULLUP);
    pinMode(BOTON_DECREMENTAR, INPUT_PULLUP);
    Serial.begin(9600);
    Serial.println("=== Contador Iniciado ===");
    Serial.println("Contador: 0");
}

void loop() {
    // Leer botón incrementar
    int lecturaInc = digitalRead(BOTON_INCREMENTAR);
    if (lecturaInc != estadoIncAnterior) {
        ultimoDebounceInc = millis();
    }
    if ((millis() - ultimoDebounceInc) > DELAY_DEBOUNCE) {
        if (lecturaInc == LOW && estadoIncAnterior == HIGH) {
            contador++;
            Serial.print("Contador: ");
            Serial.println(contador);
        }
    }
    estadoIncAnterior = lecturaInc;

    // Leer botón decrementar
    int lecturaDec = digitalRead(BOTON_DECREMENTAR);
    if (lecturaDec != estadoDecAnterior) {
        ultimoDecounceDec = millis();
    }
    if ((millis() - ultimoDecounceDec) > DELAY_DEBOUNCE) {
        if (lecturaDec == LOW && estadoDecAnterior == HIGH) {
            contador--;
            Serial.print("Contador: ");
            Serial.println(contador);
        }
    }
    estadoDecAnterior = lecturaDec;
}
```

---

### Ejercicio 4: Selector de Modo con LED (45 min)

**Objetivo:** Usar un botón para ciclar entre diferentes patrones de parpadeo.

**Componentes:**

- Arduino Uno R3
- 1 Botón pulsador
- 1 LED
- 1 Resistencia 220Ω

**Código:**

```cpp
/*
 * Ejercicio 4: Selector de Modos
 * Botón cambia entre: Apagado → Encendido → Parpadeo Lento → Parpadeo Rápido
 */

const int BOTON_PIN = 2;
const int LED_PIN = 8;

int modoActual = 0;
const int TOTAL_MODOS = 4;

int estadoBotonAnterior = HIGH;
unsigned long ultimoDebounce = 0;
const unsigned long DELAY_DEBOUNCE = 50;

// Para controlar parpadeo sin delay()
unsigned long ultimoParpadeo = 0;
bool estadoLED = false;

void setup() {
    pinMode(BOTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    imprimirModo();
}

void loop() {
    // Leer botón con debounce
    int lecturaBoton = digitalRead(BOTON_PIN);
    if (lecturaBoton != estadoBotonAnterior) {
        ultimoDebounce = millis();
    }
    if ((millis() - ultimoDebounce) > DELAY_DEBOUNCE) {
        if (lecturaBoton == LOW && estadoBotonAnterior == HIGH) {
            modoActual = (modoActual + 1) % TOTAL_MODOS;
            imprimirModo();
        }
    }
    estadoBotonAnterior = lecturaBoton;

    // Ejecutar modo actual
    ejecutarModo();
}

void imprimirModo() {
    Serial.print("Modo: ");
    switch(modoActual) {
        case 0: Serial.println("Apagado"); break;
        case 1: Serial.println("Encendido"); break;
        case 2: Serial.println("Parpadeo Lento"); break;
        case 3: Serial.println("Parpadeo Rapido"); break;
    }
}

void ejecutarModo() {
    switch(modoActual) {
        case 0:  // Apagado
            digitalWrite(LED_PIN, LOW);
            break;

        case 1:  // Encendido
            digitalWrite(LED_PIN, HIGH);
            break;

        case 2:  // Parpadeo lento (500ms)
            if (millis() - ultimoParpadeo >= 500) {
                estadoLED = !estadoLED;
                digitalWrite(LED_PIN, estadoLED);
                ultimoParpadeo = millis();
            }
            break;

        case 3:  // Parpadeo rápido (100ms)
            if (millis() - ultimoParpadeo >= 100) {
                estadoLED = !estadoLED;
                digitalWrite(LED_PIN, estadoLED);
                ultimoParpadeo = millis();
            }
            break;
    }
}
```

---

## 🔨 Proyecto de la Semana: Cerradura con Combinación

**Descripción:** Sistema de cerradura que requiere presionar botones en secuencia correcta.

**Componentes:**

- Arduino Uno R3
- 4 Botones pulsadores
- 3 LEDs (Rojo, Amarillo, Verde)
- 3 Resistencias 220Ω

**Diagrama de Conexión:**

```
Botones (INPUT_PULLUP):
Pin 2 ──── Botón 1 ──── GND
Pin 3 ──── Botón 2 ──── GND
Pin 4 ──── Botón 3 ──── GND
Pin 5 ──── Botón 4 ──── GND

LEDs:
Pin 8  ──[220Ω]──[LED Verde]──── GND  (Acceso concedido)
Pin 9  ──[220Ω]──[LED Amarillo]── GND  (Esperando)
Pin 10 ──[220Ω]──[LED Rojo]───── GND  (Error)
```

**Código Solución:**

```cpp
/*
 * Proyecto Semana 2: Cerradura con Combinación
 * Secuencia correcta: 1-3-2-4
 */

// Pines de botones
const int BOTONES[] = {2, 3, 4, 5};
const int NUM_BOTONES = 4;

// Pines de LEDs
const int LED_VERDE = 8;
const int LED_AMARILLO = 9;
const int LED_ROJO = 10;

// Secuencia secreta (botón 1, botón 3, botón 2, botón 4)
const int SECUENCIA[] = {0, 2, 1, 3};  // Índices de BOTONES[]
const int LONGITUD_SECUENCIA = 4;

// Variables de estado
int secuenciaIngresada[4];
int indiceActual = 0;

// Debounce
int estadosAnteriores[4] = {HIGH, HIGH, HIGH, HIGH};
unsigned long ultimoDebounce[4] = {0, 0, 0, 0};
const unsigned long DELAY_DEBOUNCE = 50;

void setup() {
    // Configurar botones
    for (int i = 0; i < NUM_BOTONES; i++) {
        pinMode(BOTONES[i], INPUT_PULLUP);
    }

    // Configurar LEDs
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    pinMode(LED_ROJO, OUTPUT);

    Serial.begin(9600);
    Serial.println("=== Cerradura con Combinacion ===");
    Serial.println("Ingrese la secuencia de 4 botones");

    // Indicar que está esperando
    digitalWrite(LED_AMARILLO, HIGH);
}

void loop() {
    // Revisar cada botón
    for (int i = 0; i < NUM_BOTONES; i++) {
        int lectura = digitalRead(BOTONES[i]);

        if (lectura != estadosAnteriores[i]) {
            ultimoDebounce[i] = millis();
        }

        if ((millis() - ultimoDebounce[i]) > DELAY_DEBOUNCE) {
            if (lectura == LOW && estadosAnteriores[i] == HIGH) {
                procesarBoton(i);
            }
        }

        estadosAnteriores[i] = lectura;
    }
}

void procesarBoton(int boton) {
    Serial.print("Boton ");
    Serial.print(boton + 1);
    Serial.println(" presionado");

    // Guardar en secuencia ingresada
    secuenciaIngresada[indiceActual] = boton;
    indiceActual++;

    // Parpadear LED amarillo
    digitalWrite(LED_AMARILLO, LOW);
    delay(100);
    digitalWrite(LED_AMARILLO, HIGH);

    // Verificar si se completó la secuencia
    if (indiceActual >= LONGITUD_SECUENCIA) {
        verificarSecuencia();
    }
}

void verificarSecuencia() {
    bool correcta = true;

    for (int i = 0; i < LONGITUD_SECUENCIA; i++) {
        if (secuenciaIngresada[i] != SECUENCIA[i]) {
            correcta = false;
            break;
        }
    }

    if (correcta) {
        accesoPermitido();
    } else {
        accesoDenegado();
    }

    // Reiniciar
    indiceActual = 0;
}

void accesoPermitido() {
    Serial.println("*** ACCESO PERMITIDO ***");

    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_VERDE, HIGH);

    // Parpadear LED verde 5 veces
    for (int i = 0; i < 5; i++) {
        digitalWrite(LED_VERDE, HIGH);
        delay(200);
        digitalWrite(LED_VERDE, LOW);
        delay(200);
    }

    digitalWrite(LED_AMARILLO, HIGH);
    Serial.println("Ingrese nueva secuencia");
}

void accesoDenegado() {
    Serial.println("!!! ACCESO DENEGADO !!!");

    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);

    // LED rojo encendido 2 segundos
    delay(2000);

    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    Serial.println("Intente de nuevo");
}
```

**Extensiones Opcionales:**

1. **Cambio de contraseña:** Permitir cambiar la secuencia
2. **Intentos limitados:** Bloquear después de 3 intentos fallidos
3. **Sonido:** Agregar buzzer para feedback auditivo

---

## 📖 Recursos

### Documentación

- [Digital Pins - Arduino](https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins)
- [digitalRead() Reference](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/)
- [Internal Pull-up Resistors](https://www.arduino.cc/en/Tutorial/BuiltInExamples/InputPullupSerial)

### Tutoriales

- [Button Debouncing](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce)
- [State Change Detection](https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection)

---

## ✅ Checklist de Completitud

- [ ] Ejercicio 1: Botón enciende LED completado
- [ ] Ejercicio 2: Toggle LED funcionando con debounce
- [ ] Ejercicio 3: Contador con monitor serial
- [ ] Ejercicio 4: Selector de modos implementado
- [ ] Proyecto: Cerradura con combinación completada
- [ ] Conceptos de pull-up/pull-down entendidos
- [ ] Técnica de debounce aplicada correctamente
- [ ] Circuitos guardados en Tinkercad

---

## 🎓 Evaluación

| Componente                    | Porcentaje |
| ----------------------------- | ---------- |
| Ejercicios prácticos (1-4)    | 40%        |
| Proyecto de la semana         | 50%        |
| Documentación y código limpio | 10%        |

---

## 📝 Notas Importantes

1. **Siempre usar debouncing** en aplicaciones con botones
2. **INPUT_PULLUP invierte la lógica:** presionado = LOW
3. **millis() no usa delay():** permite multitarea
4. **Arrays simplifican código** cuando hay múltiples elementos similares

---

**Dedicación:** 4 horas | **Anterior:** [← Semana 1](../semana-01/README.md) | **Siguiente:** [Semana 3 →](../semana-03/README.md)
