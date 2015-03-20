#include <iostream>

using namespace std;

const int MAX=1000;

long long int sumA[MAX][MAX],sumB[MAX][MAX],n;

inline long long int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar()) ;
    long long int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

int main(){
    int i,j;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%I64d",&sumA[i][i]);
        sumB[i][i]=0;
    }
    for(i=2;i<=n;i++)
        for(j=0;j<=n-i;j++)
            if(i%2){
                if(sumA[j][j+i-2]+sumA[j+i-1][j+i-1] > sumA[j+1][j+i-1]+sumA[j][j]){
                    sumA[j][j+i-1]=sumA[j][j+i-2]+sumA[j+i-1][j+i-1];
                    sumB[j][j+i-1]=sumB[j][j+i-2];
                }else{
                    sumA[j][j+i-1]=sumA[j+1][j+i-1]+sumA[j][j];
                    sumB[j][j+i-1]=sumB[j+1][j+i-1];
                }
            }else{
                if(sumB[j][j+i-2]+sumA[j+i-1][j+i-1] > sumB[j+1][j+i-1]+sumA[j][j]){
                    sumA[j][j+i-1]=sumA[j][j+i-2];
                    sumB[j][j+i-1]=sumB[j][j+i-2]+sumA[j+i-1][j+i-1];
                }else{
                    sumA[j][j+i-1]=sumA[j+1][j+i-1];
                    sumB[j][j+i-1]=sumB[j+1][j+i-1]+sumA[j][j];
                }
            }
    if(n%2==0) swap(sumA[0][n-1],sumB[0][n-1]);
    printf("%I64d %I64d",sumA[0][n-1],sumB[0][n-1]);
    while(1);
    return 0;
}