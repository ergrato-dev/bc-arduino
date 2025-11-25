# Semana 6: Displays y Visualización

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Controlar displays de 7 segmentos
- Utilizar displays LCD 16x2
- Implementar matrices de LEDs
- Crear interfaces de usuario visuales
- Diseñar menús interactivos con displays

---

## 📚 Contenido Teórico

### 1. Display de 7 Segmentos (45 min)

#### Anatomía del Display

```
    ┌─────────────┐
    │     AAA     │
    │    ─────    │
    │ F │     │ B │
    │   │     │   │
    │    ─────    │  ← Segmento G
    │ E │     │ C │
    │   │     │   │
    │    ─────    │
    │     DDD   ○ │ ← DP (punto decimal)
    └─────────────┘

Segmentos: A, B, C, D, E, F, G, DP

Tipos:
- Cátodo Común: GND compartido, HIGH enciende
- Ánodo Común: 5V compartido, LOW enciende
```

#### Tabla de Segmentos para Dígitos

```
Dígito    A  B  C  D  E  F  G
  0       1  1  1  1  1  1  0
  1       0  1  1  0  0  0  0
  2       1  1  0  1  1  0  1
  3       1  1  1  1  0  0  1
  4       0  1  1  0  0  1  1
  5       1  0  1  1  0  1  1
  6       1  0  1  1  1  1  1
  7       1  1  1  0  0  0  0
  8       1  1  1  1  1  1  1
  9       1  1  1  1  0  1  1
```

---

### 2. Display LCD 16x2 (45 min)

#### Características

```
┌────────────────────────────────────┐
│ H O L A   M U N D O                │ ← Fila 0 (16 caracteres)
│ T e m p :   2 5 . 5   C            │ ← Fila 1 (16 caracteres)
└────────────────────────────────────┘

- 2 filas × 16 columnas = 32 caracteres
- Controlador HD44780 (estándar)
- Retroiluminación LED
```

#### Conexiones

```
LCD sin I2C (Paralelo - 6 pines de datos):
  RS, E, D4, D5, D6, D7 → Pines digitales Arduino
  V0 → Potenciómetro (contraste)
  VCC → 5V
  GND → GND

LCD con I2C (Solo 2 pines de datos):
  SDA → A4 (Arduino Uno)
  SCL → A5 (Arduino Uno)
  VCC → 5V
  GND → GND

Dirección I2C común: 0x27 o 0x3F
```

#### Funciones de la Librería LiquidCrystal

```cpp
#include <LiquidCrystal.h>

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() {
    lcd.begin(16, 2);           // Inicializar (columnas, filas)
    lcd.clear();                // Limpiar pantalla
    lcd.setCursor(0, 0);        // Posicionar cursor (col, fila)
    lcd.print("Hola");          // Escribir texto
    lcd.home();                 // Cursor a (0,0)
    lcd.blink();                // Cursor parpadeando
    lcd.noBlink();              // Sin parpadeo
    lcd.cursor();               // Mostrar cursor
    lcd.noCursor();             // Ocultar cursor
    lcd.scrollDisplayLeft();    // Desplazar izquierda
    lcd.scrollDisplayRight();   // Desplazar derecha
}
```

---

### 3. Caracteres Personalizados LCD (30 min)

#### Crear Caracteres Custom

```cpp
// Cada carácter es una matriz de 5x8 píxeles
// Máximo 8 caracteres personalizados (índices 0-7)

byte corazon[8] = {
    B00000,
    B01010,
    B11111,
    B11111,
    B11111,
    B01110,
    B00100,
    B00000
};

byte carita[8] = {
    B00000,
    B00000,
    B01010,
    B00000,
    B10001,
    B01110,
    B00000,
    B00000
};

void setup() {
    lcd.createChar(0, corazon);  // Guardar en posición 0
    lcd.createChar(1, carita);   // Guardar en posición 1

    lcd.begin(16, 2);
    lcd.write(byte(0));          // Mostrar corazón
    lcd.write(byte(1));          // Mostrar carita
}
```

---

### 4. Multiplexación (30 min)

#### Concepto

