#include <bits/stdc++.h>
using namespace std;

vector<vector <int>> ans;

vector<int> v;

int N = 10;

int f(int n){
	if(n == N + 1){
		bool check = true;
		for(int i = 0;i < N;++i){
			for(int j = 0;j < N;++j){
				if(i != j && abs(i - j) == abs(v[i] - v[j])){
					check = false;
					i = N - 1;
					break;
				}
			}
		}
		if(check){
			ans.push_back(v);
		}
	}else{
		for(int i = 1;i <= N;++i){
			if(find(v.begin() , v.end() , i) == v.end()){
				v.push_back(i);
				f(n + 1);
				v.erase(find(v.begin() , v.end() , i));
				
			}
		}
	}
}
int main(){
	
	FILE *fi;
	fi = fopen("140_3.txt","w");
	f(1);
	fprintf(fi,"%d\n",ans.size());
	for(int i = 0;i < ans.size();++i){
		//printf("pri(\"");
		for(int j = 0;j < ans[i].size();++j){
			fprintf(fi,"%d ",ans[i][j]);
		}
		fprintf(fi,"\n");
	}
	fclose(fi);
}
