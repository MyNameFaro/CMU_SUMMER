#include <bits/stdc++.h>
using namespace std;

vector<int> l[27];
int N , K;
int ans = 0;

void f(int x){
	if(x == N + 1){
		bool check = true;
		int s = 0;
		int i;
		for(i = 1;i <= K;++i){
			s += l[i].size();
			if(l[i].size() == 0){
				check = false;
				break;
			}
		}
		if(s == N && check){
			++ans;
		}
			
	}else{
		int i;
		for(i = 1;i <= K;++i){
			//if(x >= N - K + 1){
				//if(l[i].empty()){
					l[i].push_back(x);
					f(x + 1);
					l[i].pop_back();
				//}
			//}else{
				//l[i].push_back(x);
				//f(x + 1);
				//l[i].pop_back();
			//}
			
			//f(x + 1);
		}
	}
	
}

int main(){
	int T;
	int t ;
	int result;
	scanf("%d",&T);
	for(t = 1;t <= T;++t){
		ans = 0;
		scanf("%d %d",&N, &K);
		f(1);
		cout << ans << endl;
	}
}


