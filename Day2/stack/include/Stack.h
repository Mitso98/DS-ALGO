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
    Node *NewNode;
    Node *top;
}Stack;

int Push(Stack *stk, int data)
{
    if(stk->top == MaxSize-1)
        return 0;

    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    if(top == NULL)
    {
        top = newNode;
    }
    else
    {
        newNode->Next=top;
    }
    top = newNode;
    printf("Node is Inserted\n\n");
    return 1;
}

/*int Pop(Stack *stk, int *data)
{
    if(stk->top == -1)
    {
        return 0;
    }

    *data = stk->arr[stk->top];
    stk->top--;

    return 1;
}*/

#endif // STACK_H
