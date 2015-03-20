#include <iostream>
#include <1044_Guess.h>

using namespace std;

int main(){
    int low=1, high=Initialize()+1, mid;
    while( high-low>1 )
    {
        mid=(low+high)/2;
        if( Guess(mid) )
        {
            if( !Guess(mid-1) )
                Report(mid);
            else
                high=mid;
        }
        else
            low=mid;
    }
    Report(low);
    return 0;
}