#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
int main()
{
    unsigned int N,mask = 1,Nmax = N;
    cin>>N;
    unsigned int N1 = N;
    unsigned int q=1;
    while(q<=N) q = q<<1;
    q = q>>1;
    if(N==0){cout<<0<<endl; return 0;}
    do
    {
        if(N&mask == 1)
        {
            N =N>>1;
            N|= q;
        }
        else N =N>>1;
        if(Nmax< N) Nmax = N;
    } while (N1!=N);
    cout<<Nmax;
}