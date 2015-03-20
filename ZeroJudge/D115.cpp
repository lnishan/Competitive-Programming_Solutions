#include<iostream>
using namespace std;
int n,m,a[100];
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
    while(scanf("%d",&n)==1)
    {
            for(int i=0;i<n;i++)scanf("%d",&a[i]);
            scanf("%d",&m);
            sort(a,a+n);
            for(int i=0;i<n;i++)
            {
                    if(n-i>=m)
                              if(i==0)p(m,i,b);else if(a[i]!=a[i-1])p(m,i,b);
                    else
                        break;
            }
    }
    return 0;
}
