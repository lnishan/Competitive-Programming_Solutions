#include <iostream>

using namespace std;

int i,a[200000][4],ans; // 0:no. 1:left 2:right 3:count
char c;
bool inputEnd=false,found=false;

int input(){
    for(c=getchar();c<48||c>57;c=getchar()) if(c=='\n'){inputEnd=true; return 0;}
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

void insert(int ind){
    if(a[ind][0]==a[i][0]){
        a[ind][3]++;
        found=true;
    }else if(a[ind][0]>a[i][0]){
        if(a[ind][1]==0)
            a[ind][1]=i;
        else
            insert(a[ind][1]);
    }else if(a[ind][0]<a[i][0]){
        if(a[ind][2]==0)
            a[ind][2]=i;
        else
            insert(a[ind][2]);
    }
}

int main(){
    memset(a,0,sizeof(a));
    a[0][0]=input();
    for(i=1;;i+=1-found)
    {
        a[i][0]=input();
        if(inputEnd) break;
        found=false;
        insert(0);
        if(c=='\n') break;
    }
    for(int j=0;j<i;j++)
        if(a[j][3]<2){ printf("%d",a[j][0]); break; }
    return 0;
}
