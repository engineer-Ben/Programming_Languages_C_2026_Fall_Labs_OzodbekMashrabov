// week5_task2_struct_save_load.c
// Name: Ozodbek  Surname: Mashrabov  Student ID: 251ADB085
//
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// TODO: Complete the function implementations and the file handling logic.
//
// Build: make lab5   Run: ./bin/week5_task2_struct_save_load

#include <stdio.h>

typedef struct Student {
  char name[50];
  int age;
  float gpa;
} Student;

int save_student(const Student* s, const char* filename) {
  FILE* fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file for writing");
    return -1;
  }

  if (fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa) < 0) {
    fclose(fp);
    return -1;
  }

  if (fclose(fp) != 0) {
    return -1;
  }
  return 0;
}

int load_student(const char* filename, Student* out) {
  Student tmp = {0};

  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file for reading");
    return -1;
  }

  if (fscanf(fp, "%49s %d %f", tmp.name, &tmp.age, &tmp.gpa) != 3) {
    fclose(fp);
    return -1;
  }
  fclose(fp);

  *out = tmp;
  return 0;
}

int main(void) {
  Student original = {"Alice", 21, 3.75f};
  Student loaded = {0};

  printf("Saving student to file...\n");
  if (save_student(&original, "student.txt") != 0) {
    fprintf(stderr, "Error: could not save student.\n");
    return 1;
  }

  printf("Loading student from file...\n");
  if (load_student("student.txt", &loaded) != 0) {
    fprintf(stderr, "Error: could not load student.\n");
    return 1;
  }

  printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age,
         loaded.gpa);
  return 0;
}
