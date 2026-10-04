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

    Node* cur = head;
    
    int sum = cur->data;
    int maxSum = cur->data;

    cur = cur->next;

    while (cur != nullptr) {
        if (sum + cur->data > cur-> data) {
            sum = sum + cur->data;
        }
        else {
            sum = cur->data;
        }

        if (sum > maxSum) {
            maxSum = sum;
        }
        cur = cur->next;
    }

    cout << maxSum << endl;

    
    return 0;
}