// Tim chieu cao cua dinh
// Tim so node cua cac dinh
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool used[1001];
int depth[1001];
int size[1001];

int dfs(int u, int parent)
{
        // Khi bat dau tham dinh u thi ta cho co cua cay la u=1: chinh no
        size[u]=1;
        depth[u]=depth[parent]+1;
        used[u] = true;
        for(int v:adj[u])
        {
                if(used[v]==false)
                {
                        size[u]+=dfs(v,u); // Cong co cua cay co goc la v la co cua cay co goc u
                }
        }
        // Sau khi dinh u duyet xong cac dinh con cua no
        return size[u];
}
void inp()
{
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
                int x,y;
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        memset(used,false,sizeof(used));
        dfs(1,0);
        for(int i=1;i<=n;i++)
        {
                cout << "So node cua " << i << " la: " << size[i] << endl;
        }
        cout << endl;
        for(int i=1;i<=n;i++)
        {

                cout << "Chieu cao cua dinh " << i << " la: " << depth[i] << endl;
        }
}

int main()
{
        inp();
        return 0;
}
//11
//1 2
//1 3
//1 4
//2 5
//2 6
//6 11
//3 7
//4 8
//4 9
//4 10


