#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
int afun[10000001],bfun[10000001];
int sod(int n){
    int c=0;
    while(n>0)
    {
              c+=n%10;
              n/=10;
    }
    return c;
}
int main(){
    char s[50];
    char *ptr;
    int ns,ct,a[2],t;
    for(int i=1;i<=10000000;i++)afun[i]=-1;
    for(int i=9999950;i>0;i--)
    {
            t=i+sod(i);
            if(t<=10000000)afun[t]=i;
    }
    bfun[0]=0;
    for(int i=1;i<=10000000;i++)
            bfun[i]=bfun[i-1]+(afun[i]==-1);
    scanf("%d",&ns);
    gets(s);
    for(int i=1;i<=ns;i++)
    {
            gets(s);
            ptr=strtok(s," ");
            ct=0;
            while(ptr!=NULL){ a[ct++]=atoi(ptr); ptr=strtok(NULL," "); }
            if(ct==2)printf("Case %d: %d\n",i,bfun[a[1]]-bfun[a[0]-1]);
            else printf("Case %d: %d\n",i,afun[a[0]]);
    }
    return 0;
}
