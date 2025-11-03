#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<unsigned long long> a(N,0LL);
    unsigned long long  mask_max = 1;
    for(int i = 0;i<N;i++)
    {
        unsigned long long  mask = 1;
        cin>>a[i];
        while(mask<a[i])
        {
            mask = (mask<<1);
        }
        if(mask>a[i]) mask = mask>>1;
        if(mask_max<mask) mask_max = mask;
    }
    for(int i = 0;i<N;i++)
    {
        unsigned long long mask = 1;
        unsigned long long flag = 0;
        while(mask<=mask_max)
        {   
            if((a[i]&mask)==0 && flag==0)
            {
                flag = mask;
            }
            else if((a[i]&mask)!=0 && flag!=0)
            {
                a[i] |= flag;
                a[i] ^=mask;
                flag = mask;
            }
            mask = (mask<<1);
        }
    }
    unsigned long long mask = 1;
    while(mask<=mask_max)
    {
        int count =0;
        for(int i = 0;i<N;i++) if((a[i]&mask)!=0) count++;

        if(count%2==1)
        {
            for(int i = 0;i<N;i++)
            {
                if((a[i]&mask)!=0)
                {
                    unsigned long long mask_i = mask_max;
                    while(mask_i>mask)
                    {
                        if((a[i]&mask_i)==0)
                        {

                            a[i] |=mask_i;
                            a[i] ^=mask;
                            count--;
                            break;
                        }
                        mask_i = (mask_i>>1);
                    }
                }
                if(count%2==0) break;
            }
            if(count%2==1)
            {
                if(mask == mask_max || mask == 2) {cout<<"imossible";return 0;}
                unsigned long long mask_i = 1;
                bool flag = false;
                while(mask_i<=mask)
                {
                    int j = 0;
                    if(count%2==1)
                    {
                        for(int i = 0;i<N;i++)
                        {
                            if(a[i]&mask==0 && a[i]&mask_i!=0)
                            {
                                a[i] |=mask;
                                a[i] ^=mask_i;
                                count++;
                                j = i;
                                break;
                            }
                        }
                    }
                    if(count%2==1) { mask_i = mask_i<<1;}
                    else
                    {
                        mask = mask<<1;
                        for(int i = j+1;i<N;i++)
                        {
                            if(a[i]&mask==0 && a[i]&mask_i!=0)
                            {
                                a[i] |=mask;
                                a[i] ^=mask_i;
                                flag = true;
                                break;
                            }
                        }
                        if(flag)  {mask = mask>>1;break;}
                    }
                }
                if(!flag) {cout<<"imossible";return 0;}
            }
        }
        mask = mask<<1;
    }
    for(int i =0 ;i<N;i++) cout<<a[i]<<" ";
    return 0;
}