#include<iostream>
#include<fstream>
using namespace std;
int main(){
    long long int t[33];
    ofstream fout("two.txt");
    t[0]=1;fout<<"t[33]={0";
    for(int i=1;i<33;i++){t[i]=t[i-1]*2;fout<<","<<t[i];}
    fout<<"};";
    return 0;
}
    