```
Multiplexación = Compartir pines encendiendo displays alternadamente
                muy rápido (imperceptible al ojo humano)

Ejemplo: 4 displays de 7 segmentos
- Sin multiplexar: 4 × 8 = 32 pines
- Multiplexado: 8 + 4 = 12 pines

         Display 1  Display 2  Display 3  Display 4
           ┌───┐      ┌───┐      ┌───┐      ┌───┐
           │ 1 │      │ 2 │      │ 3 │      │ 4 │
           └───┘      └───┘      └───┘      └───┘
             │          │          │          │
         ────┴──────────┴──────────┴──────────┴────
              Segmentos compartidos (A-G, DP)

Pines de control (cátodos/ánodos) activan uno a la vez
```

---

## 💻 Ejercicios Prácticos

### Ejercicio 1: Contador con 7 Segmentos (45 min)

**Objetivo:** Mostrar números del 0-9 en un display de 7 segmentos.

**Componentes:**

- Arduino Uno R3
- 1 Display 7 segmentos (cátodo común)
- 7 Resistencias 220Ω

**Diagrama:**

```
Pin 2 ──[220Ω]── Segmento A
Pin 3 ──[220Ω]── Segmento B
Pin 4 ──[220Ω]── Segmento C
Pin 5 ──[220Ω]── Segmento D
Pin 6 ──[220Ω]── Segmento E
Pin 7 ──[220Ω]── Segmento F
Pin 8 ──[220Ω]── Segmento G
Cátodo común ── GND
```

**Código:**

```cpp
/*
 * Ejercicio 1: Contador 7 Segmentos
 * Muestra números del 0 al 9
 */

// Pines para cada segmento (A, B, C, D, E, F, G)
const int SEGMENTOS[] = {2, 3, 4, 5, 6, 7, 8};
const int NUM_SEGMENTOS = 7;

// Tabla de dígitos (1 = encendido para cátodo común)
//                    A  B  C  D  E  F  G
const byte DIGITOS[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
};

int contador = 0;

void setup() {
    for (int i = 0; i < NUM_SEGMENTOS; i++) {
        pinMode(SEGMENTOS[i], OUTPUT);
    }
    Serial.begin(9600);
}

void loop() {
    mostrarDigito(contador);
    Serial.print("Mostrando: ");
    Serial.println(contador);

    contador = (contador + 1) % 10;
    delay(1000);
}

void mostrarDigito(int digito) {
    if (digito < 0 || digito > 9) return;

    for (int i = 0; i < NUM_SEGMENTOS; i++) {
        digitalWrite(SEGMENTOS[i], DIGITOS[digito][i]);
    }
}

void apagarDisplay() {
    for (int i = 0; i < NUM_SEGMENTOS; i++) {
        digitalWrite(SEGMENTOS[i], LOW);
    }
}
```

---

### Ejercicio 2: Hola Mundo en LCD (30 min)

**Objetivo:** Mostrar mensajes en LCD 16x2.

**Componentes:**

- Arduino Uno R3
- LCD 16x2
- Potenciómetro 10kΩ (contraste)

**Diagrama:**

```
LCD (Modo 4 bits):
  VSS → GND
  VDD → 5V
  V0  → Potenciómetro (central)
  RS  → Pin 12
  RW  → GND
  E   → Pin 11
  D4  → Pin 5
  D5  → Pin 4
  D6  → Pin 3
  D7  → Pin 2
  A   → 5V (backlight)
  K   → GND (backlight)
```

**Código:**

```cpp
/*
 * Ejercicio 2: Hola Mundo LCD
 * Mensajes básicos en display LCD
 */

#include <LiquidCrystal.h>

// Pines: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    lcd.begin(16, 2);  // 16 columnas, 2 filas

    // Mensaje de bienvenida
    lcd.print("Hola Mundo!");
    lcd.setCursor(0, 1);
    lcd.print("Arduino LCD");

    delay(2000);
}

void loop() {
    // Mostrar tiempo activo
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tiempo activo:");

    lcd.setCursor(0, 1);
    unsigned long segundos = millis() / 1000;
    unsigned long minutos = segundos / 60;
    segundos = segundos % 60;

    if (minutos < 10) lcd.print("0");
    lcd.print(minutos);
    lcd.print(":");
    if (segundos < 10) lcd.print("0");
    lcd.print(segundos);

    delay(1000);
}
```

