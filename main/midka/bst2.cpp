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

    int check(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }

        int left = check(node->left);
        int right = check(node->right);

        return left + right;
    }

    void print() {
        cout << check(root) << endl;
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