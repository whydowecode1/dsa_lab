#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 5, 6}, n = 6, low = 0, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) low = mid + 1;
        else high = mid - 1;
    }
    cout << "Missing: " << low + 1;
}