---

### Ejercicio 3: Termómetro con LCD (45 min)

**Objetivo:** Mostrar temperatura en LCD con símbolos personalizados.

**Componentes:**

- Arduino Uno R3
- LCD 16x2
- TMP36
- Potenciómetro 10kΩ

**Código:**

```cpp
/*
 * Ejercicio 3: Termómetro LCD
 * Muestra temperatura con gráficos
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int TEMP_PIN = A0;

// Caracteres personalizados
byte gradoC[8] = {
    B01000, B10100, B01000, B00011, B00100, B00100, B00011, B00000
};

byte termometro[8] = {
    B00100, B01010, B01010, B01110, B01110, B11111, B11111, B01110
};

byte frio[8] = {
    B00100, B10101, B01110, B11111, B01110, B10101, B00100, B00000
};

byte calor[8] = {
    B00100, B00100, B01110, B01110, B11111, B11111, B01110, B00100
};

void setup() {
    lcd.begin(16, 2);

    // Crear caracteres personalizados
    lcd.createChar(0, gradoC);
    lcd.createChar(1, termometro);
    lcd.createChar(2, frio);
    lcd.createChar(3, calor);

    // Pantalla de inicio
    lcd.setCursor(0, 0);
    lcd.write(byte(1));
    lcd.print(" Termometro");
    lcd.setCursor(0, 1);
    lcd.print("Iniciando...");
    delay(2000);
}

void loop() {
    float temp = leerTemperatura();

    lcd.clear();

    // Fila 1: Temperatura
    lcd.setCursor(0, 0);
    lcd.write(byte(1));
    lcd.print(" Temp: ");
    lcd.print(temp, 1);
    lcd.write(byte(0));  // Símbolo grado

    // Fila 2: Estado e indicador
    lcd.setCursor(0, 1);

    if (temp < 18) {
        lcd.write(byte(2));  // Icono frío
        lcd.print(" FRIO      ");
        mostrarBarra(map(temp, 0, 18, 0, 5));
    } else if (temp > 28) {
        lcd.write(byte(3));  // Icono calor
        lcd.print(" CALIENTE! ");
        mostrarBarra(map(temp, 28, 40, 5, 10));
    } else {
        lcd.print("  Normal   ");
        mostrarBarra(map(temp, 18, 28, 3, 7));
    }

    delay(500);
}

float leerTemperatura() {
    int raw = analogRead(TEMP_PIN);
    float voltaje = (raw / 1023.0) * 5.0;
    return (voltaje - 0.5) * 100.0;
}

void mostrarBarra(int nivel) {
    // Barra de 5 caracteres al final de la segunda fila
    lcd.setCursor(11, 1);
    for (int i = 0; i < 5; i++) {
        if (i < nivel / 2) {
            lcd.print((char)255);  // Bloque lleno
        } else {
            lcd.print("-");
        }
    }
}
```

---

### Ejercicio 4: Menú con LCD y Botones (45 min)

**Objetivo:** Crear un menú navegable con botones.

**Componentes:**

- Arduino Uno R3
- LCD 16x2
- 3 Botones (Arriba, Abajo, Seleccionar)

**Código:**

