#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define Amax 1000000
int main()
{
    int T,n;
    cin>>T;
    for(int i= 0;i<T;i++)
    {
        cin>>n;
        int amin = Amax,a,alen = 0;;
        vector<int> Len;
        for(int j = 0;j<n;j++)
        {
            cin>>a;
            if(amin == Amax)
            {
                amin = a;
                alen++;
                if(j==n-1) Len.push_back(alen);
                continue;
            }
            if(amin<=a)
            {
                if(amin==alen)
                {
                    Len.push_back(alen);
                    alen = 1;
                    amin = a;
                    if(j==n-1) Len.push_back(alen);
                    continue;
                }
                else
                {
                    alen++;
                }
            }
            else
            {
                if(a<=alen)
                {
                    Len.push_back(alen);
                    alen = 1;
                    amin = a;
                    if(j==n-1) Len.push_back(alen);
                    continue;
                }
                else
                {
                    amin = a;
                    alen++;
                }
            }
            if(j==n-1) Len.push_back(alen);
        }
        cout<<Len.size()<<endl;
        for(int i= 0 ;i<Len.size();i++)
        {
            cout<<Len[i]<<" ";
        }
        cout<<endl;
    }
}