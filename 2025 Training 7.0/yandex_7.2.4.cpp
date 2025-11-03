#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define Max(a,b) a<b ? b:a
using namespace std;
int count_max(vector<int>&,int,int ,int,int,int);
void set_t(vector<int>&,int,int ,int,int,int);
int main()
{
    int N,K;
    cin>>N;
    int P = 1;
    while(P<N) P*=2;
    vector<int> tree_seg(P*2-1,-1);
    for(int i =0 ;i<N;i++)
    {
        cin>>tree_seg[i+P-1];
    }
    for(int i =P-2;i>=0;i--)
    {
        if(tree_seg[i*2+1]<tree_seg[i*2+2])
        {
            tree_seg[i] = tree_seg[i*2+2];
        }
        else
        {
            tree_seg[i] = tree_seg[i*2+1];
        }
    }
    cin>>K;
    for(int i = 0;i<K;i++)
    {
        int L,R;
        char s;
        cin>>s;
        cin>>L>>R;
        L--;
        R--;
        if(s==115) cout<<count_max(tree_seg,0,0,P-1,L,R)<<" ";
        else set_t(tree_seg,0,0,P-1,L,R+1);
    }
}
int count_max(vector<int>& tree_seg,int v,int l,int r,int L,int R)
{
    if(l>R || r<L) return -1;
    if(R>=r  && l>=L) return tree_seg[v];
    int p1,p2;
    p1 = count_max(tree_seg,v*2+1,l,(r+l)/2,L,R);
    p2 = count_max(tree_seg,v*2+2,((r+l)/2)  + 1,r,L,R);
    if(p1>p2) { return p1;}
    else  {return p2;}
}
void set_t(vector<int>& tree_seg,int v,int l,int r,int AT,int VL)
{
    if(AT<l || AT>r) return;
    if(r-l == 0)
    {
        tree_seg[v] = VL;
        return;
    }
    set_t(tree_seg,v*2+1,l,(l+r)/2,AT,VL);
    set_t(tree_seg,v*2+2,((l+r)/2)+1,r,AT,VL);
    tree_seg[v] = Max(tree_seg[v*2+1],tree_seg[v*2+2]);
}