```cpp
/*
 * Ejercicio 4: Menú LCD
 * Sistema de menú navegable
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pines de botones
const int BTN_ARRIBA = 8;
const int BTN_ABAJO = 9;
const int BTN_SELECT = 10;

// Opciones del menú
const char* MENU_ITEMS[] = {
    "1. Temperatura",
    "2. Luminosidad",
    "3. Configuracion",
    "4. Acerca de..."
};
const int NUM_ITEMS = 4;

int menuIndex = 0;
int itemSeleccionado = -1;

// Debounce
unsigned long ultimoDebounce = 0;
const unsigned long DEBOUNCE_DELAY = 200;

void setup() {
    lcd.begin(16, 2);

    pinMode(BTN_ARRIBA, INPUT_PULLUP);
    pinMode(BTN_ABAJO, INPUT_PULLUP);
    pinMode(BTN_SELECT, INPUT_PULLUP);

    mostrarMenu();
}

void loop() {
    if (millis() - ultimoDebounce > DEBOUNCE_DELAY) {
        if (digitalRead(BTN_ARRIBA) == LOW) {
            ultimoDebounce = millis();
            if (itemSeleccionado == -1) {
                menuIndex = (menuIndex - 1 + NUM_ITEMS) % NUM_ITEMS;
                mostrarMenu();
            }
        }

        if (digitalRead(BTN_ABAJO) == LOW) {
            ultimoDebounce = millis();
            if (itemSeleccionado == -1) {
                menuIndex = (menuIndex + 1) % NUM_ITEMS;
                mostrarMenu();
            }
        }

        if (digitalRead(BTN_SELECT) == LOW) {
            ultimoDebounce = millis();
            if (itemSeleccionado == -1) {
                itemSeleccionado = menuIndex;
                ejecutarOpcion(itemSeleccionado);
            } else {
                itemSeleccionado = -1;
                mostrarMenu();
            }
        }
    }

    // Actualizar si hay opción seleccionada
    if (itemSeleccionado != -1) {
        actualizarOpcion(itemSeleccionado);
    }
}

void mostrarMenu() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(">");
    lcd.print(MENU_ITEMS[menuIndex]);

    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.print(MENU_ITEMS[(menuIndex + 1) % NUM_ITEMS]);
}

void ejecutarOpcion(int opcion) {
    lcd.clear();

    switch(opcion) {
        case 0:
            lcd.print("Temperatura:");
            break;
        case 1:
            lcd.print("Luminosidad:");
            break;
        case 2:
            lcd.print("Config Menu");
            lcd.setCursor(0, 1);
            lcd.print("No implementado");
            break;
        case 3:
            lcd.print("Arduino LCD");
            lcd.setCursor(0, 1);
            lcd.print("Version 1.0");
            break;
    }
}

void actualizarOpcion(int opcion) {
    switch(opcion) {
        case 0:
            // Temperatura
            lcd.setCursor(0, 1);
            lcd.print("                ");
            lcd.setCursor(0, 1);
            float temp = (analogRead(A0) / 1023.0 * 5.0 - 0.5) * 100;
            lcd.print(temp, 1);
            lcd.print(" C");
            delay(500);
            break;

        case 1:
            // Luminosidad
            lcd.setCursor(0, 1);
            lcd.print("                ");
            lcd.setCursor(0, 1);
            int luz = map(analogRead(A1), 0, 1023, 0, 100);
            lcd.print(luz);
            lcd.print(" %");
            delay(500);
            break;
    }
}
```

---

## 🔨 Proyecto de la Semana: Dashboard de Monitoreo

**Descripción:** Sistema completo de monitoreo con múltiples pantallas.

**Componentes:**

- Arduino Uno R3
- LCD 16x2
- TMP36
- LDR + Resistencia 10kΩ
- Potenciómetro
- 2 Botones
- 1 LED

**Código Solución:**

