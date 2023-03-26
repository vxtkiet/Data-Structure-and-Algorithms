#include <bits/stdc++.h>
using namespace std;
int n,m;
bool used[1001];
vector<int> adj[1001];

void dfs(int u)
{
        used[u]=true;
        for(int v:adj[u])
        {
                if(used[v]==false)
                {
                        dfs(v);
                }
        }
}
void inp()
{
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        int cnt=0;
        memset(used,false,sizeof(used));
        for(int i=1;i<=n;i++)
        {
                if(used[i]==false)
                {
                        dfs(i);
                        ++cnt;
                }
        }
        for(int i=1;i<=n;i++)
        {
                 memset(used,false,sizeof(used));
                 used[i]=true;
                 int dem=0;
                 for(int j=1;j<=n;j++)
                 {
                         if(used[j]==false)
                         {
                                 dfs(j);
                                 ++dem;
                         }
                 }
                 if(dem > cnt) // Kiem tra do thi co tang thanh phan lien thong hay khong
                        cout << i << " ";
        }
}
int main()
{
        inp();
        return 0;
}
