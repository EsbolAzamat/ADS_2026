#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value): value(value), left(nullptr), right(nullptr) {};
};

struct BST {
private:
    Node* root;
    int sum;
    vector<int> result;


    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (node->value > value) {
            node->left = insertRec(node->left, value);
        }
        else {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void greaterSum(Node* node) {
        if (node == nullptr) {
            return;
        }

        greaterSum(node->right);

        sum += node->value;
        node->value = sum;

        result.push_back(node->value);

        greaterSum(node->left);
    }

public:
    BST() {
        root = nullptr; 
        sum = 0;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void print() {
        greaterSum(root);

        for (int x: result) cout << x << ' ';
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