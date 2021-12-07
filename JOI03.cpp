#include<bits/stdc++.h>
using namespace std;
using lli = long long;

const int NN=2e5+10;
lli A[NN] ,leftsum[NN] ,rightsum[NN];

int main()
{
    int N;
    cin >> N;
    for(int i=1;i<=N;++i)
    {
        scanf("%lld",&A[i]);
    }
    for(int i=2;i<=N;++i)
    {
        leftsum[i] = leftsum[i-1] + max(A[i-1] - A[i] + 1 , 0LL);
    }
    for(int i=N-1;i>=1;--i)
    {
        rightsum[i] = rightsum[i+1] + max(A[i+1] - A[i] + 1 , 0LL);
    }
    lli ans = 3e18;
    for(int k=1;k<=N;++k)
    {
        ans = min(ans , max(leftsum[k] , rightsum[k]));
    }
    cout << ans;
}
