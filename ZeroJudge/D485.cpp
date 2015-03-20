#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b){
                     if(fmod(b-a,2)==0)
                                        cout<<abs((fmod(a,2)==1)?(b-a)/2:(b-a)/2+1);
                     else
                           cout << abs((b-a+1)/2);
                     cout << endl;
    }
    return 0;
}
