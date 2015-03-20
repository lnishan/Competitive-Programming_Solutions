#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
using namespace std;
int main(){
    long n;
    while(cin>>n){
           int cn=0;
           string t="";
           while(1){
                    cn+=1;
                    if (pow(2,cn)>n) break;
           }
           for(int i=cn-1;i>=1;i--){
                   t=t+((int(n/pow(2,i))==0)?"0":"1");
                   if(int(n/pow(2,i))!=0) n=n-pow(2,i);
           }
           cout << ((n==1)?t+"1":t+"0") << endl;
    }
    system("pause");
    return 0;
}
