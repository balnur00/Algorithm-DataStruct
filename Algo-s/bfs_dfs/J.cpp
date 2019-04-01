#include <bits/stdc++.h>

using namespace std; 

const int maxn = 505;
int fa[maxn];

struct outpost
{
    double x,y;
}a[maxn];

struct node
{
    int u,v;
    double w;
}edge[maxn*maxn];

bool cmp(node a,node b)
{
    return a.w<b.w;
}

int find(int x)
{
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int s,p;
        scanf("%d%d",&s,&p);
        for(int i=0;i<p;i++) 
        {
            fa[i]=i;
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }
        int tot=0;
        for(int i=0;i<p-1;i++)
            for(int j=i+1;j<p;j++)
            {
                double dx=a[i].x-a[j].x,dy=a[i].y-a[j].y;
                double w=sqrt(dx*dx+dy*dy);
                edge[tot++]=(node){i,j,w};
            }
        sort(edge,edge+tot,cmp);
        int cnt=0;
        double ans;
        for(int i=0;i<tot;i++)
        {
            int fu=find(edge[i].u),fv=find(edge[i].v);
            if(fu!=fv)
            {
                fa[fu]=fv;
                cnt++;
            }
            if(cnt==p-s)
            {
                ans=edge[i].w;
                break;
            }
        }
        printf("%.2f\n",ans);
    }
}