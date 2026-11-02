#include<iostream>
#include<vector>


using namespace std;

struct maxHeap {
private:
    vector<int> heap;

    int parent(int i) {return (i - 1) / 2; }
    int left(int i) {return 2*i + 1; }
    int right(int i) {return 2*i + 2; }

    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int curr = i;
            int lefti = left(i);
            int righti = right(i);

            if (lefti < n && heap[lefti] > heap[curr]){
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
    void heapBuild() {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void read(int n) {
        heap.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> heap[i];
        }
    }

    void print() {
        for (int x: heap) {
            cout << x << ' ';
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    maxHeap h;

    h.read(n);
    h.heapBuild();
    h.print();
    return 0;
}