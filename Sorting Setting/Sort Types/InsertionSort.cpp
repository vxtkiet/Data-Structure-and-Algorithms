#include <bits/stdc++.h>
using namespace std;
void nhapMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
}
void insertion_sort(int a[], int n)
{
        int pos=0;
        int x;
        for(int i=1;i<n;i++)
        {
              x=a[i];
              for(pos=i;pos>0&&a[pos-1]>x;pos--)
              {
                      a[pos]=a[pos-1];      // Tim vi tri chen
              }
              a[pos]=x; // Chen phan tu vao vi tri chen
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
        insertion_sort(a,n);
        xuatMang(a,n);
        return 0;
}

