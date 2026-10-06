#include<iostream>
#include<vector>

using namespace std;

struct Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value): value(value), right(nullptr), left(nullptr) {} 
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

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    int child(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }

        return child(node->left) + child(node->right);

    }

    void print() {
        cout << child(root) << endl;
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