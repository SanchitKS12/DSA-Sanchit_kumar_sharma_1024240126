#include<iostream>
using namespace std;

int main() {
    int m;
    cout<<"ENTER THE NUMBER OF ROWS-";
    cin>>m;
    int n;
    cout<<"ENTER THE NUMBER OF COLUMNS-";
    cin>>n;
    int arr1[m][n] ;
    cout<<"ENTER THE ARRAY ELEMENTS-";
    for(int i=0;i<m;i++){
        cout<<"ENTER THE ELEMENTS OF ROW"<<i+1<<" -";
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }

     cout << "Before Transpose of Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    int arr2[n][m];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr2[j][i] = arr1[i][j];
        }
    }

    cout << "Transpose of Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}