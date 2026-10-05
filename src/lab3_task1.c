/*
 * Name: Ozodbek Mashrabov
 * Student ID: 251ADB085
 */

#include <stdio.h>

int array_min(int arr[], int size) {
  int min_val = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < min_val) {
      min_val = arr[i];
    }
  }
  return min_val;
}

int array_max(int arr[], int size) {
  int max_val = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max_val) {
      max_val = arr[i];
    }
  }
  return max_val;
}

int array_sum(int arr[], int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += arr[i];
  }
  return total;
}

float array_avg(int arr[], int size) {
  int total = array_sum(arr, size);
  return (float)total / size;
}

int main(void) {
  int arr[] = {10, 20, 5, 30, 15};
  int size = 5;

  printf("Min: %d\n", array_min(arr, size));
  printf("Max: %d\n", array_max(arr, size));
  printf("Total: %d\n", array_sum(arr, size));
  printf("Avg: %.2f\n", array_avg(arr, size));

  return 0;
}