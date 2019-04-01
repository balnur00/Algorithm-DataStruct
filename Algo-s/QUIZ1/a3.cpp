#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
int main(){
    map<char,char> mapp;
    mapp[')'] = '(';
    mapp[']'] = '[';
    mapp['}'] = '{';
    int t;
    cin >> t;
    while(t--){
        string s;
        stack<char>st;
        cin >> s;
        int q = 0;
        for(int i = 0; s[i] != '\0'; ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(!st.empty() && mapp[s[i]] == st.top()){
                    st.pop();
                }else{
                    q = 1;
                    break;
                }
            }
        }
        if(!q && st.empty())
        cout << "YES" << endl;
        else cout << "NO" <<  endl;
    }
    return 0;
}
