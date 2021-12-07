#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[62],t[62],u[62],v[62];
	scanf("%s",s);scanf("%s",t);scanf("%s",u);scanf("%s",v);
	int ss=strlen(s),tt=strlen(t),uu=strlen(u),vv=strlen(v);
	int table[ss+1][tt+1][uu+1][vv+1];
	for(int i=0;i<ss;++i) s[i]=toupper(s[i]);
	for(int i=0;i<tt;++i) t[i]=toupper(t[i]);
	for(int i=0;i<uu;++i) u[i]=toupper(u[i]);
	for(int i=0;i<vv;++i) v[i]=toupper(v[i]);
	for(int i=0;i<=ss;++i){
		for(int j=0;j<=tt;++j){
			for(int k=0;k<=uu;++k){
				for(int l=0;l<=vv;++l){
					if(i==0 and j==0 and k==0 and l==0){
						table[i][j][k][l]=0;
					}else{
						table[i][j][k][l]=2e9;
						if(i>0 and j>0 and k>0 and l>0 and s[i-1]==t[j-1] and t[j-1]==u[k-1] and u[k-1]==v[l-1]){ //stuv
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i-1][j-1][k-1][l-1]);
						}
						if(i>0 and l>0 and k>0 and s[i-1]==v[l-1] and v[l-1]==u[k-1]){ //kli
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i-1][j][k-1][l-1]);
						}
						if(k>0 and j>0 and l>0 and u[k-1]==t[j-1] and t[j-1]==v[l-1]){ //jkl
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i][j-1][k-1][l-1]);
						}
						if(i>0 and j>0 and l>0 and s[i-1]==t[j-1] and t[j-1]==v[l-1]){ //lij
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i-1][j-1][k][l-1]);
						}
						if(i>0 and j>0 and k>0 and s[i-1]==t[j-1] and t[j-1]==u[k-1]){ //ijk
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i-1][j-1][k-1][l]);
						}
						if(j>0 and l>0 and t[j-1]==v[l-1]){ //jl
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i][j-1][k][l-1]);
						}
						if(i>0 and k>0 and s[i-1]==u[k-1]){ //ik
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i-1][j][k-1][l]);
						}
						if(i>0 and l>0 and s[i-1]==v[l-1]){ //li
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i-1][j][k][l-1]);
						}
						if(k>0 and l>0 and u[k-1]==v[l-1]){ //kl
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i][j][k-1][l-1]);
						}
						if(j>0 and k>0 and t[j-1]==u[k-1]){ //jk
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i][j-1][k-1][l]);
						}
						if(i>0 and j>0 and s[i-1]==t[j-1]){ //ij
							table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i-1][j-1][k][l]);
						}
						if(i>0) table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i-1][j][k][l]);
						if(j>0) table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i][j-1][k][l]);
						if(k>0) table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i][j][k-1][l]);
						if(l>0) table[i][j][k][l]=min(table[i][j][k][l] , 1+table[i][j][k][l-1]);
					}
				}
			}
		}
	}
	printf("%d",table[ss][tt][uu][vv]);
}