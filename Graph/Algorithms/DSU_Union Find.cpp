// Kiem tra do thi co bao nhieu thanh phan lien thong
// Kiem tra do thi co chu trinh hay khong
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
int parent[1001];
int size[1001];
// size[i]: Luu so dinh thuoc thanh phan lien thong ma i la dinh dai dien
// parent[i]: Dinh dai dien cua dinh i

int Find(int u)
{
//        if(u==parent[u])
//                return u;
////        else
////                return Find(parent[u])
        while(u!=parent[u])
        {
                u = parent[u];
        }
        return u;
}

int Find_compression_path(int u) // Optimization
{
        if(u==parent[u])
                return u;
        return parent[u] = Find_compression_path(parent[u]);
}

// x=y  : false ( khong gop duoc )
// x!=y : true  ( gop duoc )
bool Union(int x,int y)
{
        x = Find_compression_path(x); // Tim cha cua x
        y = Find_compression_path(y); // Tim cha cua y
        if(x==y)
                return false;
        if(x!=y)
        {
                if(size[x]>size[y])
                {
                        parent[y]=x;
                        size[x]+=size[y];
                }
                else
                {
                        parent[x]=y;
                        size[y]+=size[x];
                }
                return true;
        }
}

void inp()
{
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
                parent[i]=i;
                size[i]=1;
        }
        for(int i=0;i<m;i++)
        {
                int x,y; cin >> x >> y;
                Union(x,y);
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
                if(i==parent[i])
                        cnt++;
        }
        cout << cnt;
}

int main()
{
        inp();
        return 0;
}

