#include <bits/stdc++.h>

using namespace std;

vector<int> g[100];
bool used[100];
vector<int> result;
void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == false) {
            dfs(g[v][i]);
        }
    }  
    result.push_back(v);
}

int main() {
    int n, m;
    int x, y;

    while (cin >> n >> m){
        if (n == 0) {
            break;
        }
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            g[x - 1].push_back(y - 1);
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << result.back() + 1 << " ";
            result.pop_back();
        }
        result.clear();
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        cout << endl;
    }
    return 0;
}