// Di qua moi canh 1 lan
// Do thi vo huong:
// Co chu trinh Euler: Tat ca cac dinh deu co bac chan

// Buoc 1: Tao 1 stack, day dinh bat dau vao stack
// Buoc 2: Lap khi stack con chua rong
        // 1, Lay phan tu o dinh stack: u
        // 2, Neu ma u khong con dinh ke: xoa u khoi stack, day u vao chu trinh
        // 3, Neu ma u con dinh ke: Day dinh ke dau tien cua u vao stack (v), xoa canh (u,v) khoi do thi

#include <bits/stdc++.h>
using namespace std;

set<int> adj[1001];
int a[1001][1001]; // Su dung ma tran ke
int degree[1001]={0};
int n,m;

void inp_set()
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

void inp_matranke()
{
        cin >> n >> m;
        for(int i=1;i<=m;i++)
        {
                int x,y; cin >> x >> y;
                a[x][y]=a[y][x]=1;
                degree[x]++;
                degree[y]++;
        }
}

void Euler_Cycle_matranke(int u)
{
        // Kiem tra do thi co chu trinh Euler hay khong
        for(int i=1;i<=n;i++)
        {
                if(degree[i]%2==1)
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
                int ok=1;
                for(int i=1;i<=n;i++)
                {
                        if(a[u][i]==1)
                        {
                                st.push(i); // Day dinh ke cua dinh u vao dau ngan xep
                                a[u][i]=a[i][u]=0; // Xoa canh (u,i) khoi do thi
                                ok=0;
                                break;
                        }
                }
                if(ok) // Dinh u khong con dinh ke
                {
                        st.pop(); // Xoa dinh u khoi ngan xep
                        cycle.push_back(u); // Day dinh u vao chu trinh
                }
        }
        for(auto x:cycle)
        {
                cout << x << " ";
        }
}

void Euler_Cycle_set(int u)
{
        // Kiem tra do thi co chu trinh Euler hay khong
        for(int i=1;i<=n;i++)
        {
                if(degree[i]%2==1)
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
        for(auto x:cycle)
        {
                cout << x << " ";
        }
}

int main()
{
//        inp_matranke();
//        Euler_Cycle_matranke(6);
        inp_set();
        Euler_Cycle_set(6);
        return 0;
}
