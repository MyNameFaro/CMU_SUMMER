#include <bits/stdc++.h>
#define V first
#define W second
using namespace std;

vector <pair <int , int>> g[1002]; //{Vertex , Weight}
int p[1002]; //Path

stack <int> findpath(int s,int t){
	stack <int> path;
	path.push(t);
	pair <int , int> node;
	node = make_pair(t , p[t]);
	while(p[node.V] > 0){ //Travel From T to S
		for(int i = 0 ;i < g[node.V].size();++i){
			if( p[node.V] - g[node.V][i].W == p[g[node.V][i].V] ){
				node = make_pair(g[node.V][i].V , p[g[node.V][i].V]);
				path.push(node.V);
				break;  // To have only one vertex that travelling pass
			}
		}
	}
	return path;
}

int travel(int s , int t){ // BST
	queue <pair <int , int>> q;
	pair <int , int> node;
	q.push({s , 0});
	p[s] = 0;
	while(!q.empty()){
		node = q.front();
		//cout << node.V << " " << node.W << endl;
		q.pop();
		for(int i = 0;i < g[node.V].size();++i){ //IF have Path less than...
			if(g[node.V][i].W + node.W < p[g[node.V][i].V]){
				p[g[node.V][i].V] = g[node.V][i].W + node.W;
				q.push({g[node.V][i].V , p[g[node.V][i].V]});
				
			}
		}
	}
	if(p[t] == 2e9){
		return -1;
	}
	return p[t];
}

int main(){
	for(int i = 0;i < 1002;++i){
		p[i] = 2e9;
	}
	int n , m , z , s , t;
	scanf("%d %d %d",&n ,&m ,&z);
	scanf("%d %d",&s,&t);
	int u , v , w;
	for(int i = 1;i <= m;++i){
		scanf("%d %d %d",&u ,&v ,&w);
		if(z < w){
			g[u].push_back({v , w});
			g[v].push_back({u , w});
		}
		
	}
	int q;
	scanf("%d",&q);
	int j = travel(s , t);
	printf("%d\n",j);
	if(q == 1 || j == -1){
		return 0;
	}else{
		stack <int> path = findpath(s , t);
	
		printf("%d\n",path.size());
		while(!path.empty()){
			printf("%d ",path.top());
			path.pop();
		}
	}
	
	
}
