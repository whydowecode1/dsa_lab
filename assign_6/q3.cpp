#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *prev, *next;
};

DNode* createDoubly(int arr[], int n) {
    if (n == 0) return nullptr;
    DNode *head = new DNode{arr[0], nullptr, nullptr};
    DNode *last = head;
    for (int i = 1; i < n; i++) {
        DNode *temp = new DNode{arr[i], last, nullptr};
        last->next = temp;
        last = temp;
    }
    return head;
}

int sizeDoubly(DNode *head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

struct CNode {
    int data;
    CNode *next;
};

CNode* createCircular(int arr[], int n) {
    if (n == 0) return nullptr;
    CNode *head = new CNode{arr[0], nullptr};
    CNode *last = head;
    for (int i = 1; i < n; i++) {
        CNode *temp = new CNode{arr[i], nullptr};
        last->next = temp;
        last = temp;
    }
    last->next = head;
    return head;
}

int sizeCircular(CNode *head) {
    if (!head) return 0;
    int count = 0;
    CNode *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    DNode *dHead = createDoubly(arr, 5);
    CNode *cHead = createCircular(arr, 5);
    cout << "Size of Doubly Linked List: " << sizeDoubly(dHead) << endl;
    cout << "Size of Circular Linked List: " << sizeCircular(cHead) << endl;
    return 0;
}
