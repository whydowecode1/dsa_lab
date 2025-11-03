#include <iostream>
using namespace std;

int partition(int a[], int start, int end) {
    int pivot = a[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (a[j] < pivot) {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[end];
    a[end] = t;
    return i + 1;
}

void quickSort(int a[], int start, int end) {
    if (start < end) {
        int p = partition(a, start, end);
        quickSort(a, start, p - 1);
        quickSort(a, p + 1, end);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {24, 9, 29, 14, 19, 27};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Before sorting array elements are:\n";
    printArray(a, n);
    quickSort(a, 0, n - 1);
    cout << "After sorting array elements are:\n";
    printArray(a, n);
    return 0;
}
