#include "vm.h"
#include "bytecode.h"
#include <stdio.h>

int main() {
    // Bytecode program: PUSH 5, PUSH 10, ADD, HALT
        uint8_t code[] = {
            OP_PUSH, 5, 0, 0, 0,    // PUSH 5 (little-endian)
            OP_PUSH, 10, 0, 0, 0,   // PUSH 10 (little-endian)
            OP_ADD,
            OP_HALT
        };


    VM *vm = vm_create(code);
    vm_execute(vm);

    printf("Result: %d\n", vm_pop(vm));
    vm_free(vm);
    return 0;
}