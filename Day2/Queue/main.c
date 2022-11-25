#include <stdio.h>
#include <stdlib.h>
#include "./include/Queue.h"

int main()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->length = 0;

    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);

    DeQueue(q);
    DeQueue(q);
    display(q);
    return 0;
}
