#include <bits/stdc++.h>
#include <bitset>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=0; i<pow(2,n); i++) {
        for (int j = n-1; j >= 0; j--)
            cout << ((i >> j) & 1);
        cout << endl;
    }
}