#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) {
        next = nullptr;
        data = value;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail-> next = newNode;
            tail = newNode;
        }
    }

    while (head != nullptr && head->data == q) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head != nullptr) {
        Node* curr = head->next;
        Node* prev = head;

        while (curr != nullptr) {
            if (curr->data == q) {
                Node* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;

    return 0;
}