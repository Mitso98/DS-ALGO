#include <stdio.h>
#include <stdlib.h>
#include "./include/Stack.h"

int main()
{
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->NewNode = NULL;
    s->top = NULL;
    s->length = 0;

    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 4);
    Push(s, 5);
    // 6 will not be instered as we only can insert up to 5
    //Push(s, 6);

    Pop(s);

    display(s);
    return 0;
}
