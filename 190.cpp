#include <bits/stdc++.h>
using namespace std;
using pii = pair <int , int>;

bool cp(pii a , pii b){
	return a.first*a.second > b.first * b.se;
}

int main(){
	int N;scanf("%d",&N);
	int a , e;
	vector <pii> pq;
	for(int i = 1;i <= N;++i){
		scanf("%d %d",&a,&e);
		pq.push_back({a , e});
	}
	sort(pq.begin() , pq.end() , cp);
	int sum = 0;
	for(auto ae : pq){
		a = ae.first;
		e = ae.second;
		if(a < sum) continue;
		//cout << a << " " << e << endl;
		sum += e;
	}
	printf("%d",sum);
}
