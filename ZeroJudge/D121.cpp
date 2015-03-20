#include<iostream>
using namespace std;
bool a[46342],nstart;
int p[5000],pc=0,n;
void createPrime(){
     for(int i=3;i<46342;i++)
             if(i%2)a[i]=true;else a[i]=false;
     a[2]=true;
     for(int i=3;i<46342;i+=2)
             if(a[i])
                     for(int j=2;j<=46341/i;j++)a[i*j]=false;
     for(int i=2;i<46342;i++)
             if(a[i])p[pc++]=i;
}
int main(){
    createPrime();
    while(scanf("%d",&n),n!=0)
    {
         printf("%d =",n);
         if(n<0){
                 printf(" -1");
                 nstart=true;
         }else nstart=false;
         n=(n<0)?-n:n;
         for(int i=0;i<pc;i++)
         {
                 if(n<p[i])break;
                 if(n%p[i]==0)
                      while(n%p[i]==0){if(nstart)printf(" x");else nstart=true;printf(" %d",p[i]);n/=p[i];}
         }
         if(n!=1)
                 if(nstart)printf(" x %d",n);else printf(" %d",n);
         putchar('\n');
    }
    return 0;
}
