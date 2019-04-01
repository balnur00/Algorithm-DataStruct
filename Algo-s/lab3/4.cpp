#include <iostream>

using namespace std;

int main(){
	int n, k;
	cin >> n;
	int a[n];
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	cin >> k;
	for (int i = 1; i <= n; ++i){
		if(a[i] == k) cout << i << " ";
	}
	return 0;
}