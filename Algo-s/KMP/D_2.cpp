#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int T;

int main()
{
	cin >> T;
	while (T--)
	{
		string s, t;
		cin >> s >> t;
		int n = (int)t.length();
		string q = t + '#' + s;
		vector<int> pi = prefix_function(q), ans;
		for (int i = n + 1; i < q.length(); i++)
			if (pi[i] == n)
				ans.push_back(i - 2 * n + 1);
		if (ans.empty())
			cout << "Not Found\n";
		else
		{
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << ' ';
			cout << endl;
		}
		cout << endl;
	}
}