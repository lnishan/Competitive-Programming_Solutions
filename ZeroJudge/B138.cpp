#include<iostream>
using namespace std;
int main(){
    int a[10],n,c=0;
    for(int i=0;i<10;i++)scanf("%d",&a[i]);
    scanf("%d",&n);n+=30;
    for(int i=0;i<10;i++)if(n>=a[i])c++;
    printf("%d",c);
    return 0;
}
    
