#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = nullptr;
    }
};

Node* mergeLists(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    Node* head = nullptr;
    Node* tail = nullptr;

    if (a->val <= b->val) {
        head = a;
        a = a->next;
    }
    else {
        head = b;
        b = b->next;
    }

    tail = head;

    while (a != nullptr && b != nullptr) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        }
        else {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    if (a != nullptr) {
        tail->next = a;
    }
    else {
        tail->next = b;
    }

    return head;
}

int main() {
    int n;
    cin >> n;

    Node* head1 = nullptr;
    Node* tail1 = nullptr;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        Node* node = new Node(x);

        if (head1 == nullptr) {
            head1 = node;
            tail1 = node;
        }
        else {
            tail1->next = node;
            tail1 = node;
        }
    }

    int m;
    cin >> m;

    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        Node* node = new Node(x);

        if (head2 == nullptr) {
            head2 = node;
            tail2 = node;
        }
        else {
            tail2->next = node;
            tail2 = node;
        }
    }

    Node* head = mergeLists(head1, head2);

    Node* current = head;

    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }

    cout << endl;

    return 0;
}