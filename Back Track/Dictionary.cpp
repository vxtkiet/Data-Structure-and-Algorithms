#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

char c[101][101];
int n, m, k;
set<string> dic;
bool used[101][101];
vector<string> res;

void ql(int i, int j, string s)
{
	cout << i << " " << j << " " << s << endl;
	if(dic.find(s) != dic.end()){
		res.push_back(s);
	}
	for(int k = 0; k < 8; k++){
		int i1 = i + dx[k], j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !used[i1][j1]){
			used[i1][j1] = true;
			ql(i1, j1, s + c[i1][j1]);
			used[i1][j1] = false;
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--){
		cin >> k >> n >> m;
		for(int i = 0; i < k ; i++){
			string x; cin >> x;
			dic.insert(x);
		}
		for(int i =1 ; i <= n; i++){
			for(int j =1; j <= n; j++){
				cin >> c[i][j];
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				memset(used, false, sizeof(used));
				used[i][j] = true;
				string tmp = "";
				ql(i,j,tmp + c[i][j]);
			}
		}
		for(string x : res){
			cout << x << " ";
		}
		res.clear();
		dic.clear();
	}
	return 0;
}


