#include <bits/stdc++.h>
using namespace std;
struct edge
{
        int d; // Dinh dau
        int c; // Dinh cuoi
        int w; // Trong so
};

int n,m;
int parent[1001];
int size[1001];
vector<edge> canh; // Danh sach canh

int Find(int u)
{
        if(u==parent[u])
        {
                return u;
        }
        return parent[u]=Find(parent[u]);
}

bool Union(int x,int y)
{
        x = Find(x);
        y = Find(y);
        if(x==y)
        {
                return false;
        }
        if(x!=y)
        {
                if(size[x]>=size[y])
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

bool cmp(edge a,edge b) // Sap xep trong cua cac canh so tu nho den lon
{
        return a.w < b.w;
}

void kruskal()
{
        vector<edge> mst; // Cay khung nho nhat: minimum spanning tree
        int d=0; // Tong trong so cua cay khung
        sort(canh.begin(),canh.end(),cmp);
        for(int i=0;i<m;i++)
        {
                if(mst.size()==n-1)
                {
                        break;
                }
                int u = canh[i].d;
                int v = canh[i].c;
                if(Union(u,v)==true)
                {
                        mst.push_back(canh[i]);
                        d+=canh[i].w;
                }
        }
        if(mst.size()!=n-1)
        {
                cout << "Khong lien thong !\n";
        }
        else
        {
                cout << d << endl;
        }
}

void inp()
{
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
                int x,y,w;
                cin >> x >> y >> w;
                edge tmp{x,y,w};
                canh.push_back(tmp);
        }
        for(int i=1;i<=n;i++)
        {
                parent[i]=i;
                size[i]=1;
        }
}
int main()
{
        int t; cin >> t;
        while(t--)
        {
                canh.clear();
                inp();
                kruskal();
        }
        return 0;
}

