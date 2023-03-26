#include <bits/stdc++.h>
using namespace std;

int pre(char c)
{
        if(c=='(') return 0;
        else if(c=='+' || c=='-') return 1;
        else if(c=='*' || c=='/') return 2;
        else if(c=='^') return 3;
}

long long calculate(long long a, long long b, char c)
{
        if(c=='+') return a+b;
        else if(c=='-') return a-b;
        else if(c=='*') return a*b;
        else if(c=='/') return a/b;
}

void solve(string s)
{
        stack<char> st1;
        stack<long long> st2;
        for(int i=0;i<s.size();i++)
        {
                if(s[i]=='(')
                {
                        st1.push(s[i]);
                }
                else if(isdigit(s[i]))
                {
                        long long tmp=0;
                        while(i<s.size() && isdigit(s[i]))
                        {
                                tmp=tmp*10+s[i]-'0';
                                ++i;
                        }
                        st2.push(tmp);
                        --i;
                }
                else if(s[i]==')')
                {
                        while(!st1.empty() && st1.top()!='(')
                        {
                                long long o1=st2.top();
                                st2.pop();
                                long long o2=st2.top();
                                st2.pop();
                                st2.push(calculate(o2,o1,st1.top()));
                                st1.pop();
                        }
                        st1.pop();
                }
                else
                {
                        while(!st1.empty() && pre(st1.top())>= pre(s[i]))
                        {
                                long long o1=st2.top();
                                st2.pop();
                                long long o2=st2.top();
                                st2.pop();
                                st2.push(calculate(o2,o1,st1.top()));
                                st1.pop();
                        }
                        st1.push(s[i]);
                }
        }
        while(!st1.empty())
        {
                long long o1=st2.top();
                st2.pop();
                long long o2=st2.top();
                st2.pop();
                st2.push(calculate(o2,o1,st1.top()));
                st1.pop();
        }
        cout << st2.top() << endl;
}
int main()
{

        string s; cin >> s;
        solve(s);
        return 0;
}


