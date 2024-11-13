#include <stdio.h>

int counter = 0;

void printArray(int arr[], int start, int end) {
    int i;
	for (i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;    // no. of elements in 1st array
    int n2 = r - m;        // no. of elements in 2nd array

    int L[n1], R[n2];

    // splitting elements into left and right halves
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    printf("Step %d: ", ++counter);
    printArray(arr, l, r);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int size;
    printf("Enter number of elements in array: ");
    scanf("%d", &size);
    
    int arr[size], i;
    printf("Enter elements of array, one by one: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Given array is \n");
    printArray(arr, 0, size - 1);

    mergeSort(arr, 0, size - 1);

    printf("\nSorted array is \n");
    printArray(arr, 0, size - 1);
    return 0;
}
