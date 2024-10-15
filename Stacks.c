#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly linked list
typedef struct Node {
   int d;
   struct Node* next;
   struct Node* prev;
} Node;

// Function to push a value onto the stack
void pushtolist(Node** top, int value) {
   Node* newnode = (Node*)malloc(sizeof(Node));
   newnode->d = value;
   newnode->next = NULL;
   newnode->prev = *top;

   if (*top != NULL) {
       (*top)->next = newnode;
   }
   *top = newnode;
}

// Function to display the stack from top to bottom
void displaylist(Node* top) {
   Node* temp = top;
   if (temp == NULL) {
       printf("Empty Stack\n");
       return;
   }
   while (temp != NULL) {
       printf("%d\n", temp->d);
       temp = temp->prev;
   }
}

// Function to pop a value from the stack
void popfromlist(Node** top) {
   if (*top == NULL) {
       printf("Empty Stack\n");
       return;
   }
   Node* temp = *top;
   *top = (*top)->prev;
   if (*top != NULL) {
       (*top)->next = NULL;
   }
   free(temp);
}

// Structure for Stack
typedef struct {
   Node* top;
} Stack;

// Initialize a stack
void initStack(Stack* stack) {
   stack->top = NULL;
}

// Push a value onto the stack
void push(Stack* stack, int value) {
   pushtolist(&stack->top, value);
}

// Traverse the stack
void traverse(Stack* stack) {
   displaylist(stack->top);
}

// Pop a value from the stack
void pop(Stack* stack) {
   popfromlist(&stack->top);
}

// Peek at the top value of the stack
void peek(Stack* stack) {
   if (stack->top == NULL) {
       printf("Empty Stack\n");
   } else {
       printf("%d\n", stack->top->d);
   }
}

// Main function
int main() {
   Stack st;
   initStack(&st);

   while (1) {
       int choice;
       printf("1. Push\n");
       printf("2. Peek\n");
       printf("3. Traverse\n");
       printf("4. Pop\n");
       printf("5. Exit\n");
       printf("Enter Choice: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1: {
               int num;
               printf("Enter Data: ");
               scanf("%d", &num);
               push(&st, num);
               break;
           }
           case 2:
               peek(&st);
               break;
           case 3:
               traverse(&st);
               break;
           case 4:
               pop(&st);
               break;
           case 5:
               printf("Exited!\n");
               exit(0);
       }
   }
   return 0;
}
