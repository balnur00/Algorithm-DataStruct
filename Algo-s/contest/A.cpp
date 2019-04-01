#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
string s;
int priority [300];
stack <char> op;
stack <int> num;
void do_operation(){
	char cur_op = op.top(); 
	op.pop();
	int x = num.top();
	num.pop();
	int y= num.top();
	num.pop();
	int res = 0;
	switch(cur_op){
		case '+': res= x + y;
			break;
		case '-': res= y - x;
			break;
		case '*': res= x * y;
			break;
	}
	num.push(res);
}

int main(){
		
priority['(']=0;
priority['+']=1;
priority['-']=1;
priority['*']=2;
 cin>>s;
 for(int i = 0; i<s.size();i++){
 	char ch = s[i];
 	if(ch == '+' || ch == '-'|| ch =='*'){
 		while(!op.empty()&& priority[op.top()]>=priority[s[i]]){
 			do_operation();
 		}
 		op.push(ch);
 	}else if(ch =='('){
 		op.push(ch);
 	}else if(ch == ')'){
 		while(op.top()!= '('){
 			do_operation();
 		}
 		op.pop();
 	}else{
 		int number= ch - '0';
 		num.push(number);
 	}
 }
while(!op.empty()){
	do_operation();
}
cout<<num.top()<<endl;


	return 0;
}