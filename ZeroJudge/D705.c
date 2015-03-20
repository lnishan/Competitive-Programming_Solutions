#include <stdio.h>

char a[46340],s[2][2];
int p[4792],pc=47,n,tn,p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211};

int input(){
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
    a[1]=0;
    for(i=4;i<46340;i+=2) a[i]=0;
    for(i=3;i<46340;i+=2) a[i]=1;
    for(i=1;i<47;i++)
        for(j=p[i]*p[i];j<46340;j+=2*p[i])
            a[j]=0;
    for(i=223;i<46340;i+=2)
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
