#include <bits/stdc++.h>
using namespace std;

int table[2002][2002];
int main(){
	int mark_s;int ml = -2e9;
	string s;
	cin >> s;
	for(int i = 1;i <= s.size();++i){
		for(int j = 1;j <= s.size();++j){
			if(s[i - 1] == s[j - 1] && (i != j)){
				table[i][j] = 1 + table[i - 1][j - 1];
			}else{
				table[i][j] = max(table[i - 1][j] , table[i][j - 1]);
			} 
			
		}
	}
	cout << table[s.size()][s.size()];
}
