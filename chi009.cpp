#include<bits/stdc++.h>
using namespace std;
using lli = long long;

const int NN=1e5+10;

lli qs[NN];
int main()
{
    set <lli> S;
    lli ans = 0;
    int N;
    lli M;
    cin >> N >> M;
    S.insert(M);
    for(int i=1;i<=N;++i)
    {
        lli x;
        cin >> x;
        qs[i] = ((x % M) + M + qs[i-1])%M;
        auto it1 = S.upper_bound(qs[i]+1);
        ans = max(ans , (qs[i] + M - (long long)(*it1)) % M);
        if(qs[i]==0){
            S.insert(M);
        }else{
            S.insert(qs[i]);
        }
    }
    cout << ans;
}
