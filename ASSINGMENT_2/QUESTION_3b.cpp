#include<iostream>
using namespace std;

int main() {
    int arr[8]={1,2,3,4,6,7,8,9};
    int lo=0,hi=7;
    int missing = -1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==mid+1) lo=mid+1;
        else{
            missing=mid+1;
            hi=mid-1;        
        }
    }
    cout<<missing;
}