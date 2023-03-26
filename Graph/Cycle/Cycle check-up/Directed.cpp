// To mau do thi
// Su dung Kahn de duyet Topo
#include <bits/stdc++.h>
using namespace std;

int n,m;
bool used[1001];
vector<int> adj[1001];
int color[1001];
int degree[1001];

void inp()
{
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
        }
        memset(color,0,sizeof(color));
}

bool dfs(int u)
{
        // Bat dau tham dinh u
        color[u]=1;
        for(int v:adj[u])
        {
                if(color[v]==0)
                {
                        if(dfs(v))
                        {
                                return true;
                        }
                }
                else if(color[v]==1)
                {
                        return true;
                }
        }
        // Duyet xong => mau den
        color[u]=2;
        return false;
}

bool Kahn()     // Su dung Kahn duyet topo
{
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
                if(degree[i]==0)
                {
                        q.push(i);
                }
        }
        int cnt=0;
        while(!q.empty())
        {
                int v=q.front();
                q.pop();
                ++cnt;
                for(int x:adj[v])
                {
                        degree[x]--;
                        if(degree[x]==0)
                        {
                                q.push(x);
                        }
                }
        }
        if(cnt==n)
                return false;
        else
                return true;
}

int main()
{
        inp();
        bool ok=false;
        for(int i=1;i<=n;i++)
        {
                if(color[i]==0)
                {
                        if(dfs(i))
                        {
                                ok = true;
                                break;
                        }
                }
        }
        if(ok)
                cout << "YES";
        else
                cout << "NO";
//        if(Kahn())
//                cout << "YES";
//        else
//                cout << "NO";
}


