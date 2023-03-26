// Map luu cac pair
#include <bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin >> n;
        map<int,int> ma;
        for(int i=0;i<n;i++)
        {
                int x;
                cin >> x;
                ma[x]++;
        }
        for(pair<int,int> x: ma)
        {
                cout << x.first << " " << ma[x.first] << endl; // ma[key] = value
        }
        cout << ma.size() << endl; // Dem so luong phan tu khac nhau trong mang
        return 0;
}

