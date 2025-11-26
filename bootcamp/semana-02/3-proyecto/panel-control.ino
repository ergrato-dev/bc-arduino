/*
 * =============================================================================
 * PROYECTO: Panel de Control de Iluminación
 * =============================================================================
 *
 * Semana 02 - Bootcamp Arduino
 * Tema: Entradas y Salidas Digitales
 *
 * -----------------------------------------------------------------------------
 * ¿QUÉ HACE?
 * -----------------------------------------------------------------------------
 * Sistema de control de iluminación con 4 botones y 4 LEDs que opera en
 * 3 modos diferentes: Individual, Secuencia e Intensidad.
 *
 * -----------------------------------------------------------------------------
 * ¿PARA QUÉ SIRVE?
 * -----------------------------------------------------------------------------
 * - Demostrar el dominio de entradas/salidas digitales
 * - Aplicar debounce a múltiples botones
 * - Implementar máquinas de estados
 * - Crear código modular y profesional
 *
 * -----------------------------------------------------------------------------
 * ¿CÓMO FUNCIONA?
 * -----------------------------------------------------------------------------
 * MODOS DE OPERACIÓN:
 *
 * Modo 0 - INDIVIDUAL:
 *   - Cada botón controla su LED correspondiente (toggle)
 *   - BTN1→LED1, BTN2→LED2, BTN3→LED3, BTN4→LED4
 *
 * Modo 1 - SECUENCIA:
 *   - BTN1: Inicia secuencia de LEDs
 *   - BTN2: Detiene secuencia
 *   - BTN3: Cambia dirección
 *   - BTN4: Pausa/Continúa
 *
 * Modo 2 - INTENSIDAD:
 *   - Todos los LEDs parpadean juntos
 *   - BTN3: Aumenta velocidad
 *   - BTN4: Reduce velocidad
 *
 * CAMBIO DE MODO:
 *   - Presión larga (>2 seg) en BTN1 cambia al siguiente modo
 *
 * -----------------------------------------------------------------------------
 * HARDWARE REQUERIDO
 * -----------------------------------------------------------------------------
 * - Arduino Uno R3
 * - 4 LEDs (Rojo, Amarillo, Verde, Azul)
 * - 4 Resistencias 220Ω
 * - 4 Pulsadores
 * - Protoboard y cables
 *
 * -----------------------------------------------------------------------------
 * CONEXIONES
 * -----------------------------------------------------------------------------
 * LEDs (con resistencia 220Ω):
 *   - LED1 (Rojo)    → Pin 13
 *   - LED2 (Amarillo)→ Pin 12
 *   - LED3 (Verde)   → Pin 11
 *   - LED4 (Azul)    → Pin 10
 *
 * Botones (a GND, usando INPUT_PULLUP):
 *   - BTN1 → Pin 6
 *   - BTN2 → Pin 5
 *   - BTN3 → Pin 4
 *   - BTN4 → Pin 3
 *
 * -----------------------------------------------------------------------------
 * Compatibilidad Tinkercad: ✅
 * =============================================================================
 */

// =============================================================================
// DEFINICIÓN DE PINES
// =============================================================================
const int LED_PINS[] = {13, 12, 11, 10};  // LEDs: Rojo, Amarillo, Verde, Azul
const int BTN_PINS[] = {6, 5, 4, 3};      // Botones 1, 2, 3, 4
const int NUM_LEDS = 4;
const int NUM_BTNS = 4;

// =============================================================================
// CONSTANTES DE CONFIGURACIÓN
// =============================================================================
const unsigned long DEBOUNCE_DELAY = 50;      // Tiempo de debounce (ms)
const unsigned long LONG_PRESS_TIME = 2000;   // Tiempo para presión larga (ms)
const unsigned long DEFAULT_SEQUENCE_DELAY = 200;  // Velocidad inicial secuencia

// Velocidades para modo intensidad
const unsigned long SPEED_MIN = 50;    // Más rápido
const unsigned long SPEED_MAX = 500;   // Más lento
const unsigned long SPEED_STEP = 50;   // Incremento de velocidad

// =============================================================================
// ENUMERACIONES
// =============================================================================

