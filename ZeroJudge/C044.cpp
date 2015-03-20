#include<iostream>
#include<ctype.h>
using namespace std;
int main(){
    int al[26][2],alp[26],n,tn,ac=0,pos;
    for(int i=0;i<26;i++)al[i][1]=0;
    memset(alp,-1,sizeof(alp));
    scanf("%d",&n);tn=n;
    char c=getchar();
    for(int i=0;i<tn;i++)
    {
            while((c=getchar())!='\n')
            {
                                      if(isalpha(c))
                                      {
                                                    pos=alp[toupper(c)-65];
                                                    if(pos!=-1)
                                                    {
                                                                              al[pos][1]++;}
                                                    else
                                                    {
                                                                              alp[toupper(c)-65]=ac;
                                                                              al[ac][0]=toupper(c)-65;
                                                                              al[ac][1]=1;
                                                                              ac++;
                                                    }
                                      }
            }
    }
    for(int i=24;i>=0;i--)
    {
            for(int j=0;j<=i;j++)
            {
                    if(al[j][1]<al[j+1][1])
                    {
                                           al[j][0]+=al[j+1][0];al[j+1][0]=al[j][0]-al[j+1][0];al[j][0]-=al[j+1][0];
                                           al[j][1]+=al[j+1][1];al[j+1][1]=al[j][1]-al[j+1][1];al[j][1]-=al[j+1][1];
                    }else if(al[j][1]==al[j+1][1])
                    {
                          if(al[j][0]>al[j+1][0])
                          {
                                                 al[j][0]+=al[j+1][0];al[j+1][0]=al[j][0]-al[j+1][0];al[j][0]-=al[j+1][0];
                                                 al[j][1]+=al[j+1][1];al[j+1][1]=al[j][1]-al[j+1][1];al[j][1]-=al[j+1][1];
                          }
                    }
            }
    }
    for(int i=0;i<26;i++)
            if(al[i][1]!=0)printf("%c %d\n",char(al[i][0]+65),al[i][1]);else break;
    return 0;
}
