//
// Created by OneFl on 2020/10/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"

int main(){
    char* src = "11111111111111111111111111111111111111111111111111111111";
    int len = strlen(src);
    unsigned int res[4];
    Md5(src, len, res);
    if(NULL == res)
        printf("error in %d\n", __LINE__);
    else
        printf("MD5: %08x%08x%08x%08x\n", res[0], res[1], res[2], res[3]);

    return 0;
}