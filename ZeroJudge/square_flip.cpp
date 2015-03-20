#include<iostream>
using namespace std;
int main(){
    int r,c;
    while(cin>>r>>c){
                     int a[r][c];
                     for(int i=0;i<r;i++){
                             for(int j=0;j<c;j++){
                                     cin >> a[i][j];
                             }
                     }
                     for(int i=0;i<c;i++){
                             for(int j=0;j<r;j++){
                                     if(j==0){
                                              cout << a[j][i];
                                     }else{
                                           cout << " " << a[j][i];
                                     }
                             }
                             cout << endl;
                     }
                     cout << endl;
    }
    return 0;
}
