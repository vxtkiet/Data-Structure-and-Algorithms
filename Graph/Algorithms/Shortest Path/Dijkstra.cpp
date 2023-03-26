// Dijkstra: Tim duong di tu 1 dinh den moi dinh con lai trong do thi
// Do thi khong co trong so am
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> adj[1001];
vector<int> d;

void dijkstra(int s)
{
        d.assign(n+1,1e9); // Khoi tao n+1 phan tu, moi phan tu co gia tri la 1e9
        d[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,s});
        while(!q.empty())
        {
                pair<int,int> top=q.top(); // Lay phan tu o dinh hang doi
                q.pop();
                int u=top.second;
                int len=top.first;
                if(len>d[u])
                {
                        continue;
                }
                for(auto it:adj[u])
                {
                        int v=it.first;
                        int w=it.second;
                        if(d[v]>d[u]+w)
                        {
                                d[v]=d[u]+w;
                                q.push({d[v],v});
                        }
                }
        }
        for(int i=1;i<=n;i++)
        {
                cout << d[i] << endl;
        }
}
void inp()
{
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
                int x,y,w; cin >> x >> y >> w;
                adj[x].push_back({y,w});
                adj[y].push_back({x,w});
        }
}
int main()
{
        inp();
        dijkstra(1);
        return 0;
}

