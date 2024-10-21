#include <bits/stdc++.h>

using namespace std;

bool pha(vector<int>& arr) {
    int i = arr.size() - 2;
    while (i >= 0 && arr[i] <= arr[i + 1])
        i--;
    if (i == -1) 
        return false;
    
    int j = arr.size() - 1;
    while (arr[j] >= arr[i])
        j--;
    swap(arr[i], arr[j]);
    reverse(arr.begin() + i + 1, arr.end());
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = n - i;

    string out;
    for (int i = 0; i < k; i++) {
        string temp;
        for (int j = 0; j < n; j++) {
            temp += to_string(arr[j]); 
            if (j < n - 1) 
                temp += " ";
        }
        out = temp + "\n" + out;
        pha(arr);
    }
    cout << out;

    return 0;
}
