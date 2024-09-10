#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a Circular Linked List (CLL)
struct cll {
    int collegeID;
    int numSt;
    char grade;
    struct cll *next;
};

// Function to display the circular linked list
struct cll* show(struct cll* top) {
    if (top == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct cll* ptr = top;
    do {
        printf("College ID: %d\n", ptr->collegeID);
        printf("Number of Students: %d\n", ptr->numSt);
        printf("College Grade: %c\n", ptr->grade);
        ptr = ptr->next;
    } while (ptr != top);
    printf("\n");
    return top;
}

// Function to insert a node at the beginning of the circular linked list
struct cll* insertAtBeginning(struct cll* top, int collegeID, int numSt, char grade) {
    struct cll* ptr = (struct cll*)malloc(sizeof(struct cll));
    ptr->collegeID = collegeID;
    ptr->numSt = numSt;
    ptr->grade = grade;

    if (top == NULL) {
        top = ptr;
        top->next = top; // Make the list circular
    } else {
        ptr->next = top;
        struct cll* temp = top;
        while (temp->next != top) { // Find the last node
            temp = temp->next;
        }
        temp->next = ptr; // Update the last node to point to the new node
        top = ptr; // Update top to the new node
    }
    return top;
}

// Function to delete a node at the end of the circular linked list
struct cll* deleteAtEnd(struct cll* top) {
    if (top == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (top->next == top) { // If there's only one node
        free(top);
        return NULL;
    }
    struct cll* ptr = top;
    while (ptr->next->next != top) { // Find the second last node
        ptr = ptr->next;
    }
    free(ptr->next); // Free the last node
    ptr->next = top; // Update the second last node to point to top
    return top;
}

int main() {
    struct cll* top = NULL;
    int choice, collegeID, numSt;
    char grade;

    while (1) {
        printf("1. Insert at Beginning\n");
        printf("2. Delete at End\n");
        printf("3. Show List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter college ID to insert: ");
                scanf("%d", &collegeID);
                printf("Enter number of college students: ");
                scanf("%d", &numSt);
                printf("Enter college grade: ");
                scanf(" %c", &grade); // Space before %c to skip any newline
                top = insertAtBeginning(top, collegeID, numSt, grade);
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
