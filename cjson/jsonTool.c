/**
    快速使用 cjson 创建 cJSON 对象
    首先调用 newJson 获得一个容器，然后就可以使用add方法添加任意项到容器中
    By: LCC
 */
#include "cjson.h"
#include "jsonTool.h"

/**
 * 创建容器
 * @return
 */
cJSON* newJson(){
    return cJSON_CreateObject();
}

int errorJson(cJSON* json){
    cJSON_Delete(json);
    return cJSON_False;
}

/**
 * 添加对象到数组或容器(object)中
 * @param container
 * @param name
 * @param item
 * @return
 */
int addObject(cJSON* container, char* name, cJSON* item){
    if (item == NULL) {
        return errorJson(item);
    }
    if(cJSON_IsObject(container)) {
        if(NULL == name) return errorJson(item);
        return cJSON_AddItemToObject(container, name, item);
    }else if(cJSON_IsArray(container)){
        return cJSON_AddItemToArray(container, item);
    }else{
        return errorJson(item);
    }
}

/**
 * 添加字符串
 * @param json
 * @param itemName
 * @param value
 * @return
 */
int addString(cJSON* container, char* itemName, char* value){
    cJSON* jsonStr = cJSON_CreateString(value);
    return addObject(container, itemName, jsonStr);
}

/**
 * 添加数字
 * @param json
 * @param itemName
 * @param value
 * @return
 */
int addNumber(cJSON* container, char* itemName, double value){
    cJSON* jsonNum = cJSON_CreateNumber(value);
    return addObject(container, itemName, jsonNum);
}

/**
 * 添加数组
 * @param container
 * @param itemName
 * @param jsonArray 返回的数组是一个cJSON数组
 * @return
 */
int addArray(cJSON* container, char* itemName, cJSON* jsonArray){
    jsonArray = cJSON_CreateArray();
    return addObject(container, itemName, jsonArray);
}

/**
 * 添加布朗类型
 * @param container
 * @param itemName
 * @param bool
 * @return
 */
int addBool(cJSON* container, char* itemName, cJSON_bool bool){
    cJSON* jsonBool = cJSON_CreateBool(bool);
    return addObject(container, itemName, jsonBool);
}

/**
 * 打印json
 * @param json
 * @return
 */
char* toString(cJSON* json){
    return cJSON_Print(json);
}
