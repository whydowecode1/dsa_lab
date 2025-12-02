#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char c) {
        data = c;
        next = nullptr;
        prev = nullptr;
    }
};

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    Node* left = head;
    Node* right = head;

    while (right->next != nullptr)
        right = right->next;

    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {

    Node* head = new Node('L');
    head->next = new Node('E'); head->next->prev = head;
    head->next->next = new Node('V'); head->next->next->prev = head->next;
    head->next->next->next = new Node('E'); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node('L'); 
    head->next->next->next->next->prev = head->next->next->next;

    if (isPalindrome(head))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}

