// delete node in DLL

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }
    
    if (*head_ref == temp)
        *head_ref = temp->next;
    
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    
    free(temp);
    printf("Node with data %d deleted.\n", key);
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL)
        last = last->next;
    
    last->next = new_node;
    new_node->prev = last;
}

void printList(struct Node* node) {
    struct Node* last;
    printf("Forward traversal: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    
    printf("Original List:\n");
    printList(head);

    deleteNode(&head, 30);
    
    printf("List after deletion:\n");
    printList(head);

}
