// In tan suat xuat hien, neu tan suat bang nhau thi so sanh neu so nao nho hon thi in truoc
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b)
{
        if(a.second != b.second)
        {
                return a.second > b.second;
        }
        return a.first < b.first;
}
int main()
{
        int n;
        cin >> n;
        int a[n];
        map<int,int> ma;
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
        for(int i=0;i<n;i++)
        {
                ma[a[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto it:ma)
        {
                v.push_back(it);
        }
        sort(v.begin(),v.end(),cmp);
        for(auto it:v)
        {
                for(int j=0;j<it.second;j++)
                {
                        cout << it.first << " ";
                }
        }
        return 0;
}


