#include <stdio.h>

// Structure to hold the maximum and minimum values
typedef struct {
    int max;
    int min;
} MaxMin;

// Function to find the maximum and minimum values in a list
MaxMin find_max_min(int arr[], int low, int high) {
    MaxMin result;

    // Base case: If the list has only one element
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    // Base case: If the list has two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.max = arr[high];
            result.min = arr[low];
        } else {
            result.max = arr[low];
            result.min = arr[high];
        }
        return result;
    }

    // Divide the list into two halves
    int mid = (low + high) / 2;

    // Recursively find the maximum and minimum values in the left and right halves
    MaxMin left_result = find_max_min(arr, low, mid);
    MaxMin right_result = find_max_min(arr, mid + 1, high);

    // Combine the results
    if (left_result.max > right_result.max) {
        result.max = left_result.max;
    } else {
        result.max = right_result.max;
    }

    if (left_result.min < right_result.min) {
        result.min = left_result.min;
    } else {
        result.min = right_result.min;
    }

    return result;
}

int main() {
    int n;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Create an array to store the elements
    int arr[n];

    // Ask the user for the elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum and minimum values
    MaxMin result = find_max_min(arr, 0, n - 1);

    // Print the results
    printf("Maximum value: %d\n", result.max);
    printf("Minimum value: %d\n", result.min);

    return 0;
}