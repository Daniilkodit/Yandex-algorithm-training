#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define Max(a,b) a<b ? b:a
using namespace std;
int count_max(vector<pair<long long,long long>>&,int,int ,int,int,int);
void add_t(vector<pair<long long,long long>>&,int,int ,int,int,int,int);
void push_t(vector<pair<long long,long long>>& tree_seg,int v,int l,int r);
void pokaz(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,int AT);
int main()
{
    int N,K;
    cin>>N;
    int P = 1;
    while(P<N) P*=2;
    vector<pair<long long,long long>> tree_seg(P*2-1,{-1LL,0LL});
    for(int i =0 ;i<N;i++)
    {
        cin>>tree_seg[i+P-1].first;
    }
    for(int i =P-2;i>=0;i--)
    {
        if(tree_seg[i*2+1].first<tree_seg[i*2+2].first)
        {
            tree_seg[i].first = tree_seg[i*2+2].first;
        }
        else
        {
            tree_seg[i].first = tree_seg[i*2+1].first;
        }
    }
    cin>>K;
    for(int i = 0;i<K;i++)
    {
        int L,R,X;
        char s;
        cin>>s;
        if(s==103)
        {
            cin>>L;
            pokaz(tree_seg,0,0,P-1,L-1);
        }
        else{
            cin>>L>>R>>X;
            add_t(tree_seg,0,0,P-1,L-1,R-1,X);
        }
    }
}
void push_t(vector<pair<long long,long long>>& tree_seg,int v,int l,int r)
{
    tree_seg[v].first += tree_seg[v].second;
    if(l!=r)
    {
        tree_seg[2*v+1].second += tree_seg[v].second;
        tree_seg[2*v+2].second += tree_seg[v].second;
    }
    tree_seg[v].second = 0LL;
}
void pokaz(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,int AT)
{
    push_t(tree_seg,v,l,r);
    if(AT<l || AT>r) return;
    if(r-l == 0)
    {
        cout<<tree_seg[v].first<<endl;
        return;
    }
    pokaz(tree_seg,v*2+1,l,(l+r)/2,AT);
    pokaz(tree_seg,v*2+2,((l+r)/2)+1,r,AT);
    if(tree_seg[v*2+1].first<tree_seg[v*2+2].first)
    {
        tree_seg[v].first = tree_seg[v*2+2].first;
    }
    else
    {
        tree_seg[v].first = tree_seg[v*2+1].first;
    }
}


int count_max(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,int L,int R)
{
    push_t(tree_seg,v,l,r);
    if(l>R || r<L) return -1;
    if(R>=r  && l>=L) return tree_seg[v].first;
    int p1,p2;
    p1 = count_max(tree_seg,v*2+1,l,(r+l)/2,L,R);
    p2 = count_max(tree_seg,v*2+2,((r+l)/2)  + 1,r,L,R);
    p1 = Max(p1,p2);
    return p1;
}
void add_t(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,int L,int R,int x)
{
    push_t(tree_seg,v,l,r);
    if(R<l || L>r) return;
    if(L<=l  && r<=R)
    {
        tree_seg[v].second += x;
        push_t(tree_seg,v,l,r);
        return;
    }
    add_t(tree_seg,v*2+1,l,(l+r)/2,L,R,x);
    add_t(tree_seg,v*2+2,((l+r)/2)+1,r,L,R,x);
    if(tree_seg[v*2+1].first<tree_seg[v*2+2].first)
    {
        tree_seg[v].first = tree_seg[v*2+2].first;
    }
    else
    {
        tree_seg[v].first = tree_seg[v*2+1].first;
    }
}