```cpp
/*
 * Proyecto Semana 6: Dashboard de Monitoreo
 * Sistema con múltiples pantallas y visualizaciones
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pines
const int TEMP_PIN = A0;
const int LUZ_PIN = A1;
const int POT_PIN = A2;
const int BTN_NEXT = 8;
const int BTN_ACTION = 9;
const int LED_ALERTA = 13;

// Caracteres personalizados
byte termometro[8] = {B00100,B01010,B01010,B01110,B01110,B11111,B11111,B01110};
byte sol[8] = {B00100,B10101,B01110,B11111,B01110,B10101,B00100,B00000};
byte flecha[8] = {B00000,B00100,B00110,B11111,B11111,B00110,B00100,B00000};
byte alerta[8] = {B00100,B00100,B01110,B01110,B01110,B00000,B00100,B00000};
byte barraLlena[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111};
byte barraVacia[8] = {B11111,B10001,B10001,B10001,B10001,B10001,B10001,B11111};

// Estados y configuración
int pantallaActual = 0;
const int NUM_PANTALLAS = 4;
bool alertaActiva = false;
float tempMaxima = 30.0;
float tempMinima = 15.0;
int luzMinima = 200;

// Debounce
unsigned long ultimoDebounce = 0;
const unsigned long DEBOUNCE_DELAY = 200;

// Actualización
unsigned long ultimaActualizacion = 0;
const unsigned long INTERVALO_ACTUALIZACION = 500;

// Historial de temperatura (para gráfico)
float historialTemp[16];
int indiceHistorial = 0;

void setup() {
    lcd.begin(16, 2);

    lcd.createChar(0, termometro);
    lcd.createChar(1, sol);
    lcd.createChar(2, flecha);
    lcd.createChar(3, alerta);
    lcd.createChar(4, barraLlena);
    lcd.createChar(5, barraVacia);

    pinMode(BTN_NEXT, INPUT_PULLUP);
    pinMode(BTN_ACTION, INPUT_PULLUP);
    pinMode(LED_ALERTA, OUTPUT);

    Serial.begin(9600);

    // Pantalla de inicio
    lcd.setCursor(0, 0);
    lcd.print("  DASHBOARD v1.0");
    lcd.setCursor(0, 1);
    lcd.print("  Iniciando...");
    delay(2000);

    // Inicializar historial
    for (int i = 0; i < 16; i++) {
        historialTemp[i] = 20.0;
    }
}

void loop() {
    // Manejar botones
    manejarBotones();

    // Actualizar pantalla
    if (millis() - ultimaActualizacion >= INTERVALO_ACTUALIZACION) {
        ultimaActualizacion = millis();
        actualizarPantalla();
        verificarAlertas();
    }
}

void manejarBotones() {
    if (millis() - ultimoDebounce > DEBOUNCE_DELAY) {
        if (digitalRead(BTN_NEXT) == LOW) {
            ultimoDebounce = millis();
            pantallaActual = (pantallaActual + 1) % NUM_PANTALLAS;
            lcd.clear();
        }

        if (digitalRead(BTN_ACTION) == LOW) {
            ultimoDebounce = millis();
            accionPantalla();
        }
    }
}

void actualizarPantalla() {
    switch(pantallaActual) {
        case 0:
            pantallaResumen();
            break;
        case 1:
            pantallaTemperatura();
            break;
        case 2:
            pantallaLuz();
            break;
        case 3:
            pantallaGrafico();
            break;
    }
}

void pantallaResumen() {
    float temp = leerTemperatura();
    int luz = analogRead(LUZ_PIN);
    int luzPct = map(luz, 0, 1023, 0, 100);

    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.print(temp, 1);
    lcd.print("C  ");
    lcd.write(byte(1));
    lcd.print(luzPct);
    lcd.print("%  ");

    lcd.setCursor(0, 1);
    lcd.print("P");
    lcd.print(pantallaActual + 1);
    lcd.print("/");
    lcd.print(NUM_PANTALLAS);
    lcd.print(" ");

    if (alertaActiva) {
        lcd.write(byte(3));
        lcd.print("ALERTA!");
    } else {
        lcd.print("Normal   ");
    }
}

void pantallaTemperatura() {
    float temp = leerTemperatura();

    // Actualizar historial
    historialTemp[indiceHistorial] = temp;
    indiceHistorial = (indiceHistorial + 1) % 16;

    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.print(" TEMPERATURA");

    lcd.setCursor(0, 1);
    lcd.print(temp, 1);
    lcd.print("C ");

    // Barra de nivel
    int nivel = map(constrain(temp, 10, 40), 10, 40, 0, 8);
    for (int i = 0; i < 8; i++) {
        if (i < nivel) {
            lcd.write(byte(4));
        } else {
            lcd.write(byte(5));
        }
    }
}

void pantallaLuz() {
    int luz = analogRead(LUZ_PIN);
    int luzPct = map(luz, 0, 1023, 0, 100);

    lcd.setCursor(0, 0);
    lcd.write(byte(1));
    lcd.print(" LUMINOSIDAD");

    lcd.setCursor(0, 1);
    lcd.print(luzPct);
    lcd.print("% Raw:");
    lcd.print(luz);
    lcd.print("   ");
}

void pantallaGrafico() {
    lcd.setCursor(0, 0);
    lcd.print("Historial Temp  ");

    // Dibujar mini gráfico en segunda línea
    lcd.setCursor(0, 1);
    for (int i = 0; i < 16; i++) {
        int idx = (indiceHistorial + i) % 16;
        int nivel = map(constrain(historialTemp[idx], 15, 35), 15, 35, 0, 7);
        // Caracteres para representar niveles
        if (nivel < 2) lcd.print("_");
        else if (nivel < 4) lcd.print("-");
        else if (nivel < 6) lcd.print("=");
        else lcd.print("#");
    }
}

void accionPantalla() {
    switch(pantallaActual) {
        case 0:
            // Resumen: Reset alertas
            alertaActiva = false;
            digitalWrite(LED_ALERTA, LOW);
            lcd.clear();
            lcd.print("Alertas reset!");
            delay(1000);
            break;

        case 1:
            // Temperatura: Mostrar min/max
            lcd.clear();
            float minT = 100, maxT = -100;
            for (int i = 0; i < 16; i++) {
                if (historialTemp[i] < minT) minT = historialTemp[i];
                if (historialTemp[i] > maxT) maxT = historialTemp[i];
            }
            lcd.print("Min:");
            lcd.print(minT, 1);
            lcd.print(" Max:");
            lcd.print(maxT, 1);
            delay(2000);
            break;

        case 2:
            // Luz: Toggle LED
            static bool ledOn = false;
            ledOn = !ledOn;
            digitalWrite(LED_ALERTA, ledOn);
            break;

        case 3:
            // Gráfico: Limpiar historial
            for (int i = 0; i < 16; i++) {
                historialTemp[i] = leerTemperatura();
            }
            lcd.clear();
            lcd.print("Historial limpio");
            delay(1000);
            break;
    }
}

void verificarAlertas() {
    float temp = leerTemperatura();
    int luz = analogRead(LUZ_PIN);

    if (temp > tempMaxima || temp < tempMinima || luz < luzMinima) {
        alertaActiva = true;
        digitalWrite(LED_ALERTA, HIGH);
    }
}

float leerTemperatura() {
    int raw = analogRead(TEMP_PIN);
    float voltaje = (raw / 1023.0) * 5.0;
    return (voltaje - 0.5) * 100.0;
}
```

