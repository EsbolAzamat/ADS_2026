#include<iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value): value(value), left(nullptr), right(nullptr) {}
};

struct BST{
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

    bool checkNode(int x) {
        Node* current = root;
        
        while (current != nullptr) {
            if (current->value > x) {
                current = current->left;
            }
            else if (current->value < x) {
                current = current->right;
            }
            else return true;
        }

        return false;
    }


};

int main() {
    int n, q;
    cin >> n;
    BST tree;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        if (tree.checkNode(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}