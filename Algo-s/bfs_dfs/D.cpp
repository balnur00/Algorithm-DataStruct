#include <bits/stdc++.h>

using namespace std;

vector<int> g[100100];
int used[100100];
bool usedi[100100];
int pers[100100];

void dfs(int v) {
    usedi[v] = true;
    used[v]++;
    
    for (int i = 0; i < g[v].size(); i++) {
        if (!usedi[g[v][i]])
            dfs(g[v][i]);
    }  
}

int main() {
    int cnt = 0;
    int num_case = 1;
    int k, n, m;
    int x, y;
    int t;
    cin >> t;
    for (int h = 0; h < t; h++) {
        cin >> k >> n >> m;
        for (int i = 0; i < k; i++) {
            cin >> pers[i];
        }

        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            g[x - 1].push_back(y - 1);
        }
        for (int i = 0; i < k; i++) {
            memset(usedi, 0, sizeof(usedi));
            dfs(pers[i] - 1);
        }

        for (int i = 0; i < n; i++) {
            if (used[i] >= k) {
                cnt++;
            }
        }
        cout << "Case " << num_case << ": " << cnt;
        memset(used, 0, sizeof(used));
        memset(pers, 0, sizeof(pers));
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        num_case++;
        cnt = 0;
        cout << endl;
    }
    return 0;
}