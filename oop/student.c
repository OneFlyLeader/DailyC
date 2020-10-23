//
// Created by OneFl on 2020/10/23.
//

#include "student.h"
#include "stdio.h"

Student newStudent(char* name, int height, int weight, Gender gender, int SID, int class){
    return (Student){newPerson(name, height, weight, gender), SID, class};
}

void student_read(Student* stu);
void student_write(Student* stu);
void student_examine(Student* stu);

char* student_toString(Student* stu, char* string){
    sprintf(string, "%s, SID:%d, class:%d", person_toString(&(stu->super), string), stu->SID, stu->Class);
    return string;
}