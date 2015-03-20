#include<iostream>
#include<cstring>
using namespace std;
int a[1002][1002],mlen;
char s1[1001],s2[1001];
int main(){
    while(gets(s1+1))
    {
        mlen=0;
        gets(s2+1);
        memset(a,0,sizeof(a));
        int s1len=strlen(s1+1),s2len=strlen(s2+1);
        for(int i=1;i<=s1len;i++)
        {
            for(int j=1;j<=s2len;j++)
            {
                if(s1[i]==s2[j])
                    a[i][j]=a[i-1][j-1]+1;
                else
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
                mlen=max(mlen,a[i][j]);
            }
        }
        printf("%d\n",mlen);
    }
    return 0;
}
