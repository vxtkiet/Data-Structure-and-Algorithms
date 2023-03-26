#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool used[1001];
vector<int> topo;

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
        topo.push_back(u);
}

void inp()
{
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
        }
        memset(used,false,sizeof(used));
}
int main()
{
        int t; cin >> t;
        while(t--)
        {
                inp();
                for(int i=1;i<=n;i++)
                {
                        if(used[i]==false)
                        {
                                dfs(i);
                        }
                }
                reverse(topo.begin(),topo.end());
                for(int x:topo)
                {
                        cout << x << " ";
                }
        }
        return 0;
}
