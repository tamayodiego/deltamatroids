# deltamatroids

Programa de investigación en C++ para generar y clasificar **delta-matroides**
(una generalización de los matroides): construye extensiones de una
delta-matroide base, elimina duplicados por isomorfismo/delta-equivalencia,
separa las representables sobre GF(3) ("ternarias") de las que no lo son, y
filtra por propiedades estructurales como el ancho (`anchura`).

Reorganización, con estructura estándar de directorios y build con CMake, del
código original en [ProgramaOctubre](../ProgramaOctubre).

## Estructura del proyecto

```
deltamatroids/
├── CMakeLists.txt        # build con CMake (requiere OpenMP)
├── include/deltamatroids/ # headers (.h)
├── src/                    # implementación (.cc) + main.cc
├── data/examples/          # archivos de entrada de ejemplo
└── LICENSE
```

## Compilar

Requiere un compilador con soporte de OpenMP.

```bash
# Linux, o macOS con gcc de Homebrew (brew install gcc)
cmake -S . -B build
cmake --build build -j

# macOS con clang del sistema: instalar libomp primero
brew install libomp
cmake -S . -B build \
  -DOpenMP_CXX_FLAGS="-Xpreprocessor -fopenmp -I$(brew --prefix libomp)/include" \
  -DOpenMP_CXX_LIB_NAMES=omp \
  -DOpenMP_omp_LIBRARY=$(brew --prefix libomp)/lib/libomp.dylib
cmake --build build -j
```

El binario resultante queda en `build/deltamatroids`.

## Uso

```bash
./build/deltamatroids -P <n_hilos>   # modo paralelo con n_hilos hilos OpenMP
./build/deltamatroids -S             # modo serial (por defecto)
./build/deltamatroids -I <archivo>   # archivo de entrada (por defecto: "entrada")
./build/deltamatroids -O <archivo>   # archivo de salida (por defecto: "Ternarios")
./build/deltamatroids -D             # activa modo de depuración
```

Ver `data/examples/entrada` para el formato de archivo de entrada.

## Estado del proyecto

Código de investigación en desarrollo activo. Ver [CLAUDE.md](CLAUDE.md) para
una descripción detallada de la arquitectura. No hay suite de pruebas
automatizada todavía; `main()` (`src/main.cc`) actualmente contiene lógica de
prueba ad hoc y no invoca aún el pipeline completo expuesto en `Ejecucion`.

## Licencia

MIT — ver [LICENSE](LICENSE).
