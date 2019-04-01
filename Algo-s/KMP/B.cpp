#include <iostream>
#include <cmath>
#include <map>

using namespace std;
/*p - lowest prime number, greater than the alphabet size
  p_pow[i] - the i-th power of the prime p
  h[i] - the hash function of s substring [0...i]
  hash_t - value of the hash function of t
*/
int p = 29;
long long int p_pow[100001];
long long int h[100001];
int main() {
    map<long long int, long long int> map;
    long long int m;
    string s;
    cin >> m;
    //Calculating p_pow
    p_pow[0] = 1;
    for (long long int i = 1; i < 100001; i++) 
        p_pow[i] = p_pow[i - 1] * p;

    for (long long int k = 0; k < m; k++) {
        cin >> s;
        long long int n = s.size();
        //Calculating the hash of all s substrings
        h[0] = s[0];
        for (long long int i = 1; i < n; i++)
            h[i] = h[i - 1] + s[i] * p_pow[i];
        if (map.find(h[n - 1]) == map.end()) {
            map.insert(make_pair(h[n - 1], 1));
            cout << "OK" << endl;
            continue;
        }
        cout << s << map[h[n - 1]] << endl;
        map[h[n - 1]]++;
    }
    return 0;
}