#include "vm.h"
#include "bytecode.h"
#include <stdio.h>

int main() {
    // Bytecode program: PUSH 5, PUSH 10, ADD, HALT
        uint8_t code[] = {
        OP_PUSH, 5, 0, 0, 0,
        OP_PUSH, 3, 0, 0, 0,
        OP_ADD,
        OP_PUSH, 2, 0, 0, 0,
        OP_MUL,
        OP_PUSH, 4, 0, 0, 0,
        OP_SUB,
        OP_HALT
    };

    VM *vm = vm_create(code);
    vm_execute(vm);
    printf("Result: %d\n", vm_pop(vm));
    vm_free(vm);
}