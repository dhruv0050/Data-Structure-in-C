#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, row1, col1, row2, col2;
    int arr1[10][20];
    int *arr2, *result;

    // Get the size of the arrays
    printf("\nEnter the number of rows of array1: ");
    scanf("%d", &row1);
    printf("\nEnter the number of columns of array1: ");
    scanf("%d", &col1);

    printf("\nEnter the number of rows of array2: ");
    scanf("%d", &row2);
    printf("\nEnter the number of columns of array2: ");
    scanf("%d", &col2);

    // Check if matrix multiplication is possible
    if (col1 != row2) {
        printf("Matrix multiplication is not possible with these dimensions.\n");
        return 1;
    }

    // Allocate memory dynamically for array2 and result array
    arr2 = (int *)malloc(row2 * col2 * sizeof(int));
    result = (int *)malloc(row1 * col2 * sizeof(int)); // result matrix of size row1 x col2

    // Get the data for the arrays
    printf("\nEnter the data of array1: ");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("Enter the value of array1[%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nEnter the data of array2: ");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("Enter the value of array2[%d][%d]: ", i, j);
            scanf("%d", &arr2[i * col2 + j]); // row-major
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            result[i * col2 + j] = 0;
            for (k = 0; k < col1; k++) {
                result[i * col2 + j] += arr1[i][k] * arr2[k * col2 + j];
            }
        }
    }

    // Print the result matrix
    printf("\nThe resultant matrix after multiplication is:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d ", result[i * col2 + j]);
        }
        printf("\n");
    }

    // Free allocated memory
    free(arr2);
    free(result);

    return 0;
}
