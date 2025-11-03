#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int N,M;
    cin>>N;
    cin>>M;
    vector<vector<int>> X(N,vector<int>(2,0));
    vector<vector<int>> Y(M,vector<int>(2,0));
    vector<int> answer(N);
    for(int i = 0;i<N;i++)
    {
        cin>>X[i][0];
        X[i][1] = i+1;
    }
    for(int i = 0;i<M;i++)
    {
        cin>>Y[i][0];
        Y[i][1] = i+1;
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    for(int i = 0;i<N;i++) cout<<"("<<X[i][0]<<","<<X[i][1]<<")"<<" ";
    cout<<endl;
    for(int i = 0;i<M;i++) cout<<"("<<Y[i][0]<<","<<Y[i][1]<<")"<<" ";
    cout<<endl;
    int i = 0,j =0;
    while(i<N && j<M)
    {
        if(X[i][0]<Y[j][0])
        {
            answer[X[i][1]-1] = Y[j][1];
            i++;
            j++;
        }
        else 
        {
            j++;
        }
    }
    cout<<i<<endl;
    for(int i = 0;i<N;i++) cout<<answer[i]<<" ";


}