#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF (int)1e9
#define ll long long
using namespace std;
ll g[150][150];
int n, m;
vector<pair<int, int> > edges;
int foundMST(int x, int y, int w)
{

  bool isFirst = true;
  if(x != -1 && y != -1){
    g[x][y] = INF;
    g[y][x] = INF;
    isFirst = false;
  }

  int mstLen=0;

  vector<char> was(n, false);
  vector<int> edg(n, INF);
  vector<int> ans(n, -1);
  vector<ll> mst;

  edg[0]=0;
  for(int i=0; i<n; i++){
    int v = -1;
    for(int j=0; j<n; j++){
      if(!was[j] && (v == -1 || edg[j] < edg[v])) v=j;
    }


    if(edg[v] == INF) {
      return -1;
    }


    was[v]=true;
    if(ans[v] != -1){
      mstLen += g[v][ans[v]];

      if(isFirst)
      {
        edges.push_back(make_pair(v, ans[v]));
      }
    }

    for(int to=0; to<n; to++){
      if(g[v][to] < edg[to]){
        edg[to] = g[v][to];
        ans[to] = v;
      }
    }
  }

  if(x != -1 && y != -1){
    g[x][y] = w;
    g[y][x] = w;
  }

  return mstLen;
}

void solve(){
  int x, y, w, len;
  edges.clear();
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      g[i][j] = INF;
    }
  }
  for(int i=0; i<m; i++){
    cin>>x>>y>>w;
    g[x-1][y-1] = w;
    g[y-1][x-1] = w;
  }

  len = foundMST(-1, -1, 0);

  for(int i=0; i<edges.size(); i++){
    x = edges[i].first;
    y = edges[i].second;

    int temp = foundMST(x, y, g[x][y]);

    if(temp != -1 && temp == len)
    {
      cout << "Not Unique!";
      return;
    }
  }
  cout << len;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
    cout << "\n";
  }

}