# Módulo 01: Introducción a Microcontroladores

> ⏱️ **Tiempo estimado:** 20 minutos  
> 📚 **Nivel:** Principiante  
> 🎯 **Compatibilidad Tinkercad:** ✅

---

## 🎯 Objetivos del Módulo

Al finalizar este módulo, serás capaz de:

- [ ] Definir qué es un microcontrolador
- [ ] Identificar los componentes principales de un microcontrolador
- [ ] Explicar qué es Arduino y por qué es popular
- [ ] Diferenciar entre las placas Arduino Uno R3, R4 y WiFi

---

## 📚 Contenido

### 1.1 ¿Qué es un Microcontrolador?

Un **microcontrolador** (MCU - Microcontroller Unit) es un pequeño computador contenido en un solo chip. A diferencia de un computador de escritorio, está diseñado para tareas específicas y de control.

#### Analogía del Mundo Real

> Piensa en un microcontrolador como el "cerebro" de un electrodoméstico. Tu microondas, lavadora, o incluso tu cepillo de dientes eléctrico tienen uno. No necesitan Windows ni macOS, solo ejecutan un programa específico una y otra vez.

#### Componentes Principales

```
┌─────────────────────────────────────────────────────────────┐
│                    MICROCONTROLADOR                         │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   ┌─────────┐    ┌─────────┐    ┌─────────┐               │
│   │   CPU   │    │  FLASH  │    │  SRAM   │               │
│   │         │    │         │    │         │               │
│   │ Procesa │    │ Guarda  │    │ Variables│              │
│   │ instruc-│    │ programa│    │ temporal │              │
│   │ ciones  │    │(no volá-│    │ (volátil)│              │
│   │         │    │  til)   │    │         │               │
│   └─────────┘    └─────────┘    └─────────┘               │
│        │              │              │                     │
│        └──────────────┼──────────────┘                     │
│                       │                                    │
│   ┌─────────┐    ┌────┴────┐    ┌─────────┐               │
│   │ EEPROM  │    │  BUSES  │    │PERIFÉRI-│               │
│   │         │    │         │    │  COS    │               │
│   │ Datos   │    │ Conecta │    │         │               │
│   │ persis- │    │  todo   │    │ GPIO,   │               │
│   │ tentes  │    │         │    │ ADC,    │               │
│   │         │    │         │    │ Timer   │               │
│   └─────────┘    └─────────┘    └─────────┘               │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

| Componente | Función                                     | Analogía                 |
| ---------- | ------------------------------------------- | ------------------------ |
| **CPU**    | Ejecuta instrucciones del programa          | El "pensador"            |
| **Flash**  | Almacena el programa (persiste sin energía) | Disco duro               |
| **SRAM**   | Memoria temporal para variables             | Memoria RAM              |
| **EEPROM** | Almacena datos que deben persistir          | Bloc de notas permanente |
| **GPIO**   | Pines de entrada/salida                     | Brazos y ojos            |
| **ADC**    | Convierte señales analógicas a digitales    | Traductor                |
| **Timers** | Mide tiempo y genera eventos                | Reloj interno            |

---

### 1.2 ¿Qué es Arduino?

**Arduino** es una plataforma de código abierto (open-source) que incluye:

1. **Hardware:** Placas de desarrollo con microcontroladores
2. **Software:** IDE (Entorno de Desarrollo Integrado) gratuito
3. **Comunidad:** Miles de tutoriales, librerías y proyectos

#### ¿Por qué Arduino es tan Popular?

| Ventaja             | Descripción                                  |
| ------------------- | -------------------------------------------- |
| **Fácil de usar**   | No necesitas ser experto en electrónica      |
| **Económico**       | Placas desde $5-25 USD                       |
| **Multiplataforma** | Funciona en Windows, macOS, Linux            |
| **Gran comunidad**  | Miles de ejemplos y ayuda disponible         |
| **Open Source**     | Diseños libres, puedes crear tu propia placa |
| **Extensible**      | Shields y módulos para cualquier proyecto    |

#### Ecosistema Arduino

```
┌─────────────────────────────────────────────────────────────┐
│                   ECOSISTEMA ARDUINO                        │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ┌──────────────┐                    ┌──────────────┐      │
│  │   HARDWARE   │                    │   SOFTWARE   │      │
│  │              │                    │              │      │
│  │ • Arduino    │                    │ • Arduino    │      │
│  │   Uno        │◄──── Conectado ───►│   IDE        │      │
│  │ • Nano       │      via USB       │              │      │
│  │ • Mega       │                    │ • Librerías  │      │
│  │ • ESP32      │                    │              │      │
│  └──────────────┘                    └──────────────┘      │
│         │                                   │               │
│         ▼                                   ▼               │
│  ┌──────────────┐                    ┌──────────────┐      │
│  │   SHIELDS    │                    │  SIMULADORES │      │
│  │              │                    │              │      │
│  │ • Motor      │                    │ • Tinkercad  │      │
│  │ • WiFi       │                    │ • Wokwi      │      │
│  │ • Display    │                    │ • Proteus    │      │
│  └──────────────┘                    └──────────────┘      │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 1.3 Familia Arduino Uno

