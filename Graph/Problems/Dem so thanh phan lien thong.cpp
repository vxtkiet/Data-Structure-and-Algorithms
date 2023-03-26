#include <bits/stdc++.h>
using namespace std;
int n,m;
bool used[1001];
vector<int> adj[1001];
int tplt[1001];
int cnt=0;

void dfs(int u)
{
        tplt[u]=cnt;
        used[u] = true;
        for(int x:adj[u])
        {
                if(used[x] == false)
                {
                        dfs(x);
                }
        }
}
void bfs(int u)
{
        queue<int> q;
        q.push(u);
        used[u] = true;
        // cout << u << " ";
        while(!q.empty())
        {
                int s = q.front();
                q.pop();
                cout << s << " ";
                for(int x:adj[s])
                {
                        if(used[x] == false)
                        {
                                q.push(x);
                                used[x] = true;
                                // cout << x << " ";                        }
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
        memset(used,false,sizeof(used));
        int cnt1=0;
        for(int i=1;i<=n;i++)
        {
                if(used[i]==false)
                {
                        dfs(i);
                        ++cnt1;
                }
        }
        cout << cnt1 << endl;
}
void inp2()
{
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        memset(used,false,sizeof(used));
        for(int i=1;i<=n;i++)
        {
                if(used[i]==false)
                {
                        ++cnt;
                        dfs(i);
                }
        }
        for(int i=1;i<=n;i++)
        {
                cout << tplt[i] << " "; // Thanh phan lien thong cua tung dinh
        }
}
int main()
{
        int t; cin >> t;
        while(t--)
        {
                inp();
                for(int i=1;i<=1001;i++)
                {
                        adj[i].clear();
                }
                cout << endl;
        }
        return 0;
}

