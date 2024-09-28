#include <bits/stdc++.h>
using namespace std;

int main(){
    map <int,int> map;
    
    int k;
    int n;
    cin >> k;
    cin >> n;
     
    for (int i = k+1;i<=n;i++){ //  n!/k!
        int temp = i;
        int checkval=2;
        while (temp!=1){
            if (temp%checkval==0){
                temp = temp/checkval;
                map[checkval]++;
            }
            else{
                checkval++;
            }
        }
    }

    for (int i = 2; i<=n-k;i++){ // (n-k)!
        int temp = i;
        int checkval=2;
        while (temp!=1){
            if (temp%checkval==0){
                temp = temp/checkval;
                map[checkval]--;
            }
            else{
                checkval++;
            }
        }
    }
    unsigned long long output=1;
    for (auto i:map){
        output *= pow(i.first, i.second);
        output %= (unsigned long long)(1.0E9+7);
    }
    cout << output << endl;
    return 0;
}