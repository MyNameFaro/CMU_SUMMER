#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	struct node *left;
	struct node *right;
};

struct node *create_node(int val){
	struct node *newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode->val = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void insert(struct node *parent , int val){
	if(val < parent->val){
		if(parent->left == NULL){
			parent->left = create_node(val);
		}else{
			insert(parent->left , val);
		}
		
	}else{
		if(parent->right == NULL){
			parent->right = create_node(val);
		}else{
			insert(parent->right , val);
		}
		
	}
}

void post_order(struct node *parent){
	if(parent->left != NULL){
		post_order(parent->left);
	}
	if(parent->right != NULL){
		post_order(parent->right);
	}
	printf("%d ",parent->val);
}


int main(){
	struct node *head = NULL;
	int n , x;
	scanf("%d",&n);
	scanf("%d",&x);
	head = create_node(x);
	for(int i = 2;i <= n;++i){
		scanf("%d",&x);
		insert(head , x);
	}
	post_order(head);
}
