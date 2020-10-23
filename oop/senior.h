//
// Created by OneFl on 2020/10/23.
//

#ifndef DAILYC_SENIOR_H
#define DAILYC_SENIOR_H
#include "student.h"

typedef struct {
    Student super;
    char* paper;
} Senior;

Senior newSenior(char* name, int height, int weight, Gender gender, int SID, int class, char* paper);
void senior_read(Senior * senior);
void senior_write(Senior* senior);
void senior_examine(Senior* senior);
char* senior_toString(Senior* senior, char* string);

#endif //DAILYC_SENIOR_H
