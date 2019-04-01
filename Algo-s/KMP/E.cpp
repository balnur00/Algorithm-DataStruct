#include <iostream>
#include <string>

using namespace std;

int main() {
string str;
    while(str != ".") {
        cin >> str;
        int i, j, max_s;
        int s;
        int len;  
        for(max_s = 0,len = 1;len <= str.length();len++)
            if(str.length() % len == 0){
                for(i = 0, s = 1, j=len; str[j]!='\0'; i++, j++) {
                    if(i == len){
                        i = 0;
                        s++;
                    }
                    if(str[i] != str[j])
                    break;
            }
        if(i == len){
            i = 0;
            s++;
        }
        if(str[j] == '\0')
            if(s > max_s)
            max_s = s;
        }
            if (str != ".")
                cout << max_s << endl;
    }
 return 0;
}