#include<iostream>
#include<algorithm>
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

    sort(arr, arr + n);

    int j = 0; 
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != arr[i+1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n-1];

    cout << "UNIQUE ELEMENTS:";
    for (int i = 0; i < j; i++) cout << arr[i] << " ";
}