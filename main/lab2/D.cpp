#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};


int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; ++i) {
        int x;
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
    Node* prev = nullptr;

    while (cur != nullptr) {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;       
    }

    head = prev;
    cur = head;

    while (cur != nullptr) {
        cout << cur->data << ' ';
        cur = cur->next;
    }

    return 0;
}