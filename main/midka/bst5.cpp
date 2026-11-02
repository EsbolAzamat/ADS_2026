#include<iostream>
#include<climits>

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

    int find_min() {
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->value;
    }

    int find_max() {
        Node* current = root;

        while (current->right != nullptr) {
            current = current->right;
        }
        return current->value;
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

    cout << tree.find_min() << ' ' << tree.find_max() << endl;
    return 0;
}