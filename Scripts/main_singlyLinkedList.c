#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

int main() 
{    
    struct Node* head = NULL;

    // Adding elements at the start
    addAtStart(&head, 5);
    addAtStart(&head, 10);
    addAtStart(&head, 20);
    addAtStart(&head, 30);

    // Adding elements at the end
    addAtEnd(&head, 40);
    addAtEnd(&head, 50);
    addAtEnd(&head, 80);
    addAtEnd(&head, 90);
    addAtEnd(&head, 100);

    // adding elements at the end recursively
    addAtEndRecursive(&head, 105);
    addAtEndRecursive(&head, 110);
    addAtEndRecursive(&head, 120);
    addAtEndRecursive(&head, 130);

    // Adding elements in sorted order
    addToSortedList(&head, 15);
    addToSortedList(&head, 25);
    addToSortedList(&head, 35);
    addToSortedList(&head, 45);
    printf("List after adding elements:\n");
    printFromStartRecursive(head);
    printf("\n");

    sortList(&head);
    printf("After sorting the list:\n");
    printFromStartRecursive(head);
    // Print the list from start and  from end recursively
    printf("\nFrom Start Print:\n");
    printFromStartRecursive(head);
    printf("\nFrom End Print:\n");
    printFromEndRecursive(head);
    makeheadOfListEndOfListAndEndOfListHead(&head);
    printf("\nAfter making head of list end of list and end of list head:\n");
    printFromStartRecursive(head);

    printf("\n");
    printf("\nDeleting node with value 30:\n");
    deleteNode(&head, 30);
    printFromStartRecursive(head);
    printf("\nDeleting node with value 20:\n");
    deleteNode(&head, 20);
    printFromStartRecursive(head);
    printf("\nDeleting node with value 100:\n");
    deleteNode(&head, 100);
    printFromStartRecursive(head);
    printf("\nDeleting node with value 5:\n");
    deleteNode(&head, 5);
    printFromStartRecursive(head);

    printf("\nReversing the list:\n");
    reverseList(&head);
    printFromStartRecursive(head);

    printf("\n\nFreeing the list memory:");
    makeEmpty(&head);
    if (head == NULL) 
    {
        printf("\nList is empty now.\n");
    } 
    else 
    {
        printf("\nList is not empty.\n");
    }
    return 0;
}
