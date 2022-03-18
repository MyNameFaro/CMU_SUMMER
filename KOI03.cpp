#include <bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int>;

bool except[102];
int A[102] , dis[110][500];
bool visited[110][500];

int upper(int x,int NN,int N)
{
    if(x > N) return N + 1;
    int l=1,r=NN;
    int ans=N+1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(A[mid] >= x)
        {
            ans=min(ans,A[mid]);
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

int main()
{
    int N,M;
    cin >> N >> M;
    int x;
    for(int i=1;i<=M;++i)
    {
        cin >> x;
        except[x]=true;
    }
    int NN=0;
    for(int i=1;i<=N;++i)
    {
        if(!except[i])
        {
            A[++NN] = i;
        }
    }
    for(int i=0;i<110;++i)
    {
        for(int j=0;j<500;++j)
        {
            dis[i][j]=2e9;
        }
    }
    priority_queue <tll , vector<tll> , greater<tll>> PQ;
    dis[1][0]=0;
    PQ.emplace(dis[1][0] , 1 , 0);
    while(!PQ.empty())
    {
        int u=get<1>(PQ.top());
        int s=get<2>(PQ.top());PQ.pop();

        if(visited[u][s]) continue;
        visited[u][s]=true;

        if(u == N + 1)
        {
            cout << dis[u][s];
            return 0;
        }

        if(s >= 3)
        {
            int v = upper(u+1 , NN , N);
            int ss=s-3;
            if(!visited[v][ss] and dis[v][ss] > dis[u][s])
            {
                dis[v][ss] = dis[u][s];
                PQ.emplace(dis[v][ss] , v , ss);
            }
        }
        int v,ss;
        v = upper(u+1 , NN , N),ss = s;
        if(!visited[v][ss] and dis[v][ss] > dis[u][s] + 10000)
        {
            dis[v][ss] = dis[u][s] + 10000;
            PQ.emplace(dis[v][ss] , v , ss);
        }
        v = upper(u+3 , NN , N),ss = s + 1;
        if(!visited[v][ss] and dis[v][ss] > dis[u][s] + 25000)
        {
            dis[v][ss] = dis[u][s] + 25000;
            PQ.emplace(dis[v][ss] , v , ss);
        }
        v = upper(u+5 , NN , N),ss = s + 2;
        if(!visited[v][ss] and dis[v][ss] > dis[u][s] + 37000)
        {
            dis[v][ss] = dis[u][s] + 37000;
            PQ.emplace(dis[v][ss] , v , ss);
        }
    }
}
