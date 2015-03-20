#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double Ax,Ay,Bx,By,Cx,Cy,r;
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
            r=Ax*By-Ay*Bx+Bx*Cy-By*Cx+Cx*Ay-Cy*Ax;
            r=(r<0)?-r:r;
            r/=14;
            if(fmod(r,1)>=0.5)cout<<fixed<<setprecision(0)<<ceil(r)<<endl;else cout<<fixed<<setprecision(0)<<floor(r)<<endl;
    }
    return 0;
}
