#include<iostream>
using namespace std;
int main(){
    int a[50],ans[50],ac,n;
    char c[200];
    char *ptr;
    while(1)
    {
            ac=0;
            gets(c);
            ptr=strtok(c," ");
            bool chk=true;
            while(ptr!=NULL)
            {
                n=atoi(ptr);
                if(n==-1){chk=false;break;}
                a[ac++]=n;
                ptr=strtok(NULL," ");
            }
            if(ac>0&&(chk))
            {
                    memset(ans,0,sizeof(ans));
                    for(int i=0;i<ac;i++)
                    {
                            int ct=0;
                            for(int j=0;j<ac;j++)
                            {
                                         if(ct==a[i]&&ans[j]==0){ans[j]=i+1;break;}
                                         if(ans[j]==0)ct++;
                            }
                    }
                    for(int i=0;i<ac;i++)
                    {
                            if(i!=0)putchar(' ');
                            printf("%d",ans[i]);
                    }
            }else if(!chk)break;
            putchar('\n');
    }
    return 0;
}
