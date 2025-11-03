#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
int main()
{
    long long N,count = 0;
    cin>>N;
    while(1)
    {
        count += N%2;
        N /=2;
        if(N==1) {count++; break;}
        if(N==0) break;
    }
    cout<<count<<endl;
}
