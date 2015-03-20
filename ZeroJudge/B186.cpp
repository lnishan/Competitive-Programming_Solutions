#include<iostream>
using namespace std;
int a,b,c;
int main(){
    while(cin>>a>>b>>c)
    cout<<a<<" 個餅乾，"<<b+((a/10>c/2)?c/2:a/10)<<" 盒巧克力，"<<c<<" 個蛋糕。"<<endl;
    return 0;
}
