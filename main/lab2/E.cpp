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

    if (N == 1) {
        head = nullptr;
    }
    else {
        int middle = N / 2;
        Node* cur = head;
    
        for (int i = 0; i < middle - 1; i++) {
            cur = cur->next;
        }

        cur->next = cur->next->next;
    }

    Node* cur = head;

    while (cur != nullptr) {
        cout << cur-> data << ' ';
        cur = cur->next;
    }



    return 0;
}