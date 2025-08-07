// Reverse a Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

struct DLLNode* reverseDLL(struct DLLNode* head) {
    struct DLLNode* temp = NULL;
    struct DLLNode* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

void printDLL(struct DLLNode* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct DLLNode* head = malloc(sizeof(struct DLLNode));
    head->data = 1;
    head->prev = NULL;
    head->next = malloc(sizeof(struct DLLNode));

    head->next->data = 2;
    head->next->prev = head;
    head->next->next = malloc(sizeof(struct DLLNode));

    head->next->next->data = 3;
    head->next->next->prev = head->next;
    head->next->next->next = NULL;

    printf("Original DLL: ");
    printDLL(head);

    head = reverseDLL(head);

    printf("Reversed DLL: ");
    printDLL(head);

    return 0;
}
