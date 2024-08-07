#include <stdio.h>

int main() {
    int n, rev = 0, remainder;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n != 0) {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
    printf("Reversed number is %d", rev);
    return 0;
}
