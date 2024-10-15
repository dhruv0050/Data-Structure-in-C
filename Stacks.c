#include <stdio.h>
#include <stdlib.h>

struct node{
    int value; 
    int* next;
};

void enqueue(struct node* f, struct node* r){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("No More Memory can be allocated !\n");
    }
    else{
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}

int dequeue(struct node*f, struct node* r){
    int value = -1;
    if(f==NULL){
        printf("Stack Underflow !");
    }
    else{
        struct node* ptr = f;
        value = ptr->value;
        f=ptr->next;
        free(ptr);
    }
    return value;
}

void traverse(struct node* front, struct node* rear){
    while(front->next!=rear){
        printf("Queue is: ");
        printf("");
    }
}

int main(){
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
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                traverse(&q);
                break;
            case 4:
                printf("Exiting...\n");
                free(q.arr);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
