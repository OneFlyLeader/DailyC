//
// Created by OneFl on 2020/10/21.
//

#include <stdio.h>
#include "cjson.h"

#if 0
int main(){
    /**
     * 解析JSON
     */
    char* data = "{\"name\":\"Messi\",\"age\":29}";
    //从缓冲区中解析json结构
    cJSON* root = cJSON_Parse(data);
    if (data == NULL)
    {
        return -1;
    }

    cJSON* itemName = cJSON_GetObjectItem(root, "name");

    if (itemName)
    {
        printf("name: %s\n", itemName->valuestring);
    }

    cJSON* itemAge = cJSON_GetObjectItem(root, "age");
    if (itemAge)
    {
        printf("age: %d\n", itemAge->valueint);
    }
    //讲json结构占用的数据空间释放
    cJSON_Delete(root);

    /**
     * 生成JSON
     */
    char *char_json = "{\"hello\":\"你好\"}";

    //从缓冲区中解析出JSON结构
    cJSON *json = cJSON_Parse(char_json);

    if (json == NULL)
    {
        return -1;
    }

    //将传入的JSON结构转化为字符串
    char *buf = NULL;
    buf = cJSON_Print(json);

    //打开一个info.json文件，并写入json内容
    FILE *fp = fopen("../cjson/info.json", "w");// 根目录在Debug下
    fwrite(buf, strlen(buf), 1, fp);

    fclose(fp);//关闭文件
    free(buf);//释放资源
    cJSON_Delete(json);//释放资源

    return 0;
}
#endif

int main(){
    cJSON *monitor = cJSON_CreateObject();
    cJSON *name = cJSON_CreateString("hello");
    cJSON_AddItemToObject(monitor, "name", name);
    printf("%s\n", cJSON_Print(monitor));
    return 0;
}
