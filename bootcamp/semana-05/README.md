# Semana 5: Comunicación Serial y Debugging

## 🎯 Objetivos de Aprendizaje

Al finalizar esta semana, el estudiante será capaz de:

- Utilizar el monitor serial para debugging
- Enviar y recibir datos por comunicación serial
- Implementar comandos desde el computador
- Formatear y presentar datos de manera legible
- Crear menús interactivos por serial

---

## 📚 Contenido Teórico

### 1. Comunicación Serial (45 min)

#### ¿Qué es la Comunicación Serial?

```
Serial = Transmisión de datos bit a bit, uno después de otro

Arduino ←──────────────────────→ Computador
         TX (Transmitir)
         RX (Recibir)
         GND (Referencia común)

Velocidades comunes (baud rate):
9600, 19200, 38400, 57600, 115200 baudios
```

#### Configuración Inicial

```cpp
void setup() {
    // Inicializar comunicación serial
    Serial.begin(9600);  // 9600 baudios (bits por segundo)

    // Esperar a que el puerto esté listo (solo en algunas placas)
    while (!Serial) {
        ; // Esperar
    }

    Serial.println("Arduino listo!");
}
```

---

### 2. Funciones de Salida Serial (30 min)

#### print() vs println()

```cpp
Serial.print("Hola");      // Sin salto de línea
Serial.println("Mundo");   // Con salto de línea

// Resultado:
// HolaMundo

Serial.println("Hola");
Serial.println("Mundo");

// Resultado:
// Hola
// Mundo
```

#### Formateo de Números

```cpp
int numero = 255;
float decimal = 3.14159;

// Enteros en diferentes bases
Serial.println(numero);       // 255 (decimal)
Serial.println(numero, BIN);  // 11111111 (binario)
Serial.println(numero, OCT);  // 377 (octal)
Serial.println(numero, HEX);  // FF (hexadecimal)

// Decimales con precisión
Serial.println(decimal, 2);   // 3.14
Serial.println(decimal, 4);   // 3.1416
```

#### Tabulaciones y Formato

```cpp
// Caracteres especiales
Serial.print("\t");   // Tabulación
Serial.print("\n");   // Nueva línea
Serial.print("\r");   // Retorno de carro

// Ejemplo de tabla
Serial.println("Sensor\tValor\tEstado");
Serial.println("------\t-----\t------");
Serial.print("Temp\t");
Serial.print(25.5);
Serial.println("\tOK");
```

---

### 3. Funciones de Entrada Serial (45 min)

#### Verificar Datos Disponibles

```cpp
void loop() {
    // Verificar si hay datos disponibles
    if (Serial.available() > 0) {
        // Hay datos para leer
    }
}
```

#### Lectura de Datos

```cpp
// Leer un byte (carácter)
char caracter = Serial.read();

// Leer número entero
int numero = Serial.parseInt();

// Leer número decimal
float decimal = Serial.parseFloat();

// Leer hasta encontrar delimitador
String texto = Serial.readStringUntil('\n');

// Leer toda la cadena disponible
String todo = Serial.readString();
```

#### Configuración de Timeout

```cpp
void setup() {
    Serial.begin(9600);
    Serial.setTimeout(1000);  // Timeout de 1 segundo
}
```

---

### 4. Debugging con Serial (30 min)

#### Técnicas de Debugging

```cpp
// 1. Puntos de control
Serial.println("DEBUG: Entrando a función X");

// 2. Valores de variables
Serial.print("DEBUG: valor = ");
Serial.println(variable);

// 3. Checkpoints con tiempo
Serial.print("DEBUG [");
Serial.print(millis());
Serial.println("ms]: Checkpoint 1");

// 4. Condicional de debug
#define DEBUG true

void loop() {
    #if DEBUG
        Serial.println("Modo debug activo");
    #endif
}
```

---

## 💻 Ejercicios Prácticos

### Ejercicio 1: Monitor de Sensores (30 min)

