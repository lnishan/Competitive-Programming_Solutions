#include<iostream>
#include<math.h>
using namespace std;
int main(){
    unsigned long int n,c;
    while(cin>>n)
    {
                 c=0;
                 for(int i=1;;i++)
                         if(pow(5,i)<=n) c+=(n/pow(5,i)); else break;
                 cout << c << endl;
    }
    return 0;
}
