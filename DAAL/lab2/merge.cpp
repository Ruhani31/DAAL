#include <stdio.h>

int counter = 0;

void printArray(int arr[], int start, int end) {
    int i;
    for (i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quicksort(int arr[], int low, int high) {
    int pivot, i, j, temp;
    if (low < high) {
        pivot = high;
        i = low;
        j = high;
        
        while(i < j) {
            while(arr[i] <= arr[pivot] && i <= high) {
                i++;
            }
            while(arr[j] > arr[pivot] && j >= low){
                j--;
            }
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        
        counter++;
        printf("After pass %d: ", counter);
        printArray(arr, low, high);
        
        quicksort(arr, low, j-1);
        quicksort(arr, j+1, high);
    }
}

int main() {
    int list[100];
    int size, i;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    printf("Enter the elements: ");
    for(i = 0; i < size; i++){
        scanf("%d", &list[i]);
    }

    printf("Initial array: ");
    printArray(list, 0, size-1);

    quicksort(list, 0, size-1);

    printf("After quick sort: ");
    for(i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    
    return 0;
}

