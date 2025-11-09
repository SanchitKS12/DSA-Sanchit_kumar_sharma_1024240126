#include<bits\stdc++.h>
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

struct MaxPriorityQueue {
    vector<int> heap;
    void push(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] < heap[i]) {
                swap(heap[p], heap[i]);
                i = p;
            } else break;
        }
    }
    int top() const {
        if (heap.empty()) throw runtime_error("empty maxpq");
        return heap[0];
    }
    void pop() {
        if (heap.empty()) throw runtime_error("empty maxpq");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            maxHeapify(heap, (int)heap.size(), 0);
        }
    }
    bool empty() const { return heap.empty(); }
    int size() const { return (int)heap.size(); }
};

struct MinPriorityQueue {
    vector<int> heap;
    void push(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] > heap[i]) {
                swap(heap[p], heap[i]);
                i = p;
            } else break;
        }
    }
    int top() const {
        if (heap.empty()) throw runtime_error("empty minpq");
        return heap[0];
    }
    void pop() {
        if (heap.empty()) throw runtime_error("empty minpq");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            minHeapify(heap, (int)heap.size(), 0);
        }
    }
    bool empty() const { return heap.empty(); }
    int size() const { return (int)heap.size(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "\n=== Priority queue (heap) demo ===\n";
    MaxPriorityQueue maxpq;
    MinPriorityQueue minpq;
    vector<int> items = {4, 1, 7, 3, 8, 5};
    cout << "Max-PQ push: ";
    for (int x : items) {
        maxpq.push(x);
        cout << x << " ";
    }
    cout << "\nMax-PQ top then pop sequence: ";
    while (!maxpq.empty()) {
        cout << maxpq.top() << " ";
        maxpq.pop();
    }
    cout << "\n";
    cout << "Min-PQ push: ";
    for (int x : items) {
        minpq.push(x);
        cout << x << " ";
    }
    cout << "\nMin-PQ top then pop sequence: ";
    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << "\n";
    
    return 0;
}