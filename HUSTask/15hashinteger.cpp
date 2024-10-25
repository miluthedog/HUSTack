#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std; unordered_map <string, int> a;

int main(){string b="";string c="";while(b!="*"){cin>>b;a[b]=1;}while(c!="***"){cin>>c>>b;if(c=="find"){cout<<a[b]<< endl;}else if(c =="insert"){cout<<abs(a[b]-1)<<endl;a[b]=1;}}return 0;}