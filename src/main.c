#include "vm.h"
#include "bytecode.h"
#include <stdio.h>

void run_test(const char* name, uint8_t* code, int expected) {
    printf("Test '%s': ", name);
    VM *vm = vm_create(code);
    vm_execute(vm);
    int result = vm_pop(vm);
    if (result == expected) {
        printf("PASSED (Result: %d)\n", result);
    } else {
        printf("FAILED (Expected: %d, Got: %d)\n", expected, result);
    }
    vm_free(vm);
}

int main() {
    // Test 1: Basic addition (5 + 3 = 8)
    uint8_t test1[] = {
        OP_PUSH, 5, 0, 0, 0,
        OP_PUSH, 3, 0, 0, 0,
        OP_ADD,
        OP_HALT
    };
    run_test("Simple Addition", test1, 8);

    // Test 2: Chained operations ((5 + 3) * 2 - 4 = 12)
    uint8_t test2[] = {
        OP_PUSH, 5, 0, 0, 0,
        OP_PUSH, 3, 0, 0, 0,
        OP_ADD,
        OP_PUSH, 2, 0, 0, 0,
        OP_MUL,
        OP_PUSH, 4, 0, 0, 0,
        OP_SUB,
        OP_HALT
    };
    run_test("Chained Operations", test2, 12);

    // Test 3: Division (15 / 3 = 5)
    uint8_t test3[] = {
        OP_PUSH, 15, 0, 0, 0,
        OP_PUSH, 3, 0, 0, 0,
        OP_DIV,
        OP_HALT
    };
    run_test("Division", test3, 5);

    // Test 4: Stack manipulation (push, pop, push)
    uint8_t test4[] = {
        OP_PUSH, 10, 0, 0, 0,
        OP_POP,
        OP_PUSH, 20, 0, 0, 0,
        OP_HALT
    };
    run_test("Stack Manipulation", test4, 20);

    // Test 5: Negative numbers (-5 * 3 = -15)
    uint8_t test5[] = {
    OP_PUSH, 0xFF, 0xFF, 0xFF, 0xFB, // -5 in two's complement
    OP_PUSH, 3, 0, 0, 0,
    OP_MUL,
    OP_HALT
    };
    run_test("Negative Numbers", test5, -15);

    // Test 6: Complex expression (2*(3+4)-5/5 = 13)
    uint8_t test6[] = {
        OP_PUSH, 3, 0, 0, 0,
        OP_PUSH, 4, 0, 0, 0,
        OP_ADD,
        OP_PUSH, 2, 0, 0, 0,
        OP_MUL,
        OP_PUSH, 5, 0, 0, 0,
        OP_PUSH, 5, 0, 0, 0,
        OP_DIV,
        OP_SUB,
        OP_HALT
    };
    run_test("Complex Expression", test6, 13);

    // Test 7: Maximum value (2^31-1)
    uint8_t test7[] = {
        OP_PUSH, 0xFF, 0xFF, 0xFF, 0x7F, // INT_MAX
        OP_HALT
    };
    run_test("Maximum Integer", test7, 2147483647);

    return 0;
}