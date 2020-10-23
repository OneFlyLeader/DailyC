//
// Created by OneFl on 2020/10/23.
//

#ifndef DAILYC_PERSON_H
#define DAILYC_PERSON_H

typedef enum {
    man,
    woman
} Gender;

typedef struct {
    char* name;
    int height;
    int weight;
    Gender gender;
} Person;

Person newPerson(char* name, int height, int weight, Gender gender);
void person_jump(Person* person);
void person_speak(Person* person, char* sentence);
void person_laugh(Person* person);
char* person_toString(Person* person, char* string);

#endif //DAILYC_PERSON_H
