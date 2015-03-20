#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    int s[10]={1,5,10,20,50,100,200,500,1000,2000};
    long long int p[50001];
    for(int i=1;i<=50000;i++)
            p[i]=0;
    p[0]=1;
    for(int i=0;i<10;i++){
            for(int j=s[i];j<=50000;j++){
                    p[j]+=p[j-s[i]];
            }
    }
    string st;
    stringstream ss;
    int tot, n;
    while(getline(cin,st) && st!="0"){
                           ss.clear();
                           ss.str(st);
                           tot=0;
                           while(ss >> n)
                                    tot+=n;
                           cout << p[tot]-1 << endl;
    }
    system("pause");
    return 0;
}
