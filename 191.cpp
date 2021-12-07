#include <bits/stdc++.h>
using namespace std;

int main(){
	int N , M;
	vector <int> S , T;
	set <int> SiT , SuT , SmT , TmS;
	
	scanf("%d %d",&N ,&M);
	int s , t;
	for(int i = 1;i <= N;++i){
		scanf("%d",&s);
		S.push_back(s);
		SuT.insert(s);
	}
	for(int i = 1;i <= M;++i){
		scanf("%d",&t);
		T.push_back(t);
		SuT.insert(t);
		if(find(S.begin() , S.end() , t) == S.end()){
			TmS.insert(t);
		}else{
			SiT.insert(t);
		}
	}
	for(auto e:S){
		if(find(SiT.begin() , SiT.end() , e) == SiT.end()) SmT.insert(e);
	}
	if(!SuT.empty()){
		for(auto e:SuT) printf("%d ",e);
	}else{
		printf("{}");
	}printf("\n");
	if(!SiT.empty()){
		for(auto e:SiT) printf("%d ",e);
	}else{
		printf("{}");
	}printf("\n");
	if(!SmT.empty()){
		for(auto e:SmT) printf("%d ",e);
	}else{
		printf("{}");
	}printf("\n");
	if(!TmS.empty()){
		for(auto e:TmS) printf("%d ",e);
	}else{
		printf("{}");
	}printf("\n");
}
