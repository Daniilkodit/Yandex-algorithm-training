#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
// Нормальное UNION-FIND, через деревья
using namespace std;
int Get(int x,vector<int>& p);
void Union(int x,int y,vector<int>& p,vector<int>& r);
int main()
{
    int n;
    cin>>n;
    vector<int> p(n+1);
    vector<int> r(n+1);
    for( int i = 1 ;i<n+1;i++)
    {
        p[i] = i;
    }
    for(int i = 1 ;i<n+1;i++)
    {
        int a;
        cin>>a;
        if(p[i] == p[a])continue;
        else
        {
            Union(p[i],p[a],p,r);
        }
    }
    set<int> num;
    for(int i = 1 ;i<n+1;i++) {num.insert((Get(i,p)));}
    cout<<num.size()<<endl;
}
int Get(int x,vector<int>& p)
{
    int y = x;
    while(p[y]!=y)
    {
        y = p[y];
    }
    int z = x;
    while(p[z]!=z)
    {
        z = p[z];
        p[x] = y;
        x = p[z];
    }
    return y;
}
void Union(int x,int y,vector<int>& p,vector<int>& r)
{
    x = Get(x,p);
    y = Get(y,p);
    if(r[x]>r[y])
    {
        int sw;
        sw = x;
        x = y;
        y = sw;
    }
    p[x] = y;
    if(r[x]==r[y]) r[y]++;
}