#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
vector<int> topo;
int degree[1001]={0};

void kahn()
{
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
                if(degree[i]==0)
                {
                        q.push(i);
                }
        }
        while(!q.empty())
        {
                int v=q.front();
                q.pop();
                topo.push_back(v);
                for(int x:adj[v])
                {
                        degree[x]--;
                        if(degree[x]==0)
                        {
                                q.push(x);
                        }
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
                degree[y]++;
        }
}
int main()
{
        inp();
        kahn();
        for(int x:topo)
        {
                cout << x<< " ";
        }
        return 0;
}
