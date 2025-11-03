#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    int N,K;
    cin>>N>>K;
    vector< long int> t(N);
    vector<int> a(N);
    for( int i = 0;i<K;i++)
    {
        char s;
        int l,r;
        cin>>s>>l>>r;
        if(s=='A')
        {
            l--;
            for(unsigned int j = l;j<N;j|=(j+1))
            {
                t[j] += r-a[l];
            }
            a[l] = r;
        }
        else
        {
            l--;
            r--;
            long int sum = 0;
            unsigned int j = r;
            while(1)
            {
                sum += t[j];
                j = j&(j+1);
                if(j == 0) break;
                else j--;
            }
            if(l != 0)
            {
                j = l-1;
                while(1)
                {
                    sum -= t[j];
                    j = j&(j+1);
                    if(j == 0) break;
                    else j--;
                }
            }
            cout<<sum<<endl;
        }
    }
}