#include <bits/stdc++.h>
#include <map>
using namespace std;
// partial ...
// max = max (all case), backward, dp
map <int, int> localMax;

int main(){
    int n, l1, l2;
    cin >> n >> l1 >> l2;
    int input[n];
    for (int i = 0 ; i < n ; i++){
        cin >> input[i];
    }
    
    int curCheckLength = l2 - l1;

    for (int i = n-1 ; i >= 0 ; i--){
        if (i > n - 1 - l1){// basecase, run
            localMax[i] = input[i];
        }
        else{
            if (i > n - l2){ // adjust check
                curCheckLength = i - n + l2;
            }
            int step = 0;
            int stepMax = 0;
            for (int j = l1; j <= l1 + curCheckLength; j++){ //check
                step = input[i] + localMax[i+j];
                stepMax = max(stepMax,step);
            }
            localMax[i] = stepMax;
        }
    }
    //choose start point (l1 first val)
    int res = 0;
    for (int i = 0; i < l1; i++){
        int check = localMax[i];
        res = max(res,check);
    }
    cout << res;
}