#include<bits/stdc++.h>
using namespace std;

const int NN=1e5+10;

int A[NN],G[NN];

int main()
{
    int N;
    cin >> N;
    queue <int> Q;
    for(int i=1;i<=N;++i)
    {
        cin >> A[i];
        G[i] = 1;
    }
    for(int i=2;i<N;++i)
    {
        if(A[i] <= A[i-1] and A[i] <= A[i+1])
        {
            Q.push(i);
        }
    }
    if(A[N] < A[N-1])
    {
        Q.push(N);
    }
    if(A[2] > A[1])
    {
        Q.push(1);
    }
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        if(u > 1 and G[u-1] < G[u] + 1 and A[u-1] > A[u])
        {
            G[u-1]= G[u] + 1;
            Q.push(u-1);
        }
        if(u < N and G[u+1] < G[u] + 1 and A[u+1] > A[u])
        {
            G[u+1]= G[u] + 1;
            Q.push(u+1);
        }
    }
    long long ans=0;
    for(int i=1;i<=N;++i)
    {
        ans += G[i];
    }
    printf("%lld",ans);
}
