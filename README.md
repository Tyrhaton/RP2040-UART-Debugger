# RP2040_UART_Debugger
![Version](https://img.shields.io/badge/version-1.0.0-green.svg)

A repository demonstrating UART communication using the Raspberry Pi Pico Debug Probe with RP2040-based boards. 

# Setup Instructions

## Option 1: Standalone Project Setup

1. Create a build directory within the root directory:
   ```bash
   mkdir build
   ```

2. Navigate into the build directory:
   ```bash
   cd build
   ```

3. Generate the build files using CMake:
   ```bash
   cmake ..
   ```

4. Compile the project:
   ```bash
   make
   ```
   * Tip: Use `make -j4` to enable parallel compilation for faster build times.

---

## Option 2: Integration into Another Project

1. Navigate to your project's `modules` directory:
   ```bash
   cd modules/
   ```

2. Clone this repository into the modules directory:
   ```bash
   git clone https://github.com/Tyrhaton/RP2040_UART_Debugger.git RP2040_UART_Debugger
   ```
3. Update your project's `CMakeLists.txt`:
   ```bash
   # Add the UART module
   add_library(RP2040_UART_Debugger STATIC
     modules/RP2040_UART_Debugger/uart.c
   )

   # Include the UART module's header files
   target_include_directories(RP2040_UART_Debugger PUBLIC modules/RP2040_UART_Debugger)

   # Link the main executable with the UART library and Pico SDK
   target_link_libraries(${PROJECT_NAME} RP2040_UART_Debugger pico_stdlib)
    ```