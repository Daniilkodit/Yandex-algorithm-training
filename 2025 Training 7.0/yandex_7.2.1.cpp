#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
pair<int,int> count_max(vector<pair<int,int>>&,int,int ,int,int,int);
int main()
{
    int N,K;
    cin>>N;
    int P = 1;
    while(P<N) P*=2;
    vector<pair<int,int>> tree_seg(P*2-1,{-1,1});
    for(int i =0 ;i<N;i++)
    {
        cin>>tree_seg[i+P-1].first;
    }
    for(int i =P-2;i>=0;i--)
    {
        if(tree_seg[i*2+1].first<tree_seg[i*2+2].first)
        {
            tree_seg[i].first = tree_seg[i*2+2].first;
            tree_seg[i].second = tree_seg[i*2+2].second;
        }
        else if(tree_seg[i*2+1].first>tree_seg[i*2+2].first)
        {
            tree_seg[i].first = tree_seg[i*2+1].first;
            tree_seg[i].second = tree_seg[i*2+1].second;
        }
        else
        {
            tree_seg[i].first = tree_seg[i*2+1].first;
            tree_seg[i].second = tree_seg[i*2+1].second +tree_seg[i*2+2].second;
        }
    }
    /*for(int i = 0;i<P*2-1;i++)
    {
        cout<<tree_seg[i].first<<" "<<tree_seg[i].second<<endl;
    }*/
    cin>>K;
    pair<int,int> p;
    for(int i = 0;i<K;i++)
    {
        int L,R;
        cin>>L;
        cin>>R;
        L--;
        R--;
        p = count_max(tree_seg,0,0,P-1,L,R);
        cout<<p.first<<" "<<p.second<<endl;
    }
}
pair<int,int> count_max(vector<pair<int,int>>& tree_seg,int v,int l,int r,int L,int R)
{
    if(l>R || r<L) return {-2,-1};
    if(R>=r  && l>=L) return tree_seg[v];
    pair<int,int> p1,p2;
    p1 = count_max(tree_seg,v*2+1,l,(r+l)/2,L,R);
    p2 = count_max(tree_seg,v*2+2,((r+l)/2)  + 1,r,L,R);
    if(p1.first>p2.first) { return p1;}
    else if(p1.first<p2.first) {return p2;}
    else  {p1.second += p2.second;return p1;}
}