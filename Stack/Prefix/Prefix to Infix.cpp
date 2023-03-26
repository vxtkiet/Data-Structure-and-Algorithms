#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
        stack<string> st;
        for(int i=s.size()-1;i>=0;i--)
        {
                if(isalpha(s[i])) // Day ki tu vao stack
                {
                        st.push(string(1,s[i])); // string(1,'A') => 'A'
                }
                else
                {
                        // Lay ra 2 phan tu o dinh stack
                        string op1 = st.top();
                        st.pop();
                        string op2 = st.top();
                        st.pop();
                        string res = "(" + op1 + s[i] + op2 + ")";
                        st.push(res);
                }
        }
        cout << st.top() << endl;
}

int main()
{
        int t; cin >> t;
        while(t--)
        {
                string s; cin >> s;
                solve(s);
        }
        return 0;
}


