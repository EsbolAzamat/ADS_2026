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
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < N; ++i) {
        string x;
        cin >> x;

        if (tail == nullptr || tail->data != x) {
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
    }


    Node* cur = head;
    int count = 0;

    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }

    cout << count << endl;
    cur = head;

    while(cur != nullptr) {
        cout << cur->data << endl;
        cur = cur->next;

    }
    

    return 0;
}