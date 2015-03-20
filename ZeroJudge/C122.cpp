/*
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream fout("C122.txt");
    long long int n=1;
    for(int i=1;;i++){if(n>2000000000){fout<<i;break;}fout<<n<<",";n*=2;}
    fout<<endl;n=1;
    for(int i=1;;i++){if(n>2000000000){fout<<i;break;}fout<<n<<",";n*=3;}
    fout<<endl;n=1;
    for(int i=1;;i++){if(n>2000000000){fout<<i;break;}fout<<n<<",";n*=5;}
    fout<<endl;n=1;
    for(int i=1;;i++){if(n>2000000000){fout<<i;break;}fout<<n<<",";n*=7;}
    return 0;
}
*/
#include<iostream>
#include<math.h>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main(){
    int p2[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
    int p3[20]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
    int p5[14]={1,5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625,1220703125};
    int p7[12]={1,7,49,343,2401,16807,117649,823543,5764801,40353607,282475249,1977326743};
    int a[5842],ac=0,n;
    for(int i=0;i<31;i++)
            for(int j=0;j<=int(log10(2000000000/double(p2[i]))/log10(3));j++)
                    for(int k=0;k<=int(log10(2000000000/double(p2[i]*p3[j]))/log10(5));k++)
                            for(int l=0;l<=int(log10(2000000000/double(p2[i]*p3[j]*p5[k]))/log10(7));l++)
                                    {a[ac]=p2[i]*p3[j]*p5[k]*p7[l];ac++;}
    qsort(a, ac, sizeof(int), compare);a[5841]=2000000000;
    while(scanf("%d",&n)&&n!=0)
    {
                               printf("The %d",n);
                               if(n%10==1&&(n%100)/10!=1)printf("st");else if(n%10==2&&(n%100)/10!=1)printf("nd");else if(n%10==3&&(n%100)/10!=1)printf("rd");else printf("th");
                               printf(" humble number is %d.\n",a[n-1]);
    }
    return 0;
}
