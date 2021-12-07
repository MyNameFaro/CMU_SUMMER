#include <bits/stdc++.h>
using namespace std;

void space_(int space){
    int i;
    for(i = 1;i <= space;i++){
        printf(" ");
    }
}

void head(int n){
    int space = n + 2;
    space_(space);
    printf("  |\n");
    space_(space);
    printf("__*__\n");
}

void trunk(int n){
    int space = n + 3;
    int i;
    space_(space);
    printf("|||\n");
    for(i = 1;i<=space;i++){
        printf("_");
    }
    printf("|||");
    for(i = 1;i<=space;i++){
        printf("_");
    }
}

void head_leaf(int n){
    int space = n - 1;
    space_(space);
    printf("    /|");
    printf("\\\n");
    space_(space);
    printf("   /* *");
    printf("\\\n");
    space_(space);
    printf("  /* * *");
    printf("\\\n");
    space_(space);
    printf(" /* * * *");
    printf("\\\n");
    space_(space);
    printf("/* * * * *");
    printf("\\\n");
}

void leaf(int n){
    int space = n;
    int star = 4;
    int r , s , t;
    for(r = 1;r < n; r++){
        for(s = 1;s <= 3; s++){
            space_(space);
            printf("/*");
            for(t = 1;t < star;t++){
                printf(" *");
            }
            printf("\\\n");
            star++;
            space--;
        }
        space+=2;
        star-=2;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    head(n);
    head_leaf(n);
    leaf(n);
    trunk(n);
}
