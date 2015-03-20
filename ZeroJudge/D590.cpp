#include<iostream>
using namespace std;
int main(){
    unsigned int a,b;
    while(scanf("%d %d",&a,&b) && (a!=0||b!=0))
                    cout<<(((a%2==1&&b%2==1)||(a%2==0&&b%2==0))?"Win":"Loss")<<endl;
    return 0;
}
