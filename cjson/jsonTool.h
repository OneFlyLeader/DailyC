//
// Created by OneFl on 2020/10/21.
//

#ifndef DAILYC_JSONTOOL_H
#define DAILYC_JSONTOOL_H

cJSON* newJson();
int addString(cJSON* json, char* itemName, char* value);
int addArray(cJSON* container, char* itemName, cJSON* jsonArray);
int addNumber(cJSON* container, char* itemName, double value);
int addArray(cJSON* container, char* itemName, cJSON* jsonArray);
int addBool(cJSON* container, char* itemName, cJSON_bool bool);
char* toString(cJSON* json);

#endif //DAILYC_JSONTOOL_H
