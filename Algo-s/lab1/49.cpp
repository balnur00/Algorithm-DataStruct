#include <iostream>
#include <algorithm>
 
using namespace std;
struct Class{
    string name;
    int grade;
};
bool comp(Class a, Class b){
    return a.grade < b.grade;
}
int main()
{
    int n = 0;
    Class *c = new Class[n];
    while(cin >> c[n].grade >> c[n].name){
        n++;
    }
    sort(c, c+n, &comp);
    for(int i = 0; i < n; ++i){
        cout << c[i].grade <<" "<< c[i].name <<endl;
    }
    return 0;
}