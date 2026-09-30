#include <stdio.h>

/*
    Task:
    Write a function `int is_prime(int n)` that returns 1 if n is prime,
    and 0 if it is not.

    In main():
      - Ask user for integer n
      - If n < 2, print an error
      - Otherwise, print all prime numbers up to n
*/

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int n;

    printf("Enter an integer n (>= 2): ");
    if (scanf("%d", &n) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    if (n < 2) {
        printf("Error: n must be at least 2.\n");
    } else {
        printf("Prime numbers up to %d:\n", n);
        for (int i = 2; i <= n; i++) {
            if (is_prime(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}