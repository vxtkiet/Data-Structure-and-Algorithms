#include <bits/stdc++.h>
using namespace std;
int n,m,u,v;
bool used[1001];
vector<int> adj[1001];
int parent[1001];

void dfs(int u)
{
        used[u]=true;
        for(auto v:adj[u])
        {
                if(used[v]==false)
                {
                        parent[v]=u;
                        dfs(v);
                }
        }
}
void inp()
{
        cin >> n >> m >> u >> v;
        for(int i=1;i<=m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        memset(used,false,sizeof(used));
        dfs(u);
        if(used[v]==false)
        {
                cout << "-1";
        }
        else
        {
                vector<int> path;
                while(u!=v)
                {
                        path.push_back(v);
                        v = parent[v];
                }
                path.push_back(u);
                reverse(path.begin(),path.end());
                for(int x:path)
                {
                        cout << x << " ";
                }
        }
}
int main()
{
        int t; cin >> t;
        while(t--)
        {
                inp();
                for(int i=1;i<=1000;i++)
                {
                        adj[i].clear();
                }
                cout << endl;
        }
        return 0;
}

