#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
bool ok = true;
vector<int> g[200];
int used[200];

void dfs(int v, int color) {
    used[v] = color;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i], 3 - color);
        } else if (used[g[v][i]] == color) {
            ok = false;
        }
    }   
}

int main() {
    while (cin >> n){
        if (n == 0) break;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(0, 1);
        if (ok) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        
        memset(used, 0, sizeof(used));
        ok = true;
    }
    return 0;
}