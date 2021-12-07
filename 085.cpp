#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
	int n;
	scanf("%d",&n);
	unordered_map<int,int> arr;
	int x;
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		if(arr.find(x)==arr.end()) arr[x]=i;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		if(arr.find(x)!=arr.end()){
			printf("%d\n",arr[x]);
		}else{
			printf("Not found\n");
		}
	}
}
