#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;scanf("%d",&N);
	priority_queue <int> L;
	int x;
	int mn = 2e9;
	for(int i = 1;i <= N;++i){
		scanf("%d",&x);
		L.push(x);
	}
	int a , b;
	a = L.top();L.pop();
	while(!L.empty()){
		b = L.top();L.pop();
		mn = min(mn , a - b);
		a = b;
	}
	printf("%d",mn);
}
