#include <iostream>

using namespace std;

int a[8001],m[8]={1,13,33,43,139,169,1309,2597},n;

int main(){
    memset(a,0,sizeof(a));
    a[0]=1;
    for(int i=0;i<8;i++)
        for(int j=m[i];j<8001;j++)
            a[j]+=a[j-m[i]];
    while(scanf("%d",&n)==1)
        printf("%d\n",a[n]);
    return 0;
}
