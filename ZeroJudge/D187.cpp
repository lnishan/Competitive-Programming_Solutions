#include<iostream>
using namespace std;
int main(){
    string s;
    int ds,t[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    scanf("%d",&ds);char c=getchar();
    for(int i=0;i<ds;i++)
    {
            int tc=0;
            while((c=getchar())!='\n') if(c==' ')tc++;else tc+=t[c-97];
            printf("Case #%d: %d\n",i+1,tc);
    }
    return 0;
}
