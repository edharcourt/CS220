#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double gpa;
} Student;

void g() {

    Student *s = malloc(sizeof(Student));
    s->name = "Hermione";
    s->gpa = 3.99;

}

void print_student(Student *s) {
    printf("%s\n", s->name);
    printf("%.2f\n", s->gpa);
}

double const pi = 3.14159;

double f(int x, char *str) {
     
    int z = 33;	
    char *s = malloc(strlen(str));

    return z*pi;
}
