#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 5, 6}, n = 6, sum = 0;
    for (int i = 0; i < n - 1; i++) sum += arr[i];
    int total = n * (n + 1) / 2;
    cout << "Missing: " << total - sum;
}