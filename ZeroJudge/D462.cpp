#include <iostream>

using namespace std;

short a[10000000],t[10000000];
int n,s,st,olen;

int square(int alen){
    int i,j,tn,len=alen<<1;
    for(i=0;i<len;i++) t[i]=0;
    for(i=0;i<alen;i++)
        for(j=0;j<alen;j++){
            tn=a[i]*a[j]+t[i+j];
            t[i+j+1]+=tn/10;
            t[i+j]=tn%10;
        }
    if(tn<10) len--;
    for(i=0;i<len;i++) a[i]=t[i];
    return len;
}

int smlTimes(int alen){
    int i,tn,len=alen;
    for(i=0;i<alen+10;i++) t[i]=0;
    for(i=0;i<alen;i++)
    {
        tn=a[i]*n+t[i];
        t[i+1]+=tn/10;
        t[i]=tn%10;
    }
    if(tn>9){
        t[len++]%=10; tn/=100;
        if(tn>0)
            while(tn>0)
            {
                t[len++]=tn%10;
                tn/=10;
            }
    }
    for(i=0;i<len;i++) a[i]=t[i];
    return len;
}

int execute(int sup,int alen){
    int len;
    if(sup==0){
        a[0]=1;
        len=1;
    }else if(sup==1){
        a[0]=1;
        len=smlTimes(1);
    }else{
        len=execute(sup/2,alen);
        len=square(len);
        if(sup%2) len=smlTimes(len);
    }
    return len;
}

int main(){
    int len,i;
    while(scanf("%d%d%d%d",&n,&s,&st,&olen)==4)
    {
        len=execute(s,0);
        for(i=len-st;i>len-st-olen;i--)
            putchar(a[i]+48);
        putchar('\n');
    }
    return 0;
}
