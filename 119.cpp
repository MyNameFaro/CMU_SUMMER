#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[2002];
	scanf("%s",s);
	int Q;
	scanf("%d",&Q);
	while(Q--){
		char t[2002];
		scanf("%s",t);
		bool table[strlen(s)+1][strlen(t)+1];
		table[0][0]=true;
		for(int i=0;i<=strlen(s);++i){
			for(int j=0;j<=strlen(t);++j){
				if(i==0 and j==0) continue;
				if(i==0 or j==0){
					table[i][j]=false;
					if(t>0 and t[j-1]=='$'){
						table[i][j]=table[i][j-1];
					}
					continue;
				}
				if(t[j-1]=='$'){
					table[i][j]=table[i-1][j] or table[i][j-1] or table[i-1][j-1];
					continue;
				}
				if(s[i-1]==t[j-1] or t[j-1]=='-'){
					table[i][j]=table[i-1][j-1];
					continue;
				}
				table[i][j]=false;
			}
		}
		if(table[strlen(s)][strlen(t)]){
			printf("success\n");
		}else{
			printf("fail\n");
		}
	}
}
