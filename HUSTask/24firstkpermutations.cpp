#include <stdio.h>
#include <stdlib.h>

int n;
int x[1001];
int used[1001];
int k;

void quit(){
	exit(0);
}

void solution(){
    for(int k = 1; k <= n; k++)
        printf("%d ",x[k]);
    printf("\n");
    k--;
    if (k==0){
        quit();
    }
}

void Try(int k){
    for(int v = 1; v <= n; v++){ 
        if (used[v]==0){
            x[k] = v; 
            used[v] = 1;
            if (k == n)
                solution();
            else
                Try(k+1);
            used[v] = 0;
            }
    }
}
int main(){
    scanf("%d",&n);  
    scanf("%d",&k);
    for(int v = 1; v <= n; v++) used[v] = 0; 
    Try(1);
}