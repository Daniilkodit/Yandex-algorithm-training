#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <list>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int> people(N+1);
    list<pair<int,int>> list;
    
    for(int i = 1 ;i<N+1;i++)  
    {
        int a;
        cin>>a;
        list.push_back({a,i});
    }
    int round = 1;
    bool flag =true;
    queue<std::list<pair<int,int>>::iterator> q;
    if(N==2) {cout<<"0 0"<<endl;return 0;};
    
    for(auto  it =  list.begin();it!=list.end();it++)
    {
        auto prev = it;
        auto next = it;
        if(it==list.begin()) {prev = list.end(); prev--; next++;}
        else if(it==--list.end()) {next = list.begin(); prev--;}
        else {prev--;next++;}
        if(prev->first>it->first && next->first>it->first) q.push(it);
    }
    int r = 1;
    int n =N;
    while(!q.empty())
    {
        int dl = q.size();
        n-=dl;
        if(n<=2)
        {
            for(int i = 0;i<dl;i++)
            {
                auto it = q.front();
                people[it->second] = r;
                q.pop();
            }
            break;
        }
        for(int i = 0;i<dl;i++)
        {
            auto it = q.front();
            people[it->second] = r;
            q.pop();

            auto prev = it;
            auto next = it;
            if(it==list.begin()) {prev = list.end(); prev--; next++;}
            else if(it==--list.end()) {next = list.begin(); prev--;}
            else {prev--;next++;}
            list.erase(it);

            auto prev1 = prev;
            auto prev2 = prev;
            if(prev==list.begin()) {prev1 = list.end(); prev1--; prev2++;}
            else if(prev==--list.end()) {prev2 = list.begin();prev1--;}
            else {prev1--;prev2++;}
            if(prev1->first>prev->first && prev2->first>prev->first) q.push(prev);

            auto next1 = next;
            auto next2 = next;
            if(next==list.begin()) {next1 = list.end(); next1--;next2++;}
            else if(next==--list.end()) {next2 = list.begin();next1--;}
            else {next1--;next2++;}
            if(next1->first>next->first && next2->first>next->first) q.push(next);
            
        }
        r++;
    }
    for(int i = 1;i<N+1;i++)  cout<<people[i]<<" ";
}