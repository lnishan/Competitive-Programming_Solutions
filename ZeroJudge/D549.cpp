#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    long long int a,b,c;
    while(cin>>a>>b>>c) cout << fixed << setprecision(2) << sqrt(pow(a,2)+pow(c,2)-pow(b,2)) << endl;
    return 0;
}
