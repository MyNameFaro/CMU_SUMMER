#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}node;
node *head ;

void create(int val,node *root){
    root = new node;
    root->val = val;
    root->left = NULL;
    root->right = NULL;
}

void search_to_create(int val,node *root){
    while(root != NULL){
        if(val >= root->val){
            root = root->right;
        }else{
            root = root->left;
        }
    }
    create(val , root);
}

void search_to_print(int val,node *root){
    while(root != NULL){
        printf("%d ",root->val);
        if(root->val == val){
            return;
        }else{
            if(val >= root->val){
                root = root->right;
            }else{
                root = root->left;
            }
        }
    }
    printf("0\n");
}

int main(){
    int n , m , x ,i;
    scanf("%d",&n);
    for(i = 1;i <= n;i++){
        scanf("%d",&x);
        if(i == 1){
           create(x , head);
        }else{
            search_to_create(x , head);
        }
    }
    scanf("%d",&m);
    printf("%d \n",head->val);
    for(i = 1;i <= m;i++){
        scanf("%d",&x);
        search_to_print(x , head);
    }
}
