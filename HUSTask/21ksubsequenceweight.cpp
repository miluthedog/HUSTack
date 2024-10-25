#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; // init sequence len
    int k; // subsequence len (consecutive)
    int m; // required weight
    cin >> n >> k >> m;

    int count = 0;
    int curWeight = 0;
    int slidingWindow = k;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++){
        curWeight += arr[i];
    }
    if (curWeight == m)
        count++;
    while (slidingWindow < n){
        curWeight = curWeight + arr[slidingWindow] - arr[slidingWindow - k];
        slidingWindow++;
        if (curWeight == m)
            count++;
    }
    cout << count;
    return 0;
}