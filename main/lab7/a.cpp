#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

void print(vector<string> arr) {
    for (string x : arr) cout << x << ' ';
    cout << endl;
}

void merge(vector<string> &arr, int left, int mid, int right) {
    int n = mid - left + 1;
    int m = right - mid;

    vector<string> L(n), R(m);

    for (int i = 0; i < n; ++i) 
        L[i] = arr[i + left];
    for (int i = 0; i < m; ++i)
        R[i] = arr[mid + i + 1]; 
    
    int i = 0, j = 0;
    int k = left;

    while (i < n && j < m) {
        if (L[i].size() <= R[j].size()) {
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
        i++;
        k++;
    }
    while (j < m) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string> &arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; ++i) {
        vector<string> arr;
        string line, word;
        getline(cin, line);

        stringstream ss(line);
        while (ss >> word) {
            arr.push_back(word);
        }

        int n = arr.size();
        mergeSort(arr, 0, n - 1);
        print(arr);
    }

    return 0;
}