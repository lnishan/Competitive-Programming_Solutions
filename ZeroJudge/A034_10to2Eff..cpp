#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    while(cin>>n){
                  string t="";
                  while(n!=1 && n!=0){
                             t= ((n%2==1)?"1":"0") + t;
                             n/=2;
                  }
                  t=((n==1)?"1":"")+t;
                  cout << t << endl;
    }
    return 0;
}
