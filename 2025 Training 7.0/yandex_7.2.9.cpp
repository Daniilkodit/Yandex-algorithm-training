#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define Max(a,b) a<b ? b:a
using namespace std;
#define x1 10013233LL
#define M 1100008333LL
void push_t(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,vector<long long>& monom);
void update(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,int L,int R,int k,vector<long long>& monom,vector<int>& deg,vector<long long>& x);
long long f(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,int L,int R,vector<long long>& monom,vector<int>& deg,vector<long long>& x);
int main()
{
    int N,K;
    cin>>N;
    int P = 1;
    int q = 0;
    while(P<N){ P*=2;q++;}
    vector<pair<long long,long long>> tree_seg(P*2-1,{0,0});
    vector<long long> x(q+3,1);
    vector<long long> monom(2*P-1,1);
    for(int i =1 ;i<=q+2;i++)
    {
        x[i] = (x1*x[i-1])%M;
    }
    for(int i =0 ;i<N;i++)
    {
        cin>>tree_seg[i+P-1].first;
    }
    vector<int> deg(2*P-1);
    int P1 = P,count = 0,deg1 = 1;
    for(int i =P-2;i>=0;i--)
    {
        deg[i] = deg1;
        tree_seg[i].first = ((tree_seg[2*i+1].first*x[deg1])%M + tree_seg[2*i+2].first)%M;
        monom[i] = ((monom[i*2+1] * x[deg1])%M + monom[2*i+2])%M;
        count++;
        if(count==P1/2) { deg1*=2; P1/=2; count = 0;}
        
    }

    cin>>K;
    for(int i = 0 ;i<K;i++)
    {
        int t,L,R,k;
        cin>>t>>L>>R>>k;
        if(t==0)
        {
            update(tree_seg,0,0,P-1,L-1,R-1,k,monom,deg,x);
        }
        else
        {
            long long a = f(tree_seg,0,0,P-1,L-1,L+k-2,monom,deg,x);
            long long b =f(tree_seg,0,0,P-1,R-1,R+k-2,monom,deg,x);
            if(a==b)cout<<"+";
            else cout<<"-";
        }
        /*for(int j = 0;j<2*P-1;j++) cout<<tree_seg[j].first<<" "<<tree_seg[j].second<<"   ";
        cout<<endl;*/
    }

}
void push_t(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,vector<long long>& monom)
{   
    if(tree_seg[v].second!=0LL)
    {
        tree_seg[v].first  = (tree_seg[v].second *monom[v])%M;
        if(l!=r)
        {
            tree_seg[2*v+1].second = tree_seg[v].second;
            tree_seg[2*v+2].second = tree_seg[v].second;
        }
        tree_seg[v].second = 0LL;
    }
    
}
void update(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,int L,int R,int k,vector<long long>& monom,vector<int>& deg,vector<long long>& x)
{
    push_t(tree_seg,v,l,r,monom);
    if(R<l || L>r) return;
    if(L<=l  && r<=R)
    {
        tree_seg[v].second = k;
        push_t(tree_seg,v,l,r,monom);
        return;
    }
    update(tree_seg,v*2+1,l,(l+r)/2,L,R,k,monom,deg,x);
    update(tree_seg,v*2+2,((l+r)/2)+1,r,L,R,k,monom,deg,x);
    tree_seg[v].first = ((tree_seg[2*v+1].first*x[deg[v]])%M + tree_seg[2*v+2].first)%M;
}
long long f(vector<pair<long long,long long>>& tree_seg,int v,int l,int r,int L,int R,vector<long long>& monom,vector<int>& deg,vector<long long>& x)
{
    push_t(tree_seg,v,l,r,monom);
    if(R<l || L>r) {return 0LL;}
    if(L<=l  && r<=R)
    {
        if(r==R) {return tree_seg[v].first;}
        else if(L==l) {return (tree_seg[v].first*x[(R-L)-(r-l)])%M;}
        else
        {
            return (tree_seg[v].first*x[(R-l)-(r-l)])%M;
        }
    }
    return (f(tree_seg,v*2+1,l,(l+r)/2,L,R,monom,deg,x) + f(tree_seg,v*2+2,((l+r)/2)+1,r,L,R,monom,deg,x))%M;
}