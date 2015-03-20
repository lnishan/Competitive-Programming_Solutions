#include<iostream>
using namespace std;
int cdegree,n1,n2,n3;
int main(){
    while(cin>>cdegree>>n1>>n2>>n3 && (cdegree!=0 || n1!=0 || n2!=0 || n3!=0))
    {
                                   int c=1080;
                                   c+=(40-((n1-cdegree>=0)?n1-cdegree:n1-cdegree+40))*9;
                                   c+=(40-((n1-n2>=0)?n1-n2:n1-n2+40))*9;
                                   c+=(40-((n3-n2>=0)?n3-n2:n3-n2+40))*9;
                                   cout << c << endl;
    }
    return 0;
}
