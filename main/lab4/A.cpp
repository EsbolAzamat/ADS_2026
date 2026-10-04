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

    bool checkPath(string path) {
        Node* current = root;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == 'L') {
                if (current->left != nullptr) current = current->left;
                else return false;
            }
            if (path[i] == 'R') {
                if (current->right != nullptr) current = current->right;
                else return false;
            }
        }
        return true;
    }

};

int main() {
    BST tree;
    
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    for (int i = 0; i < M; ++i) {
        string path;
        cin >> path;
        if (tree.checkPath(path)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}