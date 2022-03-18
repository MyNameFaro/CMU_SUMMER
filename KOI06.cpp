#include <bits/stdc++.h>
using namespace std;

string s[102];
vector <char> G[300];
int deg[300] , color[300];
bool visited[300];

bool cycle(int u)
{
    color[u]=1;
    for(auto v:G[u])
    {
        if(color[v]==0)
        {
            if(!cycle(v))
            {
                return false;
            }
        }else if(color[v]==1)
        {
            return false;
        }
    }
    color[u]=2;
    return true;
}
int main()
{
    int N;
    cin >> N;
    vector <char> ans;
    priority_queue <char ,vector <char> , greater<char>> PQ;
    for(int i=1;i<=N;++i)
    {
        cin >> s[i];
    }
    for(int i=1;i<=N;++i)
    {
        for(int j=i+1;j<=N;++j)
        {
            bool pass=false;
            for(int k=0;k<min(s[i].size() , s[j].size());++k)
            {
                if(s[i][k] != s[j][k])
                {
                    G[s[i][k]].push_back(s[j][k]);
                    ++deg[s[j][k]];
                    pass=true;
                    break;
                }
            }
            if(s[i].size() > s[j].size() and !pass)
            {
                printf("-1");
                return 0;
            }
        }
    }

    for(int i='a';i<='z';++i)
    {
        if(color[i]==0 and !cycle(i))
        {
            printf("-1");
            return 0;
        }
    }
    for(int i='a';i<='z';++i)
    {
        if(deg[i]==0)
        {
            PQ.push(i);
            visited[i]=true;
        }
    }




    while(!PQ.empty())
    {
        int u=PQ.top();PQ.pop();
        ans.push_back(u);
        for(auto v:G[u])
        {
            if(--deg[(int) v] == 0 and !visited[v])
            {
                PQ.push(v);
                visited[v]=true;
            }
        }
    }
    for(auto a:ans)
    {
        cout << a;
    }
}
