#include <bits/stdc++.h>
using namespace std;
int n,m; // n: dinh, m: canh
bool used[1001]; // Danh dau xem 1 dinh nao do da duoc tham hay chua
vector<int> adj[1001]; // Danh sach ke

void bfs_matranke(int u)
{
        queue<int> q;
        q.push(u);
        used[u] = true;
        while(!q.empty())
        {
                int s = q.front();
                q.pop();
                cout << s << " ";
                for(int i=1;i<=n;i++)
                {
                        if(a[s][i]==false && used[i]==false)
                        {
                                q.push(i);
                                used[i] = true;
                        }
                }
        }
}
void bfs_danhsachke(int u)
{
        // Khoi tao hang doi
        queue<int> q;
        // Day dinh dau tien vao hang doi
        q.push(u);
        // Danh dau dinh da duoc tham
        used[u] = true;
        while(!q.empty())
        {
                // Lay ra dinh o dau hang doi
                int s = q.front();
                // Xoa phan tu do dau hang doi
                q.pop();
                // Tham dinh s
                cout << s << " ";
                // Duyet cac dinh ke cua s
                for(int x:adj[s])
                {
                        // Kiem tra xem dinh nao chua duoc tham
                        if(used[x] == false)
                        {
                                // Day x vao hang doi
                                q.push(x);
                                // Danh dau dinh da duoc tham
                                used[x] = true;
                        }
                }
        }
}
int main()
{
        cin >> n >> m;
        while(m--)
        {
                int x,y;
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        memset(used,false,sizeof(used));
        bfs_danhsachke(1);
        return 0;
}
