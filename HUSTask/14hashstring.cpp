#include <bits/stdc++.h>
using namespace std;

void cal(string input, int mod){
    int res = 0;
    for (int i = 0; i < input.length(); i++){
        int add = input[i];
        res = (res*256 + add) % mod;
    }
    cout << res << endl;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;

    string input;
    int memo = 0;
    for (int i = 0; i < n; i++){
        cin >> input;
        cal(input, m);
    }
    return 0;
}