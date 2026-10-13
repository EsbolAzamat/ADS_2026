#include<iostream>
#include<vector>

using namespace std;

struct minHeap {
private:
    vector<int> heap;
    long long total = 0;
    int k;

    int parent(int i) {return (i -1) / 2;}
    int left(int i) {return 2*i + 1; }
    int right(int i) {return 2*i + 2; }

    void heapifyUp(int i) {
        while (i > 0) {
            int p = parent(i);

            if (heap[i] < heap[p]) {
                swap(heap[i], heap[p]);
                i = p;
            }
            else break;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int curr = i;
            int lefti = left(curr);
            int righti = right(curr);

            if (lefti < n && heap[lefti] < heap[curr]) {
                curr = lefti;
            }
            if (righti < n && heap[righti] < heap[curr]) {
                curr = righti;
            }

            if (curr != i) {
                swap(heap[curr], heap[i]);
                i = curr;
            }
            else break;
        }
    }

public:     
    minHeap(int k) {
        this->k = k;
    }

    void insert(int x) {
        if (heap.size() < k) {
            heap.push_back(x);
            total += x;
            heapifyUp(heap.size() - 1);
        }
        else if (x > heap[0]) {
            total -= heap[0];
            heap[0] = x;
            total += x;
            heapifyDown(0);
        }
    }

    long long printSum() {
        return total;
    }
};

int main() {
    int q, k;
    cin >> q >> k;
    minHeap h(k);

    for (int i = 0; i < q; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            int x;  
            cin >> x;
            h.insert(x);
        }
        else if (command == "print") {
            cout << h.printSum() << endl;
        }
    }

    return 0;
}