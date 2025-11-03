#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
int f(int i);
int g(int i);
long int Pref_Sum(vector<vector<vector<long int>>>& t, int x, int y,int z);
void Add_t(vector<vector<vector<long int>>>& t, int x, int y,int z,int val,int n);
int main()
{
    int N;
    cin>>N;
    vector<vector<vector<long int>>> t (N,vector<vector<long int>>(N,vector<long int>(N,0LL)));
    int m;
    cin>>m;
    while(m!=3)
    {
        if(m==1)
        {
            int x,y,z,val;
            cin>>x>>y>>z>>val;
            Add_t(t,x,y,z,val,N);
        }
        else
        {
            int x1,y1,z1,x2,y2,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            long int sum = Pref_Sum(t,x2,y2,z2)-Pref_Sum(t,x1-1,y2,z2)-Pref_Sum(t,x2,y1-1,z2)+Pref_Sum(t,x1-1,y1-1,z2);
            sum -= Pref_Sum(t,x2,y2,z1-1) - Pref_Sum(t,x2,y1-1,z1-1) - Pref_Sum(t,x1-1,y2,z1-1) + Pref_Sum(t,x1-1,y1-1,z1-1);
            cout<<sum<<endl;
        }
        cin>>m;
    }
    return 0;
}
long int Pref_Sum(vector<vector<vector<long int>>>& t,  int x, int y,int z)
{
    int sum = 0;
    for(int i = x;i>=0; i = f(i)-1)
    {
        for(int j = y ;j>=0;j = f(j)-1)
        {
            for(int k = z;k>=0;k = f(k)-1)
            {
                sum += t[i][j][k];
            }
        }
    }
    return sum;
}
void Add_t(vector<vector<vector<long int>>>& t, int x, int y,int z,int val,int n)
{
    for(int i = x;i<n;i = g(i))
    {
        for(int j = y;j<n; j = g(j))
        {
            for(int k = z;k<n;k = g(k))
            {
                t[i][j][k]+=val;
            }
        }
    }
}
int g(int i)
{
    return (i|(i+1));
}
int f(int i)
{
    return (i&(i+1));
}