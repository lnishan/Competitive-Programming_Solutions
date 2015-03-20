#include<iostream>
using namespace std;
int a,b,ans,tn,c;
int main(){
    while(cin>>a>>b)
    {
                    ans=max(a,b);
                    c=0;
                    for(int i=0;i<30;i++)
                    {
                            cin>>tn;
                            if(tn!=0 && tn!=ans) c++;
                            if(tn==ans && c<3) c=-30;
                    }
                    cout << ((c<0)?"Y":"N") << endl;
    }
    return 0;
}
