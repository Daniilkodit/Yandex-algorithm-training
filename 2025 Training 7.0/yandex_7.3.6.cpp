#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K;
    cin>>N>>K;

    int L = (N*N*N)/64;
    int ost = (N*N*N)%64;
    vector<unsigned long long> pole(L+1);
    int l = 0;
    unsigned long long mask = 1;
    unsigned long long sdvig = ((mask<<63)-1) + (mask<<63);
    unsigned long long ost_sd;
    if(ost == 63) ost_sd = sdvig;
    else ost_sd = (mask<<ost)-1;
    unsigned long long* ptr = pole.data();
    for(int i = 0;i<K;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        z--;
        for(int j = 0;j<N;j++)
        {
            ptr[(j*N*N+y*N+z)/64]|=(mask<<((j*N*N+y*N+z)%64));
            ptr[(x*N*N+j*N+z)/64]|=(mask<<((x*N*N+j*N+z)%64));
            ptr[(x*N*N+y*N+j)/64]|=(mask<<((x*N*N+y*N+j)%64));
        }
    }
    bool flag = true;
    int i;
    for(i = 0;i<L;i++)
    {
        if((pole[i]&sdvig)!=sdvig) {flag = false;break;}
    }
    if((pole[L]&ost_sd)==ost_sd && flag)
    {
        cout<<"YES";
        cout.flush();
    }
    else
    {
        cout<<"NO"<<endl;
        if(flag) i = L;
        int x,y,z;
        
        int l = 0;
        mask = 1;
        while(l<64)
        {

            if((pole[i]&mask)==0)break;
            l++;
            mask = (mask<<1);
        }
        i *= 64;
        i+=l;
        z = i%N;
        y = ((i-z)/N)%N;
        x = (i-z-N*y)/(N*N);
        cout<<x+1<<" "<<y+1<<" "<<z+1;
        cout.flush();
    }
}