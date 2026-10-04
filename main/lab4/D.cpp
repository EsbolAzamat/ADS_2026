#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node (int value): value(value), left(nullptr), right(nullptr) {}
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

    void levelSums() {
        if (root == nullptr) {
            return;
        }

        vector<int> sums;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sum = 0;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                Node* current = q.front();
                q.pop();

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }

                sum += current->value;
            }
            sums.push_back(sum);
        }
        cout << sums.size() << endl;
        for (int x: sums) {
            cout << x << ' ';
        }
    }

};

int main() {   
    BST tree;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    tree.levelSums();

    return 0;
}