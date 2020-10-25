//
// Created by OneFl on 2020/10/25.
//
#include <stdio.h>

int sum(int* nums, int len){
    int i = 0;
    int res = 0;
    for(i = 0; i < len; i++){
        res += nums[i];
    }
    return res;
}

int main(){
    int nums[3] = {1,2,3};
    int len = (sizeof(nums)/sizeof(int));
    printf("%d\n", sum(nums, len));

    /**
     * 设置函数指针
     */
    int(*ptr)(int*, int);
    ptr = sum;
    printf("%d\n", (*ptr)(nums, len));

    return 0;
}