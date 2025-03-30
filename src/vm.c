#include "vm.h"
#include "bytecode.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new VM instance
VM *vm_create(uint8_t *code) {
    VM *vm = (VM *)malloc(sizeof(VM));
    vm->sp = -1;
    vm->code = code;
    vm->pc = 0;
    return vm;
}

// Free the VM instance
void vm_free(VM *vm) {
    free(vm);
}

// Push a value onto the stack
void vm_push(VM *vm, int32_t value) {
    if (vm->sp >= STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow!\n");
        exit(1);
    }
    vm->stack[++vm->sp] = value;
}

// Pop a value from the stack
int32_t vm_pop(VM *vm) {
    if (vm->sp < 0) {
        fprintf(stderr, "Stack underflow!\n");
        exit(1);
    }
    return vm->stack[vm->sp--];
}

// Execute the bytecode
void vm_execute(VM *vm) {
    while (1) {
        uint8_t opcode = vm->code[vm->pc++];
        switch (opcode) {
            case OP_PUSH: {
            int32_t value = 0;
            value |= vm->code[vm->pc++] << 0;
            value |= vm->code[vm->pc++] << 8;
            value |= vm->code[vm->pc++] << 16;
            value |= vm->code[vm->pc++] << 24;
            vm_push(vm, value);
            break;
        }
            case OP_POP: {
                vm_pop(vm);
                break;
            }
            case OP_ADD: {
                int32_t a = vm_pop(vm);
                int32_t b = vm_pop(vm);
                vm_push(vm, a + b);
                break;
            }
            case OP_SUB: {
                int32_t a = vm_pop(vm);
                int32_t b = vm_pop(vm);
                vm_push(vm, b - a);
                break;
            }
            case OP_MUL: {
                int32_t a = vm_pop(vm);
                int32_t b = vm_pop(vm);
                vm_push(vm, a * b);
                break;
            }
            case OP_DIV: {
                int32_t a = vm_pop(vm);
                int32_t b = vm_pop(vm);
                vm_push(vm, b / a);
                break;
            }
            case OP_HALT: {
                return;
            }
            default: {
                fprintf(stderr, "Unknown opcode: %d\n", opcode);
                exit(1);
            }
        }
    }
}