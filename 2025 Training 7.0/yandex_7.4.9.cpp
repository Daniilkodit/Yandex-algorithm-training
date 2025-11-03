#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,long long int>> a(n+1,{0,0});
    for(int i = 1;i<n+1;i++)
    {
        int num,m;
        cin>>num>>m;
        if(m>0)
        {
            a[i] = {num,a[num].second+m};
        }
        else
        {
            a[i] = a[a[num].first];
        }
    }
    long long int sum = 0;
    for(int i = 1;i<n+1;i++) sum+= a[i].second;
    cout<<sum<<endl;
}