#include<iostream>
using namespace std;
int m=10007;
int cal(int b,int p);
int cal(int b,int p){
    int vl;
    if(p==1)return b%m;
    if(p==0)return 1%m;
    else
    {
        vl=cal(b,p/2);
        vl=(vl*vl)%m;
        if(p%2)
                  return (vl*(b%m))%m;
        else
            return vl;
    }
    return 0;
}
int main(){
    int b,p;
    while(scanf("%d%d",&b,&p)!=EOF)
         printf("%d\n",cal(b,p));
    return 0;
}
