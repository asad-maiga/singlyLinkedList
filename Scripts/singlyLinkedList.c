#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

// Create a simple singly linked list node structure
struct Node 
{
    int data;
    // other data
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insertion sort function to sort the linked list
// This function sorts the linked list in ascending order
void sortList(struct Node** head) 
{
    struct Node *a, *b, *c, *d;
    if (*head == NULL || (*head)->next == NULL) return; 
    d = (*head)->next;
    (*head)->next = NULL;
    while (d != NULL) 
    {
        c = d;
        d = d->next;
        b = *head;
        while (b != NULL && b->data < c->data) 
        {
            a = b;
            b = b->next;
        }
        if (b == *head) 
        {
            c->next = *head;
            *head = c;
        } 
        else 
        {
            a->next = c;
            c->next = b;
        }
    }   
}

// Function add a node at the start of the list
void addAtStart(struct Node  ** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node in sorted order
// This function traverses the list to find the correct position for the new node
void addToSortedList(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    if (*head == NULL || (*head)->data >= data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;


    while (current->next != NULL && current->next->data < data) 
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to add a node at the end of the list
// This function traverses the list to find the last node and adds the new node there
void addAtEnd(struct Node **head, int data) 
{
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = newNode;
}
void addAtEndRecursive(struct Node** head, int data) 
{
    if (*head == NULL) 
    {
        *head = createNode(data);
        return;
    }
    addAtEndRecursive(&((*head)->next), data);
}

// Function to print the list from start recursively
// This function prints the data of each node starting from the head
void printFromStartRecursive(struct Node* head) 
{
    if (head == NULL) 
    {
        //printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    printFromStartRecursive(head->next);
}

// Function to print the list from end recursively
// This function prints the data of each node starting from the end
void printFromEndRecursive(struct Node* head) 
{
    if (head == NULL) 
    {
        //printf("NULL\n");
        return;
    }
    printFromEndRecursive(head->next);
    printf("%d -> ", head->data);
}

// Function to make the list empty
// This function frees all nodes in the list and sets the head to NULL
// It effectively clears the list and releases the memory used by the nodes

void makeEmpty(struct Node** head) 
{
    struct Node* current = *head;
    struct Node* nextNode;
    while (current != NULL) 
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

// Function to delete a node with a specific value from the list
// This function traverses the list to find the node with the specified data and removes it
void deleteNode(struct Node** head, int data) 
{
    if (*head == NULL) return;

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != data) 
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return; // Data not found

    if (prev == NULL) 
    {
        *head = current->next; // Deleting the head node
    } 
    else 
    {
        prev->next = current->next; // Bypass the node to delete it
    }
    
    free(current);
}

// Function to make the head of the list the end of the list and
// the end of the list the head
// This function finds the last node and makes it the new head, 
// while the old head becomes the last node
// It effectively rotates the list such that the first node 
// becomes the last and the last node 
// becomes the first
void makeheadOfListEndOfListAndEndOfListHead(struct Node** head) 
{
    if (*head == NULL || (*head)->next == NULL) return;

    struct Node* prev = NULL;
    struct Node* current = *head;
    
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;        

    current->next = (*head)->next;  
    struct Node* oldHead = *head;
    oldHead->next = NULL;          

    *head = current;               
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = oldHead;         
}

// Function to reverse the linked list
// This function reverses the order of nodes in the list
// It iteratively changes the next pointers of each node to point to the previous node
// The head of the list is updated to point to the last node, which becomes the new head
void reverseList(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current;
    while (*head != NULL) 
    {
        current = *head;
        *head = (*head)->next; // Move head to the next node
        current->next = prev; // Reverse the link
        prev = current; // Move prev to current
    }
    *head = prev; // Update head to the new first node
}
