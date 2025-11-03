#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int minIndex = start, maxIndex = start;
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
        if (maxIndex == start)
            maxIndex = minIndex;
        temp = arr[end];
        arr[end] = arr[maxIndex];
        arr[maxIndex] = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    improvedSelectionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
