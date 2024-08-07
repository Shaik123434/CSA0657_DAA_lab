#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int n) {
    int reversed = 0, original = n, remainder;
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    return original == reversed;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPalindrome(num))
        printf("%d is a palindrome.", num);
    else
        printf("%d is not a palindrome.", num);
    return 0;
}
