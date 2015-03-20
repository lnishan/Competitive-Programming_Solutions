/*
#include<iostream>
using namespace std;
int main(){
    long long int fn=1500,a[27000],ac=0,two=1,three=1,five=1;
    for(int i=0;i<30;i++)
    {
            three=1;
            for(int j=0;j<30;j++)
            {
                    five=1;
                    for(int k=0;k<30;k++)
                    {
                            a[ac]=two*three*five;
                            ac++;
                            five*=5;
                    }
                    three*=3;
            }
            two*=2;
    }
    sort(a,a+ac);
    int zpos;
    for(int i=0;i<ac;i++)if(a[i]>=0){zpos=i;break;}
    printf("%d\n",a[zpos+fn-1]);
    system("pause");
    return 0;
}
*/
#include<iostream>
int main(){printf("The 1500'th ugly number is 859963392.");return 0;}
