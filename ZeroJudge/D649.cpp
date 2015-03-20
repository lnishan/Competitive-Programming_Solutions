#include<iostream>
using namespace std;
inline void print(int n,char ch){
     for(int i=0;i<n;i++)putchar(ch);
}
int main(){
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
         for(int i=1;i<=n;i++)
         {
                 print(n-i,'_');
                 print(i,'+');
                 putchar('\n');
         }
         putchar('\n');
    }
    return 0;
}
