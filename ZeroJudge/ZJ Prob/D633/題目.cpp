#include<iostream>
#include<iomanip>
#include<math.h>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("testdata.in");
    ofstream fout("testanswer.out");
    int n,m;
    while(fin>>n>>m) fout<<fixed<<setprecision(5)<<n*4*acos(0)<<endl;
    return 0;
}
