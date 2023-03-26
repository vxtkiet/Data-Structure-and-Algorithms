#include <bits/stdc++.h>
using namespace std;
// Stable, O(n^2), Doi cho cac phan tu ke can
void nhapMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
}
void bubble_sort(int a[], int n)
{
        for(int i=0;i<n-1;i++)
        {
                for(int j=0;j<n-i-1;j++)
                {
                       if(a[j]>=a[j+1])
                       {
                               int temp=a[j];
                               a[j]=a[j+1];
                               a[j+1]=temp;
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
        bubble_sort(a,n);
        xuatMang(a,n);
        return 0;
}
