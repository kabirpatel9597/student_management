#include <stdio.h>
#include "../include/student.h"

void showMenu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. List Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, id;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                listStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
