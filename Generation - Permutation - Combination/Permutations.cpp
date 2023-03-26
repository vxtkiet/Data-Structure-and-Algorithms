// Hoan vi
// Cau hinh dau tien: Cac so tu 1 toi n
// Cau hinh cuoi cung: Cac so tu n ve 1
// B1: Tim vi tri dau tien tinh tu ben phai ma a[i]<a[i+1]
// B2: Tim phan tu nho nhat tinh tu chi so i+1 -> n ma lon hon a[i], va hoan doi vi tri 2 so nay
// B3: Sap xep tang dan cac phan tu tu chi so i+1 toi chi so n
#include<bits/stdc++.h>
using namespace std;

int n,a[100],ok=1;

void init()
{
        for(int i=1;i<=n;i++)
        {
                a[i]=i;
        }
}
void next()
{
        int i=n-1;
        while(i>=1 && a[i]>a[i+1])
        {
                --i;
        }
        if(i==0)
        {
                ok=0;
        }
        else
        {
                // Di tim a[k] nho nhat ma lon hon a[i] trong [i + 1 ; n ]
                int k=n;
                while(a[k]<a[i])
                {
                        --k;
                }
                swap(a[i],a[k]);
                // Lat nguoc doan [i + 1 ; n]
                reverse(a+i+1,a+n+1);
//                int left=i+1, right=n;
//                while(left<=right)
//                {
//                        swap(a[left],a[right]);
//                        left++;
//                        right--;
//                }
        }
}
int main()
{
        long long cnt=0;
        cin >> n;
        init();
        while(ok)
        {
                for(int i=1;i<=n;i++)
                {
                        cout << a[i] << " ";
                }
                cout << "\n";
                next();
                cnt++;
        }
        cout << cnt;
        return 0;
//        for(int i=0;i<n;i++)
//        {
//                a[i]=i+1;
//        }
//        do
//        {
//                for(int i=0;i<n;i++)
//                {
//                        cout << a[i] << " ";
//                }
//                cout << endl;
//        }while(next_permutation(a,a+n));
//         while(prev_permutation(a,a+n)): sinh ra hoan vi dang truoc, khoi tao tu n->1
//
}
