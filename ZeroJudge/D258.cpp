#include<iostream>
using namespace std;
int main(){
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d%d",&a,&b);
            int c=0;
            while(1)
            {
                    c+=(a/b);
                    a=a/b+a%b;
                    if(a<b)break;
            }
            if(a!=1||c==0)printf("cannot do this\n");else printf("%d\n",c);
    }
    return 0;
}
