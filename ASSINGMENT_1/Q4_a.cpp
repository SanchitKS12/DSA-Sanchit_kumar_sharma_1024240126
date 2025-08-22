#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"ENTER THE SIZE OF ARRAY-";
    cin>>n;
    int arr[n] ;
    cout<<"ENTER THE ARRAY ELEMENTS-";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // Reverse logic
    for (int i = 0; i < n/2; i++) {
        swap(arr[i], arr[n-1-i]);
    }

    cout << "Reversed Array:";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}