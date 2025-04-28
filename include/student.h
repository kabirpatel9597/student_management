#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    float gpa;
} Student;

// Student operations
void addStudent();
void listStudents();
void searchStudent();
void deleteStudent(int id);

#endif // STUDENT_H
