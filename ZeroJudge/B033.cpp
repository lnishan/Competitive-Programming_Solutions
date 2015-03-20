#include<iostream>
using namespace std;
int main(){
    long int m,n;int p,r,turn,ten[]={1,10,100,1000,10000};
    while(scanf("%d%d%d%d",&m,&n,&p,&r) &&(m!=0||n!=0||p!=0||r!=0))
    {
                                        if(m>n)turn=1;else if(m<n)turn=0;else turn=-1;
                                        for(int i=0;i<r;i++)
                                        {
                                                if(turn==1)n=(n*m)%ten[p];
                                                else m=(m*n)%ten[p];
                                                if(turn==-1||turn==2)n=m;
                                                turn=1-turn;
                                        }
                                        if(turn==0)printf("The ghost of childish won the game with %d.\n",n);
                                        else if(turn==1)printf("The king of childish won the game with %d.\n",m);
                                        else printf("Draw with %d.\n",m);
    }
    return 0;
}
