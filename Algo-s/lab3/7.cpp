#include <iostream>
using namespace std;
int main(){
    int n;
    int mx = -1001;
    cin >> n;
    int a[n];
    int index;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] > mx){
            mx = a[i];
            index = i;
        }
    }
    cout << index << endl;
     return 0;
 }