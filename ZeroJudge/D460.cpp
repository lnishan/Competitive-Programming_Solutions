#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n)
    {
     if(n<6)
           cout<<"0"<<endl;
     else if(n<12)
         cout<<"590"<<endl;
     else if(n<18)
         cout<<"790"<<endl;
     else if(n<60)
         cout<<"890"<<endl;
     else
        cout<<"399"<<endl;
    }
}
