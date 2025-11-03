#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define Max(a,b) a<b ? b:a
#define INF 100001
using namespace std;
vector<int> nolik(vector<vector<int>>&,int,int ,int,int,int);
void set_t(vector<vector<int>>&,int,int ,int,int,int);
int main()
{
    int N,K;
    cin>>N;
    int P = 1;
    while(P<N) P*=2;
    vector<vector<int>> tree_seg(P*2-1,vector<int>(2,INF));
    for(int i =0 ;i<N;i++)
    {
        cin>>tree_seg[i+P-1][0];
        tree_seg[i+P-1][1] = 1;
    }
    for(int i =P-2;i>=0;i--)
    {
        if(tree_seg[i*2+1][0]>tree_seg[i*2+2][0])
        {
            tree_seg[i][0] = tree_seg[i*2+2][0];
            tree_seg[i][1] = tree_seg[i*2+2][1];
        }
        else if(tree_seg[i*2+1][0]<tree_seg[i*2+2][0])
        {
            tree_seg[i][0] = tree_seg[i*2+1][0];
            tree_seg[i][1] = tree_seg[i*2+1][1];
        }
        else
        {
            tree_seg[i][0] = tree_seg[i*2+1][0];
            tree_seg[i][1] = tree_seg[i*2+1][1] + tree_seg[i*2+2][1];
        }
    }
    cin>>K;
    for(int i = 0;i<K;i++)
    {
        char s;
        cin>>s;
        if(s == 115)
        {
            int k,L,R;
            vector<int> count = {0,0};
            cin>>L>>R>>k;
            L--;
            R--;
            if(L!=0)
            {
                count = nolik(tree_seg,0,0,P-1,0,L-1);
            }
            if(count[0]!=0){count[1]=0;}
            k+=count[1];
            int v = 0;
            while(v<P-1)
            {
                if(tree_seg[2*v+1][0] == 0 && tree_seg[2*v+1][1]>=k)
                {
                    v = v*2+1;
                    continue;
                }
                else if(tree_seg[2*v+1][0] == 0)
                {
                    k-= tree_seg[2*v+1][1];
                }
                if(tree_seg[2*v+2][0] == 0)
                {
                    v = v*2+2;
                }
                else
                {
                    break;
                }
            }
            if(v>=P-1 && k == 1 && v-P+2<=R+1 && tree_seg[v][0] == 0)
            {
                cout<<v-P+2<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
        }
        else
        {
            int L,R;
            cin>>L>>R;
            set_t(tree_seg,0,0,P-1,L-1,R);
        }
    }
}
vector<int> nolik(vector<vector<int>>& tree_seg,int v,int l,int r,int L,int R)
{
    if(l>R || r<L) return {INF,-1};
    if(l>=L && r<=R) return tree_seg[v];
    vector<int> p1,p2;
    p1 = nolik(tree_seg,v*2+1,l,(r+l)/2,L,R);
    p2 = nolik(tree_seg,v*2+2,((r+l)/2)  + 1,r,L,R);
    if(p1[0]<p2[0]) { return p1;}
    else if(p1[0]>p2[0])  {return p2;}
    else 
    {
        p1[1]+=p2[1];
        return p1;
    }
}
void set_t(vector<vector<int>>& tree_seg,int v,int l,int r,int AT,int VL)
{
    if(AT<l || AT>r) return;
    if(r-l == 0)
    {
        tree_seg[v][0] = VL;
        tree_seg[v][1] = 1;
        return;
    }
    set_t(tree_seg,v*2+1,l,(l+r)/2,AT,VL);
    set_t(tree_seg,v*2+2,((l+r)/2)+1,r,AT,VL);
    if(tree_seg[v*2+1][0]>tree_seg[v*2+2][0])
    {
        tree_seg[v][0] = tree_seg[v*2+2][0];
        tree_seg[v][1] = tree_seg[v*2+2][1];
    }
    else if(tree_seg[v*2+1][0]<tree_seg[v*2+2][0])
    {
        tree_seg[v][0] = tree_seg[v*2+1][0];
        tree_seg[v][1] = tree_seg[v*2+1][1];
    }
    else
    {
        tree_seg[v][0] = tree_seg[v*2+1][0];
        tree_seg[v][1] = tree_seg[v*2+1][1] + tree_seg[v*2+2][1];
    }
}

