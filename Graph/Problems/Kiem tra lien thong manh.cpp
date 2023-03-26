#include <bits/stdc++.h>
using namespace std;
int n,m;
bool used[1001];
vector<int> adj[1001];

void dfs(int u)
{
        used[u]=true;
        for(auto v:adj[u])
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
        for(int i=1;i<=m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
        }
        for(int i=1;i<=n;i++)
        {
                memset(used,false,sizeof(used));
                dfs(i);
                for(int j=1;j<=n;j++)
                {
                        if(used[j]==false)
                        {
                                cout << "NO" << endl;;
                                return;
                        }
                }
        }
        cout << "YES" << endl;
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