// Modos de operación del sistema
enum OperationMode {
    MODE_INDIVIDUAL,   // Cada botón controla su LED
    MODE_SEQUENCE,     // Secuencia de LEDs
    MODE_INTENSITY,    // Control de velocidad de parpadeo
    NUM_MODES          // Total de modos (3)
};

// =============================================================================
// ESTRUCTURA PARA BOTONES
// =============================================================================
struct Button {
    int state;                    // Estado confirmado (después de debounce)
    int lastState;                // Última lectura
    unsigned long lastDebounce;   // Tiempo del último cambio
    unsigned long pressStart;     // Tiempo cuando se empezó a presionar
    bool wasLongPress;            // Flag para evitar acción después de long press
};

// =============================================================================
// VARIABLES GLOBALES
// =============================================================================

// Estado del sistema
OperationMode currentMode = MODE_INDIVIDUAL;

// Estados de botones y LEDs
Button buttons[NUM_BTNS];
bool ledStates[NUM_LEDS] = {false, false, false, false};

// Variables para modo secuencia
bool sequenceRunning = false;
bool sequencePaused = false;
int sequenceDirection = 1;        // 1 = adelante, -1 = atrás
int currentSequenceLed = 0;
unsigned long lastSequenceUpdate = 0;
unsigned long sequenceDelay = DEFAULT_SEQUENCE_DELAY;

// Variables para modo intensidad
unsigned long intensityDelay = DEFAULT_SEQUENCE_DELAY;
unsigned long lastIntensityUpdate = 0;
bool intensityState = false;

// =============================================================================
// SETUP - Inicialización
// =============================================================================
void setup() {
    // Inicializar pines de LEDs como salida
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(LED_PINS[i], OUTPUT);
        digitalWrite(LED_PINS[i], LOW);
    }

    // Inicializar pines de botones como entrada con pull-up
    for (int i = 0; i < NUM_BTNS; i++) {
        pinMode(BTN_PINS[i], INPUT_PULLUP);

        // Inicializar estructura de botón
        buttons[i].state = HIGH;
        buttons[i].lastState = HIGH;
        buttons[i].lastDebounce = 0;
        buttons[i].pressStart = 0;
        buttons[i].wasLongPress = false;
    }

    // Iniciar comunicación serial
    Serial.begin(9600);
    printWelcome();
    printCurrentMode();
}

// =============================================================================
// LOOP - Bucle principal
// =============================================================================
void loop() {
    // 1. Verificar cambio de modo (presión larga en BTN1)
    checkModeChange();

    // 2. Ejecutar lógica del modo actual
    switch (currentMode) {
        case MODE_INDIVIDUAL:
            modeIndividual();
            break;

        case MODE_SEQUENCE:
            modeSequence();
            break;

        case MODE_INTENSITY:
            modeIntensity();
            break;

        default:
            break;
    }
}

// =============================================================================
// FUNCIONES DE GESTIÓN DE MODOS
// =============================================================================

/**
 * Verifica si se debe cambiar de modo (presión larga en BTN1)
 */
void checkModeChange() {
    int reading = digitalRead(BTN_PINS[0]);

    // Detectar inicio de presión
    if (reading == LOW && buttons[0].state == HIGH) {
        buttons[0].pressStart = millis();
    }

    // Verificar presión larga
    if (reading == LOW && buttons[0].pressStart != 0) {
        if ((millis() - buttons[0].pressStart) > LONG_PRESS_TIME) {
            // Cambiar al siguiente modo
            changeMode();
            buttons[0].pressStart = 0;
            buttons[0].wasLongPress = true;

            // Esperar a que se suelte el botón
            while (digitalRead(BTN_PINS[0]) == LOW) {
                delay(10);
            }
        }
    }

    // Resetear al soltar
    if (reading == HIGH) {
        buttons[0].pressStart = 0;
        buttons[0].wasLongPress = false;
    }
}

/**
 * Cambia al siguiente modo de operación
 */
void changeMode() {
    // Avanzar al siguiente modo
    currentMode = (OperationMode)((currentMode + 1) % NUM_MODES);

    // Resetear estados
    resetStates();

    // Feedback visual: parpadear todos los LEDs 3 veces
    blinkAllLeds(3);

    // Mostrar nuevo modo en Serial
    printCurrentMode();
}

