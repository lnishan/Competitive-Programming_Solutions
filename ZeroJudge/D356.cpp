#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n)
    {
                 double c=0;
                 for(int i=1;;i++)
                 {
                         c+=(1/double(i));
                         if(c>n){printf("%d\n",i);break;}
                 }
    }
    return 0;
}
