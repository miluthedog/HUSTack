#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pha INT_MIN

// shout out to Kadane
signed main(){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int KadaneLoi = pha;
    int Kadane = pha;
    int maxEnding = arr[0];

    int cut;
    int tempCut;
    bool firstCut = true;

    for (int i = 1; i < n; i++) {
        if (maxEnding + arr[i] < arr[i]){ // cut maxEnding, save. For "cut": If odd, overwrite - If even and first, skip - If even and not first, add
            tempCut = abs(maxEnding);
            if (tempCut % 2 == 1){
                cut = tempCut;
                firstCut = false;
            }
            else if (firstCut == false){
                cut += tempCut;
            }

            maxEnding = arr[i];
        }
        else {
            maxEnding = maxEnding + arr[i];
        }

        if (maxEnding % 2 == 0)
            KadaneLoi = max(KadaneLoi, maxEnding);
        Kadane = max(Kadane, maxEnding);
    }

    int sol;
    Kadane -= cut;
    if (Kadane % 2 == 1)
        sol = KadaneLoi;
    else
        sol = max(Kadane,KadaneLoi);
    cout << sol;

    return 0;
}