#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int main() {
    int n;
    cin >> n;

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
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* curr = head;

    while (curr != nullptr) {
        Node* prev = curr;
        Node* runner = curr->next;

        while (runner != nullptr) {
            if (curr->data == runner->data) {
                Node* temp = runner;
                prev->next = runner->next;
                runner = runner->next;
                delete temp;
            }
            else {
                prev = runner;
                runner = runner->next;
            }
        }
        curr = curr->next;
    }

    curr = head;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;


    return 0;
}