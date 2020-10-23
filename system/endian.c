//
// Created by OneFl on 2020/10/23.
//
#include <stdio.h>


int main(void) {
    const char MAGIC[4] = {0xDE, 0xAD, 0xBE, 0xEF};
    unsigned int magical = *(const unsigned int *)MAGIC;
    switch(magical) {
        case 0xEFBEADDE: printf("little\n"); break;
        case 0xDEADBEEF: printf("big\n"); break;
        case 0xADDEEFBE: printf("pdp\n"); break;
        default: for(; magical; magical >>= 8) {
                switch(magical & 0xff) {
                    case 0xDE: printf("3"); break;
                    case 0xAD: printf("2"); break;
                    case 0xBE: printf("1"); break;
                    default: printf("0"); }
            } printf("\n");}

    int a[4] = {1,2,3,4};
    int* ptr1 = (int*)(&a + 1);// +1 跨度数组a所管辖的空间大小
    int* ptr2 = (int*)((int)a + 1);// 直接的地址+1
    printf("%x,%x,%x\n", a, ptr1, ptr2);
    return (0);
}
