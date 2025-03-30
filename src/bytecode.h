#ifndef BYTECODE_H
#define BYTECODE_H

typedef enum {
    OP_PUSH,    // Push a value onto the stack
    OP_POP,     // Pop a value from the stack
    OP_ADD,     // Add the top two values on the stack
    OP_SUB,     // Subtract the top two values on the stack
    OP_MUL,     // Multiply the top two values on the stack
    OP_DIV,     // Divide the top two values on the stack
    OP_HALT     // Stop execution
} OpCode;

#endif