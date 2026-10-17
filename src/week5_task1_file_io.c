/*
 * Name:       <Ozodbek>
 * Surname:    <Mashrabov>
 * Student ID: <251ADB085>
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
  const char* filename = (argc > 1) ? argv[1] : "data.txt";
  char line[256];
  int lines_read = 0;

  FILE* fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file for writing");
    return 1;
  }

  printf("Writing lines to %s...\n", filename);
  fprintf(fp, "Hello, file I/O in C!\n");
  fprintf(fp, "This is another line.\n");

  if (fclose(fp) != 0) {
    perror("Error closing file");
    return 1;
  }

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file for reading");
    return 1;
  }

  printf("Reading contents:\n");
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    lines_read++;
  }
  fclose(fp);

  printf("Lines read: %d\n", lines_read);
  return 0;
}
