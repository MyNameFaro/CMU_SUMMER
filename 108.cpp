#include <bits/stdc++.h>
using namespace std;

int table[2002][2002];
int main(){
	int mark_s;int ml = -2e9;
	string s , t;
	cin >> s >> t;
	for(int i = 1;i <= s.size();++i){
		for(int j = 1;j <= t.size();++j){
			if(s[i - 1] == t[j - 1]) table[i][j] = 1 + table[i - 1][j - 1];
			if(table[i][j] > ml){
				ml = table[i][j];
				mark_s = i;
			}
		}
	}
	for(int i = ml;i >= 1;--i) printf("%c",s[mark_s - i]);
}
