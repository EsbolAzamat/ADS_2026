#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value): value(value), left(nullptr), right(nullptr) {}
};

struct BST {
private:
    Node* root;
    vector<Node*> nodes;

public:
    BST(int n) {
        nodes.resize(n + 1);

        for (int i = 1; i <= n; ++i) {
            nodes[i] = new Node(i);
        }

        root = nodes[1];
    }

    void connect(int x, int y, int z) {
        if (z == 0) {
            nodes[x]->left = nodes[y];
        }
        else {
            nodes[x]->right = nodes[y];
        }
    }

    void get_width() {
        queue<Node*> q;
        q.push(root);
        
        int maxWith = 0;
        while (!q.empty()) {
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
            }
            maxWith = max(maxWith, len);

        }
        cout << maxWith << endl;
    }
};

int main() {
    int n;
    cin >> n;

    BST tree(n);

    for (int i = 0; i < n-1; ++i) {
        int x, y , z;
        cin >> x >> y >> z;
        tree.connect(x, y, z);
    }

    tree.get_width();
    return 0;

}