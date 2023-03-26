#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
	stack<string> st;
	for(int i=0;i<s.size();i++)
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
			string res = "(" + op2 + s[i] + op1 + ")";
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

