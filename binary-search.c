#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;  // Return the position (index) of the element
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
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
    
    // Read the elements of the array (ensure the array is sorted for binary search)
    printf("Enter %d elements of the sorted array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the target element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    
    // Perform Binary Search
    position = binarySearch(arr, n, target);

    // Display the result
    if (position != -1) {
        printf("Element found at position: %d\n", position + 1);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
