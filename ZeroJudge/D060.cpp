#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n)
                  cout << (((25-n)<0)?(85-n):(25-n)) << endl;
    return 0;
}
