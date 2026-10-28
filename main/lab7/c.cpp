#include<iostream>
#include<vector>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    int sumA = 0, sumB = 0;
    
    for (int x: a) sumA += x;
    for (int x: b) sumB += x;

    if (sumA != sumB) {
        return sumA > sumB;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return true;
}


void merge(vector<vector<int>> &arr, int left, int mid, int right) {
    int n = mid - left + 1;
    int m = right - mid;

    vector<vector<int>> L(n), R(m);

    for (int i = 0; i < n; ++i) {
        L[i] = arr[i + left];
    }
    for (int i = 0; i < m; ++i) {
        R[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n && j < m) {
        
        if (compare(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < m) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<vector<int>> &arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}