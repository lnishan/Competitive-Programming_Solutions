#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m)
                    cout << floor(m*log10(n))+1 << endl;
    return 0;
}
