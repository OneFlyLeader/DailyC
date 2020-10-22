/**
    快速使用 cjson 创建 cJSON 对象
    首先调用 newJson 获得一个容器，然后就可以使用add方法添加任意项到容器中，使用完需要删除json结构
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

/**
 * 创建数组
 * @return
 */
cJSON* newArray(){
    return cJSON_CreateArray();
}

int errorJson(cJSON* json, cJSON_bool isDelete){
    if(isDelete)
        cJSON_Delete(json);
    return cJSON_False;
}

/**
 * 添加对象到数组或容器(object)中
 * @param container 存储带的容器
 * @param name 标签名
 * @param item 标签值
 * @param isDelete true 如果出错就删除对象；false 出错不删除对象；
 * @return
 */
int addObject(cJSON* container, char* name, cJSON* item, cJSON_bool isDelete){
    if (NULL == item || NULL == container) {
        return errorJson(item, isDelete);
    }
    if(cJSON_IsObject(container)) {
        if(NULL == name) return errorJson(item, isDelete);
        return cJSON_AddItemToObject(container, name, item);
    }else if(cJSON_IsArray(container)){
        return cJSON_AddItemToArray(container, item);
    }else{
        return errorJson(item, isDelete);
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
    return addObject(container, itemName, jsonStr, cJSON_True);
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
    return addObject(container, itemName, jsonNum, cJSON_True);
}

/**
 * 添加数组
 * @param container
 * @param itemName
 * @param jsonArray 返回的数组是一个cJSON数组
 * @return
 */
int addArray(cJSON* container, char* itemName, cJSON* jsonArray){
    if(!cJSON_IsArray(jsonArray)){
        return cJSON_False;
    }
    return addObject(container, itemName, jsonArray, cJSON_False);
}

/**
 * 添加JSON对象
 * @param container
 * @param itemName
 * @param other
 * @return
 */
int addJson(cJSON* container, char* itemName, cJSON* other){
    if(!cJSON_IsObject(other)){
        return cJSON_False;
    }
    return addObject(container, itemName, other, cJSON_False);
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
    return addObject(container, itemName, jsonBool, cJSON_True);
}

/**
 * 打印json
 * @param json
 * @return
 */
char* toString(cJSON* json){
    return cJSON_Print(json);
}

/**
 * 删除cJSON结构
 * @param json
 */
void deleteJson(cJSON* json){
    cJSON_Delete(json);
}