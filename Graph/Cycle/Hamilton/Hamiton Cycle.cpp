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

void Hamilton_Cycle_1(int k)
{
        // Duyet danh sach ke cua dinh thu k-1
        for(int x:adj[X[k-1]])
        {
                if(k==n+1 && x==s)
                {
                        for(int i=1;i<k;i++)
                        {
                                cout << X[i] << " ";
                        }
                        cout << s << endl;
                }
                else if(!used[x])
                {
                         used[x]=true;
                         X[k]=x;
                         Hamilton_Cycle_1(k+1);
                         used[x]=false;
                }
        }
}

void Hamilton_Cycle_2(int u)
{
        for(int x:adj[u])
        {
                if(cycle.size()==n && x==s)
                {
                        for(int x:cycle)
                        {
                                cout << x << " ";
                        }
                        cout << s << endl;
                        return;
                }
                else if(!used[x])
                {
                        cycle.push_back(x);
                        used[x]=true;
                        Hamilton_Cycle_2(x);
                        cycle.pop_back(); // Xoa dinh x
                        used[x]=false;
                }
        }
}

void main_1()
{
        inp();
        X[1]=s;
        used[s]=true;
        Hamilton_Cycle_1(2);
}

void main_2()
{
        inp();
        cycle.push_back(s);
        used[s]=true;
        Hamilton_Cycle_2(s);
}

int main()
{
        cin >> s;
        main_2();
        return 0;
}


