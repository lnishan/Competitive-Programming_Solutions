#include<iostream>

using namespace std;

int a[26][26][26][26],z[100000][4],zc;

int main(){
    int n,ct,i,j;
    char s[5];
    memset(a,0,sizeof(a));
    while(scanf("%d",&n)==1)
    {
        getchar();
        ct = zc = 0;
        for(i=0;i<n;i++)
        {
            gets(s);
            if(a[s[0]-97][s[1]-97][s[2]-97][s[3]-97]==0){
                a[s[0]-97][s[1]-97][s[2]-97][s[3]-97]=++ct;
                printf("New! %d\n",ct);
                
                for(j=0;j<4;j++) z[zc][j]=s[j]-97;
                zc++;
            }else
                printf("Old! %d\n",a[s[0]-97][s[1]-97][s[2]-97][s[3]-97]);
        }
        for(i=0;i<zc;i++)
            a[z[i][0]][z[i][1]][z[i][2]][z[i][3]]=0;
    }
    return 0;
}