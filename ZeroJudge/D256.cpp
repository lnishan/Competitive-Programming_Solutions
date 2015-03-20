#include<iostream>
using namespace std;
int main(){
    long int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            scanf("%d %d",&a,&b);
            if(b%a!=0)printf("-1\n");else printf("%d %d\n",a,b);
    }
    return 0;
}
