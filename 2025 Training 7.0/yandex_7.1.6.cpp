#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#define Max(a,b) a<b ? b:a
using namespace std;
int main()
{
    int N,M;
    cin>>N>>M;
    vector<vector<int>> a(N,vector<int>(2,0)); // 0 - вес, 1 -стоимость
    vector<vector<pair<int,int>>>mas(N,vector<pair<int,int>>(M+1,{-1,-1})); // 0 -стоимсоть, 1 - послед добавленный
    for(int i = 0;i<N;i++)
    {
        cin>>a[i][0];
        mas[i][0].first = 0;
    }
    for(int i = 0;i<N;i++)
    {
        cin>>a[i][1];
    }
    for(int i = 0 ;i<N;i++)
    {
        for(int j = M-a[i][0];j>=0;j--)
        {
            if(mas[i][j].first!=-1)
            {
                if(mas[i][j+a[i][0]].first < mas[i][j].first+a[i][1])
                {
                    mas[i][j+a[i][0]].first = mas[i][j].first+a[i][1];
                    mas[i][j+a[i][0]].second = i;
                }
            }
        }
        if(i!=N-1)
        {
            for(int j = 0;j<M+1;j++)
            {
                mas[i+1][j] = mas[i][j];
            }
        }
    }
    int num = -1,amax = -1,num_mas = 0;
    for(int j = 0;j<M+1;j++)
    {
        if(amax<mas[N-1][j].first)
        {
            amax = mas[N-1][j].first;
            num = mas[N-1][j].second;
            num_mas = j;
        }
    }
    if(num == -1) return 0;
    cout<<num+1<<endl;
    int num_copy = num;
    for(int i = num_copy-1;i>=0;i--)
    {
        if(num_mas-a[num][0]<=0) return 0;
        amax = -1;
        int num_mas1 = 0,num1 = 0;
        for(int j = 0;j<=num_mas-a[num][0];j++)
        {
            if(amax<=mas[i][j].first)
            {
                amax = mas[i][j].first;
                num1 = mas[i][j].second;
                num_mas1 = j;
            }
        }
        num_mas = num_mas1;
        num = num1;
        cout<<num+1<<endl;
        i = num;
    }
}
