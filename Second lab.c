/** 225.Implement Stack Using Queues
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *queue1;
    int *queue2;
    int size;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->capacity = 100; // Default size
    stack->queue1 = (int*)malloc(stack->capacity * sizeof(int));
    stack->queue2 = (int*)malloc(stack->capacity * sizeof(int));
    stack->size = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue2[0] = x;
    for (int i = 0; i < obj->size; i++) {
        obj->queue2[i + 1] = obj->queue1[i];
    }
    int *tempQueue = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = tempQueue;
    obj->size++;
}

int myStackPop(MyStack* obj) {
    if (obj->size == 0) return -1;
    int topElement = obj->queue1[0];
    for (int i = 0; i < obj->size - 1; i++) {
        obj->queue1[i] = obj->queue1[i + 1];
    }
    obj->size--;
    return topElement;
}

int myStackTop(MyStack* obj) {
    if (obj->size == 0) return -1;
    return obj->queue1[0];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}






/** 232. Implement Queue Using Stacks
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *stack1;
    int *stack2;
    int top1;
    int top2;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->capacity = 100; // Default size
    queue->stack1 = (int*)malloc(queue->capacity * sizeof(int));
    queue->stack2 = (int*)malloc(queue->capacity * sizeof(int));
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}
