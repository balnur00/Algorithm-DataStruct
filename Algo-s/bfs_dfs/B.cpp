#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Node {
    public:
    int x, y;
    Node(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
};

queue<Node*> que;
int d[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
string dep[100];
int n, m;

void dfs(int i, int j) {
    Node *fir = new Node(j, i);
    que.push(fir);
    while (!que.empty()) {
        fir = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            Node* tmp = new Node(fir -> x + d[i][0], fir -> y + d[i][1]);
            if (tmp -> x < 0 || tmp -> y < 0 || tmp -> x >= m || tmp -> y >= n) {
                continue;
            }
            if (dep[tmp -> y][tmp -> x] == '@') {
                que.push(tmp);
                dep[tmp -> y][tmp -> x] = '*';
            }
        }
    }
    return;
}

int counter = 0;

int main() {
    while(cin >> n >> m) {
        if (n == 0) break;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            cin >> dep[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dep[i][j] == '@') {
                    counter++;
                    dfs(i, j);
                }
            }
        }
        cout << counter << endl;
    }
    return 0;
}