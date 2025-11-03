#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int p = 1,q = 0;
    while(p<N){p*=2;q++;}
    if(q==0)
    {
        int ch;
        cin>>ch;
        int q;
        cin>>q;
        for(int i = 0;i<q;i++)
        {
            int L,R;
            cin>>L;
            cin>>R;
            cout<<ch<<" "<<1<<endl;
        }
        return 0;
    }
    vector<vector<pair<int,int>>> rtable(q,vector<pair<int,int>>(N,{-1,-1}));
    for(int i = 0;i<N;i++)
    {
        cin>>rtable[0][i].first;
        rtable[0][i].second = i;
    }
    
    int sdvig = 1;
    for(int i = 1;i<q;i++)
    {
        for(int j = 0;j+sdvig<N;j++)
        {
            if(rtable[i-1][j+sdvig].first==-1) break;
            if(rtable[i-1][j].first<rtable[i-1][j+sdvig].first)
            {
                rtable[i][j] = rtable[i-1][j+sdvig];
            }
            else
            {
                rtable[i][j] = rtable[i-1][j];
            }
        }
        sdvig*=2;
    }
    vector<int> deg_2(N+1);
    int k = 0;
    for(unsigned int i = 2;i<N+1;i++)
    {
        if((i&(i-1))==0) k++;
        deg_2[i] = k;
    }
    vector<int> apow(q+1,1);
    for(int i = 0;i<q;i++)
    {
        apow[i+1] = apow[i]*2;
    }
    int K;
    cin>>K;
    for(int i =0;i<K;i++)
    {
        int L,R;
        cin>>L>>R;
        if(L==R) {cout<<rtable[0][L-1].first<<" "<<L<<endl;continue;}
        L--;
        R--;
        
        int deg = deg_2[R-L];
        if(rtable[deg][L].first<rtable[deg][R-apow[deg]+1].first)
        {
            cout<<rtable[deg][R-apow[deg]+1].first<<" "<<rtable[deg][R-apow[deg]+1].second+1<<endl;
        }
        else cout<<rtable[deg][L].first<<" "<<rtable[deg][L].second+1<<endl;
    }
}