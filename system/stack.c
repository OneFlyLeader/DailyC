//
// Created by OneFl on 2020/10/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int pos;
    int size;
} Stack;

Stack newStack(){
    return (Stack){NULL,0,0};
}

/**
 * pos始终指向下一个存放的位置
 * size指的是整个堆栈的尺寸
 * @param stack
 * @param a
 */
void push(Stack* stack, int a){
    // 初始化堆栈
    if(stack->size == 0){
        stack->data = (int*)(malloc(sizeof(int)*4));
        stack->size = 4;
        stack->pos = 0;
    }
    // 如果越界
    if(stack->pos == stack->size){
        // 拷贝下来
        int* tmp = (int*)(malloc(sizeof(int)*stack->size));
        for(int i = 0; i < stack->size; i++)
            tmp[i] = stack->data[i];
        free(stack->data);
        stack->data = (int*)(malloc(sizeof(int)*stack->size*2));
        // 复制回去
        for(int i = 0; i < stack->size; i++)
            stack->data[i] = tmp[i];
        free(tmp);
        stack->size <<= 1;
    }
    stack->data[stack->pos++] = a;
}

/**
 * 弹栈
 * @param stack
 * @return
 */
int pop(Stack* stack){
    if(stack->pos == 0){
        printf("error in %d\n", __LINE__);
        return -1;
    }
    return stack->data[--stack->pos];
}


int main(){
    Stack stack = newStack();
    pop(&stack);// 测试空栈弹出
    printf("push in : %d\n", 1);
    push(&stack, 1);// 测试压栈
    printf("pop out : %d\n", pop(&stack));
    for(int i = 0; i < 10; i++){
        printf("push in : %d\n", i);
        push(&stack, i);
    }
    for(int i = 0; i < 10; i++){
        printf("pop out : %d\n", pop(&stack));
    }
    return 0;
}