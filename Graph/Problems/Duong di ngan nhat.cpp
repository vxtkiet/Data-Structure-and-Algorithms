#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[505][505];
int d[505][505];
pair<int,int> path[]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void bfs(int i,int j)
{
        queue<pair<int,int>> q;
        q.push({i,j});
        a[i][j]=0;
        d[i][j]=0;
        while(!q.empty())
        {
                pair<int,int> top=q.front();
                q.pop();
                for(int k=0;k<8;k++)
                {
                        int i1 = top.first + path[k].first;
                        int j1 = top.second + path[k].second;
                        if(i1>=0 && i1<n && j1>=0 && j1<m && a[i1][j1])
                        {
                                d[i1][j1] = d[top.first][top.second]+1;
                                q.push({i1,j1});
                                a[i1][j1]=0;
                        }
                }
        }
}
void inp()
{
        int s1,s2,t1,t2;
        cin >> n >> m >> s1 >> s2 >> t1 >> t2;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<m;j++)
                {
                        cin >> a[i][j];
                }
        }
        bfs(s1,s2);
        cout << d[t1][t2] << endl;
}
int main()
{
        inp();
        return 0;
}
