#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int a[7]){
    for(int i=0;i<6;i++){
        for(int j=0;j<6-i;j++){
            if(a[j]>=a[j+1]) swap(a[j],a[j+1]);
        }
    }
    return;
}

int main() {
    int arr[7]={64,34,25,12,22,11,90}; 
    bubble_sort(arr); 
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}