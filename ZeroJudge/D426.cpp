#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,c;
    while(cin>>n)
    {
                 int l=1;
                 printf("%d",n);
                 while(n!=2)
                 {
                            c=0;
                            for(int i=1;i<=sqrt(n);i++)
                                    if(n%i==0)c+=2;
                            if(floor(sqrt(n))*floor(sqrt(n))==n)c--;
                            printf("->%d",c);
                            n=c;
                            l++;
                 }
                 printf("\nL=%d\n",l);
    }
    system("pause");
    return 0;
}
