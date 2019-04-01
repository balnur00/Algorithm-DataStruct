#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int,int> > > g;
int r[110];
int p[110];

int getPrevious(int v)
{
 if (p[v] == v) return v;
 return p[v] = getPrevious(p[v]);
}

void merge(int x, int y)
{
 x = getPrevious(x);
 y = getPrevious(y);

 if (x == y) return;

 else if (r[x] < r[y]) p[x] = y;
 else if (r[x] > r[y]) p[y] = x;
 else
 {
  p[x] = y;
  r[y]++;
 }
}

int main()
{
 int n;

 while (cin >> n)
 {
  g.clear();

  for (int i = 0; i < 110; i++)
  {
   p[i] = 0;
   r[i] = 0;
  }

  int cost;
  int m = 0;
  for (int i = 1; i <= n; i++)
  {
   for (int j = 1; j <= n; j++)
   { 
    cin >> cost;
    if (j > i)
    {
     g.push_back(make_pair(cost, make_pair(i, j))); 
     m++;
    }  
   }
  }

  int mn = 0;
  sort(g.begin(), g.end());

  for (int i = 1; i <= n; i++)
   p[i] = i;

  for (int i = 0; i < m; i++)
  {
   cost = g[i].first;
   int x = g[i].second.first;
   int y = g[i].second.second;

   x = getPrevious(x);
   y = getPrevious(y);

   if (x != y)
   {
    mn += cost;
    merge(x, y);
   }
  }

  cout << mn << endl;

 }
 return 0;
}