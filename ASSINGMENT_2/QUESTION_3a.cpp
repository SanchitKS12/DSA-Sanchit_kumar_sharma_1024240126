#include<iostream>
using namespace std;

int main() {
    int arr[8]={1,2,3,4,6,7,8,9};
    for(int i=0;i<7;i++){
        if(arr[i]!=i+1){
            cout<<"THE ELEMENT '"<<i+1<<"' IS NOT PRESENT IN THE ARRAY.";
            break;
        }
    }
}