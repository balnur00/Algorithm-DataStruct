#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool isBalanced(string str){
    for(int i = 0; i < str.size()/2; ++i){
        /*if(str[i] == '(' && str[str.size() - 1 - i] == ')'){
            return true;
        }else if(str[i] == '{' && str[str.size() - 1 - i] == '}'){
            return true;
        }else if(str[i] == '[' && str[str.size() - 1 - i] == ']'){
            return true;
        }else return false;
        */
       if((str[i] == '(' && str[str.size() - 1 - i] == ')') || (str[i] == '{' && str[str.size() - 1 - i] == '}') || (str[i] == '[' && str[str.size() - 1 - i] == ']')){
           return true;
       }
       /*
       ()[]
       ({[]})
       (([]})

       (][)
       ( ]
       */
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    //stack<string> s;
    string str[n];

    for(int i = 0; i < n; ++i){
        cin >> str[i];

    }
    for(int i = 0; i < n; ++i){
        if(isBalanced(str[i])) cout << "YES"<< endl;
        else cout << "NO"<< endl;
    }
    return 0;
}