#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n;
    int a[n];
    int o;
    for(int i=0; i<n; i++){
        cin >> o;
        if(i == 0) a[0] = o;
        else a[i] = a[i - 1] + o;
    }
    
    cin>>m;
    int q;
    
    
    for(int i=0; i<m; i++){
        cin>>q;
        
        int  l = 0, r = n - 1;
        while(l < r){
            int m = (l + r) / 2;
            if(a[m] < q){
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        cout<<r+1<<endl;
    }
    
    
    
    
    return 0;
}