**Objetivo:** Crear un monitor de sensores con formato tabular.

**Componentes:**

- Arduino Uno R3
- 1 Potenciómetro
- 1 LDR + Resistencia 10kΩ

**Diagrama:**

```
Potenciómetro → A0
LDR (divisor) → A1
```

**Código:**

```cpp
/*
 * Ejercicio 1: Monitor de Sensores
 * Muestra datos de múltiples sensores en formato tabla
 */

const int POT_PIN = A0;
const int LDR_PIN = A1;

unsigned long ultimaLectura = 0;
const unsigned long INTERVALO = 1000;
int lecturaNum = 0;

void setup() {
    Serial.begin(9600);

    // Encabezado
    imprimirEncabezado();
}

void loop() {
    if (millis() - ultimaLectura >= INTERVALO) {
        ultimaLectura = millis();
        lecturaNum++;

        // Leer sensores
        int valorPot = analogRead(POT_PIN);
        int valorLuz = analogRead(LDR_PIN);

        // Calcular valores procesados
        int porcentajePot = map(valorPot, 0, 1023, 0, 100);
        int porcentajeLuz = map(valorLuz, 0, 1023, 0, 100);

        // Imprimir fila
        Serial.print("| ");
        imprimirConAncho(lecturaNum, 5);
        Serial.print(" | ");
        imprimirConAncho(valorPot, 4);
        Serial.print(" (");
        imprimirConAncho(porcentajePot, 3);
        Serial.print("%) | ");
        imprimirConAncho(valorLuz, 4);
        Serial.print(" (");
        imprimirConAncho(porcentajeLuz, 3);
        Serial.print("%) | ");
        Serial.print(millis() / 1000.0, 1);
        Serial.println("s |");

        // Reimprimir encabezado cada 10 lecturas
        if (lecturaNum % 10 == 0) {
            Serial.println("+-------+---------------+---------------+--------+");
        }
    }
}

void imprimirEncabezado() {
    Serial.println();
    Serial.println("+-------+---------------+---------------+--------+");
    Serial.println("| # Lec | Potenciometro | Sensor Luz    | Tiempo |");
    Serial.println("+-------+---------------+---------------+--------+");
}

void imprimirConAncho(int valor, int ancho) {
    String str = String(valor);
    int espacios = ancho - str.length();
    for (int i = 0; i < espacios; i++) {
        Serial.print(" ");
    }
    Serial.print(str);
}
```

---

### Ejercicio 2: Control de LED por Comandos (45 min)

**Objetivo:** Controlar un LED enviando comandos desde el monitor serial.

**Componentes:**

- Arduino Uno R3
- 1 LED
- 1 Resistencia 220Ω

**Diagrama:**

```
Pin 9 (PWM) ──[220Ω]──[LED]── GND
```

**Código:**

