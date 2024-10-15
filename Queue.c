#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

// Enqueue operation
void enqueue(struct node** f, struct node** r, int value) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("No More Memory can be allocated !\n");
    } else {
        n->value = value;
        n->next = NULL;
        if (*f == NULL) {
            *f = *r = n; 
        } else {
            (*r)->next = n;
            *r = n;
        }
        printf("%d enqueued to queue\n", value);
    }
}

// Dequeue operation
int dequeue(struct node** f) {
    int value = -1;
    if (*f == NULL) {
        printf("Queue Underflow!\n");
    } else {
        struct node* ptr = *f;
        value = ptr->value;
        *f = (*f)->next;
        free(ptr);
        printf("%d dequeued from queue\n", value);
    }
    return value;
}

// Traversing the queue
void traverse(struct node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    struct node* ptr = front;
    while (ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;

    int choice, value;
    while (1) {
        printf("\nChoose an option: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                dequeue(&front);
                break;
            case 3:
                traverse(front);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