/**
 * Resetea todos los estados al cambiar de modo
 */
void resetStates() {
    // Apagar todos los LEDs
    allLedsOff();

    // Resetear estados de LEDs
    for (int i = 0; i < NUM_LEDS; i++) {
        ledStates[i] = false;
    }

    // Resetear variables de secuencia
    sequenceRunning = false;
    sequencePaused = false;
    sequenceDirection = 1;
    currentSequenceLed = 0;
    sequenceDelay = DEFAULT_SEQUENCE_DELAY;

    // Resetear variables de intensidad
    intensityDelay = DEFAULT_SEQUENCE_DELAY;
    intensityState = false;
}

// =============================================================================
// MODO INDIVIDUAL
// =============================================================================

/**
 * Modo Individual: cada botón controla su LED (toggle)
 */
void modeIndividual() {
    for (int i = 0; i < NUM_BTNS; i++) {
        // Ignorar BTN1 si fue presión larga
        if (i == 0 && buttons[0].wasLongPress) continue;

        if (checkButtonPress(i)) {
            // Toggle del LED correspondiente
            ledStates[i] = !ledStates[i];
            digitalWrite(LED_PINS[i], ledStates[i]);

            Serial.print("LED ");
            Serial.print(i + 1);
            Serial.println(ledStates[i] ? " ON" : " OFF");
        }
    }
}

// =============================================================================
// MODO SECUENCIA
// =============================================================================

/**
 * Modo Secuencia: LEDs se encienden en orden
 * BTN1: Iniciar | BTN2: Detener | BTN3: Dirección | BTN4: Pausa
 */
void modeSequence() {
    // BTN1: Iniciar secuencia
    if (checkButtonPress(0) && !buttons[0].wasLongPress) {
        sequenceRunning = true;
        sequencePaused = false;
        Serial.println("Secuencia: INICIADA");
    }

    // BTN2: Detener secuencia
    if (checkButtonPress(1)) {
        sequenceRunning = false;
        allLedsOff();
        Serial.println("Secuencia: DETENIDA");
    }

    // BTN3: Cambiar dirección
    if (checkButtonPress(2)) {
        sequenceDirection *= -1;
        Serial.print("Dirección: ");
        Serial.println(sequenceDirection > 0 ? "ADELANTE" : "ATRÁS");
    }

    // BTN4: Pausar/Continuar
    if (checkButtonPress(3)) {
        sequencePaused = !sequencePaused;
        Serial.println(sequencePaused ? "Secuencia: PAUSADA" : "Secuencia: CONTINUANDO");
    }

    // Ejecutar secuencia si está activa y no pausada
    if (sequenceRunning && !sequencePaused) {
        if (millis() - lastSequenceUpdate >= sequenceDelay) {
            // Apagar todos los LEDs
            allLedsOff();

            // Encender el LED actual
            digitalWrite(LED_PINS[currentSequenceLed], HIGH);

            // Mover al siguiente LED
            currentSequenceLed += sequenceDirection;

            // Wrap-around
            if (currentSequenceLed >= NUM_LEDS) {
                currentSequenceLed = 0;
            } else if (currentSequenceLed < 0) {
                currentSequenceLed = NUM_LEDS - 1;
            }

            lastSequenceUpdate = millis();
        }
    }
}

// =============================================================================
// MODO INTENSIDAD
// =============================================================================

/**
 * Modo Intensidad: todos los LEDs parpadean, BTN3/4 controlan velocidad
 */
