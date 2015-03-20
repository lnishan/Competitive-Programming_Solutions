#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int h,m;
    double ang;
    while(scanf("%d:%d",&h,&m)&&(h!=0||m!=0))
    {
         ang=30*h-5.5*m;
         ang=(ang>0)?ang:-ang;
         if(ang>180)ang=360-ang;
         cout<<fixed<<setprecision(3)<<ang<<endl;
    }
    return 0;
}
