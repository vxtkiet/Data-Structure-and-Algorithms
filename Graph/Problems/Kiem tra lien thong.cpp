// Cho do thi vo huong
#include <bits/stdc++.h>
using namespace std;
int n,m;
bool used[1001];
vector<int> adj[1001];

void dfs(int u)
{
        used[u] = true;
        for(int x:adj[u])
        {
                if(used[x] == false)
                {
                        dfs(x);
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
        dfs(1);
        bool ok=true;
        for(int i=0;i<=n;i++)
        {
                if(used[i]==false)
                {
                        ok=false;
                        break;
                }
        }
        if(ok)  cout << "Yes" << endl;
        else    cout << "No" << endl;
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
