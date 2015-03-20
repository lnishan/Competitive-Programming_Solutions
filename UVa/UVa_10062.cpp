#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int a[1000][2],sl;
int main(){
    string s;
    while(getline(cin,s))
    {
                         int ac=0,ind;
                         sl=s.length();
                         for(int i=0;i<sl;i++){a[i][0]=0;a[i][1]=0;}
                         for(int i=0;i<sl;i++)
                         {
                                 ind=ac;
                                 for(int j=0;j<ac;j++) if(a[j][0]==s[i])ind=j;
                                 a[ind][0]=s[i];
                                 a[ind][1]++;
                                 if(ind==ac)ac++;
                         }
                         for(int i=ac-2;i>=0;i--)
                         {
                                 for(int j=0;j<=i;j++)
                                 {
                                         if(a[j][1]>a[j+1][1])
                                         {
                                                              a[j][0]+=a[j+1][0];a[j+1][0]=a[j][0]-a[j+1][0];a[j][0]-=a[j+1][0];
                                                              a[j][1]+=a[j+1][1];a[j+1][1]=a[j][1]-a[j+1][1];a[j][1]-=a[j+1][1];
                                         }else if(a[j][1]==a[j+1][1])
                                         {
                                               if(a[j][0]<a[j+1][0])
                                               {
                                                                    a[j][0]+=a[j+1][0];a[j+1][0]=a[j][0]-a[j+1][0];a[j][0]-=a[j+1][0];
                                                                    a[j][1]+=a[j+1][1];a[j+1][1]=a[j][1]-a[j+1][1];a[j][1]-=a[j+1][1];
                                               }
                                         }
                                 }
                         }
                         for(int i=0;i<ac;i++)printf("%d %d\n",a[i][0],a[i][1]);
                         printf("\n");
    }
    return 0;
}
