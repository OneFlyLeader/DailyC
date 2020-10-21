/**
    构建JSON相关的工具方法
    By: LCC
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "jsonTool.h"

/**
 * 创建JsonString对象
 * @return
 */
JsonString newJsonString(){
    return (JsonString){{'{','}','\0'},2};
}

/**
 * 插入int，jsonString中的length始终指向下一个字符可以插入的位置
 * @param jsonStr
 * @param item
 * @param value
 * @return
 */
int pushItemInt(JsonString* jsonStr, char* item, int value){
    // 整型转字符串
    char cvalue[10];
    sprintf(cvalue,"%d",value);
    // 插入item名
    // 判断是不是第一个元素
    if(jsonStr->length > 2) {
        jsonStr->data[jsonStr->length - 1] = ',';// 插入分隔符
        jsonStr->data[jsonStr->length++] = '\"';
    }
    else {
        jsonStr->data[jsonStr->length - 1] = '\"';
    }
    for(int i = 0; i < strlen(item); i++){
        jsonStr->data[jsonStr->length++] = item[i];
    }
    jsonStr->data[jsonStr->length++] = '\"';
    jsonStr->data[jsonStr->length++] = ':';
    for(int i = 0; i < strlen(cvalue); i++) {
        if(cvalue[i] != '\0')
            jsonStr->data[jsonStr->length++] = cvalue[i];
        else
            break;
    }
    jsonStr->data[jsonStr->length++] = '}';
    jsonStr->data[jsonStr->length] = '\0';
    return 0;
}

/**
 * 打印字符串
 * @param jsonStr
 */
void printJsonString(JsonString* jsonStr){
    printf("%s\n", jsonStr->data);
}