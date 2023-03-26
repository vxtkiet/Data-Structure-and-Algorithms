#include <bits/stdc++.h>
using namespace std;
// O(n*log(n)) in 3 cases
// Stable
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void merge_sort(int a[], int left,int right);// Tach mang ban dau thanh cac mang con
void merge(int a[], int left, int mid, int right);// Tron mang
void sortedMerge(int a[], int b[], int res[], int n, int m);

void nhapMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
}
void merge(int a[], int left, int mid, int right)
{
        int ntemp = right-left+1;// So luong phan tu cua mang tam
        int temp[ntemp];
        int pos=0;
        int i=left;
        int j=mid+1;
        while(!(i>mid&&j>right))
        {
                if((i<=mid && j<=right && a[i]<a[j])|| j>right)
                {
                        temp[pos++]=a[i++];
                }
                else
                {
                        temp[pos++]=a[j++];
                }
        }
        for(int i=0;i<ntemp;i++)
        {
                a[left+i]=temp[i];
        }
}
void merge_sort(int a[], int left,int right)
{
        if(left>=right)
                return;// Dieu kien dung de quy
        int mid = (left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
}
void xuatMang(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
                cout << a[i] << " ";
        }
}
void sortedMerge(int a[], int b[], int res[], int n, int m)
{
        sort(a,a+n);
        sort(b,b+m);
        int i=0,j=0,k=0;
        while(i<n&&j<m)
        {
                if(a[i]<=b[j])
                {
                        res[k]=a[i];
                        i++;
                        k++;
                }
                else
                {
                        res[k]=b[j];
                        j++;
                        k++;
                }
        }
        while(i<n)
        {
                res[k]=a[i];
                i++;
                k++;
        }
        while(j<m)
        {
                res[k]=b[j];
                j++;
                k++;
        }
}
int main()
{
        int n;
        cin >> n;
        int a[n];
        nhapMang(a,n);
        int left=0, right=n-1;
        merge_sort(a,left,right);
        xuatMang(a,n);
        return 0;
}

