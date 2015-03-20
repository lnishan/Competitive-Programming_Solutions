#include <iostream>

using namespace std;

int t,n,an[10][6],a[4],ac,bc,ct;
char s[100];
bool valid;

void countAB(int ind){
    int i,j;
    ac=bc=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(an[ind][i]==a[j])
                if(i==j) ac++;
                else bc++;
}

bool checkValid(){
    int i,j;
    for(i=0;i<4;i++)
        for(j=i+1;j<4;j++)
            if(a[i]==a[j])
                return false;
    return true;
}

int main(){
    scanf("%d",&t);
    int d,i,j,k,l,m;
    for(d=0;d<t;d++)
    {
        ct=0;
        scanf("%d\n",&n);
        for(i=0;i<n;i++)
        {
            gets(s);
            an[i][4]=s[5]-48;
            an[i][5]=s[7]-48;
            for(j=0;j<4;j++)
                an[i][j]=s[j]-48;
        }
        for(i=0;i<10;i++)
        {
            a[0]=i;
            for(j=0;j<10;j++)
            {
                a[1]=j;
                for(k=0;k<10;k++)
                {
                    a[2]=k;
                    for(l=0;l<10;l++)
                    {
                        a[3]=l;
                        if(checkValid()){
                            valid=true;
                            for(m=0;m<n;m++)
                            {
                                countAB(m);
                                if(ac!=an[m][4] || bc!=an[m][5]){
                                    valid=false;
                                    break;
                                }
                            }
                            if(valid) ct++;
                        }
                    }
                }
            }
        }
        if(ct>0)
            printf("%d\n",ct);
        else
            puts("You Cheat!");
    }
    return 0;
}
