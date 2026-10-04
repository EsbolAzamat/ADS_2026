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

Node* insert(Node* head, int x, int p) {
    Node* node = new Node(x);

    if (p == 0) {
        node->next = head;
        return node;
    }

    Node* cur = head;

    for (int i = 0; i < p - 1; ++i) {
        cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;

    return head;
}

Node* removeNode(Node* head, int p) {
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* cur = head;

    for (int i = 0; i < p - 1; ++i) {
        cur = cur->next;
    }

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;

    return head;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << -1 << '\n';
        return;
    }

    Node* cur = head;

    while (cur != nullptr) {
        cout << cur->val;
        if (cur->next != nullptr) {
            cout << ' ';
        }
        cur = cur->next;
    }

    cout << '\n';
}

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) {
        return head;
    }

    Node* node = head;
    Node* prev1 = nullptr;

    for (int i = 0; i < p1; ++i) {
        prev1 = node;
        node = node->next;
    }

    if (prev1 == nullptr) {
        head = node->next;
    }
    else {
        prev1->next = node->next;
    }

    if (p2 == 0) {
        node->next = head;
        head = node;
        return head;
    }

    Node* cur = head;

    for (int i = 0; i < p2 - 1; ++i) {
        cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;

    return head;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;

    while (cur != nullptr) {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

Node* cyclic_left(Node* head, int x) {
    if (head == nullptr || head->next == nullptr || x == 0) {
        return head;
    }

    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    Node* newTail = head;

    for (int i = 1; i < x; ++i) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    tail->next = head;
    newTail->next = nullptr;

    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (head == nullptr || head->next == nullptr || x == 0) {
        return head;
    }

    int len = 1;
    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
        len++;
    }

    x %= len;

    if (x == 0) {
        return head;
    }

    int steps = len - x;

    Node* newTail = head;

    for (int i = 1; i < steps; ++i) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    tail->next = head;
    newTail->next = nullptr;

    return newHead;
}

int main() {
    Node* head = nullptr;

    int command;

    while (cin >> command) {
        if (command == 0) {
            break;
        }

        if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, x, p);
        }
        else if (command == 2) {
            int p;
            cin >> p;
            head = removeNode(head, p);
        }
        else if (command == 3) {
            print(head);
        }
        else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5) {
            head = reverseList(head);
        }
        else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }

    return 0;
}