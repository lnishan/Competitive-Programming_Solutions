#include<iostream>
using namespace std;
int n,x1,y1,x2,y2,x3,y3;
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
    {
            cin>>x1>>y1>>x2>>y2>>x3>>y3;
            cout<<(((x1*y2+x2*y3-x2*y1-x3*y2)==0)?"NO":"YES") << endl;
    }
    return 0;
}
