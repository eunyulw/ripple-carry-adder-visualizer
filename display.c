#include <stdio.h>
#include "adder.h"

void binary_brackets(char* label, int num, int bits) {
    printf("%s:\n", label);
    printf("     ");
    for (int i = bits - 1; i >= 0; i--) {
        printf("  ===  ");
    }
    printf("\n     ");
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf(" | %d |", bit);
    }
    printf("\n     ");
    for (int i = bits - 1; i >= 0; i--) {
        printf("  ===  ");
    }
    printf("\n");
}

void clear_screen() {
    printf("\033[H\033[J");  // clearing code