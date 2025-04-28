#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "student.h"

// File operations
void saveStudent(Student s);
void loadStudents();
void removeStudentById(int id);

#endif // FILE_MANAGER_H
