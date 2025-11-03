#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);        
    int flag;
    cin>>flag;
    if(flag==1)
    {
        string s;
        cin>>s;
        int N = s.size();
        int K=2;
        while((1<<K)<N+K+1) K++;
        string s0;
        int cnt =0;
        for(unsigned int i =1;i<=N+K;i++)
        {
            if((i&(i-1))==0)
            {
                s0+='0';
            }
            else {s0+=s[cnt];cnt++;}
        }
        unsigned int mask = 1;
        for(int i=0;i<K;i++)
        {
            int count = 0;
            for(unsigned int j = mask;j<=N+K;j+=mask)
            {
                for(unsigned int k = 0;k<mask;k++)
                {
                    if((j-1)+k<N+K && s0[(j-1)+k]=='1') count++;
                    if((j-1)+k>=N+K) break;
                }
                j+=mask;
            }
            if(count%2==0) s0[mask-1] = '1';
            mask = (mask<<1);
        }
        cout<<s0<<endl;
    }
    else
    {
        string s2;
        cin>>s2;
        int K = log2(s2.size())+1;
        unsigned int mask = 1;
        unsigned bit = 0;
        for(int i=0;i<K;i++)
        {
            int count = 0;
            for(unsigned int j = mask;j<=s2.size();j+=mask)
            {
                for(unsigned int k = 0;k<mask;k++)
                {
                    if((j-1)+k<s2.size() && s2[(j-1)+k]=='1') count++;
                    if((j-1)+k>=s2.size()) break;
                }
                j+=mask;
            }
            if(count%2==0) bit|=mask;
            mask = (mask<<1);
        }
        if(bit!=0)
        {
            if(s2[bit-1]=='1') s2[bit-1] = '0';
            else s2[bit-1] = '1';
        }
        string q;
        for(int i =1;i<=s2.size();i++)
        {
            if((i&(i-1))!=0) q+=s2[i-1];
        }
        cout<<q<<endl;
    }
}