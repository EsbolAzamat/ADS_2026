#include<iostream>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value): value(value), left(nullptr), right(nullptr) {}
};

class BST {
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

    Node* findNode(int X) {
        Node* current = root;
        while (current != nullptr) {
            if (X == current->value) {
                return current;
            }
            else if (X < current->value) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        } 
        return nullptr;
    }

    void preorderRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->value << ' ';
        preorderRec(node->left);
        preorderRec(node->right);
    }

public:  

    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void print(int X) {
        preorderRec(findNode(X));
    }

};

int main() {
    BST tree;
    int N, k;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    cin >> k;
    tree.print(k);
    return 0;
}