#include<iostream>
using namespace std;
int main(){
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d%d",&a,&b);
            printf("%d\n",(a/3)*(b/3));
    }
    return 0;
}
