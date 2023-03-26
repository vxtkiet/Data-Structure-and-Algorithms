#include <bits/stdc++.h>
using namespace std;
int n, cot[100], xuoi[100], nguoc[100], cnt=0;
// int a[100];
int res[100][100];
void back_tracking(int i)
{
        for(int j=1;j<=n;j++)
        {
                if(cot[j] && xuoi[i-j+n] && nguoc[i+j-1])
                {
//                        a[i]=j;// con hau o hang thu i thi xep o cot j
                        cot[j] = xuoi[i-j+n] = nguoc[i+j-1] = 0;
                        if(i==n)
                        {
                                ++cnt;
//                                memset(res,0,sizeof(res));
//                                for(int i=1;i<=n;i++)
//                                {
//                                        res[i][a[i]]=1;
//
//                                }
//                                for(int i=1;i<=n;i++)
//                                {
//                                        for(int j=1;j<=n;j++)
//                                        {
//                                                cout << res[i][j] << " ";
//                                        }
//                                        cout << endl;
//                                }
//                                cout << endl;
                        }
                        else back_tracking(i+1);
                        cot[j] = xuoi[i-j+n] = nguoc[i+j-1] = 1;
                }
        }
}
int main()
{
        cin >> n;
        for(int i=0;i<100;i++)
        {
                cot[i]=xuoi[i]=nguoc[i]=1;
        }
        back_tracking(1);
        cout << "So cach sap xep la: " << cnt << endl;
        return 0;
}
