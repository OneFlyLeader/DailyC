//
// Created by OneFl on 2020/10/21.
//

#ifndef DAILYC_JSONTOOL_H
#define DAILYC_JSONTOOL_H

cJSON* newJson();
cJSON* newArray();
int addString(cJSON* json, char* itemName, char* value);
int addArray(cJSON* container, char* itemName, cJSON* jsonArray);
int addNumber(cJSON* container, char* itemName, double value);
int addBool(cJSON* container, char* itemName, cJSON_bool bool);
int addArray(cJSON* container, char* itemName, cJSON* jsonArray);
int addJson(cJSON* container, char* itemName, cJSON* other);
char* toString(cJSON* json);
void deleteJson(cJSON* json);
#endif //DAILYC_JSONTOOL_H
