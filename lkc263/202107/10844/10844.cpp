#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define NSIZE 101
#define DIVISION 1000000000
using namespace std;

int N;
int dp[NSIZE][NSIZE];
int result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    for(int i=1;i<NSIZE;i++){
        for(int j=0;j<10;j++){
            if(i==1){
                dp[i][j] = 1;
            }else if(j==0){
                dp[i][j] = dp[i-1][1] % DIVISION;
            }else if(1<= j && j<=8){
                dp[i][j] = dp[i-1][j-1]%DIVISION + dp[i-1][j+1]%DIVISION;
            }else if(j==9){
                dp[i][j] = dp[i-1][8] % DIVISION;
            }
        }
    }


    cin >> N;
    for(int i=1;i<10;i++){
        result = (result%DIVISION + dp[N][i]%DIVISION)%DIVISION;
    }


    cout << result % DIVISION <<"\n";


    return 0;
}
