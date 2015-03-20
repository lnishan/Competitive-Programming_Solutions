#include<iostream>
using namespace std;
int main()
{
    long long int p[100];
    p[0]=1;
    p[1]=1;
    for(int i=2;i<100;i++) p[i]=p[i-1]+p[i-2];
    int a;
    while(cin>>a) cout<<p[a]<<endl;
    return 0;
}
