cmake_minimum_required(VERSION 3.20)
project(01_Blink C)
# --- Einstellungen (können per -D auf der Kommandozeile überschrieben werden) ---
set(MCU atmega328p CACHE STRING "Mikrocontroller für avr-gcc")
set(AVRDUDE_PART m328p CACHE STRING "Mikrocontroller für avrdude")
set(F_CPU 16000000UL CACHE STRING "Taktfrequenz in Hz")
set(PROG_DEV COM10 CACHE STRING "Serieller Port des Nano (Windows: COM3 o. ä.)")
set(BAUD 57600 CACHE STRING "Bootloader-Baudrate (Clone: 57600, Original: 115200)")
find_program(AVR_OBJCOPY avr-objcopy REQUIRED)
find_program(AVR_SIZE avr-size REQUIRED)
find_program(AVRDUDE avrdude REQUIRED)
add_executable(${PROJECT_NAME} main.c)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")
target_compile_options(${PROJECT_NAME} PRIVATE -mmcu=${MCU} -Os -Wall -Wextra -std=c11)
target_compile_definitions(${PROJECT_NAME} PRIVATE F_CPU=${F_CPU})
target_link_options(${PROJECT_NAME} PRIVATE -mmcu=${MCU})
# Nach dem Bauen: HEX-Datei erzeugen und Speicherbedarf anzeigen
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${AVR_OBJCOPY} -O ihex -R .eeprom $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.hex
        COMMAND ${AVR_SIZE} $<TARGET_FILE:${PROJECT_NAME}>
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Erzeuge ${PROJECT_NAME}.hex"
)
# Target "flash": baut bei Bedarf und überträgt das Programm auf den Nano
add_custom_target(flash
        COMMAND ${AVRDUDE} -c arduino -p ${AVRDUDE_PART} -P ${PROG_DEV} -b ${BAUD}
        -U flash:w:${PROJECT_NAME}.hex:i
        DEPENDS ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Flashe ${PROJECT_NAME}.hex auf ${PROG_DEV}"
        USES_TERMINAL
)