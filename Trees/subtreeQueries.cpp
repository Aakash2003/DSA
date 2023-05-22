#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = (int)(2e5+5);
vector<int> tree[N];
int val[N];
int in[N],out[N],rin[N];
int T = 0;

void dfs(int s,int p)
{
    in[s] = T++;
    rin[in[s]] = val[s];

    for(int v:tree[s])
    {
        if(v!=p) dfs(v,s);
    }

    out[s] = T;
}

int st[4*N];

void build(int start,int end,int pos)
{
    if(start==end) 
    {
        st[pos] = rin[start];
        return;
    }

    int mid = start+(end-start)/2;
    build(start,mid,2*pos+1);
    build(mid+1,end,2*pos+2);
    st[pos] = st[2*pos+1]+st[2*pos+2];
}

void update(int start,int end,int index,int val,int pos)
{
    if(start==end)
    {
        st[pos] = val;
        return;
    }

    int mid = start+(end-start)/2;
    if(index<=mid) update(start,mid,index,val,2*pos+1);
    else update(mid+1,end,index,val,2*pos+2);
    st[pos] = st[2*pos+1] + st[2*pos+2];
}

int query(int start,int end,int ql,int qr,int pos)
{
    if(ql<=start && qr>=end) return st[pos];
    if(qr<start || ql>end) return 0;
    int mid = start+(end-start)/2;
    return query(start,mid,ql,qr,2*pos+1)+query(mid+1,end,ql,qr,2*pos+2);
}

signed main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>val[i];

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v),tree[v].push_back(u);
    }

    dfs(1,0);
    build(0,n-1,0);

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int s,v;
            cin>>s>>v;
            update(0,n-1,in[s],v,0);
        }
        else
        {
            int s;
            cin>>s;
            cout<<query(0,n-1,in[s],out[s]-1,0)<<endl;
        }
    }
}