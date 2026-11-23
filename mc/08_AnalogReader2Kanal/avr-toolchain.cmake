# Diese Datei sagt CMake, dass wir NICHT fuer den PC bauen,
# sondern fuer einen Mikrocontroller.
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
# Welche Compiler benutzt werden sollen
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
# CMake testet normalerweise, ob der Compiler ein lauffaehiges
# Programm erzeugen kann - indem es eines startet. Das geht hier
# nicht, weil das Programm fuer den ATmega ist und nicht fuer den PC.
# Diese Zeile schaltet den Test auf "Bibliothek bauen" um.
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
# Nicht im PC-System nach Bibliotheken suchen
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)