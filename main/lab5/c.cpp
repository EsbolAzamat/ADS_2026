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
            int lefti = left(curr);
            int righti = right(curr);

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

    long long socer(int x) {
        long long total = 0;

        for (int i = 0; i < x; ++i) {
            int k = extractTop();

            total += k;

            if (k > 1) {
                insert(k - 1);
            }
        }
        return total;
    }
};

int main() {
    int n, x;
    cin >> n >> x;

    maxHeap h;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        h.insert(x);
    }
    cout << h.socer(x) << endl;

    return 0;
}