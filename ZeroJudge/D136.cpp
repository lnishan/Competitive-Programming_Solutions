#include<iostream>
long long int input();
unsigned long long int in1[1000000],in2[1000000];
int main(){
    int n,m,count;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            count=0;
            for(int j=0;j<m;j++)in1[j]=input();
            for(int j=0;j<m;j++)in2[j]=input();
            for(int j=0,k=0;j<m&&k<m;)
            {
                if(in1[j]>in2[k]) k++;
                if(in1[j]==in2[k]) {count++; k++; j++;}
                if(in1[j]<in2[k])  j++;
            }
            printf("%d\n",count);
        }
    }
    return 0;
}
long long int input(){
  char cha;
  unsigned long long int x=0;
  while((cha=getchar())==' '||cha=='\n');
  x=cha-48;
  while((cha=getchar())!=' '&&cha!='\n')
    x=x*10+cha-48;
  return x;
}
