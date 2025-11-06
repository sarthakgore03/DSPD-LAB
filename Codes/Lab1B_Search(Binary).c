//SarthakGore-IT-B-172
#include <stdio.h>
int* binarySearch(int arr[], int n, int key) {
    if (arr == NULL || n <= 0) {
        return NULL;
    }
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return &arr[mid];
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return NULL;
}
int main() {
    int n, key, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Search list is empty.\n");
        return 0;
    }
    int arr[n];
    printf("Enter %d elements (in sorted order):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    int* result = binarySearch(arr, n, key);
    if (result != NULL)
        printf("Element %d found at position %ld.\n", key, (result - arr) + 1);
    else
        printf("Element not found or invalid list.\n");
    return 0;
}