#include <bits/stdc++.h>
using namespace std;

const int NN=1e3+10;

bool DP[NN][NN];

void solve()
{
    string A,B;
    cin >> A;
    cin >> B;
    int N = A.size();
    int M = B.size();
    DP[0][0]=true;
    for(int i=1;i<=N;++i)
    {
        if('A' <= A[i-1] and A[i-1] <= 'Z')
        {
            DP[i][0]=false;
        }else{
            DP[i][0]=DP[i-1][0];
        }
    }
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=N;++j)
        {
            DP[i][j]=false;
            if(A[i-1] == B[j-1])
            {
                DP[i][j] = DP[i-1][j-1];
            }
            if(toupper(A[i-1]) == toupper(B[j-1]) and 'A' <= B[j-1] and B[j-1] <='Z')
            {
                DP[i][j] = DP[i][j] or DP[i-1][j-1];
            }
            if('a' <= A[i-1] and A[i-1] <= 'z')
            {
                DP[i][j] = DP[i][j] or DP[i-1][j];
            }
        }
    }
    if(DP[N][M])
    {
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        solve();
    }
}
