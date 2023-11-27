#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node * next;
} Node;

// Create stack using linked list.
void push_st(struct Node **head_ref, int data) {
    struct Node * newNode = (struct Node *)
        malloc (sizeof(struct Node));

    newNode->data = data;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

void show(struct Node * head_ref) {
    while (head_ref != NULL) {
        printf("%d\n", head_ref->data);
        head_ref = head_ref->next;
    }
}

int main() {

    Node *head = NULL;
    for(int i = 1 ; i < 6 ; ++i) {
        push_st(&head, 100 + i);
    }

    show(head);

    printf("\n");
    return 0;
}