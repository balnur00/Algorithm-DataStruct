#include <iostream>

using namespace std;

/*int guess(int n){
    int l = 0;
    int r = n - 1;
    int a[n];
    int k;
    a[0] = 1;
    while(l < r){
        int m = (l + r)/ 2;
        if (a[m] < k)
            l = m + 1;
        if (a[m] > k)
            r = m - 1;
        if (a[m] == k)
            return a[m];
    }
}*/

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int l = 1;
    while(l < n){
        l = l*2;
        ++cnt;
    }

    cout << cnt << endl;
    return 0;
}