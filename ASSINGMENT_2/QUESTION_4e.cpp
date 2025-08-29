#include<iostream>
using namespace std;

int main() {
    char arr[100]="My Name Is Niket Batra.";
    int n=0;
    while (arr[n] != '\0') {
        n++;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>=65 && arr[i]<=90){
            arr[i]=arr[i]+32;
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    cout << endl;
}