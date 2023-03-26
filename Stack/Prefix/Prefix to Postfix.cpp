#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
	stack<string> st;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(isalpha(s[i]))
		{
			st.push(string(1,s[i]));
		}
		else
		{
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();
			string res = op1 + op2 + s[i];
			st.push(res);
		}
	}
	cout << st.top() << endl;
}
int main()
{
    string s; cin >> s;
    solve(s);
    return 0;
}

