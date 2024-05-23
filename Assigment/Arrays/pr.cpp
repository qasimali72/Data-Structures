#include <iostream>
using namespace std;

int jo(int n , int k){
    if(n=1)
    return 1;
    else 
        return (jo(n-1 , k) + k +1)% n + 1;
}

int main(){

    int ans= jo(3,10);
    cout<<ans;

    return 0;
}