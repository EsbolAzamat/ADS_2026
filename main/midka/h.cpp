#include<iostream>
#include<vector>

using namespace std;

struct maxHeap {
private:
    vector<int> heap;

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
            int lefti = left(i);
            int righti = right(i);

            if (lefti < n && heap[lefti] > heap[curr]) {
                curr = lefti;
            }
            if (righti < n && heap[righti] > heap[curr]) {
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
    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        heapifyUp(i);
    } 

    int extractTop() {
        if (heap.empty()) return -1;

        int t = heap[0];
        int tail = heap.size() - 1;

        swap(heap[0], heap[tail]);
        heap.pop_back();
        heapifyDown(0);
        return t;
    }

};

int main() {
    int n;
    cin >> n;
    maxHeap h;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        h.insert(x);
    }

    for (int i = 0; i < n; ++i) {
        int k = h.extractTop();
        cout << k << ' ';

    }
    return 0;
}