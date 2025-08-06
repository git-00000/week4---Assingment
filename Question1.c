//Insert at bbeginning DLL

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL || data <= head->data) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }
    printf("Cannot insert %d at beginning; it violates sort order.\n", data);
    free(newNode);
    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(head, 30); 
    displayList(head);

    head = insertAtBeginning(head, 20); 
    displayList(head);

    head = insertAtBeginning(head, 10); 
    displayList(head);

    head = insertAtBeginning(head, 25);
    displayList(head);    
    
}
