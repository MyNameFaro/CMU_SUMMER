#include<bits/stdc++.h>
using namespace std;

long long DP[1005] , sum[1005];

int main()
{
    DP[0]=sum[0]=1;
    DP[1]=sum[1]=1;
    int N;
    long long mod=1e9+7;
    cin >> N;
    for(int i=2;i<=N;++i)
    {
        DP[i] = DP[i-1];
        DP[i] %= mod;
        DP[i] +=DP[i-2];
        DP[i] %= mod;
        if(i>=3) DP[i] +=2*(sum[i-3]%mod);
        DP[i] %= mod;DP[i] %= mod;
        if(i>=4) DP[i] +=2*(sum[i-4]%mod);
        DP[i] %= mod;DP[i] %= mod;
        sum[i] = DP[i] + sum[i-2];
        sum[i] %= mod;
    }
    printf("%lld",DP[N]);
}
