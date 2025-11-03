#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string arr[] = {"banana", "apple", "cherry"};
    sort(arr, arr + 3);
    for (int i = 0; i < 3; i++) cout << arr[i] << " ";
}
