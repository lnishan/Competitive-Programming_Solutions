#include<iostream>
using namespace std;
int a[9][9], n[10];
bool chk;
int main(){
    while(cin>>a[0][0]>>a[0][1]>>a[0][2]>>a[0][3]>>a[0][4]>>a[0][5]>>a[0][6]>>a[0][7]>>a[0][8]){
      chk=true;
      for(int i=1;i<9;i++){
              for(int j=1;j<10;j++)
                      n[j]=0;
              for(int j=0;j<9;j++){
                      cin >> a[i][j];
                      n[a[i][j]]=1;
              }
              for(int j=1;j<10;j++){
                      if(n[j]==0){
                                  chk=false;
                                  break;
                      }
              }
      }
      for(int j=0;j<9;j++){
              for(int i=1;i<10;i++)
                      n[i]=0;
              for(int i=0;i<9;i++)
                      n[a[i][j]]=1;
              for(int i=1;i<10;i++){
                      if(n[i]==0){
                                  chk=false;
                                  break;
                      }
              }
      }
      for(int i=0;i<=6;i+=3){
                        for(int j=0;j<=6;j+=3){
                                           for(int k=1;k<10;k++)
                                                   n[k]=0;
                                           n[a[i][j]]=1;
                                           n[a[i+1][j]]=1;
                                           n[a[i+2][j]]=1;
                                           n[a[i][j+1]]=1;
                                           n[a[i+1][j+1]]=1;
                                           n[a[i+2][j+1]]=1;
                                           n[a[i][j+2]]=1;
                                           n[a[i+1][j+2]]=1;
                                           n[a[i+2][j+2]]=1;
                                           for(int k=1;k<10;k++){
                                                   if(n[k]==0){
                                                               chk=false;
                                                               break;
                                                   }
                                           }
                        }
      }
      cout << ((chk==false)?"no":"yes") <<endl;
    }
    system("pause");
    return 0;
}
      
    