El **Arduino Uno** es la placa más popular para aprender. Existen varias versiones:

#### Comparativa de Placas

| Característica       | Uno R3     | Uno R4 Minima | Uno R4 WiFi |
| -------------------- | ---------- | ------------- | ----------- |
| **Microcontrolador** | ATmega328P | RA4M1 (ARM)   | RA4M1 (ARM) |
| **Arquitectura**     | 8-bit AVR  | 32-bit ARM    | 32-bit ARM  |
| **Velocidad**        | 16 MHz     | 48 MHz        | 48 MHz      |
| **Flash**            | 32 KB      | 256 KB        | 256 KB      |
| **SRAM**             | 2 KB       | 32 KB         | 32 KB       |
| **Voltaje**          | 5V         | 5V            | 5V          |
| **Pines Digitales**  | 14         | 14            | 14          |
| **Pines PWM**        | 6          | 6             | 6           |
| **Pines Analógicos** | 6          | 6             | 6           |
| **WiFi**             | ❌         | ❌            | ✅          |
| **Bluetooth**        | ❌         | ❌            | ✅          |
| **Matriz LED**       | ❌         | ❌            | ✅ 12x8     |
| **USB**              | Type-B     | Type-C        | Type-C      |
| **Tinkercad**        | ✅         | ❌            | ❌          |
| **Precio aprox.**    | $10-15     | $15-20        | $25-30      |

#### ¿Cuál Elegir?

```
┌─────────────────────────────────────────────────────────────┐
│                    GUÍA DE SELECCIÓN                        │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ¿Estás aprendiendo o simulando?                           │
│            │                                                │
│     ┌──────┴──────┐                                        │
│     ▼             ▼                                        │
│   [ SÍ ]       [ NO ]                                      │
│     │             │                                        │
│     ▼             ▼                                        │
│ ┌────────┐   ¿Necesitas WiFi/Bluetooth?                    │
│ │UNO R3  │        │                                        │
│ │        │   ┌────┴────┐                                   │
│ │Tinkercad│  ▼         ▼                                   │
│ │compatible│[ SÍ ]   [ NO ]                                │
│ └────────┘   │         │                                   │
│              ▼         ▼                                   │
│         ┌────────┐ ┌────────┐                              │
│         │UNO R4  │ │UNO R4  │                              │
│         │WiFi    │ │Minima  │                              │
│         └────────┘ └────────┘                              │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

> 📌 **Para este bootcamp:** Usaremos principalmente **Arduino Uno R3** porque es compatible con Tinkercad. Los conceptos aplican a todas las versiones.

---

### 1.4 Anatomía del Arduino Uno R3

```
                         ARDUINO UNO R3
    ┌─────────────────────────────────────────────────────┐
    │   ┌─────┐                              ┌─────┐      │
    │   │RESET│       ┌──────────┐          │ICSP │      │
    │   └──┬──┘       │   USB    │          └─────┘      │
    │      │          │  Type-B  │                       │
    │      │          └────┬─────┘                       │
