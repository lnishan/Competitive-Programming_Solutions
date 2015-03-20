/*
ID: linisha1
PROG: friday
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int am[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},wk[7];
    memset(wk,0,sizeof(wk));
    int n,dc=0;
    fin>>n;
    for(int yr=1900;yr<=1900+n-1;yr++)
    {
                        if((yr%4==0 && yr%100!=0)||(yr%400==0)) am[2]=29; else am[2]=28;
                        for(int mm=1;mm<=12;mm++)
                        {
                                wk[(dc+15)%7]++;
                                dc+=am[mm];
                        }
    }
    for(int i=1;i<7;i++)fout<<wk[i]<<" ";
    fout<<wk[0]<<endl;
    return 0;
}
