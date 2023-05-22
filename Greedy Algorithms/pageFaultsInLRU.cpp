#include<bits/stdc++.h>
using namespace std;

int pageFaults(vector<int> &pages,int c)
{

}

int main()
{
    int n;
    cin>>n;
    vector<int> pages(n);
    for(int i=0;i<n;i++) cin>>pages[i];

    int c;
    cin>>c;

    cout<<pageFaults(pages,c)<<endl;
}