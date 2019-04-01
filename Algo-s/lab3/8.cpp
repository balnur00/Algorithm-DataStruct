#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int mn = 2000000000;
    int mn2 = 2000000000;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] < mn){
            mn = a[i];
        }
    }
    for (int i = 0; i < n; ++i){
        if(a[i] < mn2 && a[i] != mn){
            mn2 = a[i];
        }
    }
    cout << mn << " " << mn2 << endl;
     return 0;
 }