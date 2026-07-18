cmake_minimum_required(VERSION 3.16)
project(deltamatroids CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(OpenMP REQUIRED)

add_executable(deltamatroids
    src/DeltaMatroide.cc
    src/Determinante.cc
    src/Ejecucion.cc
    src/ExportadorSalida.cc
    src/Huella.cc
    src/LectorEntrada.cc
    src/LectorParametros.cc
    src/Modulo.cc
    src/ModuloDepuracion.cc
    src/ModuloMDDM.cc
    src/ModuloMEI.cc
    src/ModuloMER.cc
    src/ModuloMGCP.cc
    src/ModuloMGEV.cc
    src/ModuloOperaciones.cc
    src/Racional.cc
    src/main.cc
)

target_include_directories(deltamatroids PRIVATE include/deltamatroids)
target_link_libraries(deltamatroids PRIVATE OpenMP::OpenMP_CXX)
