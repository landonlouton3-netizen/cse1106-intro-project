#include <stdio.h>
#include <stdlib.h>

/* Counts how many digits a non-negative number has. */
int count_digits(long n) {
    int count = 0;
    if (n == 0) return 1;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main(void) {
    long n;

    printf("Enter a number: ");
    if (scanf("%ld", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    n = labs(n);                       /* ignore the sign */
    int digits = count_digits(n);

    /* Remove the digits to the right of the middle */
    long temp = n;
    for (int i = 0; i < digits / 2; i++) {
        temp /= 10;
    }

    if (digits % 2 == 1) {
        /* Odd number of digits: exactly one middle digit */
        printf("Middle digit: %ld\n", temp % 10);
    } else {
        /* Even number of digits: two middle digits */
        printf("Middle digits: %ld%ld\n", (temp / 10) % 10, temp % 10);
    }

    return 0;
}
