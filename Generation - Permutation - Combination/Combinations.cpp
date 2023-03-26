// To hop
// Cau hinh dau tien: tu 1 -> k
// Cau hinh cuoi cung: tu n-k+1 -> n
// Luu cau hinh tu chi so 1 toi chi so k
// Tai moi vi tri deu co gia tri max o vi tri do: vi tri i -> n-k+i
#include <iostream>
using namespace std;
int n,k,a[100],ok=1;
void init()
{
        for(int i=1;i<=k;i++)
        {
                a[i]=i;
        }
}
void next()
{
        int i=k; // Bat dau tu phan tu ben phai
        while(i>=1 && a[i]==n-k+i)
        {
                --i;
        }
        if(i==0)
        {
                ok=0;// Cau hinh cuoi cung
        }
        else
        {
                // Tang a[i] len 1 don vi
                a[i]++;
                for(int j=i+1;j<=k;j++)
                {
                        a[j] = a[j-1]+1;
                }
        }
}
int main()
{
        cin >> n >> k;
        int cnt=0;
        init();
        while(ok)
        {
                for(int i=1;i<=k;i++)
                {
                        cout << a[i] << " ";
                }
                cout << "\n";
                cnt++;
                next();
        }
        cout << cnt << endl;
}
