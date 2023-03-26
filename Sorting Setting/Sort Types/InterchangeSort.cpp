#include <bits/stdc++.h>
using namespace std;
// Doi cho truc tiep
void nhapMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
}
void interchange_sort(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                for(int j=i+1;j<n;j++)
                {
                        if(a[i]>a[j])
                        {
                                int temp = a[i];
                                a[i] = a[j];
                                a[j] = temp;
                        }
                }
        }
}
void xuatMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cout << a[i] << " ";
        }
}
int main()
{
        int n;
        cin >> n;
        int a[n];
        nhapMang(a,n);
        interchange_sort(a,n);
        xuatMang(a,n);
        return 0;
}

