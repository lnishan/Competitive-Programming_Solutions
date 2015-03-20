#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,lyr,nleft;
    while(scanf("%d",&n)&&n!=0)
    {
         lyr=ceil(sqrt(n));
         nleft=n-(lyr-1)*(lyr-1);
         if(lyr%2==1)
         {
              if(nleft<=lyr)
                            printf("%d %d\n",lyr,nleft);
              else
                  printf("%d %d\n",2*lyr-nleft,lyr);
         }else
         {
              if(nleft<=lyr)
                            printf("%d %d\n",nleft,lyr);
              else
                  printf("%d %d\n",lyr,2*lyr-nleft);
         }
    }
    return 0;
}
