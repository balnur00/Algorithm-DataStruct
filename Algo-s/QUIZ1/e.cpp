#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
bool find(queue<int> q, int n){
    //queue<int> iterator it;
    /*for(int i =0; i<q.size(); ++i){
        if(q[i] == n) return true;
    }*/
    
    return false;
}
int main(){
    queue<int> que;
    int q, n;
    int cnt=0;
    cin >> q;
    for(int i = 0; i< q; ++i){
        cin >>n;
        while(!que.empty() && n!=0){
            int b;
            for(int a = 0; a < sqrt(n); ++a){
                if(b == n/a && !find(que, b)){
                    que.push(b);
                    cnt++;
                }
            }
            if(!find(que, n-1)){
                que.push(n-1);
                cnt++;
            }
        }
        
    }
    if(n==0){
        cout<<cnt;
    }

    return 0;
}