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

        if (value <= node->value) {
            node->left = insertRec(node->left, value);
        }
        else {
            node->right = insertRec(node->right, value);
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

    void preOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->value << ' ';
        preOrder(node->left);
        preOrder(node->right);
    }

    void print() {
        preOrder(root);
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
    cout << endl;

    return 0;
}