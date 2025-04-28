#include <stdio.h>
#include <stdlib.h>
#include "../include/file_manager.h"

void saveStudent(Student s) {
    FILE *file = fopen("data/students.dat", "ab"); // append binary
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
}

void loadStudents() {
    FILE *file = fopen("data/students.dat", "rb");
    if (!file) {
        printf("No students found.\n");
        return;
    }

    Student s;
    printf("\n--- Student List ---\n");
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("ID: %d\nName: %s\nAge: %d\nGPA: %.2f\n\n", s.id, s.name, s.age, s.gpa);
    }
    fclose(file);
}

void removeStudentById(int id) {
    FILE *file = fopen("data/students.dat", "rb");
    FILE *temp = fopen("data/temp.dat", "wb");
    if (!file || !temp) {
        printf("Error opening files.\n");
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.id != id) {
            fwrite(&s, sizeof(Student), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("data/students.dat");
    rename("data/temp.dat", "data/students.dat");

    if (found)
        printf("Student deleted successfully!\n");
    else
        printf("Student with ID %d not found.\n", id);
}
