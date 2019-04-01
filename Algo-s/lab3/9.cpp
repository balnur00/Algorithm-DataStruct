#include <iostream>

using namespace std;

int main(){
    int n;
    int x;
    cin >> x;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    bool ok = false;
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            if (x == a[i][j]) {
                ok = true;
            }
        }
    }
    if(ok) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
     return 0;
 }