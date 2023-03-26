#include <bits/stdc++.h>
using namespace std;

int n,m;
bool used[1001];
vector<int> adj[1001];
vector<int> topo;
int parent[1001];

bool bfs(int u)
{
        queue<int> q;
        q.push(u);
        used[u]=true;
        while(!q.empty())
        {
                int v=q.front();
                q.pop();
                for(int x:adj[v])
                {
                        if(used[x])
                        {
                                if(x!=parent[v])
                                {
                                        return true;
                                }
                        }
                        else
                        {
                                q.push(x);
                                used[x]=true;
                                parent[x]=v;
                        }
                }
        }
        return false;
}

bool dfs(int u)
{
        used[u] = true;
        for(int v:adj[u])
        {
                if(used[v])
                {
                        if(v!=parent[u])
                        {
                                return true;
                        }
                }
                else
                {
                        parent[v]=u;
                        if(dfs(v))
                        {
                                return true;
                        }
                }
        }
        return false;
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
}
int main()
{
        inp();
        if(dfs(1))
                cout << "Co chu trinh";
        else
                cout << "Khong co chu trinh";
        return 0;
}

