#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a Doubly Linked List (DLL)
struct dll {
    int empID;
    struct dll *prev;
    struct dll *next;
};

// Function to display the doubly linked list
struct dll* show(struct dll* top) {
    if (top == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct dll* ptr = top;
    while (ptr != NULL) {
        printf("%d ", ptr->empID);
        ptr = ptr->next;
    }
    printf("\n");
    return top;
}

// Function to insert a node at the beginning of the doubly linked list
struct dll* insertAtBeginning(struct dll* top, int empID) {
    struct dll* ptr = (struct dll *)malloc(sizeof(struct dll));
    ptr->empID = empID;
    ptr->next = top;
    if (top != NULL) {
        top->prev = ptr;
    }
    ptr->prev = NULL;
    return ptr;
}

// Function to delete a node at the end of the doubly linked list
struct dll* deleteAtEnd(struct dll* top) {
    if (top == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (top->next == NULL) {
        free(top);
        return NULL;
    }
    struct dll* ptr = top;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    ptr->prev = NULL;
    free(ptr);
    return top;
}

int main() {
    struct dll* top = NULL;
    int choice, empID;

    while (1) {
        printf("1. Insert at Beginning\n");
        printf("2. Delete at End\n");
        printf("3. Show List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter employee ID to insert: ");
                scanf("%d", &empID);
                top = insertAtBeginning(top, empID);
                break;
            case 2:
                top = deleteAtEnd(top);
                break;
            case 3:
                top = show(top);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
