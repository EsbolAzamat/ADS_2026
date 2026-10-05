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

        if (value < node->value) {
            node->left = insertRec(node->left, value);
        }
        else {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    int triangle(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int count = 0;
        if (node->left != nullptr && node->right != nullptr) {
            count = 1;
        }
        return count + triangle(node->left) + triangle(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void print() {
        cout << triangle(root) << endl;
    }

};

int main() {
    BST tree;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
    }


    tree.print();
    return 0;
}