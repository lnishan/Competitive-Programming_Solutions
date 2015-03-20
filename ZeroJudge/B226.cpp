#include<iostream>
using namespace std;
int l,w,x,y;
int main(){
    while(cin>>l>>w>>x>>y && (l!=0||w!=0||x!=0||y!=0))
    {
                          if(l%x==0 && w%y==0)
                                    cout<<(l/x)*(w/y)<<endl;
                          else if(l%y==0 && w%x==0)
                               cout<<(l/y)*(w/x)<<endl;
                          else
                              cout<<"-1"<<endl;
    }
    return 0;
}
