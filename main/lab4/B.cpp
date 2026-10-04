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

public:  

    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    Node* findNode(int X) {
        Node* current = root;
        while (current != nullptr) {
            if (X == current->value) {
                return current;
            }
            else if (current->value > X) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return nullptr;
    }
    
    
    int getSize(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        
        return 1 + getSize(node->left) + getSize(node->right);
    }


};

int main() {
    BST tree;
    int N, X;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    cin >> X;
    int res = tree.getSize(tree.findNode(X));
    cout << res << endl;


    return 0;
}