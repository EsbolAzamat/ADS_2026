#include<iostream>
#include<vector>

using namespace std;

struct maxHeap {
private: 
    vector<long long> heap;

    int parent(int i) {return (i - 1) / 2; }
    int left(int i) {return 2*i + 1; }
    int right(int i) {return 2*i + 2; }

    void heapifyUp(int i) {
        while (i > 0) {
            int p = parent(i);

            if (heap[i] > heap[p]) {
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

            if (lefti < n && heap[lefti] > heap[curr]) {
                curr = lefti;
            }
            if (righti < n && heap[righti] > heap[curr]) {
                curr = righti;
            }

            if (curr != i) {
                swap(heap[i], heap[curr]);
                i = curr;
            }
            else break;
        }
    }

public:
    void insert(long long x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        heapifyUp(i);
    }

    long long extractTop() {
        if (heap.empty()) return -1;

        long long t = heap[0];
        int tailIdx = heap.size() - 1;

        swap(heap[0], heap[tailIdx]);
        heap.pop_back();

        heapifyDown(0);

        return t;
    }

    long long rocks() {
        while (heap.size() > 1) {
            long long x = extractTop();
            long long y = extractTop();

            if (x == y) {
                continue;
            }

            if (x > y) {
                insert(x - y);
            }
            else {
                insert(y - x);
            }
        }

        if (heap.empty()) {
            return 0;
        }

        
        return heap[0];
    }

};

int main() {
    int n;
    cin >> n;
    maxHeap h;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        h.insert(x);
    }

    cout << h.rocks() << endl;
    return 0;
}