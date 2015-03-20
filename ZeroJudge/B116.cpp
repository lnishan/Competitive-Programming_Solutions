#include<iostream>
using namespace std;
int n,m,a[100],ct,maxn,tmn,r[10000],rc;
bool b[1000001];
int main(){
    while(scanf("%d%d",&m,&n)==2)
    {
        for(int i=0;i<m;i++)
        {
            ct=maxn=0;
            for(int j=0;j<n;j++){scanf("%d",&a[j]);ct+=a[j];}
            memset(b,0,sizeof(b));
            b[0]=true;
            for(int j=0;j<n;j++)
            {
                tmn=maxn;
                rc=0;
                for(int k=0;k<=tmn;k++)
                    if(b[k]){
                        r[rc++]=k;
                        if(k+a[j]>maxn)maxn=k+a[j];
                    }
                for(int i=0;i<rc;i++) b[r[i]+a[j]]=true;
            }
            if(ct%2==1||(!b[ct/2]))puts("No");else puts("Yes");
        }
    }
    return 0;
}
