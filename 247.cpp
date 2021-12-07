#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;

int main(){
	int Q;
	int c , x;
	scanf("%d",&Q);
	set <int> s;
	priority_queue <pair<int , pii> , vector<pair<int , pii>> , greater<pair<int , pii>>> mn;
	while(Q--){
		scanf("%d",&c);
		if(c == 1){
			scanf("%d",&x);
			s.insert(x);
			if(s.size() == 2) mn.push({abs(*(s.begin()) - *(--s.end())) , {*(s.begin()) , *(--s.end())}});
			if(s.size() > 2){
				if(x != *(--s.end())){
					auto it = s.find(x);++it;
					mn.push({abs(x - *it) , {x , *it}});
				}
				if(x != *(s.begin())){
					auto it = s.find(x);--it;
					mn.push({abs(x - *it) , {x , *it}});
				}
			}
		}else if(c == 2){
			scanf("%d",&x);
			if(s.size() > 2){
				int a = *(--s.find(x));
				int b = *(++s.find(x));
				mn.push({abs(a - b) , {a , b}});
			}
			s.erase(x);
		}else if(c == 4){
			int a = *(s.begin());
			int b = *(--s.end());
			printf("%d\n",abs(b - a));
		}else{
			if(s.size() == 2){
				int a = *(s.begin());
				int b = *(--s.end());
				printf("%d\n",abs(b - a));
			}else if(!mn.empty()){
				int a = mn.top().second.first;
				int b = mn.top().second.second;
				while((s.find(a) == s.end() || s.find(b) == s.end()) && !mn.empty()){
					mn.pop();
					a = mn.top().second.first;
					b = mn.top().second.second;
				}
				if(!mn.empty()) printf("%d\n",abs(b - a));
			}
		}
	}
}
