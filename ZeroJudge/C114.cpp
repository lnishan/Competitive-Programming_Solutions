#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
int main(){
    int k,e,maxExCt,dc=0,mct;
    string keys[20],maxEx[20],s,ts;
    while(scanf("%d %d",&k,&e)!=EOF)
    {
                    dc++;
                    getline(cin,keys[0]);
                    for(int i=0;i<k;i++)getline(cin,keys[i]);
                    maxExCt=-1;
                    for(int i=0;i<e;i++)
                    {
                            getline(cin,s);
                            ts=s;
                            for(int j=0;j<s.length();j++)s[j]=tolower(s[j]);
                            int ExCt=0,cPos;
                            for(int j=0;j<k;j++)
                            {
                                    cPos=0;
                                    while(s.find(keys[j],cPos)!=string::npos)
                                    {
                                         cPos=s.find(keys[j],cPos)+1;
                                         if(isalpha(s[cPos-2])==false)ExCt++;
                                    }
                            }
                            if(ExCt>maxExCt)
                            {
                                            maxExCt=ExCt;
                                            maxEx[0]=ts;
                                            mct=1;
                            }else if(ExCt==maxExCt)
                            {
                                  maxEx[mct]=ts;
                                  mct++;
                            }
                    }
                    printf("Excuse Set #%d\n",dc);
                    for(int i=0;i<mct;i++) cout<<maxEx[i]<<endl;
                    cout<<endl;
    }
    return 0;
}
