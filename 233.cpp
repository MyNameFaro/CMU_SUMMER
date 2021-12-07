#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int mapp[502][502];

int ans_total = 0;
int r = 0;
void bfs(int n , int m,int N ,int M){
	int ans = 0;
	queue <pair <int , int>> q;
	pair<int , int> node;
	q.push({m , n});
	if(mapp[n][m] == 2){
		++ans;
	}
	mapp[n][m] = 0;
	int left , right , top ,down;
	while(!q.empty()){
		
		//INIT
		node = q.front();
		q.pop();
		left = node.X - 1;
		right = node.X + 1;
		top = node.Y - 1;
		down = node.Y + 1;
		if(left == 0){
			left = M;
		}
		if(right == M + 1){
			right = 1;
		}
		if(top == 0){
			top = N;
		}
		if(down == N + 1){
			down = 1;
		}
		
		if(mapp[node.Y][left] > 0){
			if(mapp[node.Y][left] == 2){
				++ans;
			}
			mapp[node.Y][left] = r;
			q.push({left , node.Y});
		}
		if(mapp[node.Y][right] > 0){
			if(mapp[node.Y][right] == 2){
				++ans;
			}
			mapp[node.Y][right] = r;
			q.push({right , node.Y});
		}
		if(mapp[top][node.X] > 0){
			if(mapp[top][node.X] == 2){
				++ans;
			}
			mapp[top][node.X] = r;
			q.push({node.X , top});
		}
		if(mapp[down][node.X] > 0){
			if(mapp[down][node.X] == 2){
				++ans;
			}
			mapp[down][node.X] = r;
			q.push({node.X , down});
		}
		
		
	}
	
	ans_total = max(ans , ans_total);
	
	
}


int main(){
	int N , M;
	char ch;
	scanf(" %d %d",&N ,&M);
	for(int n = 1;n <= N;++n){
		for(int m = 1;m <= M;++m){
			scanf(" %c",&ch);
			if(ch == 46){
				mapp[n][m] = 1;
			}else if(ch == 42){
				mapp[n][m] = 2;
			}
		}
	}
	for(int n = 1;n <= N;++n){
		for(int m = 1;m <= M;++m){
			if(mapp[n][m] > 0){
				bfs(n , m , N , M);
			}
		}
	}
	printf("%d",ans_total);
	
}

