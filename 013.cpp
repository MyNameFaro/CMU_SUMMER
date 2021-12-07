#include<bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<lli,lli>;
map <pii , lli> memo;
lli gcd(lli a ,lli b){
	if(memo.count(make_pair(a , b)) == 0){
		if(b == 0){
			memo[make_pair(a , b)] = a;
		}else{
			memo[make_pair(a , b)] = gcd(b , a % b);	
		} 
	}
	return memo[make_pair(a , b)];
}
int main(){
	lli n , k , c , p;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld %lld %lld",&n ,&k ,&c ,&p);
		lli consider = k * p / gcd(k , c);
		if(consider <= n){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}
