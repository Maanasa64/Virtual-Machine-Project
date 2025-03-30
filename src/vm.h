#ifndef VM_H
#define VM_H

#include <stdint.h>

#define STACK_SIZE 256

typedef struct {
    int32_t stack[STACK_SIZE]; // Stack for the VM
    int32_t sp;                // Stack pointer
    uint8_t *code;             // Bytecode to execute
    uint32_t pc;               // Program counter
} VM;

// Public API
VM *vm_create(uint8_t *code);
void vm_free(VM *vm);
void vm_execute(VM *vm);
void vm_push(VM *vm, int32_t value);
int32_t vm_pop(VM *vm);

#endif