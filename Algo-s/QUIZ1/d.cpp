#include <iostream>
#include <algorithm>

using namespace std;


bool find(int x, int l, int r){
    if(l > r) return false;
    int m = (l + r) / 2;
    if(a[m] == x) return true;
    else if(a[m] > x) return find(x, l, m - 1);
    else return find(x, m + 1, r);
}

int main(){
    int t;
    cin >> t;
    int ab,ac,bc, ratio;
    for(int i = 0; i < t; ++i){
        cin >> ab >> ac >> bc >> ratio;
    }

    return 0;
}