#include<iostream>
using namespace std;

int linear_search(int a[7],int t){
    for(int i=0;i<7;i++){
        if(a[i]==t) return i;
    }
    return -1;
}

int binary_search(int a[7],int t){
    int lo=0,hi=6;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(a[mid]==t) return mid;
        else if(a[mid]<=t) lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}

int main() {
    int arr[7]={1,3,5,8,17,25,29};
    int target=25;

  
    int b=binary_search(arr,target);

    if(b==-1) cout<<"THE TARGET IS NOT PRESENT IN THE ARRAY";
    else cout<<"THE TARGET IS FOUND AT INDEX : "<<b<<"";
}