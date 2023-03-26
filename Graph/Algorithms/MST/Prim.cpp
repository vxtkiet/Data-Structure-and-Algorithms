#include <bits/stdc++.h>
using namespace std;

int n,m;
bool used[1001];
vector<pair<int,int>> adj[1001];
int parent[1001];


void inp()
{
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
                int x,y,w; cin >> x >> y >> w;
                adj[x].push_back({w,y});
                adj[y].push_back({w,x});
        }
        memset(used,false,sizeof(used));
}

void prim(int x)
{
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
        vector<int> mst;
        int mst_cost = 0; // Tong trong so cua cay
        Q.push({0,x});
        while(!Q.empty())
        {
                pair<int,int> p=Q.top();//chon canh co trong so nho nhat trong heap
		Q.pop();
		int v = p.second;
		if(used[v])
		{
			continue;
		}
		mst_cost += p.first;
		used[v] = true;
		mst.push_back(v);
		for(int i=0;i<adj[v].size();i++)
                {
			int tmp= adj[v][i].second;
			if(!used[tmp]){
				Q.push({adj[v][i].first, tmp});
				parent[tmp] = v;
			}
		}
	}
	cout << mst_cost << endl;
}
int main()
{
        int t; cin >> t;
        while(t--)
        {
                for(int i=0;i<1001;i++)
                {
                        adj[i].clear();
                }
                inp();
                prim(1);
        }
        return 0;
}
//2
//3 3
//1 2 5
//2 3 3
//1 3 1
//2 1
//1 2 5

