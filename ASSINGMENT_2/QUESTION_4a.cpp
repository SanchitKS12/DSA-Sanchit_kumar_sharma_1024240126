#include<iostream>
#include<string>
using namespace std;

int main() {
    char str1[100]="my name is ";
    char str2[50]="niket batra";
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';

    cout << "Concatenated string: " << str1;
}