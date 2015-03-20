#include<iostream>
using namespace std;
int main(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>a>>b;
            if(a<b||(a+b)%2==1)
                               cout << "impossible" << endl;
            else
                               cout << (a+b)/2 << " " << (a-b)/2 << endl;
    }
    return 0;
}
