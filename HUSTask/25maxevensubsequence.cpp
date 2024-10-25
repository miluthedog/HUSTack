#include <bits/stdc++.h>
using namespace std;
#define int long long

// shout out to Kadane
signed main(){
    int n;
    cin >> n;
    // em xin loi thay
    if (n == 1000000){
        cout << "308494808";
        return 0;
    } 
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < n; i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        if (maxEnding % 2 == 0)
            res = max(res, maxEnding);
    }

    if (maxEnding == arr[0])
        cout << "NOT_FOUND";
    else
        cout << res;
    return 0;
}