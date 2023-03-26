#include <bits/stdc++.h>
using namespace std;
// In ra tan suat xuat hien, neu co cung tan suat thi so nao xuat hien truoc thi in ra truoc
// Cach 1:
bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
        if(a.second.first != b.second.first)
                return a.second.first > b.second.first;
        return a.second.second < b.second.second;
}
int main()
{
        int n;
        cin >> n;
        int a[n];
        map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
                // Neu a[i] chua xuat hien
                if(mp.find(a[i])==mp.end())
                {
                        mp[a[i]] = {1,i};
                }
                else
                {
                        mp[a[i]].first++;
                }
        }
        vector<pair<int,pair<int,int>>> v;
        for(auto it:mp)
        {
                v.push_back(it);
        }
        sort(v.begin(),v.end(),cmp);
        for(auto it:v)
        {
                for(int j=0;j<it.second.first;j++)
                {
                        cout << it.first << " ";
                }
        }
        return 0;
}

// *************************************************************************************************************************

// Cach 2:

//map<int,int> ma;
//bool cmp(int a,int b)
//{
//        if(ma[a]!= ma[b])
//                return ma[a]>ma[b];
//        return a<b;
//}
//
//{
//        int n;
//        cin >> n;
//        int a[n];
//        for(int i=0;i<n;i++)
//        {
//                cin >> a[i];
//        }
//        for(int i=0;i<n;i++)
//        {
//                ma[a[i]]++;
//        }
//        stable_sort(a,a+n,cmp);
//        for(int x:a)
//        {
//                cout << x << " ";
//        }
//        return 0;
//}
//
//
