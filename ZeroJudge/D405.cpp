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
                    cout<<"��!!!�ۿ���"<<i<<"���k�ͪ��Z�Ůy���F��!!"<<endl;
            }else{
                  cout<<"��"<<i<<"���k��  ��"<<cl<<"�Z����"<<no<<"��  ���Z��"<<a[cl][no];
                  if(a[cl][no]>=90)cout<<" ���Z�u"; else if(a[cl][no]<60)cout<<" ���ή�r~~";
                  cout<<endl;
            }
    }
    return 0;
}
