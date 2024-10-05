#include <stdio.h>

int n;
int x[100];
int used[100];

void solution(){
    for(int k = 1; k <= n; k++)
        printf("%d ",x[k]);
    printf("\n");
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
    for(int v = 1; v <= n; v++) used[v] = 0; 
    Try(1);
}

