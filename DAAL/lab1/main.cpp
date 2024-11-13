#include <iostream>
using namespace std;

int itBinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int recBinarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            return recBinarySearch(arr, mid + 1, right, target);

        return recBinarySearch(arr, left, mid - 1, target);
    }

    return -1;
}

int itLinearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int recLinearSearch(int arr[], int size, int target, int index = 0) {
    if (index >= size)
        return -1;
    if (arr[index] == target)
        return index;
    return recLinearSearch(arr, size, target, index + 1);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int choice;
    int result;

    cout << "Choose search method:\n";
    cout << "1. Iterative Binary Search\n";
    cout << "2. Recursive Binary Search\n";
    cout << "3. Iterative Linear Search\n";
    cout << "4. Recursive Linear Search\n";
    cin >> choice;

    switch (choice) {
        case 1:
            result = itBinarySearch(arr, size, target);
            break;
        case 2:
            result = recBinarySearch(arr, 0, size - 1, target);
            break;
        case 3:
            result = itLinearSearch(arr, size, target);
            break;
        case 4:
            result = recLinearSearch(arr, size, target);
            break;
        default:
            cout << "Invalid choice" << endl;
            return 1;
    }

    if (result != -1)
        cout << "Element is present at index " << result << endl;
    else
        cout << "Element is not present in array" << endl;

    return 0;
}
