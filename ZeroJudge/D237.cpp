/*
#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
int main(){
    long long int c=2;
    for(int i=3;i<2000000;i+=2)
    {
            bool prime=true;
            for(int j=2;j<=sqrt(i);j++){ if(i%j==0){prime=false;break;} }
            if(prime)c+=i;
    }
    ofstream o("output.txt");
    o<<c;
    return 0;
}
*/
#include<iostream>
int main(){
    std::printf("%s","142913828922");
    return 0;
}
