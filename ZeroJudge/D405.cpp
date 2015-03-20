#include<iostream>
using namespace std;
int main(){
    int a[5001][31],n,m,grl,cl,no;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            cin>>m;
            a[i][0]=m;
            for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    cin>>grl;
    for(int i=1;i<=grl;i++)
    {
            cin>>cl>>no;
            if(no<1 || no>a[cl][0])
            {
                    cout<<"啊!!!抄錯第"<<i<<"號女生的班級座號了啦!!"<<endl;
            }else{
                  cout<<"第"<<i<<"號女生  第"<<cl<<"班的第"<<no<<"號  成績為"<<a[cl][no];
                  if(a[cl][no]>=90)cout<<" 成績優"; else if(a[cl][no]<60)cout<<" 不及格呀~~";
                  cout<<endl;
            }
    }
    return 0;
}
