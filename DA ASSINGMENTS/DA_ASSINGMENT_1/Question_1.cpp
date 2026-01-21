#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return binarySearchRecursive(arr, left, mid - 1, target);
    return binarySearchRecursive(arr, mid + 1, right, target);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
