//
// Created by OneFl on 2020/10/22.
//
#include <stdio.h>
#include "person.h"

Person newPerson(char* name, int height, int weight, Gender gender){
    return (Person){name, height, weight, gender};
}

void person_jump(Person* person){
    printf("%s is jumping.\n", person->name);
}

void person_speak(Person* person, char* sentence){
    printf("%s says %s.\n", person->name, sentence);
}

void person_laugh(Person* person){
    printf("%s is laughing.\n", person->name);
}

char* person_toString(Person* person, char* string){
    char* tmp = NULL;
    if(person->gender == man){
        tmp = "man";
    }else{
        tmp = "woman";
    }
    sprintf(string, "Name:%s, Gender:%s, Height:%d, Weight:%d", person->name, tmp, person->height, person->weight);
    return string;// 返回局部变量
}
