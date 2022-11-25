#ifndef STACK_H
#define STACK_H

#define MaxSize 5

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Next;
};

Node* top = NULL;

typedef struct Stack
{
    int length;
    Node *NewNode;
    Node *top;
} Stack;

int Push(Stack *stk, int data)
{
    if(stk->length == MaxSize)
        return 0;

    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Next = NULL;

    if(top == NULL)
    {
        top = newNode;
    }
    else
    {
        newNode->Next=top;
    }
    top = newNode;


    stk->top = top;
    stk->length += 1;
    stk->NewNode= newNode;



    printf("Node %d is Inserted\n\n", newNode->Data);
    return 1;
}

int Pop(Stack *s)
{
    if(top == NULL)
    {
        return 0;
    }

    printf("Node %d is poped\n\n", s->NewNode->Data);

    s->NewNode = s->NewNode->Next;
    s->length -= 1;
    s->top = s->NewNode;

    return 1;
}

void display(Stack *s)
{
    do
    {

        printf(">>> %d", s->NewNode->Data);
        s->NewNode = s->NewNode->Next;

    }
    while(s->NewNode->Next != NULL);

    printf(">>> %d", s->NewNode->Data);
}

#endif // STACK_H
