#include <bits/stdc++.h>
using namespace std;

bool check(vector <int> &M , vector<int> &A){
	int o_check = 0;int p_check = 0;
	vector <bool> mark_i (4 , false) , mark_j (4 , false);
	/*for(auto x:A) printf("%d",x);
	printf("\n");*/
	for(int i = 0;i < 4;++i){
		if(M[i] == A[i]){
			++o_check;
			mark_i[i] = true;
			mark_j[i] = true;
		} 
	}
	for(int i = 0;i < 4;++i){
		for(int j = 0;j<4;++j){
			if(i == j) continue;
			if(M[i] == A[j]){
				if(mark_i[i] || mark_j[j]) continue;
				if(i == j) ++o_check;
				if(i != j) ++p_check;
				mark_i[i] = true;
				mark_j[j] = true;
				continue;
			}
		}
	}
	return (o_check == M[4] && p_check == M[5]);
}

int main(){
	int N;
	scanf("%d",&N);
	int o , p;
	vector <int> M[N] , A;
	string s;
	
	for(int i = 0;i < N;++i){
		cin >> s;
		scanf("%d %d",&o,&p);
		M[i].push_back(s[0] - '0');M[i].push_back(s[1] - '0');
		M[i].push_back(s[2] - '0');M[i].push_back(s[3] - '0');
		M[i].push_back(o);M[i].push_back(p);
	}
	
	for(int i = 0;i <= 9;++i){
		for(int j = 0;j <= 9;++j){
			for(int k = 0;k <= 9;++k){
				for(int l = 0;l <= 9;++l){
					bool result = true;
					A.push_back(i);A.push_back(j);
					A.push_back(k);A.push_back(l);
					for(int h = 0;h < N;++h){
						result = result && check(M[h] , A);
					} 
					if(result) printf("%d%d%d%d\n",i,j,k,l);
					A.clear();
				}
			}
		}
	}
}
