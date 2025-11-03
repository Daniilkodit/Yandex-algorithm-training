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
    vector<vector<int>> a(N,vector<int>(2,0));
    vector<int>mas(M+1);
    mas[0] = 0;
    for(int i = 0;i<N;i++)
    {
        cin>>a[i][0];
    }
    for(int i = 0;i<N;i++)
    {
        cin>>a[i][1];
    }
    
    for(int i = 0 ;i<N;i++)
    {
        for(int j = M-a[i][0];j>=0;j--)
        {
            if(mas[j]!=-1)
            {
                mas[j+a[i][0]] = Max(mas[j]+a[i][1],mas[j+a[i][0]]);
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
