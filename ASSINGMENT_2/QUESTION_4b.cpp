#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    char str1[100]="my name is niket batra.";
    int i=0;
    while (str1[i] != '\0') {
        i++;
    }
    for(int j=0;j<i/2;j++){
        swap(str1[j],str1[i-j-1]);
    }
    cout << "Reversed string: " << str1;
}