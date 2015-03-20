#include<iostream>
#include<string>
using namespace std;
int n,m,wn;
int main(){
    while(cin>>n>>m && (n!=0 || m!=0))
    {
                    string ts,s="",sf="";
                    for(int i=0;i<n;i++){
                            cin>>ts;
                            s+=ts;
                    }
                    for(int j=0;j<m;j++){
                            cin>>wn;
                            sf+=s[wn-1];
                    }
                    cout << sf << endl;
    }
    return 0;
}
