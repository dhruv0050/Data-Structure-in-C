#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the position (index) of the element
        }
    }
    return -1;  // Element not found
}

int main() {
    int n, target, position;
    
    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    
    // Read the elements of the array
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the target element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    
    // Perform Linear Search
    position = linearSearch(arr, n, target);

    // Display the result
    if (position != -1) {
        printf("Element found at position: %d\n", position + 1);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
