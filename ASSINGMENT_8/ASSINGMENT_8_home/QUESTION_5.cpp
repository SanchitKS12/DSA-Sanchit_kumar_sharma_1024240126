#include<bits/stdc++.h>
using namespace std;


void maxHeapify(vector<int> &a, int n, int i) {
    int largest = i;
    while (true) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest != i) {
            swap(a[i], a[largest]);
            i = largest;
        } else break;
    }
}

void minHeapify(vector<int> &a, int n, int i) {
    int smallest = i;
    while (true) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && a[l] < a[smallest]) smallest = l;
        if (r < n && a[r] < a[smallest]) smallest = r;
        if (smallest != i) {
            swap(a[i], a[smallest]);
            i = smallest;
        } else break;
    }
}

void heapSortIncreasing(vector<int> a) {
    int n = (int)a.size();
    for (int i = n/2 - 1; i >= 0; --i) maxHeapify(a, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
    cout << "Heapsort increasing: ";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

void heapSortDecreasing(vector<int> a) {
    int n = (int)a.size();
    for (int i = n/2 - 1; i >= 0; --i) minHeapify(a, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }
    cout << "Heapsort decreasing: ";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "\n=== Heapsort demo ===\n";
    vector<int> v1 = {3, 5, 1, 8, 7, 2};
    heapSortIncreasing(v1);
    vector<int> v2 = {3, 5, 1, 8, 7, 2};
    heapSortDecreasing(v2);
    
    return 0;
}