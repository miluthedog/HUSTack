#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std; unordered_map <string, int> database;
int main(){ string num = ""; string input = "";
    while (num!="*"){cin >> num; database[num] = 1;}
    while (input!="***"){cin >> input >> num; if(input == "find"){cout << database[num] << endl;} else if (input == "insert"){cout << abs(database[num]-1) << endl;database[num] = 1;}} return 0;}