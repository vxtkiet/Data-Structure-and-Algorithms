#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[1001];
bool used[1001];
int h[1001]={0}; // Luu chieu cao cua node
int c[1001]; // Luu so node cau cay khung
int parent[1001]={0};

void inp()
{
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
}

int dfs(int u)
{
        h[u]=h[parent[u]]+1;
        c[u]=1;
        used[u]=true;
        for(int v:adj[u])
        {
                if(used[v]==false)
                {
                        parent[v]=u;
                        c[u]+=dfs(v); // Cong so node con cua cay con goc v vao cay con goc u
                }
        }
        return c[u];
}

int main()
{
        inp();
        dfs(1);
        for(int i=1;i<=n;i++)
        {
                cout << "Dinh " << i << " co chieu cao la: " << h[i] << " va so con la: " << c[i] << endl;
        }
        return 0;
}

