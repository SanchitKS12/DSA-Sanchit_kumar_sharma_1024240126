#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int Left1[n1], Right1[n2];

    for (int i = 0; i < n1; i++)
        Left1[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        Right1[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (Left1[i] <= Right1[j]) {
            arr[k] = Left1[i];
            i++;
        } else {
            arr[k] = Right1[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = Left1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Right1[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