```cpp
/*
 * Ejercicio 2: Control por Comandos
 * Comandos: ON, OFF, BLINK, FADE, BRILLO <0-255>
 */

const int LED_PIN = 9;
String modoActual = "OFF";
int brilloActual = 255;

// Variables para modos
bool parpadeando = false;
bool fadeActivo = false;
int valorFade = 0;
int incrementoFade = 5;
unsigned long ultimoParpadeo = 0;
unsigned long ultimoFade = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);

    mostrarMenu();
}

void loop() {
    // Procesar comandos entrantes
    if (Serial.available() > 0) {
        String comando = Serial.readStringUntil('\n');
        comando.trim();
        comando.toUpperCase();
        procesarComando(comando);
    }

    // Ejecutar modo actual
    ejecutarModo();
}

void procesarComando(String cmd) {
    Serial.print("> Comando recibido: ");
    Serial.println(cmd);

    if (cmd == "ON") {
        modoActual = "ON";
        parpadeando = false;
        fadeActivo = false;
        analogWrite(LED_PIN, brilloActual);
        Serial.println("LED encendido");

    } else if (cmd == "OFF") {
        modoActual = "OFF";
        parpadeando = false;
        fadeActivo = false;
        analogWrite(LED_PIN, 0);
        Serial.println("LED apagado");

    } else if (cmd == "BLINK") {
        modoActual = "BLINK";
        parpadeando = true;
        fadeActivo = false;
        Serial.println("Modo parpadeo activado");

    } else if (cmd == "FADE") {
        modoActual = "FADE";
        parpadeando = false;
        fadeActivo = true;
        Serial.println("Modo fade activado");

    } else if (cmd.startsWith("BRILLO ")) {
        int valor = cmd.substring(7).toInt();
        if (valor >= 0 && valor <= 255) {
            brilloActual = valor;
            if (modoActual == "ON") {
                analogWrite(LED_PIN, brilloActual);
            }
            Serial.print("Brillo establecido a: ");
            Serial.println(brilloActual);
        } else {
            Serial.println("Error: Brillo debe ser 0-255");
        }

    } else if (cmd == "HELP" || cmd == "?") {
        mostrarMenu();

    } else if (cmd == "STATUS") {
        mostrarEstado();

    } else {
        Serial.println("Comando no reconocido. Escribe HELP para ver opciones.");
    }

    Serial.println();
}

void ejecutarModo() {
    if (parpadeando) {
        if (millis() - ultimoParpadeo >= 500) {
            ultimoParpadeo = millis();
            static bool ledEncendido = false;
            ledEncendido = !ledEncendido;
            analogWrite(LED_PIN, ledEncendido ? brilloActual : 0);
        }
    }

    if (fadeActivo) {
        if (millis() - ultimoFade >= 20) {
            ultimoFade = millis();
            valorFade += incrementoFade;
            if (valorFade <= 0 || valorFade >= 255) {
                incrementoFade = -incrementoFade;
            }
            analogWrite(LED_PIN, valorFade);
        }
    }
}

void mostrarMenu() {
    Serial.println();
    Serial.println("=========================================");
    Serial.println("   CONTROL DE LED POR COMANDOS SERIAL   ");
    Serial.println("=========================================");
    Serial.println("Comandos disponibles:");
    Serial.println("  ON          - Encender LED");
    Serial.println("  OFF         - Apagar LED");
    Serial.println("  BLINK       - Modo parpadeo");
    Serial.println("  FADE        - Modo fade");
    Serial.println("  BRILLO <n>  - Establecer brillo (0-255)");
    Serial.println("  STATUS      - Ver estado actual");
    Serial.println("  HELP        - Mostrar este menu");
    Serial.println("=========================================");
    Serial.println();
}

void mostrarEstado() {
    Serial.println("----- Estado Actual -----");
    Serial.print("Modo: ");
    Serial.println(modoActual);
    Serial.print("Brillo: ");
    Serial.print(brilloActual);
    Serial.print(" (");
    Serial.print(map(brilloActual, 0, 255, 0, 100));
    Serial.println("%)");
}
```

---

### Ejercicio 3: Registrador de Datos (Data Logger) (45 min)

**Objetivo:** Crear un sistema que registre datos de sensores en formato CSV.

**Componentes:**

- Arduino Uno R3
- 1 TMP36
- 1 LDR + Resistencia 10kΩ

**Código:**

