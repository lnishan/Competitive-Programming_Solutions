#include<iostream>
using namespace std;
int a,b,c;
int main(){
    while(cin>>a>>b>>c)
    cout<<a<<" �ӻ氮�A"<<b+((a/10>c/2)?c/2:a/10)<<" �����J�O�A"<<c<<" �ӳJ�|�C"<<endl;
    return 0;
}
