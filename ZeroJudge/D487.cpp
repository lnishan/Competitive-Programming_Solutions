#include<iostream>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
    {
                              if(n==0)
                              {
                                      printf("0! = 1 = 1\n");
                              }else{
                                    printf("%d! = %d",n,n);
                                    int c=n;
                                    for(int i=n-1;i>=1;i--){printf(" * %d",i);c*=i;}
                                    printf(" = %d\n",c);
                              }
    }
    return 0;
}
