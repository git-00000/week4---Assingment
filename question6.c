// Sorted Insert in Circular Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* sortedInsert(struct Node* head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if (!head) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* current = head;
    if (data < head->data) {
        while (current->next != head)
            current = current->next;
        current->next = newNode;
        newNode->next = head;
        head = newNode;
    } else {
        while (current->next != head && current->next->data < data)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

void printCLL(struct Node* head) {
    if (!head) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = sortedInsert(head, 30);
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 20);
    head = sortedInsert(head, 5);

    printf("Sorted Circular Linked List: ");
    printCLL(head);

    return 0;
}
