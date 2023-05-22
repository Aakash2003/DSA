#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll powerOfTwo(int x)
{
    return (1LL<<x);
}

int main()
{
    int t;
    cin>>t;

    ll L,R;
    ll ans;

    while(t--)
    {
        cin>>L>>R;
        ans = L;

        for(int i=0;i<64;i++)
        {
            if((ans & powerOfTwo(i))==0) 
            {
                ll temp = ans + powerOfTwo(i);
                if(temp>R) break;
                else ans = temp;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}