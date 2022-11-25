#ifndef QUEUE_H
#define QUEUE_H

#define MaxQSize 5
typedef struct Node
{
    int data;
    struct Node *prevNode;
} Node;
typedef struct Queue
{
    int length;
    Node *front;
    Node *rear;
} Queue;

void EnQueue(Queue *q, int data)
{
    // do not insert if maximum is reached
    if(q->length == MaxQSize)
        return;

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    q->length += 1;

    if(q->length != 1)
    {
        newNode->prevNode = q->front;
        q->front = newNode;

    }
    else
    {
        newNode->prevNode = NULL;
        q->rear = newNode;
        q->front = newNode;
    }
}

void DeQueue(Queue *q)
{
    if(q->length == 0)
    {
        return;
    }
    else
    {
        q->rear->data = q->front[1].data;
        q->length -= 1;
    }

}

void display(Queue * q)
{
    int i;
    for(i = 0; i < q->length; i++)
    {
        printf(">> %d", q->front->data);
        q->front = q->front->prevNode;
    }
}
#endif // QUEUE_H
