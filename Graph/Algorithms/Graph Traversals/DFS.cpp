// Input: Danh sach canh
#include <bits/stdc++.h>
using namespace std;
int n,m; // n: dinh, m: canh
bool used[1001]; // Danh dau xem 1 dinh nao do da duoc tham hay chua
vector<int> adj[1001]; // Danh sach ke
int a[1001][1001];

//void inp_matranke()
//{
//        for(int i=1;i<=n;i++)
//        {
//                for(int j=1;j<=n;j++)
//                {
//                        cin >> a[i][j];
//        }
//}

//void dfs_matranke(int u)
//{
//        cout << u << " ";
//        for(int i=1;i<=n;i++)
//        {
//                if(a[u][i]==1)
//                {
//                        a[u][i]=a[i][u]=0;
//                        dfs(i);
//                }
//        }
//}

void dfs_danhsachke(int u)
{
        cout << u << " ";
        used[u] = true;
        for(int v:adj[u])
        {
                if(used[v]==false)
                {
                        dfs_danhsachke(v);
                }
        }
}
int main()
{
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
                // Chuyen danh sach canh ve danh sach ke
                int x,y;
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        memset(used,false,sizeof(used));
        dfs_danhsachke(1);
        return 0;
}

