#include<iostream>
using namespace std;
int a[1500001],n;
int main(){
    memset(a,0,sizeof(a));
    a[2]=1;a[3]=1;a[5]=1;a[7]=1;a[13]=1;a[17]=1;a[19]=1;a[31]=1;a[61]=1;a[89]=1;a[107]=1;a[127]=1;a[521]=1;a[607]=1;a[1279]=1;a[2203]=1;a[2281]=1;a[3217]=1;a[4253]=1;a[4423]=1;a[9689]=1;a[9941]=1;a[11213]=1;a[19937]=1;a[21701]=1;a[23209]=1;a[44497]=1;a[86243]=1;a[110503]=1;a[132049]=1;a[216091]=1;a[756839]=1;a[859433]=1;a[1257787]=1;a[1398269]=1;
    while(scanf("%d",&n)&&n!=0)if(a[n])printf("yes\n");else printf("no\n");
    return 0;
}
