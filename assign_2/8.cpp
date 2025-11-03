#include <iostream>
using namespace std;

class DistinctElements {
    int arr[50];
    int n;

public:
    void readArray() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void countDistinct() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < i; j++) {
                if (arr[i] == arr[j])
                    break;
            }
            if (j == i)
                count++;
        }
        cout << "Total distinct elements = " << count << endl;
    }
};

int main() {
    DistinctElements obj;
    obj.readArray();
    obj.countDistinct();
    return 0;
}
