//
// Created by OneFl on 2020/10/23.
//

#ifndef DAILYC_STUDENT_H
#define DAILYC_STUDENT_H
#include "person.h"

typedef struct {
    Person super;
    int SID;
    int Class;
} Student;

Student newStudent(char* name, int height, int weight, Gender gender, int SID, int class);
void student_read(Student* stu);
void student_write(Student* stu);
void student_examine(Student* stu);
char* student_toString(Student* stu, char* string);

#endif //DAILYC_STUDENT_H
