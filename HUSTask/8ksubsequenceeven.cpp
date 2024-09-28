#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    long long sum = 0;
    int out = 0;
    for (int i = 0; i < k; i++) {
        sum += array[i];
    }
    // if (sum % 2) {
    //     out++;
    // }
    for (int i = 0; i < n - k + 1; i++) {
        if (sum % 2 == 0) {
            out++;
        }
        sum = sum - array[i] + array[i + k];
    }
    cout << out;
    return 0;
}