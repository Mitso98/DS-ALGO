#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    /*LinkedList myList = {.head = NULL, .tail = NULL};
    Add(&myList, 3);*/

    Add(9);
    Add(4);
    Add(2);
    Add(1);

    Display();

    printf("\n%d",GetCount());

    GetDataByIndex(3);

    printf("\n");

    InsertAfter(10, 4);

    Display();

    return 0;
}
