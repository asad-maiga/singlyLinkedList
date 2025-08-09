#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct Node;  // Forward declaration

void makeheadOfListEndOfListAndEndOfListHead(struct Node** head);
void deleteNode(struct Node** head, int data);
void makeEmpty(struct Node** head);
void printFromEndRecursive(struct Node* head);
void printFromStartRecursive(struct Node* head);
void addAtEndRecursive(struct Node** head, int data);
void addAtEnd(struct Node **head, int data);
void addToSortedList(struct Node** head, int data);
void addAtStart(struct Node  **head, int data);
void sortList(struct Node** head);
void reverseList(struct Node** head);

#endif
