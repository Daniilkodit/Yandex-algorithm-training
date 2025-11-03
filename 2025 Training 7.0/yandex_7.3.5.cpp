#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    unsigned int x,y,c;
    cin>>x>>y;
    cout<<(x^y)<<endl;
    cin>>x>>c;
    unsigned res = 0,mask = 1;
    while(mask<=x && mask<=c)
    {
        if(((c&mask)==0 && (x&mask)!=0) || ((c&mask)!=0 && (x&mask)==0) )
        {
            res |= mask;
        }
        mask = mask<<1;
    }
    while(mask<=x)
    {
        if((mask&x)!=0)
            res |= mask;
        mask = mask<<1;
    }
    while(mask<=c)
    {
        if((mask&c)!=0)
            res |= mask;
        mask = mask<<1;
    }
    cout<<res<<endl;


}