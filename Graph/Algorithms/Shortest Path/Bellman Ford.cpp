// Bellman Ford: Tim duoc duong di ngan nhat cho do thi co huong co trong so am
// Khong ap dung cho do thi co chu trinh am
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1001];
int n,m;

void inp()
{
        cin >> n >> m;
        for(int i=1;i<=m;i++)
        {
                int x,y,w; cin >> x >> y >> w;
                adj[x].push_back({y,w});
        }
}

void Bellman_Ford(int u)
{
        vector<int> d(n+1,1e9); // Tao vector khoang canh d co n+1 phan tu va moi phan tu co gia tri la 1e9
        d[u]=0;
        // Lap n-2
        for(int i=1;i<=n-2;i++)
        {
                // Xet tat ca cac cap canh cua do thi va cap nhat
                for(int u=1;u<=n;u++)
                {
                        // Doi voi dinh u, xet cac dinh v ke voi dinh u
                        for(auto it:adj[u])
                        {
                                int v=it.first, c=it.second;
                                d[v]=min(d[v],d[u]+c);
                        }
                }
        }
        for(int i=1;i<=n;i++)
        {
                cout << d[i] << " ";
        }
}

int main()
{
        inp();
        Bellman_Ford(1);
        return 0;
}

