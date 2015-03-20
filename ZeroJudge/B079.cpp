#include<iostream>
using namespace std;
unsigned int a[1000001],n;
int main(){
    a[1]=a[2]=1;
    for(int i=3;i<1000001;i++)
            a[i]=a[i-a[i-1]]+a[i-1-a[i-2]];
    while(cin>>n && n!=0)
                 cout << a[n] << endl;
    return 0;
}
