#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std; unordered_map <string, int> a;

int main(){string b="";string c="";while(b!="*"){cin>>b;a[b]=1;}while(1){cin>>c>>b;if(c=="***")break;cout<<((c=="find")?a[b]:abs(a[b]-1))<<endl;if(c=="insert")a[b]=1;}return 0;}