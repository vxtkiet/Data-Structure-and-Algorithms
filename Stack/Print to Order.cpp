#include <bits/stdc++.h>
using namespace std;
int main()
{
        int t; cin >> t;
        vector<int> v;
        while(t--)
        {
                string s; cin >> s;
                if(s=="push")
                {
                        int x; cin >> x;
                        v.push_back(x);
                }
                else if(s=="pop")
                {
                        v.pop_back();
                }
                else
                {
                        for(int x:v)
                        {
                                cout << x << " ";
                        }
                        cout << endl;
                }
        }
        return 0;
}
//Input:
//8
//push 3
//push 5
//show
//push 7
//show
//pop
//pop
//show

