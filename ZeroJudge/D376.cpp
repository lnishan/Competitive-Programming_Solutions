#include<iostream>
using namespace std;
int main(){
     int n,a,sum;
     while(cin>>n){
                   sum=0;
                   for(int i=0;i<n;i++){cin>>a; sum+=a;}
                   cout << sum << endl;
     }
     return 0;
}
