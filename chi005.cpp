#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> f , d;

int main()
{
    int q;
    int t,x;
    cin >> q;
    while(q--)
    {
        cin>>t >> x;
        if(t == 1)
        {
            int pre = d[x];
            int cur = d[x] + 1;
            ++d[x];
            f[cur]++;
            if(f[pre] > 0) f[pre]--;
        }else if(t==2)
        {
            //if(d[x] > 0)
            //{
                int pre = d[x];
                int cur = d[x] - 1;
                --d[x];
                f[cur]++;
                if(f[pre] > 0) f[pre]--;
            //}

        }else if(t==3)
        {
            cout << (bool) f[x] << endl;
        }
    }
}
