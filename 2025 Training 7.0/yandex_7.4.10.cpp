#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <list>
#include <string>
using namespace std;
int main()
{
    list<long long int> a;
    int n;
    cin>>n;
    long long int sum = 0;
    for(int i = 0;i<n;i++)
    {
        long long int elem;
        cin>>elem;
        sum += elem*elem;
        a.push_back(elem);
    }
    cout<<sum<<endl;
    int k;
    cin>>k;
    int count = n;
    auto it  = a.begin();
    int pred_number = 1;
    for(int i = 0; i<k ;i++)
    {
        int t,num;
        cin>>t>>num;
        
        if(pred_number>num)
        {
            while(pred_number >num)
            {
                pred_number--;
                it--;
            }
        }
        else if(pred_number<num)
        {
            while(pred_number<num)
            {
                pred_number++;
                it++;
            }
        }
        if(t==1)
        {
            if(it == a.begin())
            {
                
                auto next = ++a.begin();
                sum-=(*next)*(*next) + (*it)*(*it);
                *next+=*it;
                sum+=(*next)*(*next);
                a.erase(it);
                it = a.begin();
                pred_number = 1;
            }
            else if(it == --a.end())
            {
                auto prev = --a.end();prev--;
                sum-=(*prev)*(*prev) + (*it)*(*it);
                *prev+=*it;
                sum+=(*prev)*(*prev);
                a.erase(it);
                it = --a.end();
                pred_number = count-1;
            }
            else
            {
                auto next = it; next++;
                auto prev = it; prev--;
                sum-=(*next)*(*next) + (*it)*(*it)+(*prev)*(*prev) ;
                *prev+= *it/2;
                *next+= *it-(*it/2);
                sum+=(*prev)*(*prev);
                sum+=(*next)*(*next);
                a.erase(it);
                it = prev; pred_number = num-1;
            }
            count--;
            cout<<sum<<endl;
        }
        else
        {
            sum-=(*it)*(*it);
            sum+=(*it-(*it/2)) *(*it-(*it/2)) + ((*it/2)*(*it/2));
            
            it = a.insert(it,(*it/2)); it++;
            *it = (*it-(*it/2));
            cout<<sum<<endl;
            count++;
            pred_number = num+1;
        }
    }
}