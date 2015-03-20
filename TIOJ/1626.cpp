#include <stdio.h>

unsigned int range[1000000];

int BSearch(int n, int high){
    int low=1, mid;
    while( high-low>1 )
    {
        mid=(low+high)/2;
        if( range[mid]>n )
            high=mid;
        else
            low=mid;
    }
    return low;
}

int main(){
    int i;
    unsigned int n;
    range[1]=1;
    for(i=2; i<1000000; i++)
        range[i] = range[i-1] + BSearch(i-1, i);
    while( scanf("%u", &n), n>0 )
        printf("%d\n", BSearch(n,1000000));
    return 0;
}