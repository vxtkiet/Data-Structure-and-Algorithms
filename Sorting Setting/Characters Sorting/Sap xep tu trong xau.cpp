#include <bits/stdc++.h>
using namespace std;
int cmp(const void *a, const void *b)// Theo thu tu TU DIEN
{
        char *x = (char*)a;
        char *y = (char*)b;
        if(strcmp(x,y)<0)
        {
                return -1;
        }
        return 1;
}
int cmp1(const void *a, const void *b)// Theo DO DAI cua tu
{
        char *x = (char*)a;
        char *y = (char*)b;
        int len1 = strlen(x);
        int len2 = strlen(y);
        if(len1<len2)
                return -1;
        else return 1;
}
int cmp3(const void *a, const void *b)// Theo DO DAI cua tu va theo thu tu TU DIEN
{
        char *x = (char*)a;
        char *y = (char*)b;
        int len1 = strlen(x);
        int len2 = strlen(y);
        if(len1!=len2)
        {
                if(len1<len2)
                        return -1;
                else return 1;
        }
        else
        {
                if(strcmp(x,y)<0)
                        return 1;
                else return -1;
        }
}
int main()
{
        char c[1000];
        gets(c);
        char a[100][100];
        int n=0;
        char *token=strtok(c," ");
        while(token!=NULL)
        {
                strcpy(a[n++],token);
                token = strtok(NULL," ");
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++)
        {
                cout << a[i] << " ";
        }
        return 0;
}
