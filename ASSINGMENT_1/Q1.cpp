#include <iostream>
using namespace std;

int main() {
    int arr[100];   // maximum size
    int n = 0;      // current size
    int choice;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: { // CREATE
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            break;
        }

        case 2: { // DISPLAY
            cout << "Array elements are: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }

        case 3: { // INSERT
            int pos, val;
            cout << "Enter position (0-based index): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;

            if (pos < 0 || pos > n) {
                cout << "Invalid position!" << endl;
            } else {
                // shift elements right
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i-1];
                }
                arr[pos] = val;
                n++;
                cout << "Element inserted." << endl;
            }
            break;
        }

        case 4: { // DELETE
            int pos;
            cout << "Enter position (0-based index): ";
            cin >> pos;
            if (pos < 0 || pos >= n) {
                cout << "Invalid position!" << endl;
            } else {
                // shift elements left
                for (int i = pos; i < n-1; i++) {
                    arr[i] = arr[i+1];
                }
                n--;
                cout << "Element deleted." << endl;
            }
            break;
        }

        case 5: { // LINEAR SEARCH
            int key, found = -1;
            cout << "Enter element to search: ";
            cin >> key;
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    found = i;
                    break;
                }
            }
            if (found != -1)
                cout << "Element found at position " << found << endl;
            else
                cout << "Element not found!" << endl;
            break;
        }

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}