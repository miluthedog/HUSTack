#include <bits/stdc++.h> 

main(){
    int n;
    std::cin>>n;
    int array[n];
    for (int i;i<n;i++){
        std::cin>>array[i];
    }

    double sum=0;
    for (int i=0;i<n;i++){
        sum+=array[i];
    }
    std::cout<<sum<<std::endl;
    return 0;
}