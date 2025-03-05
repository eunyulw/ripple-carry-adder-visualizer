#include <stdio.h>
#include "adder.h"
#include <unistd.h>

// visualizing ripple carry adder with ASCII
void ripple_carry_adder(int a, int b) {
    int sum = 0, carry = 0;

    printf("\n=== Ripple Carry Adder Visualization ===\n");
    binary_brackets("A   ", a, 4);
    binary_brackets("B   ", b, 4);
    printf("  +----------------------------+\n");
    printf("  | Full Adder Circuit Flow   |\n");
    printf("  +----------------------------+\n");

    for (int i = 0; i < 4; i++) {
        int bit_a = (a >> i) & 1;
        int bit_b = (b >> i) & 1;
        int bit_sum = bit_a ^ bit_b ^ carry;
        int new_carry = (bit_a & bit_b) | (bit_b & carry) | (bit_a & carry);

        sum |= (bit_sum << i);
        printf("\nStep %d: Bit %d\n", i + 1, i);
        printf("  +---+   +---+   +---+\n");
        printf("  | %d |-->| %d |-->| %d |--> Carry: %d\n", bit_a, bit_b, carry, new_carry);
        printf("  +---+   +---+   +---+\n");
        printf("       | Sum: %d |\n", bit_sum);
        printf("       +--------+\n");
        if (i < 3) {
            printf("         ||||\n");
            printf("         vvvv\n");
        }

        sleep(1);
        carry = new_carry;
    }

    printf("\n  +----------------------------+\n");
    printf("  |        Final Result        |\n");
    printf("  +----------------------------+\n");
    binary_brackets("Sum ", sum, 4);
    printf("Final Carry: %d\n", carry);
}