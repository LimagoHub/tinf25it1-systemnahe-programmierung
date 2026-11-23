cmake_minimum_required(VERSION 3.20)

# Toolchain-Datei laden, falls CLion sie nicht schon per Profil mitgibt
if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/avr-toolchain.cmake)
endif()

project(05_PWM C)

# Fest: Arduino Nano (ATmega328P, 16 MHz, Arduino-Bootloader)
set(MCU atmega328p)
set(F_CPU 16000000UL)
set(PROG arduino)

# ============ HIER ANPASSEN ============
set(PORT COM5)  # <<< DEINE Portnummer eintragen!
set(BAUD 57600) # Nano-Clone (alter Bootloader): 57600, Original-Nano (neuer Bootloader): 115200
# =======================================

set(CMAKE_C_STANDARD 99)

# Optionen fuer den Compiler
add_compile_options(
        -mmcu=${MCU}           # Fuer welchen Chip uebersetzt wird
        -DF_CPU=${F_CPU}       # Taktfrequenz an das Programm weitergeben
        -Os                    # Auf kleine Programmgroesse optimieren
        -Wall -Wextra          # Alle Warnungen anzeigen
        -ffunction-sections -fdata-sections
)

# Optionen fuer den Linker
add_link_options(
        -mmcu=${MCU}
        -Wl,--gc-sections      # Ungenutzten Code entfernen
        -Wl,-Map=${PROJECT_NAME}.map
)

# Das eigentliche Programm
add_executable(${PROJECT_NAME}.elf main.c)

# Nach dem Uebersetzen: HEX-Datei erzeugen und Groesse anzeigen
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND avr-objcopy -O ihex -R .eeprom
        $<TARGET_FILE:${PROJECT_NAME}.elf> ${PROJECT_NAME}.hex
        COMMAND avr-size $<TARGET_FILE:${PROJECT_NAME}.elf>
        COMMENT "HEX-Datei erzeugen"
)

# --- Zusaetzliche Knoepfe ---
add_custom_target(flash
        COMMAND avrdude -c ${PROG} -P ${PORT} -b ${BAUD} -p ${MCU}
        -U flash:w:${PROJECT_NAME}.hex:i
        DEPENDS ${PROJECT_NAME}.elf
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Programm auf den Chip laden"
)

add_custom_target(testconnection
        COMMAND avrdude -c ${PROG} -P ${PORT} -b ${BAUD} -p ${MCU} -v
        COMMENT "Verbindung zum Chip pruefen"
)
