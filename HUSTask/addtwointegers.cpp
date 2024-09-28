#include <bits/stdc++.h>
using namespace std;

int main(){
    string astr;
    string bstr;
    cin >> astr >> bstr;
    string::iterator a_pointer = astr.end()-1;
    string::iterator b_pointer = bstr.end()-1;
    string sum="";
    int remain = 0;
    while (a_pointer >= astr.begin() || b_pointer >= bstr.begin()){
        int a = *a_pointer - '0';
        int b = *b_pointer - '0'; 
        
        if (a_pointer < astr.begin()){
            a=0;
        }
        else if(b_pointer < bstr.begin()){
            b=0;
        }

        int num = (a+b)%10;
        
        sum.insert(0, 1, (num+remain) + '0');
        remain = (a+b)/10;

        a_pointer--;
        b_pointer--;
    }
    if (remain==1){
    sum.insert(0, 1, (remain) + '0');
    }
    cout << sum << endl;
    return 0;
}