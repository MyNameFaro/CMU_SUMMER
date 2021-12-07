#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	vector <char> new_s;
	int i = 0;
	for(auto c:s){
		if(c == '['){
			i = -1;
		}else if(c != ']'){
			new_s.insert(new_s.begin() + i, c);
		}else{
			i = new_s.size() - 1;
		}
		++i;
	}
	for(auto c:new_s) cout << c;
}
