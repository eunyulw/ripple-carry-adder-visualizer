#include <stdio.h>
#include <string.h>

// for creating the Box visual
void binary_brackets(char* label, int num, int bits) {
    printf("%s:\n", label);

    // Top layer of the Box
    printf("    ");
    for (int i = bits - 1; i >= 0; i--) {
        printf("  ===  ");
    }
    printf("\n    ");

    // Bit values in the Box
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("| %d | ", bit);
    }
    printf("\n    ");
    
    // Bottom layer
    for (int i = bits - 1; i >= 0; i--) {
        printf("  ===  ");
    }
    printf("\n");
}

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
        carry = new_carry;
    }

    printf("\n  +----------------------------+\n");
    printf("  |        Final Result        |\n");
    printf("  +----------------------------+\n");
    binary_brackets("Sum ", sum, 4);
    printf("Final Carry: %d\n", carry);
}

int main() {
    int a, b;
    char char_a[5], char_b[5];

    printf("Enter first 4-bit binary number (e.g., 1010): ");
    scanf("%s", char_a);
    printf("Enter second 4-bit binary number (e.g., 0011): ");
    scanf("%s", char_b);

    // Input validation
    for (int i = 0; i < 4; i++) {
        if ((char_a[i] != '0' && char_a[i] != '1') || 
            (char_b[i] != '0' && char_b[i] != '1')) {
            printf("Error: Use only 0s and 1s!\n");
            return 1;
        }
    }

    // Convert binary strings to integers
    a = 0;
    b = 0;
    for (int i = 0; i < 4; i++) {
        a = (a << 1) | (char_a[i] - '0');
        b = (b << 1) | (char_b[i] - '0');
    }

    ripple_carry_adder(a, b);

    return 0;
}