────┤ IOREF│               │                             ├────
────┤ RESET│        ┌──────┴──────┐                      │ D13
────┤ 3.3V │        │             │                      │ D12
────┤  5V  │        │  ATmega328P │        [LED]         │ D11~
────┤ GND  │        │             │         L            │ D10~
────┤ GND  │        │   16 MHz    │                      │ D9~
────┤ Vin  │        │             │                      │ D8
    │      │        └─────────────┘                      ├────
────┤  A0  │                                             │ D7
────┤  A1  │        ┌─────────────┐                      │ D6~
────┤  A2  │        │   POWER     │                      │ D5~
────┤  A3  │        │     ◯      │                      │ D4
────┤A4/SDA│        │   Jack DC   │                      │ D3~
────┤A5/SCL│        └─────────────┘                      │ D2
    │      │                                             │ TX→1
    │      │                                             │ RX←0
    └──────┴─────────────────────────────────────────────┴────

    ALIMENTACIÓN        ANALÓGICOS              DIGITALES
    Y CONTROL           (6 pines)               (14 pines)
```

#### Grupos de Pines

| Grupo            | Pines                          | Función                             |
| ---------------- | ------------------------------ | ----------------------------------- |
| **Alimentación** | 5V, 3.3V, GND, Vin             | Proveer energía a componentes       |
| **Digitales**    | D0-D13                         | Entrada/Salida HIGH(5V) o LOW(0V)   |
| **PWM (~)**      | D3, D5, D6, D9, D10, D11       | Salida "analógica" simulada         |
| **Analógicos**   | A0-A5                          | Lectura de voltajes (0-5V → 0-1023) |
| **Comunicación** | TX(1), RX(0), SDA(A4), SCL(A5) | Serial, I2C                         |
| **Especiales**   | RESET, ICSP                    | Reinicio, programación directa      |

---

## 💡 Puntos Clave

1. **Microcontrolador ≠ Microprocesador:** El MCU tiene todo integrado (CPU, memoria, periféricos)
2. **Arduino = Hardware + Software + Comunidad**
3. **Uno R3 para aprender:** Compatible con Tinkercad y la mayoría de tutoriales
4. **Los pines son la interfaz:** Conectan el MCU con el mundo físico

---

## ⚠️ Errores Comunes

| Error              | Problema                         | Solución                                         |
| ------------------ | -------------------------------- | ------------------------------------------------ |
| Confundir voltajes | Conectar 5V a componente de 3.3V | Verificar especificaciones siempre               |
| Ignorar GND        | Circuito no funciona             | Todo circuito necesita referencia a tierra       |
| Usar pin 0 o 1     | Conflicto con Serial             | Evitar D0/D1 si usas Serial Monitor              |
| Olvidar el `~`     | PWM no funciona                  | Solo pines marcados con `~` soportan analogWrite |

---

## ✅ Autoevaluación

Responde mentalmente o en tu cuaderno:

1. ¿Qué diferencia hay entre Flash y SRAM en un microcontrolador?
2. ¿Por qué el Arduino Uno R3 es mejor para principiantes que el R4 WiFi?
3. ¿Cuántos pines PWM tiene el Arduino Uno?
4. ¿Qué función tienen los pines A0-A5?
5. ¿Qué significa "open source" en el contexto de Arduino?

<details>
<summary>💡 Ver respuestas</summary>

1. **Flash** almacena el programa y persiste sin energía; **SRAM** es temporal y se borra al apagar.
2. El **R3 es compatible con Tinkercad** para simulación, tiene más tutoriales y es más económico.
3. **6 pines PWM**: D3, D5, D6, D9, D10, D11 (marcados con ~).
4. Son **entradas analógicas** que leen voltajes de 0-5V y los convierten a valores de 0-1023.
5. **Open source** significa que los diseños son públicos y libres de usar, modificar y compartir.

</details>

---

## 🔗 Referencias

- [Arduino Uno R3 - Documentación Oficial](https://docs.arduino.cc/hardware/uno-rev3)
- [Arduino Uno R4 - Documentación Oficial](https://docs.arduino.cc/hardware/uno-r4-wifi)
- [¿Qué es un Microcontrolador? - SparkFun](https://learn.sparkfun.com/tutorials/what-is-a-microcontroller)

---

<div align="center">

[⬅️ Índice Teoría](./README.md) | [Módulo 02 ➡️](./02-electronica-basica.md)

</div>