```cpp
/*
 * Ejercicio 3: Data Logger CSV
 * Registra datos de sensores en formato CSV
 */

const int TEMP_PIN = A0;
const int LUZ_PIN = A1;

bool registrando = false;
unsigned long ultimoRegistro = 0;
unsigned long intervaloRegistro = 1000;  // 1 segundo
unsigned long tiempoInicio = 0;
int numeroMuestra = 0;

void setup() {
    Serial.begin(9600);

    Serial.println("=== DATA LOGGER CSV ===");
    Serial.println("Comandos:");
    Serial.println("  START        - Iniciar registro");
    Serial.println("  STOP         - Detener registro");
    Serial.println("  INTERVAL <n> - Intervalo en ms");
    Serial.println("  SINGLE       - Una sola lectura");
    Serial.println();
}

void loop() {
    // Procesar comandos
    if (Serial.available() > 0) {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();
        cmd.toUpperCase();
        procesarComando(cmd);
    }

    // Registrar si está activo
    if (registrando) {
        if (millis() - ultimoRegistro >= intervaloRegistro) {
            ultimoRegistro = millis();
            registrarDatos();
        }
    }
}

void procesarComando(String cmd) {
    if (cmd == "START") {
        if (!registrando) {
            registrando = true;
            numeroMuestra = 0;
            tiempoInicio = millis();

            Serial.println();
            Serial.println("--- INICIO DE REGISTRO ---");
            Serial.print("Intervalo: ");
            Serial.print(intervaloRegistro);
            Serial.println("ms");
            Serial.println();

            // Encabezado CSV
            Serial.println("muestra,tiempo_ms,temp_raw,temp_celsius,luz_raw,luz_porcent");
        }

    } else if (cmd == "STOP") {
        if (registrando) {
            registrando = false;
            Serial.println();
            Serial.println("--- FIN DE REGISTRO ---");
            Serial.print("Total muestras: ");
            Serial.println(numeroMuestra);
            Serial.print("Duracion: ");
            Serial.print((millis() - tiempoInicio) / 1000.0, 2);
            Serial.println(" segundos");
        }

    } else if (cmd.startsWith("INTERVAL ")) {
        int valor = cmd.substring(9).toInt();
        if (valor >= 100 && valor <= 60000) {
            intervaloRegistro = valor;
            Serial.print("Intervalo: ");
            Serial.print(intervaloRegistro);
            Serial.println("ms");
        } else {
            Serial.println("Error: Intervalo debe ser 100-60000 ms");
        }

    } else if (cmd == "SINGLE") {
        Serial.println();
        Serial.println("muestra,tiempo_ms,temp_raw,temp_celsius,luz_raw,luz_porcent");
        numeroMuestra = 1;
        tiempoInicio = millis();
        registrarDatos();
    }
}

void registrarDatos() {
    numeroMuestra++;

    // Leer sensores
    int tempRaw = analogRead(TEMP_PIN);
    int luzRaw = analogRead(LUZ_PIN);

    // Calcular valores
    float voltaje = (tempRaw / 1023.0) * 5.0;
    float tempCelsius = (voltaje - 0.5) * 100.0;
    int luzPorcent = map(luzRaw, 0, 1023, 0, 100);

    // Tiempo desde inicio
    unsigned long tiempoActual = millis() - tiempoInicio;

    // Imprimir en formato CSV
    Serial.print(numeroMuestra);
    Serial.print(",");
    Serial.print(tiempoActual);
    Serial.print(",");
    Serial.print(tempRaw);
    Serial.print(",");
    Serial.print(tempCelsius, 2);
    Serial.print(",");
    Serial.print(luzRaw);
    Serial.print(",");
    Serial.println(luzPorcent);
}
```

---

### Ejercicio 4: Terminal Interactiva (45 min)

**Objetivo:** Crear una terminal con menú interactivo completo.

**Componentes:**

- Arduino Uno R3
- 1 Potenciómetro
- 2 LEDs
- 2 Resistencias 220Ω

**Código:**

