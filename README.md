# DINAMIČNI SISTEMI

Numerical simulations of dynamical systems for FNM UM FIZ (pendulums, damped and driven oscillators, ...).
The simulations are written in C++ and write their results to text files.
The Python scripts then load those files for analysis and plotting.

## Project structure

```
.
├── CMakeLists.txt     # build configuration
├── main.cpp           # entry point, calls the simulations
├── src/               # C++ sources (one class per exercise, e.g. Vaja1)
├── python/            # analysis and plotting scripts
├── output/            # simulation output (.dat files), one subfolder per exercis
```

## Setup

### 1. Create the output folders

The C++ code opens files for writing but does **not** create folders.
Before the first run, create one folder per exercise inside `output/`:

```bash
mkdir -p output/vaja1
```

For exercise N, use `output/vaja<N>`, for example `output/vaja2`, `output/vaja3`.
If the folder is missing, `fopen` returns `NULL` and nothing is written.

### 2. Build and run the C++ code

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
./cmake-build-debug/dinamicni_sistemi
```

In CLion this is just the normal Run button.

Output files are written to `output/vaja<N>/`, for example `output/vaja1/dusnih.dat`.
Each line is whitespace-separated columns, usually `t  fi  om` (time, angle, angular velocity).

### 3. Run the Python scripts

```bash
python -m venv .venv
source .venv/bin/activate
pip install numpy matplotlib
python python/<script>.py
```
(Also set the .venv as the interpreter in your IDE)
The scripts read from `output/vaja<N>/`, so run the C++ simulation first.
## Notes

- Paths are anchored to the project root, so the programs work regardless of the directory they are started from.
- The integrators use semi-implicit (symplectic) Euler, which avoids the artificial energy growth of plain explicit Euler.