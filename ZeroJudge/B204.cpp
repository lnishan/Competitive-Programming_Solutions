#include<iostream>
using namespace std;
int n,c;
int main(){
    while(cin >> n && n!=0)
    {
              c=0;
              int f,pf;
              cin >> pf;
              for(int i=1;i<n;i++)
              {
                      cin >> f;
                      c+=((f>pf)?(f-pf)*20:(pf-f)*10);
                      pf=f;
              }
              cout << c << endl;
    }
    return 0;
}
                      
