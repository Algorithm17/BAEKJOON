#include<iostream>

using namespace std;


int dp[5];
int test(int n){
    return dp[n] = n;
}

int main(){
    int n = 3;
    cout << test(n)<<"\n";
    cout << dp[n];
    return 0;
}
