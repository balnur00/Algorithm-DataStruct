#include <iostream>
#include <vector>

using namespace std;
vector<int> a;
int i, size ,t,m, q;

void pushLeft(int q){
    
}
void pushRight(int q){
    //a[i] = size;
    //i++;
}
void popLeft(){

}
void popRight(){
    //int res = a[i-1];
    //i--;
}

int main(){
    cin >> t;
    string str;
    for(int i = 0; i < t; i++){
        cin >> size >> m;
        for(int j = 0; j < m; j++){
            cin >> str;
            if(str == "pushLeft"){
                cin >> q;
                pushLeft(q);
            }else if(str == "pushRight"){
                cin >> q;
                pushRight(q);
            }else if(str == "popLeft"){
                popLeft();
            }else if(str == "popRight"){
                popRight();
            }
        }
    }


    return 0;
}