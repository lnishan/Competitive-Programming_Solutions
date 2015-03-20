#include<iostream>
using namespace std;
int main(){
    long int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
                                   long int c=a;
                                   while(a!=0)
                                   {
                                               c+=(a/b);
                                               a=a/b+a%b;
                                               if(a/b==0)break;
                                   }
                                   printf("%d\n",c);
    }
    return 0;
}
