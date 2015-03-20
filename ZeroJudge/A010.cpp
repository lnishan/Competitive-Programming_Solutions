#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a[100000][2], c, n, cn;
    while(cin>>n){
                  cn=n;
                  c=0;
                  for(int i=2;i<=sqrt(n);i++){
                          if (fmod(cn,i)==0){
                                             a[c][0]=i;
                                             for(int j=1;j<=(cn/i);j++){
                                                     if (fmod(cn, pow(i,j))!=0){
                                                                  a[c][1]=j-1;
                                                                  cn=cn/pow(i,j-1);
                                                                  break;
                                                     }
                                             }
                                             c+=1;
                          }
                  }
                  if(cn!=1){
                            a[c][0]=cn;
                            a[c][1]=1;
                            c+=1;
                  }
                  for(int i=0; i<=(c-1); i++){
                          if a[i][1]==1
    }
    system("pause");
    return 0;
}
