#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    char arr[100]="my name is niket batra.";
    int n=0;
    while (arr[n] != '\0') {
        n++;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (!(arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U'||
              arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u')) {
            arr[k++] = arr[i];
        }
    }
    arr[k] = '\0';
    cout << arr;
    cout << endl;
}