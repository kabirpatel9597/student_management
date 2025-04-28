#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"
#include "../include/file_manager.h"

void addStudent() {
    Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    getchar(); // consume newline
    printf("Enter Name: ");
    fgets(s.name, NAME_LENGTH, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // remove newline
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    saveStudent(s);
    printf("Student added successfully!\n");
}

void listStudents() {
    loadStudents();
}

void searchStudent() {
    int searchId;
    FILE *file = fopen("data/students.dat", "rb");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter ID to search: ");
    scanf("%d", &searchId);

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.id == searchId) {
            printf("Student found:\nID: %d\nName: %s\nAge: %d\nGPA: %.2f\n", s.id, s.name, s.age, s.gpa);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Student with ID %d not found.\n", searchId);
    }
}

void deleteStudent(int id) {
    removeStudentById(id);
}
