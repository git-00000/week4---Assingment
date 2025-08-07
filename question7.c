// Check if Linked List is Circular
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isCircular(struct Node* head) {
    if (!head) return 1;

    struct Node* temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    struct Node* second = malloc(sizeof(struct Node));
    head->next = second;
    second->data = 2;
    struct Node* third = malloc(sizeof(struct Node));
    second->next = third;
    third->data = 3;
    third->next = head; // make it circular

    
    if (isCircular(head))
        printf("The linked list is circular.\n");
    else
        printf("The linked list is not circular.\n");

    return 0;
}
