//
// Created by OneFl on 2020/10/23.
//
#include "person.h"
#include "student.h"
#include "senior.h"
#include <stdio.h>

int main(){
    Person person = newPerson(
            "Jhon",
            180,
            70,
            man
    );
    char string[2000];
    printf("Person: %s\n", person_toString(&person, string));

    Student student = newStudent(
            "Jhon",
            180,
            70,
            man,
            12,
            1
    );
    printf("Student: %s\n", student_toString(&student, string));
    printf("Person: %s\n", person_toString((Person*)(&student), string));// 调用父类方法

    Senior senior = newSenior(
            "Jhon",
            180,
            70,
            man,
            12,
            1,
            "\"How to feed a cat\""
    );
    printf("Senior: %s\n", senior_toString(&senior, string));

    return 0;
}

