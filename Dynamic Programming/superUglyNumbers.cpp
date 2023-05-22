#include <bits/stdc++.h>
using namespace std;

int nthSuperUglyNumber(int n, vector<int> &primes)
{
    int m = primes.size();
    vector<int> dp(n + 1);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

    for (int i = 0; i < m; i++)
        pq.push({primes[i],{primes[i],1}});

    dp[1] = 1;
    
}