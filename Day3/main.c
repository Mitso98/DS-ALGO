#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;



void Swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void BubbleSort(int *data, int size)
{
    int counter, index;
    int sorted = 0;

    for(counter = 0; counter < size - 1 && !sorted; counter++)
    {
        sorted = 1;

        for(index = 0; index < size - 1 - counter; index++)
        {
            if(data[index] > data[index + 1])
            {
                Swap(&data[index], &data[index + 1]);
                sorted = 0;
            }
        }
    }
}

void SelectionSort(int *data, int size)
{
    int counter;

    for(counter = 0; counter < size - 1; counter++)
    {
        int minIndex = counter, index;

        for(index = minIndex + 1; index < size; index++)
        {
            if(data[index] < data[minIndex])
                minIndex = index;
        }

        Swap(&data[counter], &data[minIndex]);
    }
}

void InsertionSort(int *data, int size)
{
    int counter, key, index;

    for(counter = 1; counter < size; counter++)
    {
        key = data[counter];
        index = counter - 1;

        while(index >= 0 && data[index] > key)
        {
            data[index + 1] = data[index];
            index--;
        }
        data[index+1] = key;
    }
}

int BinarySearch(int item, int *data, int size)
{
    int minIndex = 0, maxIndex = size - 1, midIndex;

    while(minIndex <= maxIndex)
    {
        midIndex = (minIndex + maxIndex) / 2;

        if(item == data[midIndex])
            return midIndex;

        if(item > data[midIndex])
            minIndex = midIndex + 1;
        else
            maxIndex = midIndex - 1;
    }

    return -1;
}

void Display(int *data, int size)
{
    int index;

    for(index = 0; index < size; index++)
    {
        printf("%d  ", data[index]);
    }
}

void Push(Node *head, int value)
{
    Node *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;
    current->next = newNode;
}

void DisplayList(Node *head)
{
    Node * current = head;

    while(current->next != NULL)
    {
        current = current->next;
        printf(">> %d ", current->value);
    }
}

int MaxIndex(Node *head, int minIndex)
{
    int maxIndex = 0;
    //find length
    while(head->next != NULL)
    {
        maxIndex += 1;
        head = head->next;
    }
    maxIndex -= 1;

    return maxIndex;
}

Node* FindMid(Node* start, Node* last)
{
    if (start == NULL)
        return NULL;
    Node* slow = start;
    Node* fast = start->next;

    while (fast != last)
    {
        printf(">>mid");
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    return slow;
}

int BinarySearchLinkedList(Node *head, int value)
{
    Node* start = head;
    Node* last = NULL;

    do
    {
        Node* mid = FindMid(start, last);

        if (mid == NULL)
            return 1;

        if (mid->value == value)
            return mid->value;

        // if value is more than mid
        if (value > mid->value)
            start = mid->next;
        else
            last = mid;

    }while(last != start);

    return 0;
}

void BubleSortLinkedList(Node * head)
{
    if(head->next->next == NULL)
    {
        return;
    }

    int i, swapped = 0;

    Node *current;
    Node *prev;
    Node *tmp = (Node*)malloc(sizeof(Node));

    while(!swapped)
    {
        current = head->next->next;
        prev = head->next;
        swapped = 1;

        for(i = 0; prev->next != NULL; i++)
        {
            if(current->value < prev->value)
            {
                swapped = 0;
                tmp->value = prev->value;
                prev->value = current->value;
                current->value = tmp->value;

            }
            prev = current;
            current = current->next;
        }
    }
}
int main()
{
    /*
        int arr[] = {4, 3, 5, 6, 2, 1};

        SelectionSort(arr, 6);

        Display(arr, 6);
    */

    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    Push(head, 6);
    Push(head, 4);
    Push(head, 3);
    Push(head, 5);
    Push(head, 2);
    Push(head, 1);
    Push(head, 7);

    DisplayList(head);

    BubleSortLinkedList(head);

    printf("\nSoreted:\n");
    DisplayList(head);

    printf("\nvalue of binary search: %d", BinarySearchLinkedList(head,5));


    //printf("\n>>> %d", BinarySearchLinkedList(head, 6));
    return 0;
}
