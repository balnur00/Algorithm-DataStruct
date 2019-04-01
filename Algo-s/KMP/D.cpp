#include <iostream>
#include <cmath>

using namespace std;
/*p - lowest prime number, greater than the alphabet size
  p_pow[i] - the i-th power of the prime p
  h[i] - the hash function of s substring [0...i]
  hash_t - value of the hash function of t
*/
int p = 29;
long long int p_pow[1000000];
long long int h[1000000];
long long int hash_t = 0;

int main() {
    int k;
    cin >> k;

    for (int g = 0; g < k; g++) {
        bool OK = false;
        int counter = 0;
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();

        //Calculating p_pow
        p_pow[0] = 1;
        for (int i = 1; i < n; i++) 
            p_pow[i] = p_pow[i - 1] * p;
        //Calculating the hash of all s substrings
        h[0] = s[0];
        for (int i = 1; i < n; i++)
            h[i] = h[i - 1] + s[i] * p_pow[i];
        //Calculating the hash of t string
        hash_t = t[0];
        for (int i = 1; i < m; i++)
            hash_t += t[i] * p_pow[i];

        for (int i = 0; i + m - 1 < n; i++) {
            int j = i + m - 1;
            long long int hash = h[j];
            if (i > 0) hash -= h[i - 1];
            if (hash == hash_t * p_pow[i]) {
                OK = true;
                counter++;
            }
        }
        if (counter != 0) cout << counter << endl;
        for (int i = 0; i + m - 1 < n; i++) {
            int j = i + m - 1;
            long long int hash = h[j];
            if (i > 0) hash -= h[i - 1];
            if (hash == hash_t * p_pow[i]) {
                cout << i + 1 << " ";
            }
        }
        if (!OK) cout << "Not Found";
        cout << endl;
    }

    return 0;
}