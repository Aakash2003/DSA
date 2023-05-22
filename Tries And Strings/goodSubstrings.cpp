#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string str,bad;
        cin>>str>>bad;

        int k;
        cin>>k;

        set<ll> s;
        ll M = 1e18+7;
        int n = str.length();

        for(int i=0;i<n;i++)
        {
            ll cnt = 0;
            ll total = 0;

            for(int j=i;j<n;j++)
            {
                total = ((total*26LL)+(str[j]-'a'+1))%M;
                cnt += (bad[str[j]-'a']=='0');
                if(cnt>k) break;
                s.insert(total);
            }
        }

        cout<<s.size()<<endl;
    }
    
}