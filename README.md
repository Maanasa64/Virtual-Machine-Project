# Virtual Machine (VM) Project

A simple stack-based virtual machine implemented in C. This VM executes bytecode instructions and supports basic operations like arithmetic, stack manipulation, and control flow.

## Features

- **Stack-based architecture** with 256-element stack
- **Custom instruction set**:
  - Arithmetic: `ADD`, `SUB`, `MUL`, `DIV`
  - Stack operations: `PUSH`, `POP`
  - Control flow: `HALT`
- **32-bit integer support** including negative numbers
- **Little-endian bytecode encoding**
- **Comprehensive test suite** covering edge cases

## Build and Run
1. Clone the repository:
   ```
   git clone https://github.com/Maanasa64/vm-project.git
   cd vm-project
   make
   ./vm
   ```
