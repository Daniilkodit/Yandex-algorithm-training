#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define Max(a,b) a<b ? b:a
using namespace std;
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> a(N);
    vector<int> mas(M+1,-1);
    mas[0] = 0;
    for(int i = 0;i<N;i++)
    {
        cin>>a[i];
    }
    for(int i = 0 ;i<N;i++)
    {
        for(int j = M-a[i];j>=0;j--)
        {
            if(mas[j]!=-1)
            {
                mas[j+a[i]] = Max(mas[j]+a[i],mas[j+a[i]]);
            }

        }
    }
    int amax = 0;
    for(int i = 0;i<M+1;i++)
    {
        amax = Max(amax,mas[i]);
    }
    cout<<amax<<endl;
}
