#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
int count1 = 0, sum = 0;
  int max = 0, s = 0;

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  for(int i = 0; i < n - 1; i++){               
    for(int j = 0; j < n - i - 1; j++){
      if(a[j] > a[j + 1]){                       //bs
        s = a[j + 1];
        a[j + 1] = a[j];
        a[j] = s;
      }
    }
  }

  int a1[n];

  for(int i = 0; i < n; i++){                
    if(a[i] == a[i + 1]){
      count1++;
    }
    else{
      a1[sum] = count1 + 1;
      sum++;
      count1 = 0;
    }
  }

  if(n == 1){
    cout << 1 << " " << 1;
  }

  else if(sum == 0){
    if(count1 != 0){
      cout << n << " " << 1;  
    }

    else{
      cout << 1 << " " << n;
    }
  }


  else{
  
    for(int i = 0; i < sum; i++){
      if(a1[i] > max)
        max = a1[i];
    }

    cout << max << " " << sum;
  }

  return 0;
}