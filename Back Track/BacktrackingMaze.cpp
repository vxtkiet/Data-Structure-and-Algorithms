#include <bits/stdc++.h>
using namespace std;
int n, cot[100], xuoi[100], nguoc[100], a[100], cnt=0, dem;
int res[100][100];
char path[100];
void back_tracking(int i, int j)
{
        if(i==n && j==n)
        {
                ++dem;
                for(int i=0;i<cnt;i++)
                {
                        cout << path[i];
                }
                cout << endl;
        }
        // Lua chon di xuong duoi
        if(i+1<=n)
        {
                path[cnt]='D';
                ++cnt;
                back_tracking(i+1,j);
                --cnt; // lua chon di xuong duoi chay xong thi giam nuoc di di 1
        }
        // Lua chon di sang phai
        if(j+1<=n)
        {
                path[cnt]='R';
                ++cnt;
                back_tracking(i,j+1);
                --cnt;
        }
}
int main()
{
        cin >> n;
        back_tracking(1,1);
        cout << "So cach di chuyen la: " << dem << endl;
        return 0;
}
