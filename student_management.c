#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int roll_no;
    char name[50];
    char course[50];
};

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student database is full. Cannot add more students.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]s", newStudent.name);
    printf("Enter Course: ");
    scanf(" %[^\n]s", newStudent.course);

    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully.\n");
}

void displayStudents(struct Student students[], int count) {
    printf("Roll Number\tName\t\tCourse\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%s\n", students[i].roll_no, students[i].name, students[i].course);
    }
}

void searchStudent(struct Student students[], int count, int roll_no) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("Roll Number\tName\t\tCourse\n");
            printf("%d\t\t%s\t\t%s\n", students[i].roll_no, students[i].name, students[i].course);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll_no);
}

void deleteStudent(struct Student students[], int *count, int roll_no) {
    for (int i = 0; i < *count; i++) {
        if (students[i].roll_no == roll_no) {
            for (int j = i; j < (*count - 1); j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with Roll Number %d deleted.\n", roll_no);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll_no);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                int roll_no;
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll_no);
                searchStudent(students, studentCount, roll_no);
                break;
            case 4:
                printf("Enter Roll Number to delete: ");
                scanf("%d", &roll_no);
                deleteStudent(students, &studentCount, roll_no);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
