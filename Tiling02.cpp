#include<bits/stdc++.h>
using namespace std;

int DP[40] , sum[40];

int main()
{
    int t;
    scanf("%d",&t);
    DP[0] = sum[0] = 1;
    for(int i=2;i<=30;i+=2)
    {
        DP[i] = 3*DP[i-2];
        if(i >= 4) DP[i] += 2*sum[i-4];
        sum[i] += DP[i] + sum[i-2];
    }
    while(t--)
    {
        int n;
        scanf("%d",&n);
        cout << DP[n] << endl;
    }
}
