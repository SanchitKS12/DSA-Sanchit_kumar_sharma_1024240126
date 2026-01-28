#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxCrossingSum(vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int leftMax = INT_MIN;

    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        leftMax = max(leftMax, sum);
    }

    sum = 0;
    int rightMax = INT_MIN;

    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        rightMax = max(rightMax, sum);
    }

    return leftMax + rightMax;
}

int maxSubArray(vector<int>& arr, int left, int right) {
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int leftSum = maxSubArray(arr, left, mid);
    int rightSum = maxSubArray(arr, mid + 1, right);
    int crossSum = maxCrossingSum(arr, left, mid, right);

    return max({leftSum, rightSum, crossSum});
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(arr, 0, arr.size() - 1);
    return 0;
}
