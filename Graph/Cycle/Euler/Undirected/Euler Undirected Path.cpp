// Di qua moi canh 1 lan
// Do thi vo huong:
// Co duong di Euler: Neu ton tai duy nhat 2 dinh co bac le, duong di Euler se bat dau va ket thuc o 2 dinh le nay

// Buoc 1: Tao 1 stack, day dinh bat dau vao stack
// Buoc 2: Lap khi stack con chua rong
        // 1, Lay phan tu o dinh stack: u
        // 2, Neu ma u khong con dinh ke: xoa u khoi stack, day u vao chu trinh
        // 3, Neu ma u con dinh ke: Day dinh ke dau tien cua u vao stack (v), xoa canh (u,v) khoi do thi

#include <bits/stdc++.h>
using namespace std;

set<int> adj[1001];
int degree[1001]={0};
int n,m;

void inp()
{
        cin >> n >> m;
        for(int i=1;i<=m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].insert(y);
                adj[y].insert(x);
                degree[x]++;
                degree[y]++;
        }
}

void Euler_path()
{
        // Kiem tra do thi co duong di Euler hay khong
        int cnt=0, u=-1, v=-1;
        for(int i=1;i<=n;i++)
        {
                if(degree[i]%2==1)
                {
                        ++cnt;
                        // Tim 2 dinh co bac le
                        if(u==-1) u=i;
                        else if(v==-1) v=i;
                }
        }
        if(cnt!=2)
        {
                cout << "Do thi khong ton tai duong di Euler";
                return;
        }
        // Buoc 1: Tao stack
        stack<int> st;
        st.push(u); // Day u vao trong stack
        vector<int> path; // Tao duong di
        // Buoc 2: Lap
        while(!st.empty())
        {
                int u=st.top(); // Kiem tra dinh o dau ngan xep
                if(adj[u].size()!=0)
                {
                        int v=*adj[u].begin(); // Phan tu dau tien trong danh sach ke cua dinh u
                        st.push(v);
                        // Xoa canh (u,v)
                        adj[u].erase(v);
                        adj[v].erase(u);
                }
                else
                {
                        st.pop(); // Xoa dinh u khoi stack
                        path.push_back(u); // Day dinh u vao duong di

                }
        }
        for(auto x:path)
        {
                cout << x << " ";
        }
}
int main()
{
        inp();
        Euler_path();
        return 0;
}

