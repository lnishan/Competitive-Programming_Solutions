#include<iostream>
using namespace std;
int n, l, w, k, tx, ty, a[10][10];
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
    {
            cin >> w >> l;
            for(int j=0;j<=l+2;j++){
                    for(int jj=0;jj<=w+2;jj++){
                            a[j][jj]=0;
                    }
            }
            cin >> k;
            for(int j=0;j<k;j++){cin >> tx >> ty; a[tx][ty]=-1;}
            unsigned long long int psb=1;
            bool allm1=true;
            for(int x=1;x<=l+1;x++){
                    for(int y=1;y<=w+1;y++){
                            if(a[x][y]!=-1){
                                            int tmp=0;
                                            a[x][y]=1;
                                            if(a[x+1][y]==1) tmp++;
                                            if(a[x-1][y]==1) tmp++;
                                            if(a[x][y+1]==1) tmp++;
                                            if(a[x][y-1]==1) tmp++;
                                            if(tmp!=4) psb*=(4-tmp);
                                            allm1=false;
                            }
                    }
            }
            cout << "Case " << i+1 << ": " << ((allm1==true)?0:psb) << endl;
    }
    return 0;
}
