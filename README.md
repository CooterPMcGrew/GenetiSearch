# GenetiSearch

## Overview
GenetiSearch is a modular genetic algorithm framework designed for flexible experimentation with different species and solution spaces. The project is structured to allow easy modifications and testing of evolutionary algorithms. It is built using C++ and leverages CMake for cross-platform compatibility.

## Features
- **Modular Genetic Algorithm Framework**: Supports different species and solution spaces.
- **Configurable Evolutionary Strategies**: Allows customization of selection, mutation, and crossover mechanisms.
- **CMake Build System**: Ensures easy compilation and extensibility.
- **Test Suite**: Built-in testing framework for validating algorithm performance.
- **Cross-Platform Compatibility**: Works on Windows, Linux, and macOS with minimal setup.

## Directory Structure
```
GenetiSearch/
│── build/                  # Compiled binaries and CMake build files
│── src/                    # Source code
│   ├── GeneticAlgorithm/   # Core GA logic
│   ├── Utils/              # Utility functions
│   ├── main.cpp            # Main program entry
│   ├── test_GA_Evolver.cpp # Testbench for GA evolution
│── CMakeLists.txt          # CMake build system configuration
│── .gitignore              # Ignored files for Git
│── README.md               # Project documentation
```

## Installation & Compilation
### **1. Install Dependencies**
Ensure you have **CMake** and **GCC/MinGW** installed:
```sh
cmake --version
gcc --version
```
If missing, install **MinGW-w64** for Windows or `gcc` for Linux/Mac.

### **2. Clone the Repository**
```sh
git clone https://github.com/YOUR_USERNAME/GenetiSearch.git
cd GenetiSearch
```

### **3. Build the Project**
From the project root directory, run:
```sh
mkdir -p build
cd build
cmake -G "MinGW Makefiles" ..
make
```
This will compile the main program and test binaries into the `build/` directory.

### **4. Running the Executables**
Run the main program:
```sh
./build/GenetiSearch.exe
```
Run the testbench:
```sh
./build/test_GA.exe
```

## Development Workflow
### **Adding New Source Files**
If you add a new `.cpp` file, CMake will automatically include it.
However, if you need a **new executable**, update `CMakeLists.txt` like this:
```cmake
add_executable(my_test src/MyTest.cpp)
```
Then, rebuild:
```sh
cmake ..
make
```

### **Cleaning the Build**
If CMake configurations change, remove old files and rebuild:
```sh
rm -rf build/*
cmake -G "MinGW Makefiles" ..
make
```

## Contribution Guidelines
We welcome contributions! To contribute:
1. Fork the repository on GitHub.
2. Create a new branch: `git checkout -b feature-branch`.
3. Make your changes and commit: `git commit -m "Description of changes"`.
4. Push to your fork: `git push origin feature-branch`.
5. Open a Pull Request on GitHub.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


