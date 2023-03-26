// Floyd: Tim duong di ngan nhat giua 2 dinh
#include <bits/stdc++.h>
using namespace std;
int d[101][101];
int n,m;

void inp()
{
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++)
                {
                        if(i==j) d[i][j]=0;
                        else d[i][j]=1e9;
                }
        }
        for(int i=0;i<m;i++)
        {
                int x,y,w; cin >> x >> y >> w;
                d[x][y]=d[y][x]=w;
        }
}

void Floyd()
{
        for(int k=1;k<=n;k++)
        {
                for(int i=1;i<=n;i++)
                {
                        for(int j=1;j<=n;j++)
                        {
                                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                        }
                }
        }
}
int main()
{
        inp();
        Floyd();
        int q; // So luong truy van
        cin >> q;
        while(q--)
        {
                int x,y; cin >> x >> y; // Nhap 2 dinh can tinh duong di ngan nhat
                cout << d[x][y] << endl;
        }
        return 0;
}

