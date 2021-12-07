#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int p[200002],h[200002]; //PARENT AND HEIGHT
vector <int> member[200002];
int id_=1;
unordered_map<lli,int> id;
string idd[200002];
int P=1e9+7;

void merge(int u,int v,int d){
	if(p[u]==p[v]) return;
	//IF
	if(member[p[v]].size() > member[p[u]].size()){
		swap(u,v);
		d*=-1;
	}
	int diff=h[u]-h[v]-d; //h[u]-d=h[v]+diff
	u=p[u]; //PARENT
	v=p[v]; //PARENT
	h[v]+=diff; //CHANGE TO U STANDARD
	for(auto c:member[v]){
		h[c]+=diff;
	}
	if(h[u]<h[v]) swap(u,v); //FIND NEW ROOT
	//UNION
	p[v]=u;
	member[u].push_back(v); 
	for(auto c:member[v]){
		p[c]=u;
		member[u].push_back(c);
	}
	member[v].clear();
}
int input(){
	//INPUT AND CHANGE STRING TO NODE NUMBER
	string s;
	cin >> s;
	lli hash=0;
	for(int i=0;i<s.size();++i){
		hash*=P;
		hash+=s[i];
	}
	if(id[hash]==0){
		id[hash]=id_;
		idd[id_]=s; //ID x : string...
		++id_;
	}
	return id[hash];
}
int main(){
	int N,Q;
	scanf("%d %d",&N,&Q);
	for(int i=1;i<=200000;++i) p[i]=i;
	while(Q--){
		int m;
		string s;
		scanf("%d",&m);
		if(m==1){
			int a=input();
			int b=input();
			int d;
			scanf("%d",&d);
			merge(a,b,d);
		}else if(m==2){
			int a=input();
			int b=input();
			if(p[a]!=p[b]){
				printf("cannot tell\n");
			}else{
				printf("%d\n",h[a]-h[b]);
			}
		}else if(m==3){
			int ans=0;
			bool tell=true; //IF HAVE ONLY ONE PARENT
			for(int i=1;i<id_;++i){
				if(p[i]!=p[i-1] and i>1) tell=false; //IF DONT HAVE ONLY ONE PARENT
				ans=p[i]; 
				if(!tell) break; 
			}
			if(tell){
				cout << idd[ans] << endl;
			}else{
				printf("cannot tell\n");
			}
		}
	}
}
