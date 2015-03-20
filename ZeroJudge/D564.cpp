#include<iostream>
#include<string>
using namespace std;
string lang;
int n;
int main(){
    while(cin>>lang>>n)
    {
                       if(lang=="C")
                            cout<<"\"C\" can use printf(\"%d\",n); to show integer like "<<n<<"."<<endl;
                       else if(lang=="C++")
                            cout<<"\"C++\" can use cout<<n; to show integer like "<<n<<"."<<endl;
                       else if(lang=="Java")
                            cout<<"\"Java\" can use System.out.print(n); to show integer like "<<n<<"."<<endl;
                       else if(lang=="Pascal")
                            cout<<"\"Pascal\" can use Write(n); to show integer like "<<n<<"."<<endl;
                       else if(lang=="Basic")
                            cout<<"\"Basic\" can use Print n to show integer like "<<n<<"."<<endl;
    }
    return 0;
}
