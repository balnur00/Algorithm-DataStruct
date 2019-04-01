#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function (string s) 
{
  int n = (int)s.length();
  vector<int> pi (n);
  for (int i = 1; i < n; i++) 
  {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int n;

int main()
{
  while (true)
  {
    cin >> n;
    if (n == 0) break;
    string pat[n], s;
    map<string, int> cnt;
    for (int i = 0; i < n; i++)
      cin >> pat[i];
    cin >> s;
    for (int i = 0; i < n; i++)
    {
      int m = pat[i].length();
      string t = pat[i] + '#' + s;
      vector<int> pi = prefix_function(t);
      for (int j = m + 1; j < t.length(); j++)
        if (pi[j] == m)
          cnt[pat[i]]++;
    }
    int mx = 0;

    for (auto &it: cnt)
      mx = max(it.second, mx);
    cout << mx << endl;
    
    for (int i = 0; i < n; i++)
      if (cnt[pat[i]] == mx)
        cout << pat[i] << endl;
  }
}
