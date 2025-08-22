#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    int arr[m][n];

    cout << "Enter the elements of the matrix:"<<endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout<<endl;


    cout << "Sum of each row:"<<endl;
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i+1 << " = " << rowSum << endl;
    }
    cout<<endl;

    // Sum of each column
    cout << "Sum of each column:"<<endl;
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j+1 << " = " << colSum << endl;
    }

    return 0;
}