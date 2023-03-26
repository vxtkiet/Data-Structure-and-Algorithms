#include <bits/stdc++.h>
using namespace std;
char *convert(char d[])
{
        char c[100];
        strcpy(c,d);
        int n=0;
        char a[100][100];
        char *token = strtok(c," ");
        while(token!=NULL)
        {
                strcpy(a[n++],token);
                token = strtok(NULL," ");
        }
        // nguyen van long -> longnguyenvan
        char res[100];
        strcpy(res,a[n-1]);
        for(int i=0;i<n-1;i++)
        {
                strcat(res,a[i]);
        }
        char *kq=res;
        return kq;
}
int cmp(const void *a,const void *b)
{
        char *x = (char*)a;
        char *y = (char*)b;
        char *x1 = convert(x);
        char tmp[100];
        strcpy(tmp,x1);
        char *y1 = convert(y);
        char tmp1[100];
        strcpy(tmp1,y1);
        if(strcmp(tmp,tmp1)<0)
        {
                return -1;
        }
        else return 1;
}
int main()
{
        int n;
        cin >> n;
        getchar();
        char c[100][100];
        for(int i=0;i<n;i++)
        {
                gets(c[i]);
        }
        qsort(c,n,sizeof(c[0]),cmp);
        for(int i=0;i<n;i++)
        {
                cout << c[i] << "\n";
        }
        return 0;
}

