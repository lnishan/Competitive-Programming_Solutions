#include<iostream>
using namespace std;
int main(){
    int w[7490],m[5]={1,5,10,25,50},n;
    memset(w,0,sizeof(w));w[0]=1;
    for(int i=0;i<5;i++)
            for(int j=m[i];j<=7489;j++)
                    w[j]+=w[j-m[i]];
    while(scanf("%d",&n)!=EOF)printf("%d\n",w[n]);
    return 0;
}
