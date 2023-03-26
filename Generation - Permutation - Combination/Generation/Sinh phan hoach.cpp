#include <bits/stdc++.h>
using namespace std;
int n, a[100], ok, cnt;
void ktao()
{
        cnt=1;
        a[1]=n;
}
void sinh()
{
        int i=cnt;
        while(i>=1 && a[i]==1)
        {
                --i;
        }
        if(i==0)
        {
                ok=0;
                // Cau hinh cuoi cung
        }
        else
        {
                a[i]--;
                int d=cnt-i+1; // So luong so 1 da bo qua + 1 don vi do a[i]--
                cnt=i;
                int q=d/a[i];
                int r=d%a[i];
                if(q)
                {
                        for(int j=1;j<=q;j++)
                        {
                                a[i+j]=a[i];
                        }
                        cnt+=q;
                }
                if(r)
                {
                        a[cnt+1]=r;
                        ++cnt;
                }
        }
}
int main()
{
        cin >> n;
        ktao();
        ok=1;
        while(ok)
        {
                for(int i=1;i<=cnt;i++)
                {
                        cout << a[i] << " ";
                }
                cout << endl;
                sinh();
        }
        return 0;
}

