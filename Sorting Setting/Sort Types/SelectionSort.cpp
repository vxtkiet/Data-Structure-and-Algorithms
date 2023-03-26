#include <bits/stdc++.h>
using namespace std;
// Dat phan tu nho nhat la phan tu dau tien cua mang, kiem tra cac phan tu tiep theo, neu nho hon phan tu ban dau
// thi cap nhap phan tu nho nhat la phan tu do, sau do doi cho voi phan tu ban dau
void nhapMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
}
void selection_sort(int a[], int n)
{
        for(int i=0;i<n-1;i++)
        {
               int min=i;
               for(int j=i+1;j<n;j++)
               {
                       if(a[j]<a[min])
                       {
                               min = j;
                       }
               }
               int temp=a[i];
               a[i]=a[min];
               a[min]=temp;
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
        selection_sort(a,n);
        xuatMang(a,n);
        return 0;
}
