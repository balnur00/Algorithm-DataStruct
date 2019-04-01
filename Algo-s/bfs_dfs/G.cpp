#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int> > q;
vector<pair<int, int> > result;
vector<int> g[100];
bool used[100];

void bfs(int v) {
    q.push(make_pair(v, 0));
    used[v] = true;
    while (!q.empty()) {
        for (int i = 0; i < g[v].size(); i++) {
            if (!used[g[v][i]]) {
                q.push(make_pair(g[v][i], q.front().second + 1));
                used[g[v][i]] = true;
            }
        }
        result.push_back(q.front());
        q.pop();
        v = q.front().first;
    }
}

int main() {
    int n, x, m, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> m;
        for (int j = 0; j < m; j++) {
            cin >> y;
            g[x - 1].push_back(y - 1);
        }
    }

    bfs(0);
    sort(result.begin(), result.end());
    reverse(result.begin(), result.end());
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            cout << result.back().first + 1 << " " << result.back().second << endl;
            result.pop_back();
        }
        else
            cout << i + 1 << " " <<  -1 << endl;
    }
    return 0;
}