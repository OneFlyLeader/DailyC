//
// Created by OneFl on 2020/10/23.
//
#include "senior.h"
#include "stdio.h"

Senior newSenior(char* name, int height, int weight, Gender gender, int SID, int class, char* paper){
    return (Senior){newStudent(name, height, weight, gender, SID, class), paper};
}

void senior_read(Senior * senior);
void senior_write(Senior* senior);
void senior_examine(Senior* senior);

char* senior_toString(Senior* senior, char* string){
    sprintf(string, "%s, paper:%s", student_toString(&(senior->super), string), senior->paper);
    return string;
}