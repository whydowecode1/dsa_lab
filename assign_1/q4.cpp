#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - i - 1]);
}

void multiplyMatrix(int a[10][10], int b[10][10], int c[10][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

void transposeMatrix(int a[10][10], int t[10][10], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    reverseArray(arr, n);
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    int a[10][10] = {{1, 2}, {3, 4}}, b[10][10] = {{5, 6}, {7, 8}}, c[10][10];
    multiplyMatrix(a, b, c, 2, 2, 2);
    cout << "\nMatrix Multiplication:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) cout << c[i][j] << " ";
        cout << "\n";
    }

    int t[10][10];
    transposeMatrix(a, t, 2, 2);
    cout << "Transpose:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) cout << t[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
