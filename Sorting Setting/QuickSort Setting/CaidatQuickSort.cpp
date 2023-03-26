#include <bits/stdc++.h>
using namespace std;
// Neu cmp tra ve 1, a dung sau b
// Neu cmp tra ve -1, a dung truoc b
int cmp(const void *a, const void *b)
{
        int *x = (int*)a;
        int *y = (int*)b;
        if((*x) < (*y))
        {
                return 1;
        }
        else
                return -1;
}
int cmp2(const void *a, const void *b)
{
        int *x = (int*)a;
        int *y = (int*)b;
        if(abs(*x) < abs(*y))
                return -1;
        else
                return 1;

}
int cmp3(const void *a, const void *b)
{
        int *x = (int*)a;
        int *y = (int*)b;
        if(abs(*x) != abs(*y))
        {
                if(abs(*x)<abs(*y))
                        return -1;
                else
                        return 1;
        }
        else
        {
                if()
        }

}
int main()
{
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
        {
                cin >> a[i];
        }
        qsort(a,n,sizeof(int),cmp);
        for(int i=0;i<n;i++)
        {
                cout << a[i] << " ";
        }
        return 0;
}