void modeIntensity() {
    // BTN3: Aumentar velocidad (reducir delay)
    if (checkButtonPress(2)) {
        if (intensityDelay > SPEED_MIN) {
            intensityDelay -= SPEED_STEP;
            Serial.print("Velocidad: ");
            Serial.print(intensityDelay);
            Serial.println("ms");
        } else {
            Serial.println("Velocidad: MÁXIMA");
        }
    }

    // BTN4: Reducir velocidad (aumentar delay)
    if (checkButtonPress(3)) {
        if (intensityDelay < SPEED_MAX) {
            intensityDelay += SPEED_STEP;
            Serial.print("Velocidad: ");
            Serial.print(intensityDelay);
            Serial.println("ms");
        } else {
            Serial.println("Velocidad: MÍNIMA");
        }
    }

    // Parpadeo de todos los LEDs
    if (millis() - lastIntensityUpdate >= intensityDelay) {
        intensityState = !intensityState;

        for (int i = 0; i < NUM_LEDS; i++) {
            digitalWrite(LED_PINS[i], intensityState);
        }

        lastIntensityUpdate = millis();
    }
}

// =============================================================================
// FUNCIONES DE BOTONES (DEBOUNCE)
// =============================================================================

/**
 * Verifica si un botón fue presionado (con debounce)
 * Retorna true solo en el momento exacto de la pulsación (flanco)
 *
 * @param btnIndex Índice del botón (0-3)
 * @return true si el botón fue presionado en este ciclo
 */
bool checkButtonPress(int btnIndex) {
    bool pressed = false;
    int reading = digitalRead(BTN_PINS[btnIndex]);

    // Detectar cambio
    if (reading != buttons[btnIndex].lastState) {
        buttons[btnIndex].lastDebounce = millis();
    }

    // Verificar estabilidad
    if ((millis() - buttons[btnIndex].lastDebounce) > DEBOUNCE_DELAY) {
        if (reading != buttons[btnIndex].state) {
            buttons[btnIndex].state = reading;

            // Detectar flanco de bajada (presión)
            if (buttons[btnIndex].state == LOW) {
                pressed = true;
            }
        }
    }

    buttons[btnIndex].lastState = reading;
    return pressed;
}

// =============================================================================
// FUNCIONES AUXILIARES DE LEDs
// =============================================================================

/**
 * Apaga todos los LEDs
 */
void allLedsOff() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], LOW);
    }
}

/**
 * Enciende todos los LEDs
 */
void allLedsOn() {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], HIGH);
    }
}

/**
 * Parpadea todos los LEDs n veces
 *
 * @param times Número de parpadeos
 */
void blinkAllLeds(int times) {
    for (int i = 0; i < times; i++) {
        allLedsOn();
        delay(100);
        allLedsOff();
        delay(100);
    }
}

// =============================================================================
// FUNCIONES DE SERIAL (MENSAJES)
// =============================================================================

/**
 * Imprime mensaje de bienvenida
 */
void printWelcome() {
    Serial.println();
    Serial.println("================================================");
    Serial.println("   PANEL DE CONTROL DE ILUMINACIÓN");
    Serial.println("   Bootcamp Arduino - Semana 02");
    Serial.println("================================================");
    Serial.println();
    Serial.println("CONTROLES:");
    Serial.println("  - Presión larga BTN1: Cambiar modo");
    Serial.println("  - Los demás controles dependen del modo");
    Serial.println();
    Serial.println("------------------------------------------------");
}

/**
 * Imprime el modo actual y sus controles
 */
void printCurrentMode() {
    Serial.println();
    Serial.print(">>> MODO ACTUAL: ");

    switch (currentMode) {
        case MODE_INDIVIDUAL:
            Serial.println("INDIVIDUAL");
            Serial.println("    BTN1 → LED1 (toggle)");
            Serial.println("    BTN2 → LED2 (toggle)");
            Serial.println("    BTN3 → LED3 (toggle)");
            Serial.println("    BTN4 → LED4 (toggle)");
            break;

        case MODE_SEQUENCE:
            Serial.println("SECUENCIA");
            Serial.println("    BTN1 → Iniciar");
            Serial.println("    BTN2 → Detener");
            Serial.println("    BTN3 → Cambiar dirección");
            Serial.println("    BTN4 → Pausar/Continuar");
            break;

        case MODE_INTENSITY:
            Serial.println("INTENSIDAD");
            Serial.println("    BTN3 → Aumentar velocidad");
            Serial.println("    BTN4 → Reducir velocidad");
            break;

        default:
            Serial.println("DESCONOCIDO");
            break;
    }

    Serial.println("------------------------------------------------");
}
