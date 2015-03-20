#include<iostream>
using namespace std;
int main(){
    int a,b,mh=0,mwd;
    for(int i=1;i<=7;i++)
    {
            scanf("%d%d",&a,&b);
            if(a+b>mh){mh=a+b;mwd=i;}
    }
    if(mh<=8)printf("0");else printf("%d",mwd);
    return 0;
}
