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
        int n, p, x; 
        cin >> n;

        Node* head = nullptr;
        Node* tail = nullptr;

        for (int i = 0; i < n; ++i) {
            int data;
            cin >> data;

            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        cin >> p >> x;

        Node* newNode = new Node(x);
        
        if (p == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* curr = head;
            
            for (int i = 0; i < p - 1; ++i) {
                curr = curr->next;
            }

            Node* temp = curr->next;
            curr->next = newNode;
            newNode->next = temp;
        }

        Node* curr = head;


        while (curr!= nullptr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << endl;

        
        return 0;
    }