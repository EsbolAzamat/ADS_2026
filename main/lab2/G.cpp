#include<iostream>

using namespace std;

struct Node {
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};


int main() {
    int n, k;
    cin >> n >> k;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;

        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* cur = head;
    for (int i = 0; i < k - 1; ++i) {
        cur = cur->next;
    }

    Node* newHead = cur->next;
    tail->next = head;

    cur->next = nullptr;
    head = newHead;

    cur = head;

    while (cur != nullptr) {
        cout << cur->data << ' ';
        cur = cur->next;
    }

    return 0;
}