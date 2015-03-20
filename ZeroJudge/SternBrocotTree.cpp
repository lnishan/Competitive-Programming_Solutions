#include <iostream>

int lvl,no,path[31],pc,p[2][2],m[2],t[2];

inline int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar()) ;
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

void getPath(){
    int i;
    pc=0;
    for(i=2;i<lvl;i++)
    {
        path[pc++]=no%2;    // 0 for right
        no=(no+1)/2;
    }
}

int main(){
    int i;
    while(lvl=input(),no=input(),lvl!=0 && no!=0)
    {
        if(lvl<2)
            if(no-1)
                puts("1/0");
            else
                puts("0/1");
        else{
            p[0][0]=0; p[0][1]=1;
            p[1][0]=1; p[1][1]=0;
            m[0]=1; m[1]=1;
            getPath();
            for(i=pc-1;i>=0;i--)
            {
                t[0]=m[0]; t[1]=m[1];
                m[0]+=p[1-path[i]][0];
                m[1]+=p[1-path[i]][1];
                p[path[i]][0]=t[0];
                p[path[i]][1]=t[1];
            }
            printf("%d/%d\n",m[0],m[1]);
        }
    }
    return 0;
}
