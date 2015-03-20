#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int n[19]={6,2,5,5,4,5,6,3,7,6,4,7,7,6,7,8,5,9};
    int p[27],c;
    for(int i=1;i<27;i++)p[i]=0;
    for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                             p[n[i]+n[j]+n[i+j]+4]++;}}
    ofstream fcout("output.txt");
    for(int i=1;i<27;i++)fcout<<p[i]<<",";
    return 0;
}
