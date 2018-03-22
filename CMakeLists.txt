cmake_minimum_required(VERSION 3.3)

project(cmake-imagenes)

# Dependencias
find_package (OpenCV REQUIRED)

# Banderas de compilación para los ejercicios y ejemplos
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wshadow -pedantic")

# Función para agregar un nuevo ejercicio
function (agregar_ejercicio nombre_ejercicio)
    get_filename_component(PREFIJO ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    add_executable (${PREFIJO}-${nombre_ejercicio} ${nombre_ejercicio}.cpp)
    target_link_libraries (${PREFIJO}-${nombre_ejercicio} ${OpenCV_LIBS})
    set_target_properties(${PREFIJO}-${nombre_ejercicio} PROPERTIES OUTPUT_NAME ${nombre_ejercicio})
endfunction (agregar_ejercicio)

# Función para agregar fuentes a un ejercicio existente
function (agregar_fuentes nombre_ejercicio string_archivos)
    get_filename_component (PREFIJO ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    separate_arguments (lista_archivos UNIX_COMMAND ${string_archivos})
    target_sources (${PREFIJO}-${nombre_ejercicio} PUBLIC ${lista_archivos})
endfunction ()

# Configurar el archivo que va a tener la referencia al directorio fuente del proyecto
configure_file(config.hpp.cmake ${CMAKE_SOURCE_DIR}/config.hpp)

# Ejemplos
add_subdirectory (ejemplos)

# Ejercicios
add_subdirectory (guia_1)
