#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> p(n+1);
    map<int,set<int>> list;
    for( int i = 1 ;i<n+1;i++)
    {
        p[i] = i;
        list[i].insert(i);
    }
    bool flag =true;
    for(int i = 1 ;i<m+1;i++)
    {
        int x,y;
        cin>>x>>y;
        x = p[x];
        y = p[y];
        if(x==y) continue;
        if(list[x].size()>list[y].size())
        {
            int sw;
            sw = x;
            x = y;
            y = sw;
        }
        for(auto& elem : list[x])
        {
            list[y].insert(elem);
            p[elem] = y;
        }
        list[x].clear();
        if(list[y].size() == n) 
        {
            flag = false;
            for(int j = i+1;j<m+1;j++) cin>>x>>y;
            cout<<i<<endl; 
            break;
        }
    }
    if(flag) cout<<m<<endl;
}
