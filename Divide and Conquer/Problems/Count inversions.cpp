// Dem so luong cap nghich the
#include <bits/stdc++.h>
using namespace std;
// Tron 2 doan cua mang a: [1,m], [m+1,r]
int merge(int a[], int l, int m, int r)
{
        vector<int> x(a+l,a+m+1); // a[1,m]
        vector<int> y(a+m+1,a+r+1); // a[m+1,r]
        int i=0,j=0;
        int cnt=0;
        while(i<x.size() && j<y.size())
        {
                if(x[i] <= y[j])
                {
                        a[l] = x[i];
                        ++l;
                        ++i;
                }
                else
                {
                        cnt += x.size()-i;
                        a[l] = y[j];
                        ++l;
                        ++j;
                }
        }
        while(i<x.size())
        {
                a[l] = x[i];
                ++l;
                ++i;
        }
        while(j<y.size())
        {
                a[l] = y[j];
                ++l;
                ++j;
        }
        return cnt;
}

int mergeSort(int a[], int l, int r)
{
        int dem=0; // Dem so luong cap nghich the trong doan [l,r]
        if(l<r)
        {
                int m = (l+r)/2;
                dem += mergeSort(a,l,m);
                dem += mergeSort(a,m+1,r);
                dem += merge(a,l,m,r);
        }
        return dem;
}
void ess()
{

        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
        cout << cnt << endl;
        int ans = mergeSort(a,0,n-1);
        cout << ans;
}
int main()
{
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ess();
        return 0;
}
