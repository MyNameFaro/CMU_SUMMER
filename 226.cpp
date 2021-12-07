#include <bits/stdc++.h>
using namespace std;

map <pair <int , int> , int> memo;
queue <pair <int , int>> q;
int M , N , D;


int f(){
	int m , n , w;
	auto p = make_pair(0 , 0);
	int ans = 2e9;
	memo.insert({p , 0});
	q.push({0 , 0});
		
		while(!q.empty()){
			
			m = q.front().first;
			n = q.front().second;
			q.pop();
			p = make_pair(m , n);
			w = memo[p];
			if(m == D || n == D){
				ans = min(w , ans);
			}
			else{
				p = make_pair(0 , n);
				if( memo.find(p) == memo.end()){
			//printf("%d %d\n",p.first , p.second);
					memo.insert({p , w + 1});
					q.push({p.first , p.second});
				}
				p = make_pair(m , 0);
				if( memo.find(p) == memo.end()){
			//printf("%d %d\n",p.first , p.second);
					memo.insert({p , w + 1});
					q.push({p.first , p.second});
				}
				p = make_pair(M , n);
				if( memo.find(p) == memo.end()){
			//printf("%d %d\n",p.first , p.second);
					memo.insert({p , w + 1});
					q.push({p.first , p.second});
				}
				p = make_pair(m , N);
				if( memo.find(p) == memo.end()){
			//printf("%d %d\n",p.first , p.second);
					memo.insert({p , w + 1});
					q.push({p.first , p.second});
				}
				p = make_pair(min(m + n , M) , max(0 , (n - (M - m))));
				if( memo.find(p) == memo.end()){
			//printf("%d %d\n",p.first , p.second);
					memo.insert({p , w + 1});
					q.push({p.first , p.second});
				}
				p = make_pair( max(0 , (m - (N - n))) , min(m + n,N) );
				if( memo.find(p) == memo.end()){
			//printf("%d %d\n",p.first , p.second);
					memo.insert({p , w + 1});
					q.push({p.first , p.second});
				}
			}
			
		}
		return ans;

}

int main(){
	int T;
	
	int t , m , n , d;
	int result;
	scanf("%d",&T);
	for(t = 1;t <= T;++t){
		scanf("%d %d %d",&M , &N,&D);
		
		result = f();
		if(result == 2e9){
			printf("-1\n");
		}else{
			printf("%d\n",result);
		}
		
		memo.clear();
	}
}


