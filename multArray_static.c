#include <stdio.h>
int main() {
    int arr1[2][2], arr2[2][2];
    int multiplication_arr[2][2] = {{0, 0}, {0, 0}};
    int i, j, k;

    // Input for the first matrix
    printf("Enter the elements of the first 2x2 matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("arr1[%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    // Input for the second matrix
    printf("Enter the elements of the second 2x2 matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("arr2[%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }
    // Matrix multiplication
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                multiplication_arr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    // Display the result
    printf("The resultant matrix after multiplication is:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", multiplication_arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
