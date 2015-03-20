#include<iostream>
using namespace std;
int m,n,cans[100],ta[100],t;
int main(){
    while(cin>>m>>n)
    {
                    long long int f=0;
                    for(int i=0;i<n;i++) cin>>cans[i];
                    for(int i=0;i<n;i++)
                    {
                            for(int j=0;j<m;j++)
                                    cin >> ta[j];
                                    
                            for(int k=m-2;k>=m-1-cans[i];k--)
                            {
                                    for(int l=0;l<=k;l++)
                                    {
                                            if(ta[l]>ta[l+1]) {t=ta[l]; ta[l]=ta[l+1]; ta[l+1]=t;}
                                    }
                            }
                            for(int j=m-1;j>=m-cans[i];j--)
                                    if(ta[j]>0) f+=ta[j]; else break;
                    }
                    cout << f << endl;
    }
    return 0;
}
                                    
