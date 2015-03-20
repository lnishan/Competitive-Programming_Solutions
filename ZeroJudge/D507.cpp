#include<iostream>
using namespace std;
int main(){
    int a[3];
    while(cin>>a[0]>>a[1]>>a[2])
    {
                                if(a[0]>a[1]) {a[0]=a[0]+a[1]; a[1]=a[0]-a[1]; a[0]=a[0]-a[1];}
                                if(a[1]>a[2]) {a[1]=a[1]+a[2]; a[2]=a[1]-a[2]; a[1]=a[1]-a[2];}
                                if(a[0]>a[1]) {a[0]=a[0]+a[1]; a[1]=a[0]-a[1]; a[0]=a[0]-a[1];}
                                if((a[0]*a[0]+a[1]*a[1])<(a[2]*a[2])){
                                                                     cout << "obtuse triangle" << endl;
                                }else if((a[0]*a[0]+a[1]*a[1])>(a[2]*a[2])){
                                      cout << "acute triangle" << endl;
                                }else{
                                      cout << "right triangle" << endl;
                                }
    }
    return 0;
}
