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
    int n, k;
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

    Node* slow = head;
    Node* fast = head;

    cin >> k;
    
    for (int i = 0; i < k; ++i) {
        fast = fast->next;
    }

    if (fast == nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        Node* temp = slow->next;
        slow = temp->next;
        delete temp;
    }

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;

    return 0;
}