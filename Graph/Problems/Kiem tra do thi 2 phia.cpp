#include <bits/stdc++.h>
using namespace std;

int n,m;
bool used[1001];
vector<int> adj[1001];
int color[1001];

void inp()
{
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        memset(color,0,sizeof(color));

}
bool bfs(int u)
{
        queue<int> q;
        q.push(u);
        color[u]=1;
        while(!q.empty())
        {
                int v=q.front();
                q.pop();
                for(int x:adj[v])
                {
                        if(color[x]==color[v])
                        {
                                return false;
                        }
                        else if(color[x]==0)
                        {
                                q.push(x);
                                color[x]=3-color[v];
                        }
                }
        }
        return true;
}
int main()
{
        inp();
        if(bfs(1))
                cout << "Yes\n";
        else
                cout << "No\n";
        for(int i=1;i<=n;i++)
        {
                cout << i << " " << color[i] << endl; // In ra cac mau
        }
        return 0;
}

