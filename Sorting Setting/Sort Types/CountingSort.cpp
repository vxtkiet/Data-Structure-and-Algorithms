#include <bits/stdc++.h>
using namespace std;
// O(n)
void nhapMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
}
void counting_sort(int a[], int n)
{
        int m=a[0];
        for(int i=1;i<n;i++)
        {
                m=max(m,a[i]);
        }
        int cnt[m+1]={0};
        for(int i=0;i<n;i++)
        {
                cnt[a[i]]++;
        }
        for(int i=0;i<n;i++)
        {
                if(cnt[i])
                {
                        for(int j=0;j<cnt[i];j++)
                        {
                                cout << i;
                        }
                }
        }
}

int main()
{
        int n;
        cin >> n;
        int a[n];
        nhapMang(a,n);
        counting_sort(a,n);
        return 0;
}