---

## 📖 Recursos

### Documentación

- [LiquidCrystal Library](https://www.arduino.cc/en/Reference/LiquidCrystal)
- [LCD Custom Characters](https://maxpromer.github.io/LCD-Character-Creator/)

### Tutoriales

- [LCD Tutorial](https://www.arduino.cc/en/Tutorial/LibraryExamples/HelloWorld)
- [7 Segment Display](https://www.arduino.cc/en/Tutorial/BuiltInExamples/SevenSegmentDisplay)

---

## ✅ Checklist de Completitud

- [ ] Ejercicio 1: Contador 7 segmentos completado
- [ ] Ejercicio 2: Hola Mundo LCD funcionando
- [ ] Ejercicio 3: Termómetro con caracteres custom
- [ ] Ejercicio 4: Menú navegable implementado
- [ ] Proyecto: Dashboard completo con pantallas
- [ ] Caracteres personalizados creados
- [ ] Menús funcionales con botones
- [ ] Circuitos guardados en Tinkercad

---

## 🎓 Evaluación

| Componente                 | Porcentaje |
| -------------------------- | ---------- |
| Ejercicios prácticos (1-4) | 40%        |
| Proyecto de la semana      | 50%        |
| Diseño de interfaz usuario | 10%        |

---

**Dedicación:** 4 horas | **Anterior:** [← Semana 5](../semana-05/README.md) | **Siguiente:** [Semana 7 →](../semana-07/README.md)
