#include <bits/stdc++.h>
using namespace std;

int table[61][61][61][61];

int main(){
	string s , t , u , v;
	cin >> s;
	cin >> t;
	cin >> u;
	cin >> v;
	for(int i = 1;i <= s.size();++i){
		for(int j = 1;j <= t.size();++j){
			for(int k = 1;k <= u.size();++k){
				for(int l = 1;l <= v.size();++l){
					if(s[i - 1] == t[j - 1] && u[k - 1] == v[l - 1] && t[j - 1] == u[k - 1]){
						table[i][j][k][l] = 1 + table[i - 1][j - 1][k - 1][l - 1];
						continue;
					}
					table[i][j][k][l] = max(table[i - 1][j][k][l] , table[i][j - 1][k][l]);
					table[i][j][k][l] = max(table[i][j][k][l] , max(table[i][j][k - 1][l] , table[i][j][k][l - 1]));
				
				}
			}
		}
	}
	printf("%d",table[s.size()][t.size()][u.size()][v.size()]);
}
