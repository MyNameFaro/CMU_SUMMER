#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair <int , int>;

int N;
int qs[1000002];
vector <vector <int>> hash_qs;
int mod(lli n){
	if(n > 0){
		return (int)(n % (lli) N);
	}else if(n == 0){
		return 0;
	}else{
		return (int)(abs((lli) N - (abs(n) % (lli) N))) % N; 
	}
}

struct Compare{
	bool operator()(pii &a , pii &b){
		if(a.first != b.first)return a.first > b.first;
		return a.second > b.second;
	}
};

priority_queue <pii , vector <pii> , Compare> pq;

int main(){
	scanf("%d",&N);
	hash_qs.assign(N , vector <int>());
	hash_qs[0].push_back(0);
	for(int i = 1;i <= N;++i){
		scanf("%lld",&qs[i]);
		qs[i] += qs[i - 1];
		hash_qs[mod(qs[i])].push_back(i);
	}
	for(int i = 0;i < N;++i){
		sort(hash_qs[i].begin() , hash_qs[i].end());
		for(int j = 0;j < hash_qs[i].size();++j){
			for(int k = j + 1;k < hash_qs[i].size();++k){
				pq.push({hash_qs[i][j] + 1,hash_qs[i][k]});
			}
		}
	}
	printf("%d\n",pq.size());
	while(!pq.empty()){
		int s = pq.top().first;int t = pq.top().second;
		pq.pop();
		printf("%d %d\n",s , t);
	}
}
