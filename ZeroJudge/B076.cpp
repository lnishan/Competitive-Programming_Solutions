#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int ds,n,spos,mn,mi;
    int rl[100];
    string na[100];
    string s;
    scanf("%d",&ds);
    for(int i=0;i<ds;i++)
    {
            scanf("%d",&n);
            getline(cin,s);
            for(int i=0;i<n;i++)
            {
                    getline(cin,s);
                    spos=s.find_last_of(" ");
                    na[i]=s.substr(0,spos);
                    rl[i]=atoi(s.substr(spos+1,s.length()-spos-1).c_str());
                    if(i==0){mn=rl[0];mi=0;}else{if(rl[i]<mn){mn=rl[i];mi=i;}}
            }
            if(mn>=0)printf("Are you kidding me?\n");else cout<<na[mi]<<endl;
    }
    return 0;
}
