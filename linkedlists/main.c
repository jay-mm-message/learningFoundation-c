#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node * next;
} Node;

// Create queue using linked list.
void push_qt(struct Node **head_ref, int data) {
 
    struct Node * newNode = (struct Node *)
        malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (NULL == (*head_ref)) {
        (*head_ref) = newNode;
    } else {
        struct Node * tail = (*head_ref);
        while(NULL != tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

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

    printf("Create stack using linked list.\n");
    Node *head = NULL;
    for(int i = 1 ; i < 6 ; ++i) {
        push_st(&head, 100 + i);
    }

    show(head);
    
    printf("Create queue using linked list.\n");
    Node *head_2 = NULL;
    for(int i = 1 ; i < 6 ; ++i) {
        push_qt(&head_2, 100 + i);
    }

    show(head_2);

    printf("\n");
    return 0;
}