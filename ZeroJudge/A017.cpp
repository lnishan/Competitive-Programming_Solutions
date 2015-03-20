#include <iostream>
#include <math.h>

using namespace std;

struct data{
    bool type;
    int n;
};
data a[1000];
int ac;
char s[10000],*ptr;

int findMatch(int s){
    int mst=1;
    for(int i=s;i<ac;i++)
    {
        if(!a[i].type){
            if(a[i].n=='(')
                mst++;
            else if(a[i].n==')')
                mst--;
            if(mst==0) return i;
        }
    }
    return -1;
}

int process(int s,int e){
    int stk1[1000],stk2[1000],top1=-1,top2=-1,n,rpos;
    for(int i=s;i<=e;i++)
        if(a[i].type || (!a[i].type && a[i].n=='(')){
            if(a[i].type)
                n=a[i].n;
            else{
                rpos=findMatch(i+1);
                n=(a[i].type)?a[i].n:process(i+1,rpos-1);
                i=rpos;
            }
            if(top2>=0)
                if(stk2[top2]=='*'){
                    top2--;
                    stk1[top1]*=n;
                }else if(stk2[top2]=='/'){
                    top2--;
                    stk1[top1]/=n;
                }else if(stk2[top2]=='%'){
                    top2--;
                    stk1[top1]%=n;
                }else stk1[++top1]=n;
            else
                stk1[++top1]=n;
        }else
            stk2[++top2]=a[i].n;
    n=stk1[0];
    for(int i=0;i<=top2;i++)
        if(stk2[i]=='+')
            n+=stk1[i+1];
        else
            n-=stk1[i+1];
    return n;
}

int main(){
    while(gets(s))
    {
        ac=0;
        ptr=strtok(s," ");
        while(ptr!=NULL)
        {
            if(isdigit(ptr[0])){
                a[ac].type=true;
                a[ac++].n=atoi(ptr);
            }else{
                a[ac].type=false;
                a[ac++].n=ptr[0];
            }
            ptr=strtok(NULL," ");
        }
        printf("%d\n",process(0,ac-1));
    }
    return 0;
}
