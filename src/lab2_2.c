#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes
    n! iteratively using a loop (not recursion).

    In main():
      - Ask user for non-negative integer n
      - If n < 0, print an error
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
  long long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

int main(void) {
  int n;

  printf("Enter a non-negative integer n: ");
  if (scanf("%d", &n) != 1) {
    printf("Error: Invalid input.\n");
    return 1;
  }

  if (n < 0) {
    printf("Error: n must be >= 0.\n");
  } else {
    long long result = factorial(n);
    printf("Factorial of %d is %lld\n", n, result);
  }

  return 0;
}
