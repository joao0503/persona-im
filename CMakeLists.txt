cmake_minimum_required(VERSION 3.27)
project(persona_project C)
set(CMAKE_C_STANDARD 99)

# Configuração da Raylib via FetchContent (Mesmo padrão usado nos exemplos do Clay)
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "5.5"
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)

# Define o executável e inclui os arquivos necessários
# Se você criar mais arquivos .c (ex: menu.c), adicione-os aqui!
add_executable(persona main.c components.c)

# Inclui a pasta raiz para encontrar o clay.h (já que está em ../clay.h)
target_include_directories(persona PRIVATE ..)

# Linka com a Raylib e bibliotecas de sistema necessárias no Linux
target_link_libraries(persona PUBLIC raylib)

# Copia a pasta de recursos para a pasta de build automaticamente
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/resources")
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endif()

# No Linux, a Raylib precisa dessas bibliotecas extras
if(UNIX AND NOT APPLE)
    target_link_libraries(persona PUBLIC m pthread dl rt X11)
endif()

# Mensagem informativa ao terminar a configuração
message(STATUS "Projeto Persona configurado. Use 'cmake --build build' para compilar.")
