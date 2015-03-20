#include<iostream>
using namespace std;
int n;
int main(){
    while(1)
    {
            cin>>n;
            if(n==0)break;
            cout<<"f91("<<n<<") = "<<((n>100)?n-10:91)<<endl;
    }
    return 0;
}
    
