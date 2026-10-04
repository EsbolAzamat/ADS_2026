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
    while (cur != nullptr && cur->next != nullptr){
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        cur = cur->next;
    }

    cur = head;

    while(cur != nullptr) {
        cout << cur -> data << ' ';
        cur = cur->next;

    }

    return 0;
}