#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    int q,n;
    cin>>q;
    string s;
    bool reverse = false;
   while(q--){
        cin>>s;
        if(s=="reverse"){
            if(reverse){
                reverse = false;
            }else{
                reverse = true;
            }
        }
        else if(s=="push_back"){
            cin>>n;
            if(!reverse){
                dq.push_back(n);
            }else{
                dq.push_front(n);
            }
        }else if(s=="push_front"){
            cin>>n;
            if(!reverse){
                dq.push_front(n);
            }else{
                dq.push_back(n);
            }
        }else if(s == "front"){
            if(dq.size()==0){
                cout<<";("<<endl;
                continue;
            }
            if(!reverse){
                cout<<dq.front()<<endl;
                dq.pop_front();
            }else{
                cout<<dq.back()<<endl;
                dq.pop_back();
            }
        }else if(s == "back"){
            if(dq.size()==0){
                cout<<";("<<endl;
                continue;
            }
            if(!reverse){
                cout<<dq.back()<<endl;
                dq.pop_back();
            }else{
                cout<<dq.front()<<endl;
                dq.pop_front();
            }
        }
    }
    
    
    return 0;
}