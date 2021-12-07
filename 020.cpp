#include <bits/stdc++.h>
using namespace std;

int main(){
	int N , M;
	cin >> N >> M;
	vector <int> P (N + 1,0);
	queue <int> Q;
	vector <bool> out_Q (N + 1,false);
	priority_queue <int , vector <int> , greater<int>> T;
	for(int m = 1;m <= M;++m) T.push(m);
	int c , x;
	for(int i = 1;i <= (N * 2);++i){
		cin >> c >> x;
		if(c == 1){
			Q.push(x);
			if(!T.empty()){
				while(!Q.empty() && out_Q[Q.front()]){
						Q.pop();
					}
					if(!Q.empty()){
						P[Q.front()] = T.top();T.pop();
						Q.pop();
					}
			}
		}else{
			if(P[x] == 0){
				out_Q[x] = true;
			}else{
				T.push(P[x]);
				//cout << T.top() << endl;
			
				if(!Q.empty()){
					while(!Q.empty() && out_Q[Q.front()]){
						Q.pop();
					}
					if(!Q.empty()){
						P[Q.front()] = T.top();T.pop();
						Q.pop();
					}
					
				}	
			}
		}
		//for(int j = 1;j <= N;++j) printf("%d ",P[j]);
		//printf("\n");
	}
	for(int i = 1;i <= N;++i) printf("%d\n",abs(P[i]));
}
