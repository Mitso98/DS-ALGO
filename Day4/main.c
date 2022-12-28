#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main()
{
    Tree tree = {.Root = NULL};

    Add(&tree, 64);
    Add(&tree, 61);
        Add(&tree, 54);
         Add(&tree, 99);



    Display(tree.Root);
    printf(">>> %d",GetMaxDepth(tree.Root));
    return 0;
}
