#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

void insert(node *ptr, int data) {
    node *start = ptr;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    ptr->next = newNode;
}

int find(node *ptr, int key) {
    while (ptr != NULL) {
        if (ptr->data == key) {
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

void delete(node *ptr, int data) {
    while (ptr->next != NULL && (ptr->next)->data != data) {
        ptr = ptr->next;
    }
    if (ptr->next == NULL) {
        printf("Element %d is not present in the list\n", data);
        return;
    }
    node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

void print(node *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    node *start;
    start = (node *)malloc(sizeof(node));
    start->next = NULL;

    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Print\n");
    printf("4. Find\n");
    printf("5. EXIT\n");

    while (1) {
        printf("Press your choice: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            int data;
            printf("The Element to be inserted in the list is: ");
            scanf("%d", &data);
            insert(start, data);
        } else if (choice == 2) {
            int data;
            printf("The Element to be deleted from the list is: ");
            scanf("%d", &data);
            delete(start, data);
        } else if (choice == 3) {
            printf("The list is: ");
            print(start->next);  // Start printing from the first actual node
        } else if (choice == 4) {
            int data;
            printf("The Element to be searched in the list is: ");
            scanf("%d", &data);
            int status = find(start->next, data);  // Start searching from the first actual node
            if (status) {
                printf("Element Found\n");
            } else {
                printf("Element Not Found\n");
            }
        } else {
            break;
        }
    }

    return 0;
}
