#include<iostream>
#include<math.h>
using namespace std;
int a,b;
long int big, sma;
int main(){
    while(cin>>a>>b && (a!=0 || b!=0))
    {
                    long int n1=-1, n2=-1;
                    double t1, t2;
                    big=max(a,b);
                    sma=min(a,b);
                    t1=sqrt(big*big-sma*sma);
                    t2=sqrt(big*big+sma*sma);
                    if (ceil(t1)==t1) n1=t1;
                    if (ceil(t2)==t2) n2=t2;
                    if(n1==-1 && n2==-1) cout << "Wrong";
                    else if(n1==-1) cout << n2;
                    else if(n2==-1) cout << n1;
                    else cout << n1 << " " << n2;
                    cout << endl;
    }
}
