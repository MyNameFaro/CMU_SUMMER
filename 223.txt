#include <bits/stdc++.h>
#define V first
#define W second
#define P first
#define T second
using namespace std;

vector <bool> visited;
vector<int> p; //SHORTEST PATH FOR 1 TO VERTEXT I
vector <vector <pair<int , int>>> g; //GRAPH

struct Comp {
    bool operator()(
        pair<int, int> & a,
        pair<int, int> & b)
    {
        return a.second > b.second;
    }
};

int shortest_path(int N){
	priority_queue <pair<int , int> , vector <pair<int , int>> ,Comp > q;
	pair<int , int> node , next;
	q.push({1 , 0});
	p[1] = 0;
	while(!q.empty()){
		node = q.top();
		q.pop();
		visited[node.V] = true;
		for(int i = 0;i < g[node.V].size() ;++i){
			next = g[node.V][i];
			if( node.W + next.W < p[next.V] && !visited[next.V]){ // IF IT HAVE SHORTER PATH
				p[next.V] = node.W + next.W;
				q.push({next.V , p[next.V]});
			}
		}	
	}
	if(!visited[N]){
		return -1;
	}
	return p[N];
}

void fx(){
		int N , x = 0, y = 0;
		int i , j;
		int cnt = 1;
		vector <pair<int , int>> v;
		scanf("%d",&N);
		for(i = 0;i <= N + 1;++i){ //INIT P VECTOR
			p.push_back(2e9);
			visited.push_back(false);
		}
		g.push_back(v); //INIT g[0]
		for(i = 1;i < N;++i){ //INIT g[1...N]
			v.clear();
			for(j = 1;j <= min(6 , N - i);++j){
				v.push_back({i + j , j});
			}
			g.push_back(v);
		}
		v.clear();
		g.push_back(v);
		
		while(true){
			scanf(" %d %d",&x ,&y);
			if(x == -1){
				break;
			}
			g[x].clear();
			g[x].push_back({y , 0});
		}
		 //SHORTEST PATH 
		printf("%d\n",shortest_path(N)); //THE MINIMUM TOKEN
		
		g.clear();
		p.clear();
		visited.clear();
		//snake.clear();
		return;
		
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t = 0;t < T;++t){
		fx();	
	}
}
