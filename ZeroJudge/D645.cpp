#include <iostream>

using namespace std;

int t,cap,a[1001],fl,v,tp,maxfl=-1,x,flag;
char c;

int input(){
    flag=1;
    for(c=getchar();c<48||c>57;c=getchar())
        if(c=='-') flag=-1;
    x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar())
        x=x*10+c-48;
    return x*flag;
}

int main(){
    memset(a,-1,sizeof(a));
    a[0]=0;
    t=input(); cap=input();
    for(int d=0;d<t;d++)
    {
        fl=input(); v=input(); tp=input();
        if(tp<0){
            for(int i=0;i<=cap-v;i++)
                if(a[i]>=0 && a[i]+fl>a[i+v]){
                    a[i+v]=a[i]+fl;
                    maxfl=max(maxfl,a[i+v]);
                }
        }else{
            for(int i=0;i<tp;i++)
                for(int j=cap-v;j>=0;j--)
                    if(a[j]>=0 && a[j]+fl>a[j+v]){
                        a[j+v]=a[j]+fl;
                        maxfl=max(maxfl,a[j+v]);
                    }
        }
    }
    printf("%d",maxfl);
    return 0;
}
