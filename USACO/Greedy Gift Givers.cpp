/*
ID: linisha1
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
int m[10],n,a,b;
string name[10],gi,re;
int reInd(string sn);
int reInd(string sn){
    int ind;
    for(int i=0;i<n;i++)if(name[i]==sn){ind=i;break;}
    return ind;
}
int main(){
    memset(m,0,sizeof(m));
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    fin>>n;
    for(int i=0;i<n;i++)fin>>name[i];
    for(int i=0;i<n;i++)
    {
            fin>>gi;
            fin>>a>>b;
            if(a!=0)
            {
                    for(int j=0;j<b;j++)
                    {
                            fin>>re;
                            m[reInd(re)]+=(a/b);
                    }
                    m[reInd(gi)]-=(a/b*b);
            }else for(int j=0;j<b;j++)fin>>re;
    }
    for(int i=0;i<n;i++)fout<<name[i]<<" "<<m[i]<<endl;
    return 0;
}
