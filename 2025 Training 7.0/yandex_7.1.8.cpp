#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#define Max(a,b) a<b ? b:a
#define Vasy 0
#define Masha 1
using namespace std;
bool cmp(const pair<int,int>& a,const pair<int,int>& b)
{
    if(a.first!=b.first)
    {
        return !(a.first<b.first);
    }
    else
    {
        return a.second<b.second;
    }
    
}
int main()
{
    int N;
    cin>>N;
    vector<pair<int,int>> problems_0;
    vector<pair<int,int>> problems_1;
    int l1 = 0,l2 = 0;
    for(int i = 0;i<N;i++)
    {
        string s;
        cin>>s;
        if(s.size()%2==0)
        {
            problems_0.push_back({0,0});
            for(int j = 0;j<s.size();j++)
            {
                if(s[j] == 83 && j%2==0) problems_0[l1].first++;
                else if (s[j] == 83 ) problems_0[l1].second++;    
            }
            l1++;
        }
        else
        {
            problems_1.push_back({0,0});
            for(int j = 0;j<s.size();j++)
            {
                if(s[j] == 83 && j%2==0) problems_1[l2].first++;
                else if (s[j] == 83 ) problems_1[l2].second++;
            }
            l2++;
        }
    }
    vector<int> cepochka_first;
    vector<int> cepochka_second;
    for(int i = 0 ;i<problems_0.size();i++)
    {
        if(problems_0[i].first<problems_0[i].second) cepochka_second.push_back(i);
        else cepochka_first.push_back(i);
    }
    int sum = 0;
    for(int i = 0;i<cepochka_first.size();i++)
    {
        sum += problems_0[cepochka_first[i]].first;
    }
    if(problems_1.size()!=0)
    {
        for(int i = 0;i<cepochka_second.size();i++) // поменяли Васю на Машу
        {
            sum += problems_0[cepochka_second[i]].second;
        }
        vector<pair<int,int>> cep_0;
        vector<pair<int,int>> cep_1;
        vector<pair<int,int>> cep_2;
        for(int i=0 ;i<problems_1.size();i++)
        {
            if(problems_1[i].first<problems_1[i].second) cep_1.push_back({problems_1[i].second,problems_1[i].first});
            else if(problems_1[i].first>problems_1[i].second) cep_0.push_back({problems_1[i].first,problems_1[i].second});
            else cep_2.push_back({problems_1[i].first,problems_1[i].second});
        }
        sort(cep_0.begin(),cep_0.end(),cmp);
        sort(cep_1.begin(),cep_1.end(),cmp);
        sort(cep_2.begin(),cep_2.end(),cmp);
        int k = 0;
        int flag = Vasy;
        int K = 0;
        cout<<sum<<endl;
        while(1)
        {
            if(k<cep_0.size() && k < cep_1.size())
            {
                sum += cep_0[k].first;
                sum += cep_1[k].first;
                flag = Vasy;
                k++;
            }
            else if(k<cep_0.size() && K<cep_2.size())
            {
                sum += cep_0[k].first;
                sum += cep_2[k].first;
                flag = Vasy;
                k++;
                K++;
                cout<<sum<<endl;
            }
            else if(k<cep_1.size() && K<cep_2.size())
            {
                sum += cep_2[k].first;
                sum += cep_1[k].first;
                flag = Vasy;
                k++;
                K++;
            }
            else if(k<cep_0.size())
            {
                if(flag==Vasy)
                {
                    sum += cep_0[k].first;
                    flag = Masha;
                    k++;
                }
                else{
                    int amax = -1,number=-1;
                    for(int i = k;i<cep_0.size();i++)
                    {
                        if(amax<cep_0[i].second)
                        {
                            amax = cep_0[i].second;
                            number = i;
                        }
                    }
                    sum+= amax;
                    auto it = cep_0.begin() + number;
                    cep_0.erase(it);
                    flag = Vasy;
                }
            }
            else if(k<cep_1.size())
            {
                if(flag==Vasy)
                {
                    int amax = -1,number=-1;
                    for(int i = k;i<cep_1.size();i++)
                    {
                        if(amax<cep_1[i].second)
                        {
                            amax = cep_1[i].second;
                            number = i;
                        }
                    }
                    sum+= amax;
                    auto it = cep_1.begin() + number;
                    cep_1.erase(it);
                    flag = Masha;
                }
                else{
                    sum += cep_1[k].first;
                    flag = Vasy;
                    k++;
                }
            }
            else if(K<cep_2.size())
            {
                sum += cep_2[K].second;
                k++;
                K++;
            }
            else break;
        }
        cout<<sum<<endl;
    }
    else
    {
        for(int i = 0;i<cepochka_second.size();i++) // поменяли Васю на Машу
        {
            sum += problems_0[cepochka_second[i]].first;
        }
        cout<<sum<<endl;
    }

    
}
