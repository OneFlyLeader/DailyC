//
// Created by OneFl on 2020/10/23.
//
#include <stdio.h>

const char MAGIC[4] = {0xDE, 0xAD, 0xBE, 0xEF};

int main(void) {
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
    return (0);
}