```cpp
/*
 * Ejercicio 4: Terminal Interactiva
 * Sistema de menús con múltiples opciones
 */

const int POT_PIN = A0;
const int LED1_PIN = 9;
const int LED2_PIN = 10;

// Estados
bool led1Estado = false;
bool led2Estado = false;
int led1Brillo = 255;
int led2Brillo = 255;

void setup() {
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    Serial.begin(9600);

    mostrarBienvenida();
    mostrarMenuPrincipal();
}

void loop() {
    if (Serial.available() > 0) {
        char opcion = Serial.read();
        // Limpiar buffer
        while (Serial.available() > 0) Serial.read();

        procesarOpcion(opcion);
    }
}

void mostrarBienvenida() {
    Serial.println();
    Serial.println("╔════════════════════════════════════╗");
    Serial.println("║    TERMINAL INTERACTIVA ARDUINO    ║");
    Serial.println("║         Bootcamp Semana 5          ║");
    Serial.println("╚════════════════════════════════════╝");
    Serial.println();
}

void mostrarMenuPrincipal() {
    Serial.println("┌─────────── MENU PRINCIPAL ───────────┐");
    Serial.println("│ 1. Control LED 1                     │");
    Serial.println("│ 2. Control LED 2                     │");
    Serial.println("│ 3. Leer Potenciometro                │");
    Serial.println("│ 4. Mostrar Estado                    │");
    Serial.println("│ 5. Test de LEDs                      │");
    Serial.println("│ 6. Ajustar Brillo                    │");
    Serial.println("│ 0. Mostrar Menu                      │");
    Serial.println("└──────────────────────────────────────┘");
    Serial.print("> Seleccione opcion: ");
}

void procesarOpcion(char opcion) {
    Serial.println(opcion);
    Serial.println();

    switch(opcion) {
        case '1':
            toggleLED(1);
            break;
        case '2':
            toggleLED(2);
            break;
        case '3':
            leerPotenciometro();
            break;
        case '4':
            mostrarEstado();
            break;
        case '5':
            testLEDs();
            break;
        case '6':
            ajustarBrillo();
            break;
        case '0':
            mostrarMenuPrincipal();
            return;  // No mostrar prompt adicional
        default:
            Serial.println("Opcion no valida");
    }

    Serial.println();
    Serial.print("> Opcion (0=menu): ");
}

void toggleLED(int led) {
    if (led == 1) {
        led1Estado = !led1Estado;
        analogWrite(LED1_PIN, led1Estado ? led1Brillo : 0);
        Serial.print("LED 1: ");
        Serial.println(led1Estado ? "ENCENDIDO" : "APAGADO");
    } else {
        led2Estado = !led2Estado;
        analogWrite(LED2_PIN, led2Estado ? led2Brillo : 0);
        Serial.print("LED 2: ");
        Serial.println(led2Estado ? "ENCENDIDO" : "APAGADO");
    }
}

void leerPotenciometro() {
    int valor = analogRead(POT_PIN);
    int porcentaje = map(valor, 0, 1023, 0, 100);

    Serial.println("--- Lectura Potenciometro ---");
    Serial.print("Valor Raw: ");
    Serial.println(valor);
    Serial.print("Porcentaje: ");
    Serial.print(porcentaje);
    Serial.println("%");

    // Barra visual
    Serial.print("Nivel: [");
    int barras = porcentaje / 5;
    for (int i = 0; i < 20; i++) {
        Serial.print(i < barras ? "█" : "░");
    }
    Serial.println("]");
}

void mostrarEstado() {
    Serial.println("═══════ ESTADO DEL SISTEMA ═══════");
    Serial.print("LED 1: ");
    Serial.print(led1Estado ? "ON" : "OFF");
    Serial.print(" (Brillo: ");
    Serial.print(led1Brillo);
    Serial.println(")");

    Serial.print("LED 2: ");
    Serial.print(led2Estado ? "ON" : "OFF");
    Serial.print(" (Brillo: ");
    Serial.print(led2Brillo);
    Serial.println(")");

    Serial.print("Pot: ");
    Serial.print(analogRead(POT_PIN));
    Serial.println(" raw");

    Serial.print("Tiempo: ");
    Serial.print(millis() / 1000);
    Serial.println(" segundos");
    Serial.println("═══════════════════════════════════");
}

void testLEDs() {
    Serial.println("Ejecutando test de LEDs...");

    for (int i = 0; i < 3; i++) {
        Serial.print("  Ciclo ");
        Serial.println(i + 1);

        analogWrite(LED1_PIN, 255);
        delay(200);
        analogWrite(LED1_PIN, 0);

        analogWrite(LED2_PIN, 255);
        delay(200);
        analogWrite(LED2_PIN, 0);
    }

    // Restaurar estados
    analogWrite(LED1_PIN, led1Estado ? led1Brillo : 0);
    analogWrite(LED2_PIN, led2Estado ? led2Brillo : 0);

    Serial.println("Test completado!");
}

void ajustarBrillo() {
    Serial.println("Ajustar brillo:");
    Serial.println("  A/a = LED1 +/-10");
    Serial.println("  B/b = LED2 +/-10");
    Serial.println("  X = Salir");

    while (true) {
        if (Serial.available() > 0) {
            char c = Serial.read();

            if (c == 'A') led1Brillo = min(255, led1Brillo + 10);
            else if (c == 'a') led1Brillo = max(0, led1Brillo - 10);
            else if (c == 'B') led2Brillo = min(255, led2Brillo + 10);
            else if (c == 'b') led2Brillo = max(0, led2Brillo - 10);
            else if (c == 'X' || c == 'x') break;

            // Actualizar si está encendido
            if (led1Estado) analogWrite(LED1_PIN, led1Brillo);
            if (led2Estado) analogWrite(LED2_PIN, led2Brillo);

            Serial.print("LED1: ");
            Serial.print(led1Brillo);
            Serial.print("  LED2: ");
            Serial.println(led2Brillo);
        }
    }

    Serial.println("Brillo ajustado");
}
```

