#include <iostream>
#include <limits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isBST_bounds(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBST_bounds(root->left, minVal, root->data) &&
           isBST_bounds(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBST_bounds(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}

bool isBST_inorder(Node* root, long long &prev) {
    if (!root) return true;
    if (!isBST_inorder(root->left, prev)) return false;
    if (root->data <= prev) return false;
    prev = root->data;
    return isBST_inorder(root->right, prev);
}

int main() {
    Node* root1 = new Node(20);
    root1->left = new Node(10);
    root1->right = new Node(30);
    root1->left->left = new Node(5);
    root1->left->right = new Node(15);

    cout << "Tree 1 (should be BST):\n";
    cout << (isBST(root1) ? "BST\n" : "Not BST\n");
    long long prev = numeric_limits<long long>::min();
    cout << (isBST_inorder(root1, prev) ? "BST (inorder)\n" : "Not BST (inorder)\n");

    Node* root2 = new Node(20);
    root2->left = new Node(30);
    root2->right = new Node(10);

    cout << "Tree 2 (should NOT be BST):\n";
    cout << (isBST(root2) ? "BST\n" : "Not BST\n");
    prev = numeric_limits<long long>::min();
    cout << (isBST_inorder(root2, prev) ? "BST (inorder)\n" : "Not BST (inorder)\n");

    return 0;
}
