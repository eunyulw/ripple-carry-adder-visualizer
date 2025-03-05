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

    return 0;
}