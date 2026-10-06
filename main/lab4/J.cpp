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
    int count;
    int answer;

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

    void kthSmallest(Node* node, int k) {
        if (node == nullptr || answer != -1) {
            return;
        }

        kthSmallest(node->left, k);

        if (answer != -1) {
            return;
        }

        count++;

        if (count == k) {
            answer = node->value;
            return;
        }

        kthSmallest(node->right, k);
    }

public:
    BST() {
        root = nullptr;
        count = 0;
        answer = -1;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void print(int k) {
        kthSmallest(root, k);
        cout << answer << endl;
    }
};

int main() {
    BST tree;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    tree.print(k);
    return 0;
}