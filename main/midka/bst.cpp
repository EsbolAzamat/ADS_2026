#include<iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value): value(value), left(nullptr), right(nullptr) {}
};

struct BST {
private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (node->value <= value) {
            node->right = insertRec(node->right, value);
        }
        else {
            node->left = insertRec(node->left, value);
        }

        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    int count = 0;
    int levels(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = levels(node->left);
        int right = levels(node->right);
        return 1 + max(left, right);
    }

    void print() {
        cout << levels(root) << endl;
    }
};

int main() {
    int n;
    cin >> n;

    BST tree;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    tree.print();
    return 0;
}