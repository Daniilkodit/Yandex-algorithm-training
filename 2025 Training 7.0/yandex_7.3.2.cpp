#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
int main()
{
    int N;
    cin>>N;
    //vector<unsigned int> a(N,0);
    vector<vector<unsigned int>> m(N,vector<unsigned int>(N,0));
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            cin>>m[i][j];
        }
    }
    for(int i = 0;i<N;i++)
    {
        unsigned int q = 0;
        for(int j =0;j<N;j++)
        {
            if(i!=j) q|=m[i][j];
        }
        cout<<q<<" ";
    }

}