#include <iostream>

using namespace std;

long long int a[1000000],t[1000000],n;
int s,st,olen;
char tmp[10],strout[20010];

int square(int alen){
    int i,j,len=alen<<1;
    long long int tn;
    for(i=0;i<len;i++) t[i]=0;
    for(i=0;i<alen;i++)
        for(j=0;j<alen;j++){
            tn=a[i]*a[j]+t[i+j];
            t[i+j+1]+=tn/10000;
            t[i+j]=tn%10000;
        }
    if(tn<10000) len--;
    for(i=0;i<len;i++) a[i]=t[i];
    return len;
}

int smlTimes(int alen){
    int i,len=alen;
    long long int tn;
    for(i=0;i<alen+10;i++) t[i]=0;
    for(i=0;i<alen;i++)
    {
        tn=a[i]*n+t[i];
        t[i+1]+=tn/10000;
        t[i]=tn%10000;
    }
    if(tn>9000){
        t[len++]%=10000; tn/=100000;
        if(tn>0)
            while(tn>0)
            {
                t[len++]=tn%10000;
                tn/=10000;
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

int getNLen(int n){
    int c=0;
    while(n>0)
    {
        n/=10;
        c++;
    }
    return c;
}

int main(){
    int len,i,j,curl;
    while(scanf("%lld%d%d%d",&n,&s,&st,&olen)==4)
    {
        len=execute(s,0);
        curl=0;
        memset(strout,0,sizeof(strout));
        for(i=len-1;i>=0;i--)
        {
            if(i==len-1){
                curl=getNLen(a[len-1]);
                sprintf(tmp,"%d",a[len-1]);
                strcat(strout,tmp);
            }else{
                curl+=4;
                sprintf(tmp,"%0.4d",a[i]);
                strcat(strout,tmp);
            }
            if(curl>=st+olen-1)
                break;
        }
        for(i=st-1;i<st+olen-1 && i<curl;i++)
            putchar(strout[i]);
        putchar('\n');
    }
    return 0;
}
