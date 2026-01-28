#include <bits/stdc++.h>
using namespace std;

int toMinutes(const string& t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

int minimumPlatforms(vector<string>& AT, vector<string>& DT) {
    int n = AT.size();
    vector<int> arr(n), dep(n);

    for (int i = 0; i < n; i++) {
        arr[i] = toMinutes(AT[i]);
        dep[i] = toMinutes(DT[i]);
    }

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else {
            platforms--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {
    vector<string> AT = {"09:00", "09:10", "09:20", "11:00", "11:20"};
    vector<string> DT = {"09:40", "12:00", "09:50", "11:30", "11:40"};

    cout << "Minimum number of platforms required is "
         << minimumPlatforms(AT, DT) << endl;

    return 0;
}
