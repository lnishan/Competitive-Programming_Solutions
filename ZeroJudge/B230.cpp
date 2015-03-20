/*
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int main(){
    ofstream o("b230.txt");
    int c=0;double n;
    string s="";
    for(int i=1;c<65;i++)
    {
                 bool chk=true;
                 for(int j=1;j<=(i-1)/2;j++)
                 {
                         for(int k=j+1;k<=(i-1)/2;k++)
                         {
                                 n=double(i-j*k)/double(j+k);
                                 if(floor(n)==n && n!=j && n!=k && n>0){chk=false;break;}
                         }
                         if(chk==false)break;
                 }
                 if(chk){o<<i<<",";c++;}
    }
    system("pause");
    return 0;
}
*/
#include<iostream>
using namespace std;
int main(){
    unsigned int n,a[65]={1,2,3,4,5,6,7,8,9,10,12,13,15,16,18,21,22,24,25,28,30,33,37,40,42,45,48,57,58,60,70,72,78,85,88,93,102,105,112,120,130,133,165,168,177,190,210,232,240,253,273,280,312,330,345,357,385,408,462,520,760,840,1320,1365,1848};
    scanf("%d",&n);
    printf("%d",a[n-1]);
    return 0;
}
                 
