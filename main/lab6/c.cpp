#include<iostream>
#include<vector>
#include <climits>

using namespace std;

struct minHeap {
private:
    vector<int> heap;

    int parent(int i) {return (i - 1) / 2; }
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
    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        heapifyUp(i);
    }

    int extractTop() {
        int top = heap[0];
        int tail = heap.size() - 1;

        swap(heap[0], heap[tail]);
        heap.pop_back();

        heapifyDown(0);

        return top;
    }

    vector<int> heapSort() {
        vector<int> copyHeap(heap);
        vector<int> res(heap.size());

        int i = 0;
        while (!heap.empty()) {
            int x = extractTop();
            res[i] = x;
            ++i;
        }

        heap = copyHeap;

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    minHeap h;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        h.insert(x);
    }

    vector<int> sorted = h.heapSort();

    int minDiff = INT_MAX;

    for (int i = 0; i < n - 1; ++i) {
        int diff = sorted[i + 1] - sorted[i];

        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    for (int i = 0; i < n-1; ++i) {
        if (sorted[i + 1] - sorted[i] == minDiff) {
            cout << sorted[i] << ' ' << sorted[i + 1] << ' ';
        }
    }

    cout << endl;
    

    return 0;
}