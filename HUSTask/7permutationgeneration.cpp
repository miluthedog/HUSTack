#include <stdio.h>

int n;
int x[100];
bool used[100];

void solution(){
    for(int k = 1; k <= n; k++)
        printf("%d ",x[k]);
    printf("\n");
}

void loop(int k){
    for(int v = 1; v <= n; v++){ 
        if (used[v]==false){
            x[k] = v; 
            used[v] = true;
            if (k == n)
                solution();
            else
                loop(k+1);
            used[v] = false;
            }
    }
}
int main(){
    scanf("%d",&n);  
    for(int v = 1; v <= n; v++) used[v] = 0; 
    loop(1);
}

