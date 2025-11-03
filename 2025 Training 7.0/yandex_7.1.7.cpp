#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#define Max(a,b) a<b ? b:a
using namespace std;
#define M  5000

int main()
{
    int sum = 0;
    map <int,vector<pair<int,int>>> kirp; // первый элемент пары номер кирпича второй длина
    int N,K;
    cin>>N;
    cin>>K;
    vector<vector<pair<int,int>>> stena(K,vector<pair<int,int>>(M+1,{-1,-1})); // первое номер, второе длина кирпича
    for(int i=0 ;i<K;i++) stena[i][0].first = 0;
    for(int i = 1;i<N+1;i++)
    {
        int colour,L;
        cin>>L;
        cin>>colour;
        kirp[colour].push_back({i,L});
        if(colour == 1) sum+= L;
    }
    for(int colour = 1; colour<=K;colour++)
    {
        for(int i = 0 ;i<kirp[colour].size();i++)
        {
            int L = kirp[colour][i].second;
            int number = kirp[colour][i].first;
            for(int j = sum-L;j>=0;j--)
            {
                if(stena[colour-1][j].first!=-1 && stena[colour-1][j+L].first == -1)
                {
                    stena[colour-1][j+L].first = number;
                    stena[colour-1][j+L].second = L;
                }
            }
        }
    }
    for(int i = 1;i<sum;i++)
    {
        bool flag = true;
        for(int colour = 0 ;colour<K;colour++)
        {
            if(stena[colour][i].first == -1)
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
        {
            cout<<"YES"<<endl;
            for(int colour = 0 ;colour<K;colour++)
            {
                int r = i;
                while(r!=0)
                {
                    cout<<stena[colour][r].first<<" ";
                    if(r-stena[colour][r].second == 0) break;
                    r-=stena[colour][r].second;
                }
            }
            return 0;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}
