#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
 int t, n, v;
 int x;
    vector<int> prime;
    prime.push_back(2);
    prime.push_back(3);
    for(int i = 5; i <= 10000; i++)
    {
        int no = 0;
        for(int j = 2; j*j <= i; j++)
        {
            if(i%j == 0)
                no = 1;
        }
        if(!no)
        {
            prime.push_back(i);
  }
    }
    cin>>n>>t;
    stack<int> stack1,stack2,stack3;
    for(int i=0;i<n;i++)
    {
  cin>>x;
  stack1.push(x);
 }
 for(int i=0;i<t;i++)
 {
  int z=prime[i];
  if(stack1.empty())
  {
     break;
     }
  while(!stack1.empty())
  {
   int a=stack1.top();
   stack1.pop();
   if(a%z==0)
   {
    stack2.push(a);
   }
   else
   {
    stack3.push(a);
   }
  }
  while(!stack2.empty())
  {
      cout<<stack2.top()<<"\n";
      stack2.pop();
  }
  stack1=stack3;
  while(!stack3.empty())
  {
      stack3.pop();
     }
 
 }
 while(!stack1.empty())
 {
  cout<<stack1.top()<<"\n";
  stack1.pop();
 }
}