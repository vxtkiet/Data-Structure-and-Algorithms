#include <bits/stdc++.h>
using namespace std;
// Worst case; O(n^2)
// Best and average case: O(n*log(n))
void nhapMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
}
void xuatMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cout << a[i] << " ";
        }
}
void quick_sort(int a[], int n, int left, int right)
{
        if(left>=right)
                return; // Dieu kien ket thuc de quy
        int pivot = a[(left+right)/2];
        int i=left, j=right;
        do
        {
                while(a[i]<pivot)// Tim vi tri sai dau tien ben trai
                        i++;
                while(a[j]>pivot)// Tim vi tri sai dau tien ben phai
                        j--;
                if(i<=j)
                {
                        swap(a[i],a[j]);
                        i++;
                        j--;
                }
        }while(i<j);
        xuatMang(a,n);
        cout << endl;
        quick_sort(a,n,left,j); // Phan hoach day con < pivot den khi day con con 1 phan tu
        quick_sort(a,n,i,right); // Phan hoach day con > pivot den khi day con con 1 phan tu
}

int main()
{
        int n;
        cin >> n;
        int a[n];
        nhapMang(a,n);
        int l=0, r=n-1;
        quick_sort(a,n,l,r);
        xuatMang(a,n);
        return 0;
}
