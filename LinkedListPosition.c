#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
}
struct Node* addAtPosition(struct Node* head, int position, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    if (position == 0) {
        newNode->link = head;
        head = newNode;
        return head;
    }
    struct Node* current = head;
    int i = 0;
    while (i < position - 1 && current != NULL) {
        current = current->link;
        i++;
    }
    if (current == NULL) {
        printf("Error: invalid position\n");
        return head;
    }
    newNode->link = current->link;
    current->link = newNode;
    return head;
}
int main() {
    struct Node* head = NULL;
    head = addAtPosition(head, 0, 10); 
    head = addAtPosition(head, 1, 15); 
    head = addAtPosition(head, 1, 20); 
    head = addAtPosition(head, 3, 30); 
    printList(head);
    return 0;
}
