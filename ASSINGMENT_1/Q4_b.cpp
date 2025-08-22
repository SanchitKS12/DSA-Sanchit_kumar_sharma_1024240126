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


    int u;
    cout<<"ENTER THE NUMBER OF ROWS-";
    cin>>u;
    int v;
    cout<<"ENTER THE NUMBER OF COLUMNS-";
    cin>>v;
    int arr2[u][v] ;
    cout<<"ENTER THE ARRAY ELEMENTS-";
    for(int i=0;i<u;i++){
        cout<<"ENTER THE ELEMENTS OF ROW"<<i+1<<" -";
        for(int j=0;j<v;j++){
            cin>>arr2[i][j];
        }
    }
    int arr3[m][v];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < v; j++) {
            arr3[i][j] = 0;
            for (int k = 0; k < n; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < v; j++) {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
}