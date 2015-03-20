#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long int n;
    while(scanf("%d",&n)&&n!=0)
                        printf("%s\n",(floor(sqrt(n))==sqrt(n))?"yes":"no");
    return 0;
}
