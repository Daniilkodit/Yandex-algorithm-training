#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int M;
    long int sum =0;
    cin>>M;
    vector<int> a(31);
    vector<int> pow_2(31);
    vector<pair<double,int>> st_min;
    for(int i =0 ;i<31;i++) {cin>>a[i];pow_2[i] = pow(2,i);}
    for(int i = 0;i<31;i++)
    {
        st_min.push_back({double(pow_2[i])/double(a[i]),i});
    }
    sort(st_min.begin(),st_min.end());
    
    long int amin =0;
    for(int i = 0;i<31;i++)
    {
        while(M>=a[st_min[i].second]) {M-=a[st_min[i].second];sum+=pow_2[st_min[i].second];};
        if(M==0) {
            if(amin == 0)
            {
                cout<<sum<<endl;
                return 0;
            }
            if(sum<amin) cout<<sum<<endl;
            else cout<<amin<<endl;
            return 0;
        }
        if(i == 0) amin = sum+pow_2[st_min[i].second];
        else if(amin>sum+pow_2[st_min[i].second])
        {
            amin = sum+pow_2[st_min[i].second];
        }
    }
    cout<<amin<<endl;
    return 0;

}