#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *prev, *next;
    Node(char d) {
        data = d;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
    Node *head, *tail;
public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insert(char d) {
        Node *temp = new Node(d);
        if (!head)
            head = tail = temp;
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    bool isPalindrome() {
        Node *start = head, *end = tail;
        while (start != end && start->prev != end) {
            if (start->data != end->data)
                return false;
            start = start->next;
            end = end->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList list;
    string s = "racecar";
    for (char c : s) list.insert(c);
    if (list.isPalindrome())
        cout << "The doubly linked list is a palindrome.";
    else
        cout << "The doubly linked list is not a palindrome.";
    return 0;
}
