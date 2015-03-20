#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,m;
    long int a;
    while(cin >> n && n!=0)
    {
              a=0;
              for(int i=0; i<n; i++){cin >> m; a+=pow(m,2);}
              cout << a << endl;
    }
    return 0;
}
