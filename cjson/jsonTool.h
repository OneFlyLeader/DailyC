//
// Created by OneFl on 2020/10/21.
//

#ifndef DAILYC_JSONTOOL_H
#define DAILYC_JSONTOOL_H

#define JSON_STRING_LENGHTH 2048

typedef struct {
    char data[JSON_STRING_LENGHTH];    // 存储字符串
    int length;         // 字符串长度不包含'\0'
} JsonString;

JsonString newJsonString();
int pushItemInt(JsonString* jsonStr, char* item, int value);
void printJsonString(JsonString* jsonStr);

#endif //DAILYC_JSONTOOL_H
