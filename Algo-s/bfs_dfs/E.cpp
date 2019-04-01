#include <iostream>

using namespace std;

int u[100][100];

int main() {
    int n, id;
    int k, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> v;
            u[id - 1][v - 1] = 1;
        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1)
                cout << u[i][j];
            else
                cout << u[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}