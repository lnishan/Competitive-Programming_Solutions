#include<iostream>
#include<ctype.h>
using namespace std;
int n,m,a[100];
int input(){
    char c;
    for(c=getchar();!isdigit(c);c=getchar());
    int x=c-48;
    for(c=getchar();isdigit(c);c=getchar())x=x*10+c-48;
    return x;
}
int p(int leftn,int ind,int c[]){
    c[m-leftn]=a[ind];
    leftn--;
    if(leftn==0){
                printf("%d",c[0]);
                for(int i=1;i<m;i++)printf(" %d",c[i]);
                putchar('\n');
                return 0;
    }
    for(int i=ind+1;i<n;i++)
            if(n-i>=leftn && (a[i]!=a[i-1]||i==ind+1))p(leftn,i,c);
    return 0;
}
int main(){
    int b[100];
    /*
    freopen("d653.in","r",stdin);
    freopen("d653.out","w",stdout);
    */
    while(scanf("%d%d",&n,&m),n>0||m>0)
    {
            for(int i=0;i<n;i++) a[i]=input();
            sort(a,a+n);
            for(int i=0;i<=n-m;i++)
                if(i==0) p(m,i,b);
                else if(a[i]!=a[i-1]) p(m,i,b);
    }
    return 0;
}
