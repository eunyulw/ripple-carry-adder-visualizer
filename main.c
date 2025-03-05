#include <stdio.h>
#include <string.h>

void binary_brackets(char* number, int num, int bits) {
    printf("%s: ", number);
    for (int i = bits - 1; i >= 0; i--) {
        printf("[%d]", (num >> i) & 1);
    }
    printf("\n");
}

void ripple_carry_adder(int a, int b) {
    int sum = 0, carry = 0;

    printf("\n=== Ripple Carry Adder Visualization ===\n");

    for (int i = 0; i < 4; i++) {
        int bit_a = (a >> i) & 1;
        int bit_b = (b >> i) & 1;
        int bit_sum = bit_a ^ bit_b ^ carry;
        int new_carry = (bit_a & bit_b) | (bit_b & carry) | (bit_a & carry);  // setting next bit's carry

        sum |= (bit_sum << i);  // getting the sum
        printf("Step %d:\n", i + 1);
        printf("  Bit %d: %d + %d + %d = %d (Carry: %d)\n", i, bit_a, bit_b, carry, bit_sum, new_carry);
        carry = new_carry;
    }

    
}

int main() {
    int a, b;
    char char_a[5], char_b[5];

    printf("Enter first 4-bit binary number (e.g., 1010): ");
    scanf("%s", char_a);
    printf("Enter second 4-bit binary number (e.g., 0011): ");
    scanf("%s", char_b);

    // converting binary to integer using bit-shifting
    a = 0;
    b = 0;
    for (int i = 0; i < 4; i++) {
        a = (a << 1) | (char_a[i] - '0');
        b = (b << 1) | (char_b[i] - '0');
    }

    ripple_carry_adder(a, b);

    return 0;
}