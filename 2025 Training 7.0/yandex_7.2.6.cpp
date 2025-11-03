#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define Max(a,b) a<b ? b:a
#define INF 200001
using namespace std;
void set_t(vector<int>&,int,int ,int,int,int);
int find(vector<int>&,int,int,int,int,int);
int main()
{
    int N,K;
    cin>>N;
    cin>>K;
    int P = 1;
    while(P<N) P*=2;
    vector<int> tree_seg(P*2-1,-1);
    for(int i =0 ;i<N;i++)
    {
        cin>>tree_seg[i+P-1];
    }
    for(int i =P-2;i>=0;i--)
    {
        tree_seg[i] = Max(tree_seg[2*i+1],tree_seg[2*i+2]);
    }
    
    for(int i = 0;i<K;i++)
    {
        int t,j,x;
        cin>>t;
        cin>>j;
        cin>>x;
        if(t==0) set_t(tree_seg,0,0,P-1,j-1,x);
        else
        {
            j--;
            int answer = find(tree_seg,0,0,P-1,j,x);
            if(answer==-1) cout<<-1<<endl;
            else cout<<answer-P+2<<endl;
        }
        /*for (int i= 0;i<2*P-1;i++) cout<<tree_seg[i]<<" ";
        cout<<endl;*/
    }
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
    tree_seg[v] = Max(tree_seg[2*v+1],tree_seg[2*v+2]);
}
int find(vector<int>& tree_seg,int v,int l,int r,int j,int x)
{
    if(tree_seg[v]<x) return -1;
    if(r-l==0) return v;
    if(tree_seg[v*2+1]>=x && (r+l)/2>=j)
    {
        int answer = find(tree_seg,2*v+1,l,(r+l)/2,j,x);
        if(answer >-1) return answer;
    }
    if(tree_seg[v*2+2]>=x && r>=j)
    {
        int answer = find(tree_seg,2*v+2,((r+l)/2)+1,r,j,x);
        if(answer>-1) return answer;
    }
    return -1;
}