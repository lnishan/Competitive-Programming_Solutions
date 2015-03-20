#include<iostream>
using namespace std;
int a[1000],n;
int main(){
    while(cin>>n && n!=0)
    {
                 int c=0;
                 double avg=0;
                 for(int i=0;i<n;i++) {cin >> a[i]; avg+=a[i];}
                 avg/=n;
                 for(int i=0;i<n;i++) if(a[i]<avg) c++;
                 cout << c << endl;
    }
    return 0;
}
