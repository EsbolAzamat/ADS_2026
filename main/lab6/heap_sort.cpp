#include<iostream>
#include<vector>

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

            if (i != curr) {
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
        
        int top = heap[0];
        int tail = heap.size() - 1;

        swap(heap[0], heap[tail]);
        heap.pop_back();

        heapifyDown(0);

        return top;
    }

    vector<int> heapSort() {
        vector<int> copyHeap(heap);
        vector<int> result(heap.size());

        int i = 0;
        while (!heap.empty()) {
            int top = extractTop();
            result[i] = top;
            i++;
        }

        heap = copyHeap;
        
        return result;
    }

    void print() {
        for (int x: heap) cout << x << ' ';
        cout << endl;
    }

};

int main() {
    int a[] = {3, 5, 10, 1, 9};
    int n = sizeof(a) / sizeof(int);

    minHeap h;

    for (int i = 0; i < n; ++i) {
        h.insert(a[i]);
    }

    h.print();

    vector<int> ex = h.heapSort();

    for (int x: ex) cout << x << ' ';
    cout << endl;

    return 0;
}