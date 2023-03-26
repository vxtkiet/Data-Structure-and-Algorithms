// Di qua moi canh 1 lan
// Do thi co huong:
// Co chu trinh Euler: Tat ca cac dinh cua do thi co ban bac ra = bac bac vao

// Buoc 1: Tao 1 stack, day dinh bat dau vao stack
// Buoc 2: Lap khi stack con chua rong
        // 1, Lay phan tu o dinh stack: u
        // 2, Neu ma u khong con dinh ke: xoa u khoi stack, day u vao chu trinh
        // 3, Neu ma u con dinh ke: Day dinh ke dau tien cua u vao stack (v), xoa canh (u,v) khoi do thi

#include <bits/stdc++.h>
using namespace std;

set<int> adj[1001];
int in[1001]={0}; // Ban bac vao
int out[1001]={0}; // Ban bac ra
int n,m;

void inp()
{
        cin >> n >> m;
        for(int i=1;i<=m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].insert(y);
                in[y]++;
                out[x]++;
        }
}

void Euler_Cycle(int u)
{
        // Kiem tra do thi co chu trinh Euler hay khong
        for(int i=1;i<=n;i++)
        {
                if(in[i]!=out[i])
                {
                        cout << "Khong ton tai chu trinh Euler";
                        return;
                }
        }
        // Buoc 1: Tao stack
        stack<int> st;
        st.push(u); // Day u vao trong stack
        vector<int> cycle; // Tao chu trinh
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
                        cycle.push_back(u); // Day dinh u vao chu trinh

                }
        }
        reverse(cycle.begin(),cycle.end());
        for(auto x:cycle)
        {
                cout << x << " ";
        }
}
int main()
{
        inp();
        Euler_Cycle(1);
        return 0;
}
