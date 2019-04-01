#include <iostream>
#include <set>

using namespace std;


int main(){
	int n, k, res;
	int mx = 10000;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	cin >> k;

	for (int i = 0; i < n; ++i){
		if(a[i] == k) {
			res = k;
			//cout << a[i]<< endl;
			break;
		}else if (abs(a[i]-k) < mx) {
			mx = abs(a[i]-k);
			//cout << a[i] << endl;
			//break;
			res = a[i];
		}

	}
	cout << res << endl;

	return 0;
}