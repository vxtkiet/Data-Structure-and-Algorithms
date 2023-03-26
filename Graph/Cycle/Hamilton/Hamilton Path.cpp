// Chu trinh va duong di Hamilton: Di qua moi dinh 1 lan
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
vector<int> cycle;
int X[100];
bool used[1001];
int n,m,s; // s la dinh bat dau

void inp()
{
        cin >> n >> m;
        for(int i=1;i<=m;i++)
        {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        memset(used,false,sizeof(used));
}

void Hamilton_Path(int k)
{
        // Duyet danh sach ke cua dinh thu k-1
        for(int x:adj[X[k-1]])
        {
                if(k==n+1)
                {
                        for(int i=1;i<k;i++)
                        {
                                cout << X[i] << " ";
                        }
                        cout << endl;
                        return;
                }
                else if(!used[x])
                {
                         used[x]=true;
                         X[k]=x;
                         Hamilton_Path(k+1);
                         used[x]=false;
                }
        }
}

int main()
{
        inp();
        X[1]=s;
        used[s]=true;
        Hamilton_Path(2);
}