---

## 🔨 Proyecto de la Semana: Sistema de Monitoreo con Comandos

**Descripción:** Sistema completo de monitoreo con interfaz de comandos rica.

**Código Solución:**

```cpp
/*
 * Proyecto Semana 5: Sistema de Monitoreo
 * Interfaz serial completa con múltiples funcionalidades
 */

// Pines
const int TEMP_PIN = A0;
const int LUZ_PIN = A1;
const int LED_ALERTA = 9;
const int BUZZER_PIN = 8;

// Configuración
struct Configuracion {
    float tempMinima = 18.0;
    float tempMaxima = 28.0;
    int luzMinima = 200;
    bool alertasActivas = true;
    int intervaloMonitoreo = 2000;
};

Configuracion config;

// Estado
bool monitoreoActivo = false;
unsigned long ultimoMonitoreo = 0;
int contadorAlertas = 0;

// Buffer para comandos
String comandoBuffer = "";

void setup() {
    pinMode(LED_ALERTA, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);

    delay(100);
    mostrarBanner();
    mostrarAyuda();
}

void loop() {
    // Leer comandos
    while (Serial.available() > 0) {
        char c = Serial.read();
        if (c == '\n') {
            procesarComando(comandoBuffer);
            comandoBuffer = "";
        } else if (c != '\r') {
            comandoBuffer += c;
        }
    }

    // Monitoreo automático
    if (monitoreoActivo) {
        if (millis() - ultimoMonitoreo >= config.intervaloMonitoreo) {
            ultimoMonitoreo = millis();
            ejecutarMonitoreo();
        }
    }
}

void mostrarBanner() {
    Serial.println();
    Serial.println("    _          _       _             ");
    Serial.println("   / \\   _ __ | |_ ___| |_ ___  ___  ");
    Serial.println("  / _ \\ | '_ \\| __/ _ \\ __/ _ \\/ __| ");
    Serial.println(" / ___ \\| | | | ||  __/ ||  __/\\__ \\ ");
    Serial.println("/_/   \\_\\_| |_|\\__\\___|\\__\\___||___/ ");
    Serial.println();
    Serial.println("Sistema de Monitoreo Ambiental v1.0");
    Serial.println("=====================================");
    Serial.println();
}

void mostrarAyuda() {
    Serial.println("COMANDOS DISPONIBLES:");
    Serial.println("--------------------------------------");
    Serial.println("MONITOREO:");
    Serial.println("  monitor on/off    - Iniciar/detener");
    Serial.println("  read              - Lectura unica");
    Serial.println("  status            - Estado del sistema");
    Serial.println();
    Serial.println("CONFIGURACION:");
    Serial.println("  set temp <min> <max>  - Umbrales temp");
    Serial.println("  set luz <min>         - Umbral luz");
    Serial.println("  set intervalo <ms>    - Intervalo");
    Serial.println("  alertas on/off        - Activar/desact");
    Serial.println();
    Serial.println("OTROS:");
    Serial.println("  test              - Test de hardware");
    Serial.println("  reset             - Valores por defecto");
    Serial.println("  help              - Esta ayuda");
    Serial.println("--------------------------------------");
    Serial.println();
    Serial.print("> ");
}

void procesarComando(String cmd) {
    cmd.trim();
    cmd.toLowerCase();

    Serial.println(cmd);

    if (cmd == "" ) return;

    if (cmd == "help" || cmd == "?") {
        mostrarAyuda();

    } else if (cmd == "monitor on") {
        monitoreoActivo = true;
        contadorAlertas = 0;
        Serial.println("[OK] Monitoreo iniciado");
        Serial.println("Temp,Luz,Estado");

    } else if (cmd == "monitor off") {
        monitoreoActivo = false;
        digitalWrite(LED_ALERTA, LOW);
        Serial.println("[OK] Monitoreo detenido");

    } else if (cmd == "read") {
        lecturaUnica();

    } else if (cmd == "status") {
        mostrarEstado();

    } else if (cmd.startsWith("set temp ")) {
        String params = cmd.substring(9);
        int espacio = params.indexOf(' ');
        if (espacio > 0) {
            config.tempMinima = params.substring(0, espacio).toFloat();
            config.tempMaxima = params.substring(espacio + 1).toFloat();
            Serial.print("[OK] Temp: ");
            Serial.print(config.tempMinima);
            Serial.print(" - ");
            Serial.println(config.tempMaxima);
        }

    } else if (cmd.startsWith("set luz ")) {
        config.luzMinima = cmd.substring(8).toInt();
        Serial.print("[OK] Luz minima: ");
        Serial.println(config.luzMinima);

    } else if (cmd.startsWith("set intervalo ")) {
        config.intervaloMonitoreo = cmd.substring(14).toInt();
        Serial.print("[OK] Intervalo: ");
        Serial.print(config.intervaloMonitoreo);
        Serial.println("ms");

    } else if (cmd == "alertas on") {
        config.alertasActivas = true;
        Serial.println("[OK] Alertas activadas");

    } else if (cmd == "alertas off") {
        config.alertasActivas = false;
        digitalWrite(LED_ALERTA, LOW);
        Serial.println("[OK] Alertas desactivadas");

    } else if (cmd == "test") {
        testHardware();

    } else if (cmd == "reset") {
        config = Configuracion();  // Valores por defecto
        Serial.println("[OK] Configuracion reiniciada");

    } else {
        Serial.print("[ERROR] Comando desconocido: ");
        Serial.println(cmd);
    }

    if (!monitoreoActivo) {
        Serial.print("> ");
    }
}

void ejecutarMonitoreo() {
    float temp = leerTemperatura();
    int luz = analogRead(LUZ_PIN);

    // Verificar alertas
    bool alerta = false;
    String tipoAlerta = "";

    if (temp < config.tempMinima) {
        alerta = true;
        tipoAlerta = "TEMP_BAJA";
    } else if (temp > config.tempMaxima) {
        alerta = true;
        tipoAlerta = "TEMP_ALTA";
    }

    if (luz < config.luzMinima) {
        alerta = true;
        tipoAlerta += (tipoAlerta.length() > 0 ? "+" : "") + String("LUZ_BAJA");
    }

    // Mostrar datos
    Serial.print(temp, 1);
    Serial.print(",");
    Serial.print(luz);
    Serial.print(",");

    if (alerta) {
        Serial.print("ALERTA:");
        Serial.println(tipoAlerta);
        contadorAlertas++;

        if (config.alertasActivas) {
            digitalWrite(LED_ALERTA, HIGH);
            tone(BUZZER_PIN, 1000, 100);
        }
    } else {
        Serial.println("OK");
        digitalWrite(LED_ALERTA, LOW);
    }
}

void lecturaUnica() {
    float temp = leerTemperatura();
    int luz = analogRead(LUZ_PIN);
    int luzPct = map(luz, 0, 1023, 0, 100);

    Serial.println("--- LECTURA ACTUAL ---");
    Serial.print("Temperatura: ");
    Serial.print(temp, 1);
    Serial.print(" C");
    if (temp < config.tempMinima) Serial.print(" [BAJA!]");
    if (temp > config.tempMaxima) Serial.print(" [ALTA!]");
    Serial.println();

    Serial.print("Luz: ");
    Serial.print(luz);
    Serial.print(" (");
    Serial.print(luzPct);
    Serial.print("%)");
    if (luz < config.luzMinima) Serial.print(" [BAJA!]");
    Serial.println();
    Serial.println("---------------------");
}

void mostrarEstado() {
    Serial.println("=== ESTADO DEL SISTEMA ===");
    Serial.print("Monitoreo: ");
    Serial.println(monitoreoActivo ? "ACTIVO" : "INACTIVO");
    Serial.print("Alertas: ");
    Serial.println(config.alertasActivas ? "ON" : "OFF");
    Serial.print("Intervalo: ");
    Serial.print(config.intervaloMonitoreo);
    Serial.println("ms");
    Serial.println();
    Serial.println("Umbrales:");
    Serial.print("  Temp: ");
    Serial.print(config.tempMinima);
    Serial.print(" - ");
    Serial.print(config.tempMaxima);
    Serial.println(" C");
    Serial.print("  Luz minima: ");
    Serial.println(config.luzMinima);
    Serial.println();
    Serial.print("Alertas registradas: ");
    Serial.println(contadorAlertas);
    Serial.print("Tiempo activo: ");
    Serial.print(millis() / 1000);
    Serial.println("s");
    Serial.println("==========================");
}

void testHardware() {
    Serial.println("Iniciando test de hardware...");

    Serial.print("  LED Alerta: ");
    digitalWrite(LED_ALERTA, HIGH);
    delay(500);
    digitalWrite(LED_ALERTA, LOW);
    Serial.println("OK");

    Serial.print("  Buzzer: ");
    tone(BUZZER_PIN, 1000, 200);
    delay(300);
    Serial.println("OK");

    Serial.print("  Sensor Temp: ");
    float temp = leerTemperatura();
    Serial.print(temp, 1);
    Serial.println(" C - OK");

    Serial.print("  Sensor Luz: ");
    int luz = analogRead(LUZ_PIN);
    Serial.print(luz);
    Serial.println(" - OK");

    Serial.println("Test completado!");
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

- [Serial Reference](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
- [Serial Monitor Guide](https://www.arduino.cc/en/Tutorial/BuiltInExamples/SerialMonitor)

---

## ✅ Checklist de Completitud

- [ ] Ejercicio 1: Monitor de sensores completado
- [ ] Ejercicio 2: Control por comandos funcionando
- [ ] Ejercicio 3: Data logger CSV operativo
- [ ] Ejercicio 4: Terminal interactiva implementada
- [ ] Proyecto: Sistema de monitoreo completo
- [ ] Uso de Serial.print() y println() dominado
- [ ] Lectura de comandos por serial funcionando
- [ ] Formato de datos profesional

---

## 🎓 Evaluación

| Componente                 | Porcentaje |
| -------------------------- | ---------- |
| Ejercicios prácticos (1-4) | 40%        |
| Proyecto de la semana      | 50%        |
| Calidad de interfaz serial | 10%        |

---

**Dedicación:** 4 horas | **Anterior:** [← Semana 4](../semana-04/README.md) | **Siguiente:** [Semana 6 →](../semana-06/README.md)
