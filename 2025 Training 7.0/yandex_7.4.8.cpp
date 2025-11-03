#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <string>
using namespace std;
int Get(int x,vector<int>& p);
void Union(int x,int y,vector<int>& p,vector<int>& r);
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> p(n+1);
    vector<int> r(n+1);
    vector<pair<char,vector<int>>> vopr(k,{0,{0,0}});
    stack<string> answer; 
    for( int i = 1 ;i<n+1;i++)
    {
        p[i] = i;
    }
    int x,y;
    for(int i = 0;i<m;i++) cin>>x>>y;
    for(int i = 0;i<k;i++)
    {
        string s;
        int x,y;
        cin>>s>>x>>y;
        vopr[i] = {s[0],{x,y}};
    }
    for(int i = k-1;i>=0;i--)
    {
        if(vopr[i].first =='c')
        {
            Union(vopr[i].second[0],vopr[i].second[1],p,r);
        }
        else
        {
            if(Get(vopr[i].second[0],p)==Get(vopr[i].second[1],p)) answer.push("YES");
            else answer.push("NO");
        }
    }
    while(!answer.empty()) {cout<<answer.top()<<endl; answer.pop();}
    
    
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