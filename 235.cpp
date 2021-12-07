#include <bits/stdc++.h>
using namespace std;

string s , t;
long long int memo[502][502];
bool visit[502][502];

long long int f(int a , int b){
	if(b < 0){
		return 1;
	}else if(a < 0){
		return 0;
	}
	if(!visit[a][b]){
		visit[a][b] = true;
		long long int ans = 0;
		
		if(s[a] == t[b]){
			ans += f(a - 1,b - 1);
		}
		ans += f(a - 1,b);
		
		memo[a][b] = ans;
	}
	return memo[a][b];
}

int main(){
	cin >> s;
	cin >> t;
	printf("%lld", f(s.size() - 1 , t.size() - 1));
}
