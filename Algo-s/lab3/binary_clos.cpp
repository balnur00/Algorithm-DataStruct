#include <iostream>
#include <cmath>
 
using namespace std;
 
int binary (int a[], int k, int n){
    int l = 0;
    int r = n - 1;
    while (l < r){
        int m = (l + r) / 2;
        if (a[m] < k)
            l = m + 1;
        if (a[m] > k)
            r = m - 1;
        if (a[m] == k)
            return a[m];
    }
    if (l != 0)
        l--;
    if (r != n - 1)
        r++;
    int ans = a[l];
    for (int i = l; i <= r; i++){
        if (abs(ans - k) > abs(a[i] - k))
            ans = a[i];
        if (abs(ans - k) == abs(a[i] - k) && a[i] < ans)
            ans = a[i];
    }
    return ans;
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++){
        int k;
        cin >> k;
        cout << binary(a, k, n) << endl;
    }
    return 0;
}