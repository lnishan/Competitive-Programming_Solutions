#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long int n,t;
    while(cin>>n){
                  t=0;
                  for(int i=1;i<=sqrt(n);i++){
                          if(fmod(n,i)==0)
                                           t=t+((i==1)?(1):(i+n/i));
                  }
                  if(sqrt(n)==int(sqrt(n))) t-=sqrt(n);
                  if(t>n){
                          cout << "�ռ�" << endl;
                  }else if(t==n){
                        cout << "������" << endl;
                  }else{
                       cout << "����" << endl;
                  }
    }
    return 0; 
}
