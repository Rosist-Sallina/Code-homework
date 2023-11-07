#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        cout << "Insert element[" << i+1 << "]:" << endl;

        // Init state
        cout << "  Init:";
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                cout << a[j];
            else
                cout << " " << a[j];
        }
        cout << endl;

        // Insertion process
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            // Move back step
            cout << "  Move back:";
            for (int k = 0; k <= i; k++) {
                
                    if (k == j + 1)
                        cout << " " << a[j];
                    else
                        if (k == 0)
                        {
                            cout << a[k];

                        }
                        else
                        cout << " " << a[k];
                }
            
            cout << endl;

            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        // Final state
        cout << "  Final:";
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                cout << a[j];
            else
                cout << " " << a[j];
        }
        cout << endl;
    }

    return 0;
}
