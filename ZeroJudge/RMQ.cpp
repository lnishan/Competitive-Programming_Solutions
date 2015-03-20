#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n,q,M[500000][20],a,b,t,two[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

int main() {
    n=input();
    for(int i=0;i<n;i++)
        M[i][0]=input();
    for (int i=1;two[i]<=n;i++)
	   for (int j=0;j+two[i]-1<n;j++)
	       M[j][i]=max(M[j][i-1],M[j+two[i-1]][i-1]);
    q=input();
    for(int k=0;k<q;k++)
    {
	   a=input();
	   b=input();
	   if(a>b) swap(a,b);
	   a--; b--;
	   t=(int)(log(b-a+1)/log(2));
	   printf("%d\n",max(M[a][t],M[b-two[t]+1][t]));
    }
    return 0;
}
