#include<iostream>
using namespace std;
bool a[1000001];
int recur(int n){
    int sum=n;
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    if(sum>1000000)
         return 0;
    else if(!a[sum]){
         a[sum]=true;
         recur(sum);
    }else return 0;
}
int main(){
    memset(a,0,sizeof(a));
    for(int i=1;i<=1000000;i++)
            if(!a[i]){printf("%d\n",i); recur(i);}
    return 0;
}
