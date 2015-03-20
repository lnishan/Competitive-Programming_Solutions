#include<iostream>
using namespace std;
int main(){
    for(int i=3;i<1001;i++)
    {
            for(int j=i+1;j<1000-i;j++)
            {
                    if(i*i+j*j==(1000-i-j)*(1000-i-j)) cout << i<<" "<<j<<endl; else if(i*i+j*j>(1000-i-j)*(1000-i-j)) break;
            }
    }
    cout<<200*375*425;
    system("pause");
    return 0;
}
