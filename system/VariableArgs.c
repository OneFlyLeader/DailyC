//
// Created by OneFl on 2020/10/23.
//

#include <stdarg.h>
#include <stdio.h>

// 宏也可以支持可变参数输入
#define LOG(...) printf(__VA_ARGS__)

double average(int num, ...){
    va_list valist;
    double sum = 0.0;
    va_start(valist, num);
    for(int i = 0; i < num; i++){
        sum += va_arg(valist, int);
    }
    va_end(valist);
    return (sum/num);
}

int main(){
    LOG("%lf\n", average(10,11,12,13));

#define STR(s) #s
#define CONCAT(a,b) ((int)(a##b))

    printf("%s\n", STR(123));
    printf("%d\n", CONCAT(1,2));
    return 0;
}
