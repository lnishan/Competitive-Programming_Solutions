#include<iostream>
using namespace std;
int main(){
    unsigned int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d %d",&a,&b);printf("%d\n",2*(a+b));}
    return 0;
}
