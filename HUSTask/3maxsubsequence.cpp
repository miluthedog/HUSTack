#include <bits/stdc++.h>
using namespace std;
// shoutout to kadane
int main(){
    int n;
    cin>>n;
    int array[n];
    for (int i;i<n;i++){
        cin>>array[i];
    }

    int left=array[0];
    int res=array[0];
    for (int i=1;i<n;i++){
        left = max(array[i] ,left+array[i]);

        res = max(res,left); 
    }
    cout << res << endl;
    return 0;
    }