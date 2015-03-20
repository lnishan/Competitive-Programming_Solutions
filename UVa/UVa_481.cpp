#include <iostream>

using namespace std;

int a[500000],lis[500000],lc=1,pos[500000],n=0,p,prc=0;

int binSearch(int n){
    int l=0,h=lc,m;
    while(h-l > 1)
    {
        m=(l+h)/2;
        if(a[lis[m]] > n)
            h=m;
        else
            l=m;
    }
    return l;
}

int main(){
    int i;
    while(scanf("%d",&a[n])==1) n++;
    lis[0]=0;
    for(i=1;i<n;i++)
        if( a[i]>a[lis[lc-1]] ){
            pos[i]=lis[lc-1];
            lis[lc++]=i;
        }else{
            p=binSearch(a[i]);
            if( a[lis[p]]!=a[i] )
                if( p>0 ){
                    lis[p+1]=i;
                    pos[i]=lis[p];
                }else if( p==0 ){
                    if( a[i]<a[lis[0]] )
                        lis[0]=i;
                    else{
                        lis[1]=i;
                        pos[i]=lis[0];
                    }
                }
        }
    p=lis[lc-1];
    for(i=lc-1;i>=0;i--)
    {
        lis[prc++]=a[p];
        p=pos[p];
    }
    printf("%d\n",lc);
    puts("-");
    for(i=prc-1;i>=0;i--)
        printf("%d\n",lis[i]);
    while(1);
    return 0;
}