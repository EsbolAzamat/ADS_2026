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
    int diameter;

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


    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        diameter = max(diameter, leftHeight + rightHeight + 1);

        return max(leftHeight, rightHeight) + 1;
    }
 

public:
    BST() {
        root = nullptr;
        diameter = 0;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void print() {
        height(root);
        cout << diameter << endl;
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