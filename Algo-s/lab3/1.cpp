#include <iostream>
#include <algorithm>

using namespace std;


int main(){

	int n, q;
	cin >> n;

	int k[n];

	for (int i = 0; i < n; ++i){
		cin >> k[i];
	}
	cin >> q;

	int cnt = 0;
	int l = 0;
	int r = n - 1;
	while(l <= r){
		int m = (l+r)/2;
		if(k[n] < q){
			l = m + 1;
		}else if(k[n] > q){
			r = m - 1;
		}else{
			cnt++;
			break;
		}
	}
	cout << cnt << endl;


	return 0;
}