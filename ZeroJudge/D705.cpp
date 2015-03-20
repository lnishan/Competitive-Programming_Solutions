#include <iostream>

using namespace std;

char a[46340],s[2][2];
int p[4792],pc=1,n,tn;

inline int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar()) ;
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

int main(){
    int i,j;
    s[0][0]=49; s[0][1]='\0';
    s[1][0]=48; s[1][1]='\0';
    a[1]=0; a[2]=1;
    for(i=4;i<46340;i+=2) a[i]=0;
    for(i=3;i<46340;i+=2) a[i]=1;
    for(i=3;i<215;i++)
        if(a[i])
            for(j=i*i;j<46340;j+=i<<1)
                a[j]=0;
    p[0]=2;
    for(i=3;i<46340;i+=2)
        if(a[i]) p[pc++]=i;
    while(n=input(),n>0)
    {
        if(n>46339){
            tn=n;
            for(i=0;p[i]*p[i]<=tn;i++)
                if(tn%p[i]==0){
                    tn/=p[i];
                    break;
                }
            puts(s[tn==1 || tn==n]);
        }else
            puts(s[a[n]]);
    }
    return 0;
}
