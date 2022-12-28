#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

int main()
{
    Tree tree = {.Root = NULL};

    Add(&tree, 50);
    Add(&tree, 40);
    Add(&tree, 30);
    Add(&tree, 65);
    Add(&tree, 70);
    Add(&tree, 60);
    Add(&tree, 35);

    printf(">>> %d",GetMaxDepth(&tree));
    return 0;
}
