#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[100];

bool used[100];
vector<vector<int> > result;
int counter = 1;


void dfs(int v) {
    vector<int> tmp(3);
    used[v] = true;
    tmp[0] = v;
    tmp[1] = counter;
    counter++;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == false) {
            dfs(g[v][i]);
        }
    }
    tmp[2] = counter;
    counter++;
    result.push_back(tmp);
}

int main() {
    int n, m;
    int x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> y;
            g[x - 1].push_back(y - 1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < n; i++) {
        cout << result[i][0] + 1 << " " << result[i][1] << " " << result[i][2] << endl;
    }
    return 0;
}