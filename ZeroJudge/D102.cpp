#include<iostream>
using namespace std;
long int posb;
int n,a[100];
int p(int sidec,int ind,int edgec);
int p(int sidec,int ind,int edgec){
    sidec+=a[ind];
    edgec++;
    if(edgec>=2)
                for(int i=ind+1;i<n;i++) if(sidec>a[i])posb++;else break;
    for(int i=ind+1;i<n;i++) p(sidec,i,edgec);
    return 0;
}
int cmp(const void * a,const void * b);
int cmp(const void * a,const void * b){
    return (*(int*)a-*(int*)b);
}
int main(){
    char c;
    while(1)
    {
            n=posb=0;
            do
            {
                    while((c=getchar())==' '||c=='\n');
                    a[n]=c-48;
                    while((c=getchar())!=' '&&c!='\n')a[n]=a[n]*10+c-48;
                    n++;
            }while(c!='\n');
            if(n==1&&a[0]==0)break;
            qsort(a,n,sizeof(int),cmp);
            for(int i=0;i<n-2;i++) p(0,i,0);
            printf("%d\n",posb);
    }
    return 0;
}
