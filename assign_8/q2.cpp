#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

Node* search_recursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search_recursive(root->left, key);
    return search_recursive(root->right, key);
}

Node* search_iterative(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (cur->data == key) return cur;
        if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}

Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = search_iterative(root, key);
    if (!target) return nullptr;

    if (target->right) return findMin(target->right);

    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (key < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (key > cur->data)
            cur = cur->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = search_iterative(root, key);
    if (!target) return nullptr;

    if (target->left) return findMax(target->left);

    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (key > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (key < cur->data)
            cur = cur->left;
        else break;
    }
    return pred;
}

void printNode(const char* label, Node* n) {
    cout << label << ": ";
    if (n) cout << n->data << '\n';
    else cout << "NULL\n";
}

int main() {
    Node* root = nullptr;
    int vals[] = {20, 10, 30, 5, 15, 25, 35, 12, 18};
    for (int v : vals) root = insert(root, v);

    printNode("Recursive search 15", search_recursive(root, 15));
    printNode("Iterative search 100", search_iterative(root, 100));

    printNode("Min of BST", findMin(root));
    printNode("Max of BST", findMax(root));

    int keys[] = {10, 12, 20, 35};
    for (int k : keys) {
        cout << "\nKey = " << k << '\n';
        printNode("  Successor", inorderSuccessor(root, k));
        printNode("  Predecessor", inorderPredecessor(root, k));
    }

    return 0;
}
