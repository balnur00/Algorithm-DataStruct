#include <iostream>
#include <vector>
 
using namespace std;
vector<int> a;
int i;
void push(int n){
    a[i] = n;
    i++;
    cout << "ok" << endl;
}
int pop(){
    int res = a[i-1];
    i--;
    cout<< res << endl;
}
void back(){
    cout << a[i]<< endl;
}
void size(){
    cout << i << endl;
}
void clear(){
    i = 0;
    cout << "ok"<< endl;
}
void exit(){
    cout << "bye" << endl;
}
 
int main(){
    string str;
    int k;
 
    while(cin >> str){
        if(str == "push"){
            cin >> k;
            push(k);
        }else if(str == "pop"){
            pop();
        }else if(str == "back"){
            back();
        }else if(str == "size"){
            size();
        }else if(str == "clear"){
            clear();
        }else if(str == "exit"){
            exit();
        }
    }
    return 0;
}
